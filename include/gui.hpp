//Copyright(C) 2024 Lost Empire Entertainment

#pragma once

#include <vector>
#include <string>

//external
#include "imgui.h"

namespace Graphics::GUI
{
	using std::vector;
	using std::string;

	class BotGUI
	{
	public:
		static inline bool isImguiInitialized;
		static inline bool renderBotAdminActionWindow;

		static void Initialize();
		static void Run();

		static int GetScreenHeight();
		static int GetScreenWidth();
		static ImVec2 CenterWindow(ImVec2 windowSize);

		static void RenderParentWindow();

		static void RenderConsole(ImVec2 windowSize);
		static void RenderRightSideInteractions(ImVec2 windowSize);
		static void ListUsers(ImVec2 windowSize);

		enum class BotAction
		{
			dm,
			message,
			mute,
			kick,
			ban
		};
		static inline string actionTargetUserID;
		static inline BotAction botAction;
		static void BotAdminActionWindow();

		enum class MessageTarget
		{
			both,
			cmdOnly,
			consoleOnly,
			serverLogOnly
		};
		static void Print(
			const string& message, 
			MessageTarget messageTarget = MessageTarget::both,
			bool logInServer = false,
			string logChannelID = "");

		static void Shutdown();
	private:
		static inline bool firstScrollToBottom;
		static inline vector<string> output;
		static inline vector<string> storedLogs;
	};
}