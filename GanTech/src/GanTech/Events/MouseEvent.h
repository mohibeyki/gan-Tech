//  ganTech game engine
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

#include "GanTech/Events/Event.h"

namespace GanTech {

	class GT_API MouseMovedEvent : public Event
	{
	public:
		MouseMovedEvent(float x, float y)
			: mMouseX(x), mMouseY(y) {}

		inline float getX() const { return mMouseX; }
		inline float getY() const { return mMouseY; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseMovedEvent: " << mMouseX << ", " << mMouseY;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseMoved)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mMouseX, mMouseY;
	};

	class GT_API MouseScrolledEvent : public Event
	{
	public:
		MouseScrolledEvent(float xOffset, float yOffset)
			: mXOffset(xOffset), mYOffset(yOffset) {}

		inline float getXOffset() const { return mXOffset; }
		inline float getYOffset() const { return mYOffset; }

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseScrolledEvent: " << getXOffset() << ", " << getYOffset();
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseScrolled)
			EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	private:
		float mXOffset, mYOffset;
	};

	class GT_API MouseButtonEvent : public Event
	{
	public:
		inline int getMouseButton() const { return mButton; }

		EVENT_CLASS_CATEGORY(EventCategoryMouse | EventCategoryInput)
	protected:
		MouseButtonEvent(int button)
			: mButton(button) {}

		int mButton;
	};

	class GT_API MouseButtonPressedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonPressedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonPressedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonPressed)
	};

	class GT_API MouseButtonReleasedEvent : public MouseButtonEvent
	{
	public:
		MouseButtonReleasedEvent(int button)
			: MouseButtonEvent(button) {}

		std::string toString() const override {
			std::stringstream ss;
			ss << "MouseButtonReleasedEvent: " << mButton;
			return ss.str();
		}

		EVENT_CLASS_TYPE(MouseButtonReleased)
	};

}
