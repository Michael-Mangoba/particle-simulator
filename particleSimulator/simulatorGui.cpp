#include "simulatorGui.h"





void UseImGui::Init(SDL_Window* window, SDL_Renderer* renderer) {
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();

	// Setup Platform/Renderer bindings
	ImGui_ImplSDL2_InitForSDLRenderer(window, renderer);
	ImGui_ImplSDLRenderer2_Init(renderer);

	ImGui::StyleColorsLight();


}

void UseImGui::NewFrame() {
	//feed inputs to dear imgui, start new frame
	ImGui_ImplSDLRenderer2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();
}


void UseImGui::Update() {
	// render your GUI
	
}

void UseImGui::Render(SDL_Window* window) {
	// render imgui to screen
	ImGui::Render();
	ImGui_ImplSDLRenderer2_RenderDrawData(ImGui::GetDrawData());
	
}	

void UseImGui::Shutdown(SDL_Window* window, SDL_GLContext gl_context) {
	// Cleanup
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
	
	SDL_GL_DeleteContext(gl_context);
	SDL_DestroyWindow(window);
	SDL_Quit();
}