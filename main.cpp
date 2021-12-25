#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <windows.h>
#include <MMsystem.h>
#include "game.h"
#include <iostream>
using namespace std;

int score = 0;
int SCREENH = 600,SCREENW = 600;
bool fullscreen = false;
bool gameOver = false;
extern int level;
extern short sDirection;
extern bool win;
extern bool pauseflag;

void init(){
    glClearColor(0.0,0.0,0.0,0.0); //background_color
    initGrid(40,40);
}

void reshape(int SCREENW, int SCREENH){
    glViewport(0,0,(GLsizei)SCREENW,(GLsizei)SCREENH);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
}

void keyboard(unsigned char key,int x,int y){
    if(key=='F'||key=='f'){
        if(!fullscreen){
            glutFullScreen();
            fullscreen = true;
        }
        else{
            glutPositionWindow((glutGet(GLUT_SCREEN_WIDTH)-640)/2,(glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
            glutReshapeWindow(600,600);//window_size
            fullscreen = false;
        }
    }
    else if(key == 27 || key == ' '){
        pauseflag = true;
    }
    else if(key == 'L' || key == 'l'){
        win = true;
    }

}

void game_keyboard(int key, int, int){

    switch(key){
    case GLUT_KEY_UP:
        if(sDirection != DOWN)
            sDirection = UP;
        break;

    case GLUT_KEY_DOWN:
        if(sDirection != UP)
            sDirection = DOWN;
        break;

    case GLUT_KEY_RIGHT:
        if(sDirection != LEFT)
            sDirection = RIGHT;
        break;

    case GLUT_KEY_LEFT:
        if(sDirection != RIGHT)
            sDirection = LEFT;
        break;

    }
}

int main(int argc,char **argv){
    glutInit(&argc,argv); //just initiate
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //display_mode
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-640)/2,(glutGet(GLUT_SCREEN_HEIGHT)-480)/2);
    glutInitWindowSize(SCREENH,SCREENW);//window_size
    glutCreateWindow("Snake Game"); //window_title
    glutKeyboardFunc(keyboard);
    glutDisplayFunc(display); //display
    glutReshapeFunc(reshape); //reshape window to max,min
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(game_keyboard);//keyboard
    glutMouseFunc(mouse_event);//mouse
    PlaySound(TEXT("G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds\\ana_elso3ban.wav"),NULL,SND_ASYNC);
    init();
    glutMainLoop();
    return 0;

}
