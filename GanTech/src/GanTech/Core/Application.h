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

#include "GanTech/Core/Core.h"
#include "GanTech/Events/Event.h"
#include "GanTech/Core/Window.h"

namespace GanTech {
	class GT_API Application {
	public:
		Application();
		virtual ~Application();

		void run();
	private:
		std::unique_ptr<Window> mWindow;
		bool running = true;
	};

	/// Client should return this!
	Application* createApplication();
}
