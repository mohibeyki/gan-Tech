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

	class GT_API KeyEvent : public Event
	{
	public:
		inline int getKeyCode() const { return mKeyCode; }

		EVENT_CLASS_CATEGORY(EventCategoryKeyboard | EventCategoryInput)
	protected:
		KeyEvent(int keycode)
			: mKeyCode(keycode) {}

		int mKeyCode;
	};

	class GT_API KeyPressedEvent : public KeyEvent
	{
	public:
		KeyPressedEvent(int keycode, int repeatCount)
			: KeyEvent(keycode), mRepeatCount(repeatCount) {}

		inline int getRepeatCount() const { return mRepeatCount; }

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyPressedEvent: " << mKeyCode << " (" << mRepeatCount << " repeats)";
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyPressed)
	private:
		int mRepeatCount;
	};

	class GT_API KeyReleasedEvent : public KeyEvent
	{
	public:
		KeyReleasedEvent(int keycode)
			: KeyEvent(keycode) {}

		std::string toString() const override
		{
			std::stringstream ss;
			ss << "KeyReleasedEvent: " << mKeyCode;
			return ss.str();
		}

		EVENT_CLASS_TYPE(KeyReleased)
	};
}
