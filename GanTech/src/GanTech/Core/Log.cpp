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

#include "GanTech/Core/Log.h"
#include "spdlog/sinks/stdout_color_sinks.h"

namespace GanTech {

	std::shared_ptr<spdlog::logger> Log::coreLogger;
	std::shared_ptr<spdlog::logger> Log::clientLogger;

	void Log::init() {
		spdlog::set_pattern("%^[%T][%n]: %v%$");

		coreLogger = spdlog::stdout_color_mt("ganTech");
		coreLogger->set_level(spdlog::level::trace);

		clientLogger = spdlog::stdout_color_mt("APP");
		clientLogger->set_level(spdlog::level::trace);
	}

}
