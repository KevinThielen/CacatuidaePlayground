#include "ShaderProgram.h"
#include "Shader.h"
#include <stdio.h>


/**********************************
 * FREE FUNCTIONS 
 *******************************/

bool checkError(GLuint id)
{
    glValidateProgram(id);

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


/**********************************
 * MEMBERS 
 ********************************/

cac::ShaderProgram::ShaderProgram()
{
   id = glCreateProgram();
}

cac::ShaderProgram::~ShaderProgram()
{
   glDeleteProgram(id);
}

void cac::ShaderProgram::use()
{
    glUseProgram(id);
}

GLint cac::ShaderProgram::getUniformLoc(const char* name)
{
    GLint glLoc = glGetUniformLocation(id, name);
    return glLoc;
}

void cac::ShaderProgram::setUniform(GLint loc, float value)
{
    glUniform1f(loc, value);
}

void cac::ShaderProgram::setUniform(GLint loc, cac::vec4 value)
{
    glUniform4fv(loc, 1, &value[0]);
}


void cac::ShaderProgram::setAtrribLoc(GLuint loc, const char* name)
{
    glBindAttribLocation(id, loc, name);
}

bool cac::ShaderProgram::create(Shader& vertexShader, Shader& fragmentShader)
{
    if(!vertexShader.compiled|| !fragmentShader.compiled)
    {
        printf("Shader not compiled!\n");
        return false;
    }

    glAttachShader(id, vertexShader.id);
    glAttachShader(id, vertexShader.id);

    glLinkProgram(id);

    glDetachShader(id, vertexShader.id);
    glDetachShader(id, fragmentShader.id);    

    return checkError(id);
}

