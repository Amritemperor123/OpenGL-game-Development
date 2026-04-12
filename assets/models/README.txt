Put imported 3D assets here.

Expected placeholder paths in the current code:
- assets/models/placeholder.obj
- assets/models/placeholder.fbx

Right now the project renders a fallback cube and reports these paths in the console.
The next step is to add an OBJ or FBX loader that reads one of those files and fills the vertex/index buffers from the imported mesh.
