#ifndef GRAPHICS_ENUMS_H
#define GRAPHICS_ENUMS_H

#if EMSCRIPTEN
    #include <GLES2/gl2.h>
#endif

namespace cac 
{
    enum class EClearBuffers : GLbitfield
    {
        DEPTH = GL_DEPTH_BUFFER_BIT,
        COLOR = GL_COLOR_BUFFER_BIT,
        STENCIL = GL_STENCIL_BUFFER_BIT,
        DEPTH_COLOR = GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT
    };

}


#endif 