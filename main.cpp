/* Hello World!
 *
 *  This is a programming exercise.
 *  Coding this program I want to practice my abilities using C++ and OpenGL
 *  being, this, the first time I try to make a simple game as Tetris can be.
 *
 *  It is needed glut library installed on your computer to run the graphic interface
 *
 *  I have designed this application using a model control view pattern
 *
 *  I hope you enjoy playing it.
 *
 *
 *
 *
 *  Author: Carmine D'Alessandro
 */


#include <stdlib.h>
#include <time.h>   /*used for the random generation of pieces*/


/*this is a MODEL/CONTROL/VIEW application*/
#include <Model.h>
#include <Control.h>
#include <View.h>


int main (int argc, char* argv[])
{

    srand((unsigned int) time (NULL));

    Game* game = new Game ();
    GameView* view = new GameView (game);
    Controller* controller = new Controller (game, view);

    /*Good Game!*/
    controller->start(&argc, argv);


    return EXIT_SUCCESS;
}
