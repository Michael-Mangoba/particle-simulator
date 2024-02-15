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
		std::cout << "Angle in radians: " << angle << std::endl;

		// Calculate the displacement in x and y directions
		int dx = (int)(init_speed * cos(angle));
		int dy = (int)(init_speed * sin(angle));
		// print displacement dx and dy

		std::cout << "Displacement in x: " << dx << ", Displacement in y: " << dy << std::endl;

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
			// Check for collision with the obstacle
			if (x >= obstacle.x1 && x <= obstacle.x2 && y >= obstacle.y1 && y <= obstacle.y2)
			{
				// Print the obstacle id
				std::cout << "Obstacle ID: " << obstacle.id << std::endl;
				// Perform obstacle bounce (modify angle as needed)
				angle = -angle;
				// Print the new angle
				std::cout << "Bounce New Angle: " << angle << std::endl;
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
		// Render particles
		for (auto &particle : particles)
		{
			// Assuming Particle has a Render method
			particle.Render(renderer);
		}
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
	// SDL_GL_MakeCurrent(window, gl_context);
	// SDL_GL_SetSwapInterval(1); // Enable vsync

	// if (!glfwInit())
	//	return 1;

	// GL 3.0 + GLSL 130
	// const char* glsl_version = "#version 130";
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	// glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	// glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	// glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	// Create window with graphics context
	// GLFWwindow* window = glfwCreateWindow(1280, 720, "Particle Simulator", NULL, NULL);
	// glfwMakeContextCurrent(window);
	// glfwSwapInterval(1); // Enable vsync

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