#pragma once

#include "ImGui.h"
#include "imgui_impl_opengl3.h"
#include "SDL.h"
#include <imgui_impl_sdl2.h>
#include <imgui_impl_sdlrenderer2.h>

class UseImGui{
public:
	void Init(SDL_Window* window, SDL_Renderer* renderer);
	void NewFrame();
	virtual void Update();
	void Render(SDL_Window* window);
	void Shutdown(SDL_Window* window, SDL_GLContext gl_context);

};