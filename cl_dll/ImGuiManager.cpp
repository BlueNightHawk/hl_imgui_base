#include "hud.h"
#include "PlatformHeaders.h"
#include "CImGuiMan.h"
#include "SDL.h"

CImGuiMan g_ImGuiMan;

static void ImGuiRenderFunc()
{
	g_ImGuiMan.RenderImGui();
}

static int ImGuiEventFilter(void*, SDL_Event* event)
{
	return ImGui_ImplSDL2_ProcessEvent(event);
}

void CImGuiMan::InitImgui(void **pRenderFunc)
{
	m_pWindow = GetSdlWindow();

	// Setup Dear ImGui context
	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO();
	(void)io;
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard; // Enable Keyboard Controls
	io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;  // Enable Gamepad Controls
	io.ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

	// Setup Dear ImGui style
	ImGui::StyleColorsDark();
	// ImGui::StyleColorsLight();

	// Setup Platform/Renderer backends
	ImGui_ImplSDL2_InitForOpenGL(m_pWindow, nullptr);
	ImGui_ImplOpenGL2_Init();

	SDL_AddEventWatch(ImGuiEventFilter, nullptr);

	*pRenderFunc = ImGuiRenderFunc;
}

void CImGuiMan::ShutdownImgui()
{
	SDL_DelEventWatch(ImGuiEventFilter, nullptr);

	// Cleanup
	ImGui_ImplOpenGL2_Shutdown();
	ImGui_ImplSDL2_Shutdown();
	ImGui::DestroyContext();
}

void CImGuiMan::RenderImGui()
{
	if (!m_pWindow)
		return;

	// Start the Dear ImGui frame
	ImGui_ImplOpenGL2_NewFrame();
	ImGui_ImplSDL2_NewFrame();
	ImGui::NewFrame();

	ImGui::ShowDemoWindow();

	ImGui::Render();
	ImGui_ImplOpenGL2_RenderDrawData(ImGui::GetDrawData());
}

SDL_Window* CImGuiMan::GetSdlWindow()
{
	SDL_Window* pWindow = nullptr;
	int i = 0;

	while ((pWindow = SDL_GetWindowFromID(i)) == nullptr)
	{
		i++;
	}
	return pWindow;
}
