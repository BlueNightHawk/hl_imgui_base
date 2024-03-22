#include "SDL.h"
#include "CImGuiMan.h"

void SDL_GL_GetDrawableSize(SDL_Window* window, int* w, int* h)
{
	SDL_GetWindowSize(window, w, h);
}

Uint32 SDL_GetGlobalMouseState(int* x, int* y)
{
	Uint32 result;
	int window_x, window_y, mouse_x_global, mouse_y_global;
	result = SDL_GetMouseState(&mouse_x_global, &mouse_y_global);
	SDL_GetWindowPosition(g_ImGuiMan.m_pWindow, &window_x, &window_y);

	mouse_x_global += window_x;
	mouse_y_global += window_y;

	*x = mouse_x_global;
	*y = mouse_y_global;

	return result;
}

int SDL_GetRendererOutputSize(SDL_Renderer* renderer, int* w, int* h)
{
	SDL_GetWindowSize(g_ImGuiMan.m_pWindow, w, h);
	return 1;
}