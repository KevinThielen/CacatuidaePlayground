#ifndef CACATUIDAE_BUFFER_OBJECT_H
#define CACATUIDAE_BUFFER_OBJECT_H

#include <GLES2/gl2.h>
#include <stdio.h>

namespace cac 
{
    enum class EBufferObjectTarget
    {
        NONE,
        ARRAY_BUFFER,
        TEXTURE_BUFFER,
        PIXEL_PACK_BUFFER,
        PIXEL_UNPACK_BUFFER,
        ELEMENT_ARRAY_BUFFER,
        UNIFORM_BUFFER
    };
    
    enum class EBufferObjectUsage
    {
        STATIC,
        DYNAMIC
    };
    
    enum class EBufferObjectDataType 
    {
        BYTE,
        UBYTE,
        SHORT,
        USHORT,
        FLOAT, 
        INT,
        UINT
    };

    class BufferObject 
    {
    public:
       ~BufferObject();
        void create();

        void enableAttribPointer(GLuint location);
        void disableAttribPointer(GLuint location);

        template<EBufferObjectTarget target> void bind();
        template<EBufferObjectUsage usage> void setData(unsigned int size, void* data);
        template<EBufferObjectDataType dataType> void setAttributePointer(GLuint location, GLuint numberOfElements, bool normalized, GLuint stride, const void* offset);
  
        GLuint id = 0;
        GLuint boundTo = 0;

    private:
        bool boundCheck(const char* message);
        bool enabledCheck(GLuint location);
    };
}

bool cac::BufferObject::boundCheck(const char* message)
{
    if(!boundTo)
    {
        printf("Error: Trying to %s of unbound BufferObject\n", message);
        return false;
    }

    return true;
}

cac::BufferObject::~BufferObject() 
{
    if(id) 
        glDeleteBuffers(1, &id);
}

void cac::BufferObject::create()
{
    glGenBuffers(1, &id);
}

void cac::BufferObject::disableAttribPointer(GLuint location)
{
    
    glDisableVertexAttribArray(location);
}

void cac::BufferObject::enableAttribPointer(GLuint location)
{
    boundCheck("enable AttribPointer");
    glEnableVertexAttribArray(location);
}

bool cac::BufferObject::enabledCheck(GLuint location)
{
   // GLint enabled;
   // glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);
/*
    if(!enabled)
    {
        printf("Error: VertexAttribArray for location %i is set but not enabled yet!", location);
        return false;
    }
*/
    return true;
}


template<> void cac::BufferObject::bind<cac::EBufferObjectTarget::ARRAY_BUFFER>()
{
    glBindBuffer(GL_ARRAY_BUFFER, id);
    boundTo = GL_ARRAY_BUFFER;
}


template<> void cac::BufferObject::setAttributePointer<cac::EBufferObjectDataType::FLOAT>(GLuint location,
     GLuint numberOfElements, bool normalized, GLuint stride, const void* offset)
{
    if(boundCheck("set AttrbPointer") && enabledCheck(location))
    {
        glVertexAttribPointer(location, numberOfElements, GL_FLOAT, normalized, stride, offset);        
    }
}

template<> void cac::BufferObject::setAttributePointer<cac::EBufferObjectDataType::INT>(GLuint location,
     GLuint numberOfElements, bool normalized, GLuint stride, const void* offset)
{
    if(boundCheck("set AttrbPointer") && enabledCheck(location))
    {
        glVertexAttribPointer(location, numberOfElements, GL_INT, normalized, stride, offset);        
    }
}

template<> void cac::BufferObject::setAttributePointer<cac::EBufferObjectDataType::BYTE>(GLuint location,
     GLuint numberOfElements, bool normalized, GLuint stride, const void* offset)
{
    if(boundCheck("set AttrbPointer") && enabledCheck(location))
    {
        glVertexAttribPointer(location, numberOfElements, GL_BYTE, normalized, stride, offset);        
    }
}

template <> void cac::BufferObject::setData<cac::EBufferObjectUsage::DYNAMIC>(unsigned int size, void* data)
{
    if(boundCheck("set data"))
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_DYNAMIC_DRAW);
    }
}

template <> void cac::BufferObject::setData<cac::EBufferObjectUsage::STATIC>(unsigned int size, void* data)
{
    if(boundCheck("set data"))
    {
        glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
    }
}


#endif