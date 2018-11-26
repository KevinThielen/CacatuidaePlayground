#include "Game.h"
#include "GameStates/IGameState.h"

bool Game::init(int width, int height)
{
    if(!graphics.init(width, height))
        return false;

    return true;
}

void Game::update()
{   
    fpsCounter.update();
    float dt = fpsCounter.deltaTime;    

    graphics.clear(cac::EClearBuffers::DEPTH_COLOR);

    for(auto& state : gameStates)
    {   
        if(!state->loading()) 
        {
            state->update(dt);

            state->render();
        }
    }

}
