#ifndef CACATUIDAE_SHADER_PROGRAM_H
#define CACATUIDAE_SHADER_PROGRAM_H

#include <GLES2/gl2.h>
#include <glm/glm.hpp>

namespace cac 
{
    struct Shader;
    struct ShaderProgram
    {
        GLuint id;    

        ShaderProgram();
        ~ShaderProgram();
        bool create(Shader& vertexShader, Shader& fragmentShader);
        void use();

        void setAtrribLoc(GLuint loc, const char* name);
        GLint getUniformLoc(const char* name);
        void setUniform(GLint loc, float value);
        void setUniform(GLint loc, vec4 value);
    };
}

#endif