# OpenGL

## Visual Studio Setup
Right Click on the project, and open properties. Then:
1. Configuration Properties -> VC++ Directories -> Include Directories: Add $(ProjectDir)Linking\include
2. Configuration Properties -> VC++ Directories -> Library Directories: Add $(ProjectDir)Linking\libs
3. Configuration Properties -> C/C++ -> General -> Additional Include Directories: Add $(ProjectDir)Linking\include
4. Configuration Properties -> Linker -> General -> Additional Library Directories: Add $(ProjectDir)Linking\libs
5. Configuration Properties -> Linker -> General -> Additional Dependencies: Add opengl32.lib; glfw3.lib

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