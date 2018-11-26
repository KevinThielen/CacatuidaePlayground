#ifndef CACATUIDAE_GRAPHICS_H
#define CACATUIDAE_GRAPHICS_H

#include <map>
#include <glm/glm.hpp>
#include <Graphics/Enums.h>
#include <Graphics/ShaderProgram.h>
#include <Graphics/BufferObject.h>

namespace cac 
{
    struct ResourceHandle {int id = 0; const char* path; };
    struct Shader : public ResourceHandle { static int COUNTER; };


    class Graphics 
    {
    public:
        Graphics();
        ~Graphics();

        bool init(int width, int height);
           
        void clear(EClearBuffers clearBuffers);
        void clearColor(vec4 color);
        void clearColor(float r, float g, float b, float a);

    private:
        class GraphicsInternal;
        GraphicsInternal* pimpl;
    };
}

#endif