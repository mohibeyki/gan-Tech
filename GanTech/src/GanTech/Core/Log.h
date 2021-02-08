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
#include "spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace GanTech {
	class GT_API Log {
	public:
		static void init();
		inline static std::shared_ptr<spdlog::logger>& getCoreLogger() { return coreLogger; }
		inline static std::shared_ptr<spdlog::logger>& getClientLogger() { return clientLogger; }
	private:
		static std::shared_ptr<spdlog::logger> coreLogger;
		static std::shared_ptr<spdlog::logger> clientLogger;
	};
}

// Core Macros
#define GT_CORE_TRACE(...)     ::GanTech::Log::getCoreLogger()->trace(__VA_ARGS__)
#define GT_CORE_INFO(...)      ::GanTech::Log::getCoreLogger()->info(__VA_ARGS__)
#define GT_CORE_WARN(...)      ::GanTech::Log::getCoreLogger()->warn(__VA_ARGS__)
#define GT_CORE_ERROR(...)     ::GanTech::Log::getCoreLogger()->error(__VA_ARGS__)
#define GT_CORE_CRITICAL(...)  ::GanTech::Log::getCoreLogger()->critical(__VA_ARGS__)

// Client Macros
#define GT_TRACE(...)          ::GanTech::Log::getClientLogger()->trace(__VA_ARGS__)
#define GT_INFO(...)           ::GanTech::Log::getClientLogger()->info(__VA_ARGS__)
#define GT_WARN(...)           ::GanTech::Log::getClientLogger()->warn(__VA_ARGS__)
#define GT_ERROR(...)          ::GanTech::Log::getClientLogger()->error(__VA_ARGS__)
#define GT_CRITICAL(...)       ::GanTech::Log::getClientLogger()->critical(__VA_ARGS__)
