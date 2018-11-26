#ifndef CACATUIDAE_SHADER_H
#define CACATUIDAE_SHADER_H

#if EMSCRIPTEN 
#include <GLES2/gl2.h>
#endif

#include <stdio.h>

namespace cac 
{
    enum class EShaderType 
    {
        VERTEX_SHADER = GL_VERTEX_SHADER,
        FRAGMENT_SHADER = GL_FRAGMENT_SHADER
    };

    struct Shader 
    {
        bool compiled = false;
        EShaderType type;
        const char* source;
        GLuint id;

        Shader(EShaderType type, const char* source) : type(type), source(source)
        {
            glCreateShader(static_cast<GLint>(type));
        }

        ~Shader() 
        {
            if(id>0)
                glDeleteShader(id);
        }

        bool compile()
        {
            glShaderSource(id, 1, &source, nullptr);
            glCompileShader(id);
        
            if(!checkError())
                return false;

            compiled = true;
            return true;
        }

    private:
        bool checkError()
        {
            int result;
            int infolength;
    
            glGetShaderiv(id, GL_COMPILE_STATUS, &result);
            glGetShaderiv(id, GL_INFO_LOG_LENGTH, &infolength);
    
            //greater 1 because of null termination
            if (infolength > 1){
                char* errorMessage = new char[infolength + 1];
                glGetShaderInfoLog(id, infolength, nullptr, &errorMessage[0]);

                printf("Error %s\n", errorMessage);
                return false;
            }

            return true;
        }
    };
}
#endif