# OpenGL

## Visual Studio Setup
Right Click on the project, and open properties. Then:
1. Configuration Properties -> VC++ Directories -> Include Directories: Add $(ProjectDir)Linking\include
2. Configuration Properties -> VC++ Directories -> Library Directories: Add $(ProjectDir)Linking\libs
3. Configuration Properties -> C/C++ -> General -> Additional Include Directories: Add $(ProjectDir)Linking\include
4. Configuration Properties -> Linker -> General -> Additional Library Directories: Add $(ProjectDir)Linking\libs
5. Configuration Properties -> Linker -> General -> Additional Dependencies: Add opengl32.lib; glfw3.lib

## Running on Linux

This project was originally configured for Visual Studio on Windows, but the source code can also be built on Linux with `g++`. The Linux build uses the vendored GLAD source file in `Linking/glad.c`, the vendored headers in `Linking/include`, and system packages for GLFW and OpenGL.

### 1. Install required packages

On Ubuntu, Debian, Linux Mint, or WSL with GUI support, install the compiler and OpenGL/GLFW development packages:

```bash
sudo apt update
sudo apt install build-essential g++ libglfw3-dev libgl1-mesa-dev libx11-dev libxrandr-dev libxi-dev libxxf86vm-dev libxcursor-dev libxinerama-dev
```

On Fedora:

```bash
sudo dnf install gcc-c++ glfw-devel mesa-libGL-devel libX11-devel libXrandr-devel libXi-devel libXxf86vm-devel libXcursor-devel libXinerama-devel
```

On Arch Linux or Manjaro:

```bash
sudo pacman -S base-devel glfw-x11 mesa libx11 libxrandr libxi libxxf86vm libxcursor libxinerama
```

If your distribution uses Wayland by default, the X11 packages are still useful because many GLFW builds link against X11 compatibility libraries.

### 2. Clone the repository

```bash
git clone <repository-url>
cd OpenGL-Game-Development
```

If you already downloaded the project, simply open a terminal in the project root. The project root is the folder that contains `OpenGL.cpp`, `README.md`, `vertex_core.glsl`, and `fragment_core.glsl`.

### 3. Confirm the required project files exist

Run:

```bash
ls OpenGL.cpp Linking/glad.c Linking/include/glad/glad.h vertex_core.glsl fragment_core.glsl assets/models/Plane.obj
```

All of these files should be present. The program loads shaders and the OBJ model using relative paths, so you must run the executable from the project root unless you modify those paths in the source code.

### 4. Create a build directory

```bash
mkdir -p build
```

This keeps the generated Linux executable separate from the Visual Studio project files.

### 5. Build the project

Run this command from the project root:

```bash
g++ -std=c++17 OpenGL.cpp Linking/glad.c \
  -I./Linking/include \
  -o build/OpenGL \
  -lglfw -lGL -ldl -pthread
```

What this command does:

- `OpenGL.cpp` builds the main application.
- `Linking/glad.c` builds the GLAD OpenGL loader included with the project.
- `-I./Linking/include` tells the compiler where to find `glad`, `glm`, and the project's vendored GLFW headers.
- `-lglfw` links against the GLFW library installed through your package manager.
- `-lGL` links against the Linux OpenGL library.
- `-ldl` and `-pthread` provide common Linux runtime dependencies needed by GLFW/OpenGL programs.

If your Linux distribution requires additional X11 libraries, use this longer command:

```bash
g++ -std=c++17 OpenGL.cpp Linking/glad.c \
  -I./Linking/include \
  -o build/OpenGL \
  -lglfw -lGL -ldl -pthread \
  -lX11 -lXrandr -lXi -lXxf86vm -lXcursor -lXinerama
```

### 6. Run the application

From the project root, run:

```bash
./build/OpenGL
```

The application should open a window titled `OpenGL Window` and display the plane model from `assets/models/Plane.obj`.

### 7. Controls

- Move the mouse to orbit the camera around the scene.
- Use the scroll wheel to zoom in or out.
- Press `W`, `A`, `S`, and `D` to move the object along the X and Z axes.
- Press `Q` and `E` to rotate the object around the Y axis.
- Press `R` and `F` to zoom in and out from the keyboard.
- Press `Escape` to close the application.

### 8. Common Linux issues

#### `fatal error: glad/glad.h: No such file or directory`

Make sure you are compiling from the project root and that the command includes:

```bash
-I./Linking/include
```

#### `/usr/bin/ld: cannot find -lglfw`

GLFW is not installed, or the development package is missing. Install it with your distribution's package manager:

```bash
sudo apt install libglfw3-dev
```

#### `ERROR::MAIN::MODEL_LOAD_FAILED`

Run the executable from the project root:

```bash
./build/OpenGL
```

Do not run it from inside the `build` directory, because the program expects to find the model at `assets/models/Plane.obj`.

#### Shader files fail to load or the screen is blank

Make sure `vertex_core.glsl` and `fragment_core.glsl` are in the same directory from which you launch the executable. The current source code loads them with these relative paths:

```cpp
Shader core_program("vertex_core.glsl", "fragment_core.glsl");
```

#### `Failed to open display` or no window appears

You need a graphical desktop session, X11/Wayland display, or WSLg if you are running on Windows Subsystem for Linux. On a headless server, this program will not open a visible window without extra display forwarding or a virtual display setup.

### 9. Optional cleanup

To remove the Linux build output:

```bash
rm -rf build
```

## Project Description

This OpenGL Game Development project is a 3D graphics application built using modern OpenGL 3.3 core profile. It demonstrates fundamental concepts in 3D rendering, including:

### Features
- **3D Model Loading**: Loads and renders 3D models from OBJ files (currently featuring a plane model)
- **Orbit Camera**: Interactive camera system allowing mouse-based orbiting around the scene
- **Phong Lighting**: Implements realistic lighting with ambient, diffuse, and specular components
- **Shader-Based Rendering**: Uses GLSL vertex and fragment shaders for GPU-accelerated graphics
- **Input Handling**: Supports keyboard controls for object movement and camera adjustments
- **Window Management**: Cross-platform window creation and management using GLFW

### Controls
- **Mouse**: Orbit camera around the scene
- **Scroll Wheel**: Zoom in/out
- **WASD Keys**: Move the object along X and Z axes
- **Q/E Keys**: Rotate the object around Y-axis
- **R/F Keys**: Zoom in/out (alternative to scroll)
- **Escape**: Close the application

### Technical Details
- **OpenGL Version**: 3.3 Core Profile
- **Libraries Used**:
  - GLFW: Window and input management
  - GLAD: OpenGL function loading
  - GLM: Mathematics library for vectors and matrices
  - SOIL2: Image loading (for future texture support)
- **Shaders**: Vertex shader for transformation and normal calculation, fragment shader for Phong lighting
- **Rendering Pipeline**: Model-View-Projection matrix transformations with depth testing

### Building and Running
1. Follow the Visual Studio setup instructions above
2. Ensure the `assets/models/Plane.obj` file is present in the project directory
3. Build the project in Visual Studio
4. Run the executable to launch the 3D viewer

The application creates a window displaying the 3D plane model with dynamic lighting and interactive camera controls, serving as a foundation for more complex 3D game development projects.
