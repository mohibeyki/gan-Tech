//  ganTech Engine
//  Copyright(C) 2021 Mohi Beyki <mohibeyki@gmail.com>
//
//  This program is free software : you can redistribute it and /or modify
//  it under the terms of the GNU General Public License as published by
//  the Free Software Foundation, either version 3 of the License, or
//  (at your option) any later version.
//
//  This program is distributed in the hope that it will be useful,
//  but WITHOUT ANY WARRANTY; without even the implied warranty of
//  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.See the
//  GNU General Public License for more details.
//
//  You should have received a copy of the GNU General Public License
//  along with this program.If not, see < https://www.gnu.org/licenses/>.

#pragma once

#include "GanTech/Core/Window.h"

#include <GLFW/glfw3.h>

namespace GanTech {

	class WindowsWindow : public Window {
	public:
		WindowsWindow(const WindowProps& props);
		virtual ~WindowsWindow();

		void onUpdate() override;

		inline unsigned int getWidth() const override { return mData.width; }
		inline unsigned int getHeight() const override { return mData.height; }

		// Window attributes
		inline void setEventCallback(const EventCallbackFn& callback) override { mData.eventCallback = callback; }
		void setVSync(bool enabled) override;
		bool isVSync() const override;
	private:
		virtual void init(const WindowProps& props);
		virtual void shutdown();
	private:
		GLFWwindow* mWindow;

		struct WindowData {
			std::string title;
			unsigned int width, height;
			bool vSync;

			EventCallbackFn eventCallback;
		};

		WindowData mData;
	};

}
