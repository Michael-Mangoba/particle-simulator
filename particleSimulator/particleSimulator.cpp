#define SDL_MAIN_HANDLED

#include "simulatorGui.h"
#include "particleSimulator.h"

using namespace std;

// Define Obstacle class
class Obstacle
{
public:
	int id;
	int x1, y1, x2, y2;

	Obstacle(int id, int x1, int y1, int x2, int y2)
		: id(id), x1(x1), y1(y1), x2(x2), y2(y2) {}

	// Render method to draw the obstacle
	void Render(SDL_Renderer *renderer) const
	{
		// Set Color to Red
		SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);

		// Draw a line
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
};

class Particle
{
public:
	int id;
	int x, y;
	double angle;
	int init_speed;
	const double PI = 3.14159265358979323846;
	ImVec4 particleColor = ImVec4(255, 0, 0, 255);
	int screen_width = 1280;
	int screen_height = 720;
	std::vector<Obstacle> &obstacles; // Reference to the vector of obstacles

	Particle(int id, int x, int y, int init_angle, int init_speed, std::vector<Obstacle> &obstacles)
		: id(id), x(x), y(y), angle(init_angle), init_speed(init_speed), obstacles(obstacles)
	{
		angle = 360 - angle;
		angle = init_angle * PI / 180;
		// print angle in degrees
			std::cout << "Angle in degrees: " << angle << std::endl;
	}

	void calculateNewPosition()
	{
		// Convert the angle to radians
		while (angle < 0)
		{
			angle += 2 * PI;
		}
		while (angle > 2 * PI)
		{
			angle -= 2 * PI;
		}
		// print angle in radians
		//std::cout << "Angle in radians: " << angle << std::endl;

		// Calculate the displacement in x and y directions
		int dx = (int)(init_speed * cos(angle));
		int dy = (int)(init_speed * sin(angle));

		// print displacement dx and dy
		//std::cout << "Displacement in x: " << dx << ", Displacement in y: " << dy << std::endl;

		// Update the particle's position
		x += dx;
		y += dy;
	}

	void handleWallBounce()
	{
		// Check if the particle is hitting the left or right wall
		if (x <= 0)
		{						// If hitting the left wall
			x = 0;				// Set x to the leftmost position
			angle = PI - angle; // Reverse the x-component of the velocity
		}
		else if (x >= screen_width - 10)
		{						   // If hitting the right wall
			x = screen_width - 10; // Set x to the rightmost position
			angle = PI - angle;	   // Reverse the x-component of the velocity
		}

		// Check if the particle is hitting the top or bottom wall
		if (y <= 0)
		{					// If hitting the top wall
			y = 0;			// Set y to the topmost position
			angle = -angle; // Reverse the y-component of the velocity
		}
		else if (y >= screen_height - 10)
		{							// If hitting the bottom wall
			y = screen_height - 10; // Set y to the bottommost position
			angle = -angle;			// Reverse the y-component of the velocity
		}
		handleObstacleBounce();
	}

	void handleObstacleBounce()
	{
		for (const auto &obstacle : obstacles)
		{
			float dx = obstacle.x2 - obstacle.x1;
			float dy = obstacle.y2 - obstacle.y1;

			float px = x - obstacle.x1;
			float py = y - obstacle.y1;

			float t = (px * dx + py * dy) / (dx * dx + dy * dy);
			t = std::max(0.0f, std::min(1.0f, t));

			float closest_x = obstacle.x1 + t * dx;
			float closest_y = obstacle.y1 + t * dy;

			float distance = std::sqrt((x - closest_x) * (x - closest_x) + (y - closest_y) * (y - closest_y));

			// Collision detected
			if (distance <= 5)
			{
				// Calculate the normal to the obstacle line
				float nx = -dy;
				float ny = dx;

				// Normalize the normal vector
				float length = std::sqrt(nx * nx + ny * ny);
				nx /= length;
				ny /= length;

				// Calculate the dot product of the movement vector and the normal vector
				float dot = dx * nx + dy * ny;

				// Reflect the movement vector about the normal vector
				float reflected_dx = dx - 2 * dot * nx;
				float reflected_dy = dy - 2 * dot * ny;

				// Update the angle based on the reflected movement vector
				angle = std::atan2(reflected_dy, reflected_dx);
			}
		}
	}

	// Render method to draw the particle
	void Render(SDL_Renderer *renderer)
	{
		// print rendering color red
		SDL_SetRenderDrawColor(renderer, particleColor.x, particleColor.y, particleColor.z, particleColor.w);
		// calculate new position of partice based on angle and speed
		calculateNewPosition();
		handleWallBounce();
		handleObstacleBounce();
		// Draw a Square
		SDL_Rect rect = {x, y, 10, 10};
		SDL_RenderFillRect(renderer, &rect);
	}
};

class UserFrame : public UseImGui
{
public:
	std::vector<Particle> particles;
	std::vector<Obstacle> obstacles;
	int max_threads = 4;
	int particle_id = 0;
	int particle_x = 0;
	int particle_y = 0;
	int particle_init_angle = 0;
	int particle_init_speed = 0;

	int obstacle_id = 0;
	int obstacle_x1 = 0;
	int obstacle_y1 = 0;
	int obstacle_x2 = 0;
	int obstacle_y2 = 0;

