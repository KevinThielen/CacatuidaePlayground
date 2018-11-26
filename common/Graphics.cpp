
#include <Graphics.h>

#if EMSCRIPTEN
    #include <Graphics/GLES2/Context.h>

    class cac::Graphics::GraphicsInternal : public cac::GLES2Context { };

#else 
//not implemented yet, but VSCOde is PITA and doesn't recognize that EMSCRIPTEN define
//so it's either that or yolo coding
class cac::Graphics::GraphicsInternal 
{
public:
    bool create(int width, int height) {}
};
#endif


cac::Graphics::Graphics()
{
    pimpl = new GraphicsInternal();
}

cac::Graphics::~Graphics()
{
    delete pimpl;
}

bool cac::Graphics::init(int width, int height)
{
    return pimpl->create(width, height);
}

void cac::Graphics::clear(cac::EClearBuffers clearBuffers) 
{
    glClear(static_cast<GLbitfield>(clearBuffers)); 
}

void cac::Graphics::clearColor(cac::vec4 color)
{
    glClearColor(color.x, color.y, color.z, color.a);
}

void cac::Graphics::clearColor(float r, float g, float b, float a)
{
    glClearColor(r, g, b, a);
}
