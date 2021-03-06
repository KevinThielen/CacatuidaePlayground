#ifndef CACATUIDAE_FPS_COUNTER_H
#define CACATUIDAE_FPS_COUNTER_H

#include <chrono>
#include <emscripten.h>


namespace cac 
{
    class FPSCounter
    {
    public:
        int fps = 0;
        float deltaTime = 0;

        void update()
        {
            end = emscripten_get_now()/1000.f;
            deltaTime = end-start;
            start = end;


            accumulatedTime+=deltaTime;
            fpsCounter++;

            if(accumulatedTime >= 1.0f)
            {
                fps=fpsCounter;
                fpsCounter = 0;
                accumulatedTime = 0;
            }

        }

    private:
        int fpsCounter = 0;
        double start = 0;
        double end = 0;
        double accumulatedTime = 0;
    };
}

#endif