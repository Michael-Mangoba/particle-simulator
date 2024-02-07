#include "simulatorGui.h"
#include "glad/glad.h"
#include "GLFW/glfw3.h"
#include <vector>
#include <iostream>


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
	
	if (!glfwInit())
		return 1;

	// GL 3.0 + GLSL 130
	const char* glsl_version = "#version 130";
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 0);
	//glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);  // 3.2+ only
	//glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);            // 3.0+ only

	// Create window with graphics context
	GLFWwindow* window = glfwCreateWindow(1280, 720, "Particle Simulator", NULL, NULL);
	if (window == NULL)
		return 1;
	glfwMakeContextCurrent(window);
	glfwSwapInterval(1); // Enable vsync

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))  // tie window context to glad's opengl funcs
		throw("Unable to context to OpenGL");

	int screen_width, screen_height;
	glfwGetFramebufferSize(window, &screen_width, &screen_height);
	glViewport(0, 0, screen_width, screen_height);

	UserFrame myimgui;
	myimgui.Init(window, glsl_version);

	while (!glfwWindowShouldClose(window)) {
		glfwPollEvents();

		glClear(GL_COLOR_BUFFER_BIT);
		myimgui.NewFrame();
		myimgui.Update();

		myimgui.RenderParticlesAndObstacles();

		myimgui.Render();
		glfwSwapBuffers(window);

		// Check for OpenGL errors
		GLenum error = glGetError();
		if (error != GL_NO_ERROR) {
			std::cerr << "OpenGL Error: " << error << std::endl;
		}
	}
	myimgui.Shutdown();
	return 0;
}