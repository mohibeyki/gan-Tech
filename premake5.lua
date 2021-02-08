workspace "GanTech"
	architecture "x64"

	configurations {
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

includeDir = {}
includeDir["GLFW"] = "GanTech/vendor/GLFW/include"
includeDir["VULKAN"] = "C:/VulkanSDK/1.2.162.1/Include"

GLFWDir = "GanTech/vendor/GLFW"

project "GLFW"
	kind "StaticLib"
	language "C"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{GLFWDir}/include/GLFW/glfw3.h",
		"%{GLFWDir}/include/GLFW/glfw3native.h",
		"%{GLFWDir}/src/glfw_config.h",
		"%{GLFWDir}/src/context.c",
		"%{GLFWDir}/src/init.c",
		"%{GLFWDir}/src/input.c",
		"%{GLFWDir}/src/monitor.c",
		"%{GLFWDir}/src/vulkan.c",
		"%{GLFWDir}/src/window.c"
	}
	filter "system:linux"
		pic "On"

		systemversion "latest"
		staticruntime "On"

		files {
			"%{GLFWDir}/src/x11_init.c",
			"%{GLFWDir}/src/x11_monitor.c",
			"%{GLFWDir}/src/x11_window.c",
			"%{GLFWDir}/src/xkb_unicode.c",
			"%{GLFWDir}/src/posix_time.c",
			"%{GLFWDir}/src/posix_thread.c",
			"%{GLFWDir}/src/glx_context.c",
			"%{GLFWDir}/src/egl_context.c",
			"%{GLFWDir}/src/osmesa_context.c",
			"%{GLFWDir}/src/linux_joystick.c"
		}

		defines {
			"_GLFW_X11"
		}

	filter "system:windows"
		systemversion "latest"
		staticruntime "On"

		files {
			"%{GLFWDir}/src/win32_init.c",
			"%{GLFWDir}/src/win32_joystick.c",
			"%{GLFWDir}/src/win32_monitor.c",
			"%{GLFWDir}/src/win32_time.c",
			"%{GLFWDir}/src/win32_thread.c",
			"%{GLFWDir}/src/win32_window.c",
			"%{GLFWDir}/src/wgl_context.c",
			"%{GLFWDir}/src/egl_context.c",
			"%{GLFWDir}/src/osmesa_context.c"
		}

		defines { 
			"_GLFW_WIN32",
			"_CRT_SECURE_NO_WARNINGS"
		}

	filter "configurations:Debug"
		runtime "Debug"
		symbols "on"

	filter "configurations:Release"
		runtime "Release"
		optimize "on"

project "GanTech"
	location "GanTech"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

	pchheader "gtpch.h"
	pchsource "GanTech/src/gtpch.cpp"

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{includeDir.VULKAN}",
		"%{includeDir.GLFW}"
	}

	links {
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"GT_PLATFORM_WINDOWS",
			"GT_BUILD_DLL"
		}

		postbuildcommands {
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}

	filter "configurations:Debug"
		defines "GT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GT_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir    ("bin-int/" .. outputdir .. "/%{prj.name}")

	files {
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs {
		"%{includeDir.VULKAN}",
		"GanTech/vendor/spdlog/include",
		"GanTech/src"
	}

	links {
		"GanTech"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"
		
		defines {
			"GT_PLATFORM_WINDOWS"
		}

	filter "configurations:Debug"
		defines "GT_DEBUG"
		symbols "On"

	filter "configurations:Release"
		defines "GT_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "GT_DIST"
		optimize "On"
