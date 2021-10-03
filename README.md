# Game of Life
Simple GUI implementation of [John Conway](https://en.wikipedia.org/wiki/John_Horton_Conway)'s [Game of Life](https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life) using [raylib](https://github.com/raysan5/raylib).

# Support
Currently only supports Windows. Unix-like system support will be implemented in the future.

# Usage
## Requirements
### 1. [premake5]("https://github.com/premake/premake-core")
This implementation uses [premake5]("https://github.com/premake/premake-core") to generate project files for multiple platforms.
### 2. C++ compiler

---

## Instructions
### 1. Generate project files.
```ps
PS > premake5.exe gmake2
```

### 2. Compile dependencies
```ps
PS > cd .\vendor\raylib\src
PS > mingw32-make.exe RAYLIB_BUILD_MODE=*configuration*
PS > cd ..\..\..
```

### 3. Compile the project normally (platform dependent).
```ps
PS > mingw32-make.exe
```