workspace "Legba"
    architecture "x64"

    configurations
    {
        "Debug",
        "Release",
        "Dist"
    }

outputdir = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

project "Legba"
    location "Legba"
    kind "SharedLib"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "%{prj.name}/src",
        "%{prj.name}/vendor/spdlog/include"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LEGBA_PLATFORM_WINDOWS",
            "LEGBA_BUILD_DLL"
        }

        postbuildcommands
        {
            ("{COPY} %{cfg.buildtarget.relpath} ../bin/" ..outputdir .. "/Sandbox")
        }

    filter "configurations:Debug"
        defines "LEGBA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LEGBA_RELEASE"
        optimize "On"

    
    filter "configurations:Dist"
        defines "LEGBA_DIST"
        optimize "On"



project "Sandbox"
    location "Sandbox"
    kind "ConsoleApp"
    language "C++"

    targetdir ("bin/" .. outputdir .. "/%{prj.name}")
    objdir ("bin-int/" .. outputdir .. "/%{prj.name}")


    files 
    {
        "%{prj.name}/src/**.h",
        "%{prj.name}/src/**.cpp",
    }

    includedirs
    {
        "Legba/vendor/spdlog/include",
        "Legba/src"
    }

    links
    {
        "Legba"
    }

    filter "system:windows"
        cppdialect "C++17"
        staticruntime "On"
        systemversion "latest"

        defines
        {
            "LEGBA_PLATFORM_WINDOWS"
        }

    filter "configurations:Debug"
        defines "LEGBA_DEBUG"
        symbols "On"

    filter "configurations:Release"
        defines "LEGBA_RELEASE"
        optimize "On"

    
    filter "configurations:Dist"
        defines "LEGBA_DIST"
        optimize "On"

    