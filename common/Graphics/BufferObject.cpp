#include "BufferObject.h"

cac::BufferObject::BufferObject() 
{
    glGenBuffers(1, &id);
}

cac::BufferObject::~BufferObject() 
{
    if(id) 
        glDeleteBuffers(1, &id);
}

void cac::BufferObject::disableAttribPointer(GLuint location)
{
   if(boundCheck("disable AttribPointer"))
    glDisableVertexAttribArray(location);
}

void cac::BufferObject::enableAttribPointer(GLuint location)
{
   if(boundCheck("enable AttribPointer"))
     glEnableVertexAttribArray(location);
}

//TODO: Currently bugged in emscripten due closure. Fixed in https://github.com/kripken/emscripten/issues/7472
bool cac::BufferObject::enabledCheck(GLuint location)
{
    location = 0;
    GLint enabled;
    glGetVertexAttribiv(0, GL_VERTEX_ATTRIB_ARRAY_ENABLED, &enabled);

    if(!enabled)
    {
        printf("Error: VertexAttribArray for location %i is set but not enabled yet!", location);
        return false;
    }

    return true;
}

void cac::BufferObject::bind(cac::EBufferObjectTarget target)
{
    glBindBuffer(static_cast<GLint>(target), id);
    boundTo = target;
}

void cac::BufferObject::setAttributePointer(GLuint location, cac::EBufferObjectDataType dataType,
     GLuint numberOfElements, bool normalized, GLuint stride, const void* offset)
{
    if(boundCheck("set AttrbPointer") && enabledCheck(location))
    {
        glVertexAttribPointer(location, numberOfElements, static_cast<GLenum>(dataType), normalized, stride, offset);        
    }
}

void cac::BufferObject::setData(cac::EBufferObjectUsage usage, void* data, size_t size)
{
    if(boundCheck("set data"))
    {
        glBufferData(static_cast<GLenum>(boundTo), size, data, static_cast<GLenum>(usage));
    }
}

bool cac::BufferObject::boundCheck(const char* message)
{
    if(boundTo == EBufferObjectTarget::UNBOUND)
    {
        printf("Error: Trying to %s of unbound BufferObject\n", message);
        return false;
    }

    return true;
}
