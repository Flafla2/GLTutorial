# OpenGL Tutorial Environment

This codebase was developed for 15-462 Computer Graphics at CMU to
demonstrate basic OpenGL API functionality.  You can use the included
Sublime Text project, which has a build system already set up.

## Building

Starting in the root directory:

    $ mkdir build
    $ cd build
    $ cmake ..
    $ make

I haven't checked support on Windows / Linux (only macOS), but it
should build correctly because GLFW, GLM, and OpenGL are cross platform.

## Modifying the code

`GraphicsManager.cpp` handles most of the boilerplate GLFW / GL code as
well as the main render loop.  The `Mesh.cpp` can load basic .obj files
directly (make sure to only export triangles and disable materials and UV
data).

You can throw your rendering code in the `render()` function inside of
`main.cpp`.

## References

I used this starter code to teach a recitation on OpenGL.  You can find
some examples inside of the `checkpoints/` folder.