	virtual void Update() override
	{

		// render your GUI
		ImGui::Begin("Particle Simulator", 0, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

		particle_id = particles.size();

		// Input for particle
		ImGui::Separator();
		ImGui::Text("Particle");
		ImGui::InputInt("ID", &particle_id);
		ImGui::InputInt("X", &particle_x);
		ImGui::InputInt("Y", &particle_y);
		ImGui::InputInt("Init Angle", &particle_init_angle);
		ImGui::InputInt("Init Speed", &particle_init_speed);

		if (ImGui::Button("Add Particle"))
		{
			// add particle code
			Particle newParticle(particle_id, particle_x, particle_y, particle_init_angle, particle_init_speed, obstacles);
			particles.push_back(newParticle);
		}

		obstacle_id = obstacles.size();
		// Input for obstacle
		ImGui::Separator();
		ImGui::Text("Obstacle");
		ImGui::InputInt("ID", &obstacle_id);
		ImGui::InputInt("X1", &obstacle_x1);
		ImGui::InputInt("Y1", &obstacle_y1);
		ImGui::InputInt("X2", &obstacle_x2);
		ImGui::InputInt("Y2", &obstacle_y2);

		if (ImGui::Button("Add Obstacle"))
		{
			// add particle code
			Obstacle newObstacle(obstacle_id, obstacle_x1, obstacle_y1, obstacle_x2, obstacle_y2);
			obstacles.push_back(newObstacle);
		}

		ImGui::End();
	}

	void RenderParticlesAndObstacles(SDL_Renderer *renderer)
	{
		multiThreadParticles(renderer);
		// Render particles
		//for (auto &particle : particles)
		//{
		//	// Assuming Particle has a Render method
		//	particle.Render(renderer);
		//}
		int screen_width = 1280;
		int screen_height = 720;
		// Set the color to white
		SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

		// Draw border lines
		SDL_RenderDrawLine(renderer, 0, 0, screen_width, 0);						 // Top border line
		SDL_RenderDrawLine(renderer, screen_width, 0, screen_width, screen_height);	 // Right border line
		SDL_RenderDrawLine(renderer, screen_width, screen_height, 0, screen_height); // Bottom border line
		SDL_RenderDrawLine(renderer, 0, screen_height, 0, 0);						 // Left border line
		// Render obstacles
		for (const auto &obstacle : obstacles)
		{
			// Assuming Obstacle has a Render method
			obstacle.Render(renderer);
		}
	}

	void prepareMultiThreading() {
		// prepare multi-threading
		unsigned int cores = std::thread::hardware_concurrency();
		if (cores == 0) {
			std::cout << "Unable to determine the number of CPU cores." << std::endl;
		}
		else {
			std::cout << "Number of CPU cores: " << cores << std::endl;
			max_threads = cores;
		}
	}


	void multiThreadParticles(SDL_Renderer* renderer) {
		// Multi-threading
		std::vector<std::thread> threads;

		// Create threads
		for (int i = 0; i < max_threads; i++) {
			threads.push_back(std::thread(&UserFrame::updateParticles, this, i, renderer));
		}
		
		for (auto& thread : threads) {
			thread.join();
		}
	}

	void updateParticles(int thread_ID, SDL_Renderer* renderer) {
		// print thread id
		//std::cout << "Thread ID: " << thread_ID << std::endl;
		if (particles.size() < thread_ID) {
			return;
		}

		for (int i = thread_ID; i < particles.size(); i += max_threads) {
			particles[i].Render(renderer);
		}
	}
};

int main()
{
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}

	const char *glsl_version = "#version 130";

	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Window *window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	if (window == nullptr)
	{
		printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
		return -1;
	}

	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	if (gl_context == nullptr)
	{
		printf("Error: SDL_GL_CreateContext(): %s\n", SDL_GetError());
		return -1;
	}

	if (!gladLoadGLLoader((GLADloadproc)SDL_GL_GetProcAddress)) // tie window context to glad's opengl funcs
		throw("Unable to context to OpenGL");

	SDL_Renderer *renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	// int screen_width, screen_height;
	// glfwGetFramebufferSize(window, &screen_width, &screen_height);
	// glViewport(0, 0, screen_width, screen_height);
	ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);

	UserFrame myimgui;
	glViewport(0, 0, 1280, 720);
	myimgui.Init(window, renderer);
	myimgui.prepareMultiThreading();

	// Main loop
	bool done = false;

	SDL_Event event;
	while (!done)
	{
		while (SDL_PollEvent(&event))
		{
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				done = true;
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
				done = true;
		}
		SDL_SetRenderDrawColor(renderer, clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
		SDL_RenderClear(renderer);

		myimgui.NewFrame();
		myimgui.Update();

		myimgui.RenderParticlesAndObstacles(renderer);
		myimgui.Render(window);

		// Check for OpenGL errors
		GLenum error = glGetError();
		if (error != GL_NO_ERROR)
		{
			std::cerr << "OpenGL Error: " << error << std::endl;
		}

		SDL_RenderPresent(renderer);
	}
	myimgui.Shutdown(window, gl_context);
	return 0;
}