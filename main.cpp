#include <GL/gl.h>
#include <GL/glut.h>
#include <stdlib.h>
#include<windows.h>
#include "game.h"

#define COLUMNS 40
#define ROWS 40
#define FPS 10

extern short sDirection;
bool gameOver = false;
int score = 0;

void init(){
    glClearColor(0.0,0.0,0.0,1.0); //background_color
    initGrid(COLUMNS,ROWS);

}

void display(){
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer to new background color
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if(gameOver){
        char _score[10];
        itoa(score,_score,10);
        char text[50] = "Your Score: ";
        strcat(text,_score);
        MessageBox(NULL, text,"GAME OVER" ,0);
        exit(0);
    }
}

void reshape(int w,int h){  //some options in size of window
    glViewport(0,0,(GLsizei)w,(GLsizei)h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0,COLUMNS,0.0,ROWS,-1.0,1.0);
    glMatrixMode(GL_MODELVIEW);
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer,0);
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
    glutInitWindowSize(600,600);//window_size
    glutCreateWindow("Snake Game"); //window_title
    glutDisplayFunc(display); //display
    glutReshapeFunc(reshape); //reshape window to max,min
    glutTimerFunc(0,timer,0);
    glutSpecialFunc(keyboard);
    init();
    glutMainLoop();
    return 0;

}
