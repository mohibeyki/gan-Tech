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
	#ifdef GT_BUILD_DLL
		#define GT_API __declspec(dllexport)
	#else
		#define GT_API __declspec(dllimport)
	#endif // GT_BUILD_DLL
#else
	#error GT only supports windows!
#endif // GT_PLATFORM_WINDOWS

#ifdef GT_ENABLE_ASSERTS
	#define GT_ASSERT(x, ...) { if(!(x)) { GT_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
	#define GT_CORE_ASSERT(x, ...) { if(!(x)) { GT_CORE_ERROR("Assertion Failed: {0}", __VA_ARGS__); __debugbreak(); } }
#else
	#define GT_ASSERT(x, ...)
	#define GT_CORE_ASSERT(x, ...)
#endif

#define BIT(x) (1 << (x))
