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

#include "gtpch.h"
#include "WindowsWindow.h"

namespace GanTech {

	static bool sGLFWInitialized = false;

	Window* Window::create(const WindowProps& props) {
		return new WindowsWindow(props);
	}

	WindowsWindow::WindowsWindow(const WindowProps& props) {
		init(props);
	}

	WindowsWindow::~WindowsWindow() {
		shutdown();
	}

	void WindowsWindow::init(const WindowProps& props) {
		mData.title = props.title;
		mData.width = props.width;
		mData.height = props.height;

		GT_CORE_INFO("Creating window {0} ({1}, {2})", props.title, props.width, props.height);

		if (!sGLFWInitialized) {
			// TODO: glfwTerminate on system shutdown
			int success = glfwInit();
			GT_CORE_ASSERT(success, "Could not intialize GLFW!");

			sGLFWInitialized = true;
		}

		mWindow = glfwCreateWindow((int)props.width, (int)props.height, mData.title.c_str(), nullptr, nullptr);
		glfwMakeContextCurrent(mWindow);
		glfwSetWindowUserPointer(mWindow, &mData);
		setVSync(true);
	}

	void WindowsWindow::shutdown() {
		glfwDestroyWindow(mWindow);
	}

	void WindowsWindow::onUpdate() {
		glfwPollEvents();
		glfwSwapBuffers(mWindow);
	}

	void WindowsWindow::setVSync(bool enabled) {
		if (enabled)
			glfwSwapInterval(1);
		else
			glfwSwapInterval(0);

		mData.vSync = enabled;
	}

	bool WindowsWindow::isVSync() const {
		return mData.vSync;
	}

}
