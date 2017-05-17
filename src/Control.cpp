#include "Control.h"

#include <windows.h>
#include <GL/glut.h>

Game* Controller::game = NULL;
GameView* Controller::view = NULL;

Controller::Controller (Game* game, GameView* view)
{
    Controller::game = game;
    Controller::view = view;
}

void Controller::tetrisKeyboardInputFunction (unsigned char key, int x, int y) {
    /*no action can be performed if the game is over*/
    if (!game->isPlaying())
        return;

    switch (key) {
        /*rotate*/
    case 'w':
    case 'W':
        game->unpause();
        game->rotatePiece();
        break;
        /*move left*/
    case 'a':
    case 'A':
        game->unpause();
        game->moveLeft();
        break;
        /*all bottom*/
    case 's':
    case 'S':
        game->unpause();
        game->allBottom();
        break;
        /*move right*/
    case 'd':
    case 'D':
        game->unpause();
        game->moveRight();
        break;
        /*pause*/
    case 'p':
    case 'P':
        if (game->isInPause())
            game->unpause();
        else
            game->pause();
        break;

    default:
        /*do nothing*/
        break;

    }

    /*redisplay the game after each movement*/
    glutPostRedisplay();
    /*the line below reset the timer each input from user*/
    /*It allows a piece to stop the fall for the time the inputs come*/
    //glutTimerFunc(game->getSpeed(), nextStep, GAME_TIMER);
}

/*this function is performed each tic of the game*/
void Controller::nextStep(int value) {

    if (!game->isInPause() &&
        game->isPlaying())
        game->stepBottom();


    glutPostRedisplay();
    glutTimerFunc(game->getSpeed(), nextStep, value);
}

void Controller::start (int* argcp, char** argv) {

    glutInit(argcp, argv);

    /*the frame*/
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(600,550);
    glutInitWindowPosition(200,100);
    glutCreateWindow("Tetris");

    /*settings*/
    glutDisplayFunc(view->drawGame);
    glutKeyboardFunc(tetrisKeyboardInputFunction);
    glutTimerFunc(game->getSpeed(), nextStep, GAME_TIMER);

    glutMainLoop();
}

