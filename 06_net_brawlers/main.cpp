
#include <Cacatuidae.h>
#include "GameStates/GameStates.h"
#include "Game.h"
int main()
{
    cac::Cacatuidae app;
    Game game;

    if(!game.init(800, 600))
        return -1;

    //INITIAL GAMESTATE
    game.push<GSMenu>();
    
    app.run([&]() {
        game.update();
    });

    return 0;
}
