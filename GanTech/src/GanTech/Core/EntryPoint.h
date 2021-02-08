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

#ifdef GT_PLATFORM_WINDOWS

extern GanTech::Application* GanTech::createApplication();

int main(int argc, char** argv) {
	GanTech::Log::init();
	GT_CORE_TRACE("Powered by ganTech");

	auto *app = GanTech::createApplication();
	app->run();
	delete app;
}

#endif
