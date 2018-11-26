#ifndef GAME_STATE_H
#define GAME_STATE_H

#include "../Game.h"


class IGameState 
{
public:
    IGameState(Game* game) : game(game){}
    virtual ~IGameState()=default;

    virtual void update(float dt) = 0;
    virtual void render() = 0;

    virtual void pause(bool isPause) { paused = isPause; }
    bool isPaused() { return paused; }

    virtual bool loading() 
    {
        if(loadState==ELoadState::FRESH)
            loadState=ELoadState::FINISHED;

        return loadState!=ELoadState::FINISHED;
    }

protected:
    enum class ELoadState   
    {
        FRESH,    
        LOADING,
        FINISHED
    };

    Game* game;
    bool paused = false;
    ELoadState loadState = ELoadState::FRESH;


};


#endif