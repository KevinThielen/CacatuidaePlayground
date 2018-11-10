#ifndef CACATUIDAE_RESOURCES_LOADER
#define CACATUIDAE_RESOURCES_LOADER

#include <emscripten.h>
#define STB_IMAGE_IMPLEMENTATION
#include <stb_image.h>
namespace cac 
{
    struct File 
    {
        const char* path;
        bool loaded = false;
        unsigned char* data = nullptr;
        size_t size = 0;

        File(const char* path) : path(path) {}
        ~File() { delete[] data;}
    };


    class FileLoader 
    {
    public:
        void load(File& file);

    private:
        static void onLoad(void* arg, void* buffer, int size);
        static void onError(void* arg);
    };
}

void cac::FileLoader::onLoad(void* arg, void* buffer, int size)
{
    File* filePtr = static_cast<File*>(arg);

    filePtr->size = size;
    filePtr->loaded = true;
    filePtr->data = new unsigned char[size];
    memcpy(filePtr->data, buffer, size);
}


void cac::FileLoader::onError(void* arg)
{
}

void cac::FileLoader::load(File& file)
{
    file.loaded = false;
    emscripten_async_wget_data(file.path, &file, (em_async_wget_onload_func) &this->onLoad, (em_arg_callback_func) &this->onError);
}

#endif