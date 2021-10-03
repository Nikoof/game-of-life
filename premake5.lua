workspace "game-of-life"
    architecture "x64"
    configurations { "debug", "release" }

output = "%{cfg.buildcfg}-%{cfg.system}-%{cfg.architecture}"

vendor = {}
vendor["raylib"] = "%{wks.location}/vendor/raylib"

project "game-of-life"
    kind "ConsoleApp"
    language "C++"
    
    targetdir("%{wks.location}/bin/"..output.."/%{prj.name}")
    objdir("%{wks.location}/bin-obj/"..output.."/%{prj.name}")

    files {
        "src/**.h",
        "src/**.cpp"
    }
    
    -- Dependencies
    includedirs {
        vendor["raylib"].."/src"
    }

    libdirs {
        vendor["raylib"].."/src"
    }

    filter { "system:windows" }
        defines {
            "__WINDOWS__"
        }

        links {
            "raylib",
            "opengl32",
            "gdi32",
            "winmm"
        }

        prelinkcommands {
            "cd .\\vendor\\raylib\\src",
            "mingw32-make.exe RAYLIB_BUILD_MODE=%{string.upper(cfg.buildcfg)} PLATFORM=PLATFORM_DESKTOP",
            "cd ..\\..\\.."
        }

    