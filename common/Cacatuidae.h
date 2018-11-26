#ifndef CACATUIDAE_H
#define CACATUIDAE_H

#if EMSCRIPTEN
#include <emscripten.h>
#endif

#include <Graphics.h>
#include <FileLoader.h>

#include <functional> 



namespace cac 
{
    class Cacatuidae 
    {
    public:
        static void mainloop()
        {
            f();
        }


        void run(std::function<void()> frame)
        {
            f = frame;
            #ifdef EMSCRIPTEN
              emscripten_set_main_loop(Cacatuidae::mainloop, 0, 1);
            #endif
        }

    private: 
        static std::function<void()> f;   

    };
}


#endif