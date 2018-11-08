#ifndef CACATUIDAE_SHADER_PROGRAM_H
#define CACATUIDAE_SHADER_PROGRAM_H

#include <GLES2/gl2.h>
#include <stdio.h>

namespace cac 
{
    enum EShaderType {VERTEX_SHADER, FRAGMENT_SHADER};

    class ShaderProgram
    {
        public:
            GLuint id;    

            bool create(const char* vertexSource, const char* fragmentSource);
            void use();
        private:
            template <EShaderType e> GLuint compileShader(const char* source);     
            bool checkProgramInfoLength();    
            bool checkShaderInfoLength(GLuint id);    
    };
}

void cac::ShaderProgram::use()
{
    glUseProgram(id);
}

template<> GLuint cac::ShaderProgram::compileShader<cac::VERTEX_SHADER>(const char* source)
{
    GLuint shaderID = glCreateShader(GL_VERTEX_SHADER);
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);
    
    
    if(!checkShaderInfoLength(shaderID))
        return 0;

    return shaderID;
}

template<> GLuint cac::ShaderProgram::compileShader<cac::FRAGMENT_SHADER>(const char* source)
{
    GLuint shaderID = glCreateShader(GL_FRAGMENT_SHADER);
    glShaderSource(shaderID, 1, &source, nullptr);
    glCompileShader(shaderID);
    
    if(!checkShaderInfoLength(shaderID))
        return 0;

    return shaderID;
}


bool cac::ShaderProgram::create(const char* vertexSource, const char* fragmentSource)
{

    auto vertID = compileShader<VERTEX_SHADER>(vertexSource);
    auto fragID = compileShader<FRAGMENT_SHADER>(fragmentSource);

    if(!vertID)
    {
        if(fragID)
            glDeleteShader(fragID);

        printf("Failed to compile vert shader\n");
        return false;
    }
    if(!fragID)
    {
        if(vertID)
            glDeleteShader(vertID);

        printf("Failed to compile frag shader\n");
        return false;
    }

    id = glCreateProgram();
    glAttachShader(id, vertID);
    glAttachShader(id, fragID);

    glLinkProgram(id);

    glDeleteShader(vertID);
    glDeleteShader(fragID);

    glValidateProgram(id);

    return checkProgramInfoLength();
}

bool cac::ShaderProgram::checkProgramInfoLength()
{
     int result;
     int infolength;
  
     glGetProgramiv(id, GL_LINK_STATUS, &result);
     glGetProgramiv(id, GL_INFO_LOG_LENGTH, &infolength);
  
    //greater 1 because of null termination
    if (infolength > 1){
        char* errorMessage = new char[infolength + 1];
        glGetShaderInfoLog(id, infolength, nullptr, &errorMessage[0]);
        glDeleteShader(id);

        printf("Error %s\n", errorMessage);
        return false;
    }

    return true;
} 

bool cac::ShaderProgram::checkShaderInfoLength(GLuint shaderID)
{
     int result;
     int infolength;
  
     glGetShaderiv(shaderID, GL_COMPILE_STATUS, &result);
     glGetShaderiv(shaderID, GL_INFO_LOG_LENGTH, &infolength);
  
    //greater 1 because of null termination
    if (infolength > 1){
        char* errorMessage = new char[infolength + 1];
        glGetShaderInfoLog(shaderID, infolength, nullptr, &errorMessage[0]);
        glDeleteShader(shaderID);

        printf("Error %s\n", errorMessage);
        return false;
    }

    return true;
}    


#endif