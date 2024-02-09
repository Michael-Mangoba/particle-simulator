#include "simulatorGui.h"
#include <imgui_impl_sdl2.h>
#include <SDL_opengl.h>
#include <imgui_impl_opengl3.h>

ImVec4 clear_color = ImVec4(0.45f, 0.55f, 0.60f, 1.00f);


void UseImGui::Init(SDL_Window* window, SDL_GLContext gl_context, const char* glsl_version) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;

	// Setup Platform/Renderer bindings
	ImGui_ImplSDL2_InitForOpenGL(window, gl_context);
	ImGui_ImplOpenGL3_Init(glsl_version);

	ImGui::StyleColorsLight();


}

void UseImGui::NewFrame() {
	//feed inputs to dear imgui, start new frame
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
}


void UseImGui::Update() {
	// render your GUI
	
}

void UseImGui::Render(SDL_Window* window) {
	// render imgui to screen
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::Render();
	glViewport(0, 0, (int)io.DisplaySize.x, (int)io.DisplaySize.y);
	glClearColor(clear_color.x * clear_color.w, clear_color.y * clear_color.w, clear_color.z * clear_color.w, clear_color.w);
	glClear(GL_COLOR_BUFFER_BIT);
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
}	

void UseImGui::Shutdown(SDL_Window* window, SDL_GLContext gl_context) {
	// Cleanup
	ImGui_ImplOpenGL3_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}