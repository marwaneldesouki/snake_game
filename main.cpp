#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include<MMsystem.h>
#include "game.h"



extern short sDirection;
bool gameOver = false;
int score = 0;


void init(){
    glClearColor(0.0,0.0,0.0,1.0); //background_color
    initGrid(40,40);

}

int SCREENH=600,SCREENW=600;
void reshape(int w, int h){
	SCREENH=h,SCREENW=w;
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
     glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}



void keyboard(int key, int, int){
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
    glutInitWindowPosition(200,200);//window_position
    glutInitWindowSize(SCREENH,SCREENW);//window_size
    glutCreateWindow("Snake Game"); //window_title
    glutDisplayFunc(display); //display
    glutReshapeFunc(reshape); //reshape window to max,min
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(keyboard);
    glutMouseFunc(mouse_event);
    init();
    glutMainLoop();
    return 0;

}
