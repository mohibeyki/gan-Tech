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
