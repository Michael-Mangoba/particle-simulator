#include "simulatorGui.h"
#include "glad/glad.h"
#include <vector>
#include <iostream>
#include "imgui.h"
#include "imgui_impl_sdl2.h"
#include "imgui_impl_opengl3.h"
#include <SDL.h>



using namespace std;

class Particle {
public:
	int id;
	int x, y;
	int init_angle;
	int init_speed;
	ImVec4 particleColor = ImVec4(0.0f, 0.0f, 1.0f, 1.0f);

	Particle(int id, int x, int y, int init_angle, int init_speed)
		: id(id), x(x), y(y), init_angle(init_angle), init_speed(init_speed) {}

	// Render method to draw the particle
	void Render() const {
		//print rendering
		glColor4f(particleColor.x, particleColor.y, particleColor.z, particleColor.w);
		glPointSize(10.0f);  // Set point size (adjust as needed)
		glBegin(GL_POINTS);
		glVertex2i(x, y);
		glEnd();
	}
};

// Define Obstacle class
class Obstacle {
public:
	int id;
	int x1, y1, x2, y2;

	Obstacle(int id, int x1, int y1, int x2, int y2)
		: id(id), x1(x1), y1(y1), x2(x2), y2(y2) {}

	// Render method to draw the obstacle
	void Render() const {
		glBegin(GL_LINES);
		glVertex2i(x1, y1);
		glVertex2i(x2, y2);
		glEnd();
	}
};

class UserFrame : public UseImGui {
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

	virtual void Update() override {
		
		// render your GUI
		ImGui::Begin("Particle Simulator", 0, ImGuiWindowFlags_AlwaysAutoResize);
		ImGui::Text("FPS: %.1f", ImGui::GetIO().Framerate);

		particle_id = particles.size();

		//Input for particle
		ImGui::Separator();
		ImGui::Text("Particle");
		ImGui::InputInt("ID", &particle_id);
		ImGui::InputInt("X", &particle_x);
		ImGui::InputInt("Y", &particle_y);
		ImGui::InputInt("Init Angle", &particle_init_angle);
		ImGui::InputInt("Init Speed", &particle_init_speed);

		if (ImGui::Button("Add Particle")) {
			// add particle code
			Particle newParticle(particle_id, particle_x, particle_y, particle_init_angle, particle_init_speed);
			particles.push_back(newParticle);
		}

		//Input for obstacle
		ImGui::Separator();
		ImGui::Text("Obstacle");
		ImGui::InputInt("ID", &obstacle_id);
		ImGui::InputInt("X1", &obstacle_x1);
		ImGui::InputInt("Y1", &obstacle_y1);
		ImGui::InputInt("X2", &obstacle_x2);
		ImGui::InputInt("Y2", &obstacle_y2);

		if (ImGui::Button("Add Obstacle")) {
			// add particle code
			Obstacle newObstacle(obstacle_id, obstacle_x1, obstacle_y1, obstacle_x2, obstacle_y2);
			obstacles.push_back(newObstacle);
		}

		ImGui::End();
	}

	void RenderParticlesAndObstacles() {
		// Render particles
		for (const auto& particle : particles) {
			// Assuming Particle has a Render method
			particle.Render();
		}

		// Render obstacles
		for (const auto& obstacle : obstacles) {
			// Assuming Obstacle has a Render method
			obstacle.Render();
		}
	}
};


int main(){
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_TIMER | SDL_INIT_GAMECONTROLLER) != 0)
	{
		printf("Error: %s\n", SDL_GetError());
		return -1;
	}

	const char* glsl_version = "#version 130";
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_FLAGS, 0);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, 3);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, 0);

	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 24);
	SDL_GL_SetAttribute(SDL_GL_STENCIL_SIZE, 8);
	SDL_WindowFlags window_flags = (SDL_WindowFlags)(SDL_WINDOW_OPENGL | SDL_WINDOW_RESIZABLE | SDL_WINDOW_ALLOW_HIGHDPI);
	SDL_Window* window = SDL_CreateWindow("Dear ImGui SDL2+OpenGL3 example", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1280, 720, window_flags);
	if (window == nullptr)
	{
		printf("Error: SDL_CreateWindow(): %s\n", SDL_GetError());
		return -1;
	}

	SDL_GLContext gl_context = SDL_GL_CreateContext(window);
	SDL_GL_MakeCurrent(window, gl_context);
	SDL_GL_SetSwapInterval(1); // Enable vsync

	//if (!glfwInit())
	//	return 1;

	// GL 3.0 + GLSL 130
	//const char* glsl_version = "#version 130";
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	//glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	// Create window with graphics context
	//GLFWwindow* window = glfwCreateWindow(1280, 720, "Particle Simulator", NULL, NULL);
	//glfwMakeContextCurrent(window);
	//glfwSwapInterval(1); // Enable vsync
	
	//if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  // tie window context to glad's opengl funcs
	//	throw("Unable to context to OpenGL");
	
	//int screen_width, screen_height;
	//glfwGetFramebufferSize(window, &screen_width, &screen_height);
	//glViewport(0, 0, screen_width, screen_height);

	UserFrame myimgui;
	myimgui.Init(window, gl_context, glsl_version);


	// Main loop
	bool done = false;

	SDL_Event event;
	while(!done){
		while (SDL_PollEvent(&event)) {
			ImGui_ImplSDL2_ProcessEvent(&event);
			if (event.type == SDL_QUIT)
				done = true;
			if (event.type == SDL_WINDOWEVENT && event.window.event == SDL_WINDOWEVENT_CLOSE && event.window.windowID == SDL_GetWindowID(window))
				done = true;
		}

			myimgui.NewFrame();
			myimgui.Update();

			myimgui.RenderParticlesAndObstacles();

			myimgui.Render(window);


			// Check for OpenGL errors
			GLenum error = glGetError();
			if (error != GL_NO_ERROR) {
				std::cerr << "OpenGL Error: " << error << std::endl;
			}

	}
	myimgui.Shutdown(window, gl_context);
	return 0;
}