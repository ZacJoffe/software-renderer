workspace "Build"
    configurations { "Debug", "Release" }

project "renderer"
    kind "ConsoleApp"
    language "C++"
    location "build"
    targetdir "."
    files { "./src/*.cpp" }
    links { "SDL2" }

    filter "configurations:Debug"
        defines { "DEBUG" }
        symbols "On"

    filter "configurations:Release"
        defines { "NDEBUG" }
        optimize "On"

