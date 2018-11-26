#ifndef GAME_H
#define GAME_H

#include <FPSCounter.h>
#include <vector>
#include <queue>
#include <memory>
#include <Graphics.h>
#include <FileLoader.h>

class IGameState;
class Game 
{
public:
    cac::Graphics graphics;
    cac::FileLoader fileLoader;
    cac::FPSCounter fpsCounter;

    bool init(int width, int height);

    void update();


    template<class gameState>void push()
    {
        if(!std::is_base_of<IGameState, gameState>())
            printf("Pushing Invalid GameState\n");
    
        gameStates.push_back(std::unique_ptr<gameState>(new gameState(this)));
    }
    
private:
    std::vector<std::unique_ptr<IGameState>> gameStates;
};

#endif