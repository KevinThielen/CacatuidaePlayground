#ifndef CACATUIDAE_BUFFER_OBJECT_H
#define CACATUIDAE_BUFFER_OBJECT_H

#include <GLES2/gl2.h>
#include <stdio.h>

namespace cac 
{
    enum class EBufferObjectTarget : GLenum
    {
        UNBOUND,
        ARRAY_BUFFER = GL_ARRAY_BUFFER,
        ELEMENT_ARRAY_BUFFER = GL_ELEMENT_ARRAY_BUFFER
    };
    
    enum class EBufferObjectUsage : GLenum
    {
        STATIC = GL_STATIC_DRAW,
        DYNAMIC = GL_DYNAMIC_DRAW
    };
    
    enum class EBufferObjectDataType : GLenum
    {
        BYTE = GL_BYTE,
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
        BufferObject();
       ~BufferObject();
        void create();

        void enableAttribPointer(GLuint location);
        void disableAttribPointer(GLuint location);

        void bind(EBufferObjectTarget target);
        void setData(EBufferObjectUsage usage, void* data, size_t size);
        void setAttributePointer(GLuint location, EBufferObjectDataType dataType, GLuint numberOfElements,
                                 bool normalized, GLuint stride, const void* offset);
  
        GLuint id = 0;
        EBufferObjectTarget boundTo = EBufferObjectTarget::UNBOUND;

    private:
        bool boundCheck(const char* message);
        bool enabledCheck(GLuint location);
    };
}



#endif