#ifndef CACATUIDAE_TEXTURE_H
#define CACATUIDAE_TEXTURE_H

#include <GLES2/gl2.h>
#include <stdio.h>

namespace cac 
{

  enum class ETextureTarget : GLint
  {
    TEXTURE_2D = GL_TEXTURE_2D,
  };

  enum class EMagFilter : GLint 
  {
    NEAREST = GL_NEAREST,  //nearest manhatten distance
    LINEAR	= GL_LINEAR   //weighted average
  };
  
  enum class EMinFilter : GLint 
  {
    NEAREST = GL_NEAREST,	//nearest manhatten distance
    LINEAR = GL_LINEAR,	//weighted average
    NEAREST_MIPMAP_NEAREST = GL_NEAREST_MIPMAP_NEAREST,
    LINEAR_MIPMAP_NEAREST = GL_LINEAR_MIPMAP_NEAREST
  };
  
  enum class ETextureWrap : GLint
  {
    REPEAT = GL_REPEAT,
    CLAMP_TO_EDGE = GL_CLAMP_TO_EDGE,
    MIRRORED_REPEAT = GL_MIRRORED_REPEAT
  };
  
  enum class EInternalFormat : GLint 
  {
    RGB = GL_RGB,
    RGBA = GL_RGBA, 
    DEPTH = GL_DEPTH_COMPONENT
  };
  
  enum class EDataType : GLenum 
  {
    UNSIGNED_BYTE = GL_UNSIGNED_BYTE,
    BYTE = GL_BYTE,
    UNSIGNED_SHORT = GL_UNSIGNED_SHORT,
    SHORT = GL_SHORT,
    UNSIGNED_INT = GL_UNSIGNED_INT,
    INT = GL_INT,
    FLOAT = GL_FLOAT
  };


    class Texture 
    {
    public:
        ~Texture();

        void create();
        void bind(ETextureTarget target);
        void setMinMagFilter(EMinFilter min, EMagFilter mag);
        void setWrapST(ETextureWrap S, ETextureWrap T);
        void setData(GLint lodLevel, GLsizei width, GLsizei height, EInternalFormat interalFormat, EDataType dataType, void* data);


        GLuint id = 0;
        GLuint boundTo = 0;

    private:
        bool boundCheck(const char* message);
    };
}

    cac::Texture::~Texture()
    {
        if(id)
        {
            glDeleteTextures(1, &id);
        }

        if(boundTo)
        {
            glBindTexture(boundTo, 0);
        }
    }

    void cac::Texture::bind(cac::ETextureTarget target)
    {
        auto glTarget = static_cast<GLint>(target);
        glBindTexture(glTarget, id);
        boundTo = glTarget;
    }

    bool cac::Texture::boundCheck(const char* message)
    {
        if(!boundTo)
        {
            printf("Error: Trying to %s of unbound Texture\n", message);
            return false;
        }
        return true;
    }

    void cac::Texture::create()
    {
        glGenTextures(1, &id);
    }

    void cac::Texture::setMinMagFilter(cac::EMinFilter minFilter, cac::EMagFilter magFilter)
    {
        if(boundCheck("set MinMagFilter"))
        {
            glTexParameteri(boundTo, GL_TEXTURE_MIN_FILTER, static_cast<GLint>(minFilter));
            glTexParameteri(boundTo, GL_TEXTURE_MAG_FILTER, static_cast<GLint>(magFilter));
        }
    }

    void cac::Texture::setWrapST(cac::ETextureWrap S, cac::ETextureWrap T)
    {
        if(boundCheck("set WrapST"))
        {
            glTexParameteri(boundTo, GL_TEXTURE_WRAP_S, static_cast<GLint>(S));
            glTexParameteri(boundTo, GL_TEXTURE_WRAP_T, static_cast<GLint>(T));
        }
    }

    void cac::Texture::setData(GLint lodLevel, GLsizei width, GLsizei height, EInternalFormat interalFormat, EDataType dataType, void* data)
    {
        if(boundCheck("set Data"))
        {
            glTexImage2D(boundTo, lodLevel, static_cast<GLint>(interalFormat), width, height, 0, static_cast<GLint>(interalFormat), static_cast<GLenum>(dataType), data);
        }
    }


#endif