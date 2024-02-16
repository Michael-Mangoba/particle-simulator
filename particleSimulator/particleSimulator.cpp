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
	int collided_obstacle_id = -1;
	double angle;
	int init_velocity;
	const double PI = 3.14159265358979323846;
	ImVec4 particleColor = ImVec4(255, 0, 0, 255);
	int screen_width = 1280;
	int screen_height = 720;
	std::vector<Obstacle> &obstacles; // Reference to the vector of obstacles

	Particle(int id, int x, int y, int init_angle, int init_velocity, std::vector<Obstacle> &obstacles)
		: id(id), x(x), y(y), angle(init_angle), init_velocity(init_velocity), obstacles(obstacles)
	{
		angle = 360 - angle;
		angle = angle * PI / 180;
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

		// Calculate the displacement in x and y directions
		int dx = (int)(init_velocity * cos(angle));
		int dy = (int)(init_velocity * sin(angle));

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
			collided_obstacle_id = -1;
		}
		else if (x >= screen_width - 10)
		{						   // If hitting the right wall
			x = screen_width - 10; // Set x to the rightmost position
			angle = PI - angle;	   // Reverse the x-component of the velocity
			collided_obstacle_id = -1;
		}

		// Check if the particle is hitting the top or bottom wall
		if (y <= 0)
		{					// If hitting the top wall
			y = 0;			// Set y to the topmost position
			angle = -angle; // Reverse the y-component of the velocity
			collided_obstacle_id = -1;
		}
		else if (y >= screen_height - 10)
		{							// If hitting the bottom wall
			y = screen_height - 10; // Set y to the bottommost position
			angle = -angle;			// Reverse the y-component of the velocity
			collided_obstacle_id = -1;
		}
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
			if (distance <= 5 && obstacle.id != collided_obstacle_id)
			{
				collided_obstacle_id = obstacle.id;

				double line_angle = std::atan2(dy, dx);
				double new_angle = 2 * line_angle - angle;

				// normalize the angle
				while (new_angle < 0)
				{
					new_angle += 2 * PI;
				}
				while (new_angle > 2 * PI)
				{
					new_angle -= 2 * PI;
				}

				angle = new_angle;
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
		SDL_Rect rect = {x, y, 5, 5};
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
	int particle_init_velocity = 0;

	// Batch size for adding particles
	int batch_size = 0;
	// Method 1
	int m1_angle = 0;
	int m1_velocity = 0;
	int m1_start_x = 0;
	int m1_start_y = 0;
	int m1_end_x = 0;
	int m1_end_y = 0;
	// Method 2
	int m2_start_x = 0;
	int m2_start_y = 0;
	int m2_velocity = 0;
	int m2_start_angle = 0;
	int m2_end_angle = 0;
	// Method 3
	int m3_start_x = 0;
	int m3_start_y = 0;
	int m3_angle = 0;
	int m3_start_velocity = 0;
	int m3_end_velocity = 0;

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
		ImGui::InputInt("Init Velocity", &particle_init_velocity);

		if (ImGui::Button("Add Particle"))
		{
			// add particle code
			Particle newParticle(particle_id, particle_x, particle_y, particle_init_angle, particle_init_velocity, obstacles);
			particles.push_back(newParticle);
		}

		// Input for batch size
		ImGui::Separator();
		ImGui::Text("Batch Size");
		ImGui::InputInt("Batch Size", &batch_size);

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

		MethodOneGUI();
		MethodTwoGUI();
		MethodThreeGUI();
	}

	void MethodOneGUI()
	{
		ImGui::Begin("Method 1", 0, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::InputInt("Start X", &m1_start_x);
		clampValueRelativeToRange(m1_start_x, 0, 1280, m1_end_x);
		ImGui::InputInt("Start Y", &m1_start_y);
		clampValueRelativeToRange(m1_start_y, 0, 720, m1_end_y);
		ImGui::InputInt("End X", &m1_end_x);
		clampValueRelativeToRangeEnd(m1_end_x, 0, 1280, m1_start_x);
		ImGui::InputInt("End Y", &m1_end_y);
		clampValueRelativeToRangeEnd(m1_end_y, 0, 720, m1_start_y);
		ImGui::InputInt("Angle", &m1_angle);
		clampValue(m1_angle, 0, 360);
		ImGui::InputInt("Velocity", &m1_velocity);
		clampValue(m1_velocity, 1, 50);

		// Add particles in batch
		if (ImGui::Button("[Method 1] Add Particles in Batch"))
		{
			for (int i = 0; i < batch_size; i++)
			{
				// Calculate the distance between start and end points
				double dx = m1_end_x - m1_start_x;
				double dy = m1_end_y - m1_start_y;

				double distance = std::sqrt(dx * dx + dy * dy);

				double x = m1_start_x + (dx * i / batch_size);
				double y = m1_start_y + (dy * i / batch_size);

				int pos_x = (int)x;
				int pos_y = (int)y;

				// Add particle
				Particle newParticle(particle_id, pos_x, pos_y, m1_angle, m1_velocity, obstacles);
				particles.push_back(newParticle);
				particle_id++;
			}
		}
		ImGui::End();
	}

	void MethodTwoGUI()
	{
		ImGui::Begin("Method 2", 0, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::InputInt("Start X", &m2_start_x);
		clampValue(m2_start_x, 0, 1280);
		ImGui::InputInt("Start Y", &m2_start_y);
		clampValue(m2_start_y, 0, 720);
		ImGui::InputInt("Velocity", &m2_velocity);
		clampValue(m2_velocity, 1, 50);
		ImGui::InputInt("Start Angle", &m2_start_angle);
		clampValueRelativeToRange(m2_start_angle, 0, 360, m2_end_angle);
		ImGui::InputInt("End Angle", &m2_end_angle);
		clampValueRelativeToRangeEnd(m2_end_angle, 0, 360, m2_start_angle);
		if (ImGui::Button("[Method 2] Add Particles in Batch"))
		{
			for (int i = 0; i < batch_size; i++)
			{
				double angle = m2_start_angle + (m2_end_angle - m2_start_angle) * i / batch_size;
				Particle newParticle(particle_id, m2_start_x, m2_start_y, angle, m2_velocity, obstacles);
				particles.push_back(newParticle);
				particle_id++;
			}
		}
		ImGui::End();
	}

	void MethodThreeGUI()
	{
		ImGui::Begin("Method 3", 0, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::InputInt("Start X", &m3_start_x);
		clampValue(m3_start_x, 0, 1280);
		ImGui::InputInt("Start Y", &m3_start_y);
		clampValue(m3_start_y, 0, 720);
		ImGui::InputInt("Angle", &m3_angle);
		clampValue(m3_angle, 0, 360);
		ImGui::InputInt("Start Velocity", &m3_start_velocity);
		clampValueRelativeToRange(m3_start_velocity, 1, 50, m3_end_velocity);
		ImGui::InputInt("End Velocity", &m3_end_velocity);
		clampValueRelativeToRangeEnd(m3_end_velocity, 1, 50, m3_start_velocity);

		if (ImGui::Button("[Method 3] Add Particles in Batch"))
		{
			for (int i = 0; i < batch_size; i++)
			{
				double velocity = m3_start_velocity + (m3_end_velocity - m3_start_velocity) * i / batch_size;
				Particle newParticle(particle_id, m3_start_x, m3_start_y, m3_angle, velocity, obstacles);
				particles.push_back(newParticle);
				particle_id++;
			}
		}
		ImGui::End();
	}

	void clampValue(int &num, int min, int max)
	{
		if (num < min)
			num = min;
		if (num > max)
			num = max;
	}

	void clampValueRelativeToRange(int &num, int min, int max, int &relativeBound)
	{
		clampValue(num, min, max);
		if (num > relativeBound && num <= max)
			relativeBound = num;
	}

	void clampValueRelativeToRangeEnd(int &num, int min, int max, int &relativeBound)
	{
		clampValue(num, min, max);
		if (num < relativeBound && num >= min)
			relativeBound = num;
	}

	void RenderParticlesAndObstacles(SDL_Renderer *renderer)
	{
		multiThreadParticles(renderer);
		// Render particles
		// for (auto &particle : particles)
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

	void prepareMultiThreading()
	{
		// prepare multi-threading
		unsigned int cores = std::thread::hardware_concurrency();
		if (cores == 0)
		{
			std::cout << "Unable to determine the number of CPU cores." << std::endl;
		}
		else
		{
			std::cout << "Number of CPU cores: " << cores << std::endl;
			max_threads = (cores > 1) ? (cores - 1) : 1;
		}
	}

	void multiThreadParticles(SDL_Renderer *renderer)
	{
		// Multi-threading
		std::vector<std::thread> threads;

		// Create threads
		for (int i = 0; i < max_threads; i++)
		{
			threads.push_back(std::thread(&UserFrame::updateParticles, this, i, renderer));
		}

		for (auto &thread : threads)
		{
			thread.join();
		}
	}

	void updateParticles(int thread_ID, SDL_Renderer *renderer)
	{
		// print thread id
		// std::cout << "Thread ID: " << thread_ID << std::endl;
		if (particles.size() < thread_ID)
		{
			return;
		}

		for (int i = thread_ID; i < particles.size(); i += max_threads)
		{
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
	SDL_Window *window = SDL_CreateWindow("Particle Simulator (ImGUI SDL2+OpenGL3) - Mangoba, Palpallatoc", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
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