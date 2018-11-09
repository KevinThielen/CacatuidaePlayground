#ifndef CACATUIDAE_FPS_COUNTER_H
#define CACATUIDAE_FPS_COUNTER_H

#include <chrono>
#include <emscripten.h>



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
        fps++;

        if(accumulatedTime >= 1.0f)
        {
            printf("Frame Time: %f, FPS: %i\n", deltaTime, fps);
            fps=0;
            accumulatedTime = 0;
        }

    }

private:
    double start = 0;
    double end = 0;
    double accumulatedTime = 0;
};


#endif