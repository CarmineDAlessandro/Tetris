#ifndef CONTROL_H
#define CONTROL_H

#include <cstddef>

#include <Model.h>
#include <View.h>

#define GAME_TIMER 1

class Controller
{
    public:
        Controller (Game* game, GameView* view);
        static void tetrisKeyboardInputFunction (unsigned char key, int x, int y);
        static void start(int* argcp, char** argv);

    protected:

    private:
        static Game* game;
        static GameView* view;

        /*the function to control the time of the game*/
        static void nextStep (int value);


};


#endif // CONTROL_H
