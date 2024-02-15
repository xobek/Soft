workspace "Soft"
	architecture "x64"

	configurations 
	{
		"Debug",
		"Release",
		"Dist"
	}

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

IncludeDir = {}
IncludeDir["GLFW"] = "Soft/vendor/GLFW/include"

include "Soft/vendor/GLFW"

project "Soft"
	location "Soft"
	kind "SharedLib"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

	pchheader "stpch.h"
	pchsource "Soft/src/stpch.cpp"

	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"%{prj.name}/src",
		"%{prj.name}/vendor/spdlog/include",
		"%{IncludeDir.GLFW}"
	}

	links 
	{
		"GLFW",
		"opengl32.lib"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ST_PLATFORM_WINDOWS",
			"ST_BUILD_DLL"
		}

		postbuildcommands
		{
			("{COPY} %{cfg.buildtarget.relpath} ../bin/" .. outputdir .. "/Sandbox")
		}
		
	filter "configurations:Debug"
		defines "ST_DEBUG"
		symbols "On"

	filter "configurations:´Release"
		defines "ST_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ST_DIST"
		optimize "On"

project "Sandbox"
	location "Sandbox"
	kind "ConsoleApp"
	language "C++"

	targetdir ("bin/" .. outputdir .. "/%{prj.name}")
	objdir ("bin-temp/" .. outputdir .. "/%{prj.name}")

	
	files 
	{
		"%{prj.name}/src/**.h",
		"%{prj.name}/src/**.cpp"
	}

	includedirs 
	{
		"Soft/vendor/spdlog/include",
		"Soft/src"
	}

	links 
	{
		"Soft"
	}

	filter "system:windows"
		cppdialect "C++17"
		staticruntime "On"
		systemversion "latest"

		defines 
		{
			"ST_PLATFORM_WINDOWS",
		}
		
	filter "configurations:Debug"
		defines "ST_DEBUG"
		symbols "On"

	filter "configurations:´Release"
		defines "ST_RELEASE"
		optimize "On"

	filter "configurations:Dist"
		defines "ST_DIST"
		optimize "On"