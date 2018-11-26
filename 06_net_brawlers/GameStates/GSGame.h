#ifndef GS_GAME_H
#define GS_GAME_H

#include "IGameState.h"
#include <Camera.h>
#include <Graphics.h>
enum class EShaderProgram 
{
    DEFAULT,
    DIFFUSE
};

struct File : cac::File
{
    enum class FileType
    {
        SHADER,
        TEXTURE
    } fileType;
    cac::File file;
};

class GSGame : public IGameState 
{
public:
    GSGame(Game* game) : IGameState(game)
    {

    }

    bool loading() override 
    {
        switch(loadState)
        {
            case ELoadState::FINISHED: { return false; }
            case ELoadState::LOADING: { 

            }
            case ELoadState::FRESH: {
                
            }
            default: return true;
        }


        if(loadState==ELoadState::FINISHED)
            return false;

        if(loadState==ELoadState::FRESH)
        {
            loadState = ELoadState::LOADING;
            //init loading
        }
        else if(loadState == ELoadState::LOADING)
        {

        }
        return true;
    }

    void update(float dt) override 
    {

    }
    
    void render() override 
    {

    }

private:
    std::map<EShaderProgram, cac::ShaderProgram> shaderPrograms;
  //  cac::Camera cam;
 //   Level level;
};


#endif