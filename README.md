# OpenGL

### Currently this project renders a cube inside an OpenGL window, and the cube can be controlled by mouse movements and WASD keys. There is a model placeholder for .obj files so that external 3D models can be loaded, but currently the loader itself does not work. 

## Visual Studio Setup
Right Click on the project, and open properties. Then:
1. Configuration Properties -> VC++ Directories -> Include Directories: Add $(ProjectDir)Linking\include
2. Configuration Properties -> VC++ Directories -> Library Directories: Add $(ProjectDir)Linking\libs
3. Configuration Properties -> C/C++ -> General -> Additional Include Directories: Add $(ProjectDir)Linking\include
4. Configuration Properties -> Linker -> General -> Additional Library Directories: Add $(ProjectDir)Linking\libs
5. Configuration Properties -> Linker -> General -> Additional Dependencies: Add opengl32.lib; glfw3.lib