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

#include "gtpch.h"

#include "GanTech/Core/Core.h"
#include "GanTech/Events/Event.h"

namespace GanTech {

	struct WindowProps
	{
		std::string title;
		uint32_t width;
		uint32_t height;

		WindowProps(const std::string& title = "ganTech Engine",
			uint32_t width = 1600,
			uint32_t height = 900)
			: title(title), width(width), height(height) {
		}
	};

	// Interface representing a desktop system based Window
	class GT_API Window
	{
	public:
		using EventCallbackFn = std::function<void(Event&)>;

		virtual ~Window() = default;

		virtual void onUpdate() = 0;

		virtual uint32_t getWidth() const = 0;
		virtual uint32_t getHeight() const = 0;

		// Window attributes
		virtual void setEventCallback(const EventCallbackFn& callback) = 0;
		virtual void setVSync(bool enabled) = 0;
		virtual bool isVSync() const = 0;

		static Window* create(const WindowProps& props = WindowProps());
	};

}
