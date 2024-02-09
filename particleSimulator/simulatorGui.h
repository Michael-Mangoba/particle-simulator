#pragma once

#include "ImGui.h"
#include "imgui_impl_opengl3.h"
#include "SDL.h"

class UseImGui{
public:
	void Init(SDL_Window* window, SDL_GLContext gl_context, const char* glsl_version);
	void NewFrame();
	virtual void Update();
	void Render(SDL_Window* window);
	void Shutdown(SDL_Window* window, SDL_GLContext gl_context);

};