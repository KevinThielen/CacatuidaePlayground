#ifndef CACATUIDAE_RESOURCES_LOADER
#define CACATUIDAE_RESOURCES_LOADER

#include <emscripten.h>
#include <cstring>

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
        void load(File& file)
        {
             file.loaded = false;
    emscripten_async_wget_data(file.path, &file, this->onLoad, this->onError);
        }

    private:
        static void onLoad(void* arg, void* buffer, int size)
        {
            File* filePtr = static_cast<File*>(arg);
            filePtr->size = size;
            filePtr->loaded = true;
            filePtr->data = new unsigned char[size];
            std::memcpy(filePtr->data, buffer, size);
        }
        static void onError(void* arg){}
    };
}

#endif