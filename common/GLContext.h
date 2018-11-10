#ifndef CACATUIDAE_GL_CONTEXT_H
#define CACATUIDAE_GL_CONTEXT_H


#include <GLES2/gl2.h>
#include <emscripten.h>
#include <emscripten/html5.h>

void createWGLContext(int width, int height) 
{
    static EMSCRIPTEN_WEBGL_CONTEXT_HANDLE glContext;
    emscripten_set_canvas_element_size("canvas", width, height);

    EmscriptenWebGLContextAttributes attrs;
    emscripten_webgl_init_context_attributes(&attrs);
    attrs.alpha = 0;
    glContext = emscripten_webgl_create_context(0, &attrs);
    emscripten_webgl_make_context_current(glContext);
}


#endif