#pragma once

#include "imgui.h"
#include "backends/imgui_impl_opengl2.h"
#include "backends/imgui_impl_sdl2.h"

class CImGuiMan
{
public:
	void InitImgui();
	void ShutdownImgui();
	void RenderImGui();

private:
	SDL_Window* GetSdlWindow();

public:
	SDL_Window* m_pWindow;
};

extern CImGuiMan g_ImGuiMan;