#ifndef GS_MENU_H
#define GS_MENU_H

#include "IGameState.h"
#include "GSGame.h"
#include <stdio.h>

class GSMenu : public IGameState
{
public:
    GSMenu(Game* game) : IGameState(game)
    {
    }

    bool loading() override
    {
        if(loadState == ELoadState::FINISHED)
            return false;

        if(loadState == ELoadState::FRESH)
        {
            game->graphics.clearColor(cac::vec4(1, 0, 0, 1));
            loadState = ELoadState::LOADING;
        }
        else if(loadState == ELoadState::LOADING)
        {
            timer -= game->fpsCounter.deltaTime;

            if(timer <= 0.0f)
            {
                game->graphics.clearColor(cac::vec4(0, 1, 0, 1));
                loadState = ELoadState::FINISHED;
            }
        }

        return true;
    }

    void update(float dt) override
    {
        if(paused)
            return;
            
        pause(true);
        game->push<GSGame>();
    }

    void render() override
    {
    }

private:
    float timer = 5.0f;
};


#endif