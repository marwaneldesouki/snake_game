#include <GL/gl.h>
#include<GL/glut.h>
#include <cstdlib>
#include<ctime>
#include "game.h"

int gridX, gridY;
int snake_length = 5;
bool food = true;
int foodX, foodY;
short sDirection = RIGHT;
extern bool gameOver;
extern int score;
int posX[60] = {5,5,5,5,5}, posY [60] = {5,4,3,2,1};

void initGrid(int x, int y)
{
    gridX = x;
    gridY = y;
}

void unit(int x, int y)
{
    if(x==0 || y==0 || x==gridX-1 || y==gridY-1)
    {
        glLineWidth(1.0);
        glColor3f(1.0,0.0,0.0);
    }
    else
    {
        glLineWidth(1.0);
        glColor3f(1.0,1.0,1.0);
    }
    glBegin(GL_LINE_LOOP);
    glVertex2f(x,y);
    glVertex2f(x+1,y);
    glVertex2f(x+1,y+1);
    glVertex2f(x,y+1);
    glEnd();
}

void drawGrid()
{
    for(int x=0; x<gridX; x++)
    {
        for(int y=0; y<gridY; y++)
        {
            unit(x,y);
        }
    }
}

void random(int &x, int &y)
{
    int _maxX = gridX-2;
    int _maxY = gridY-2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() % (_maxY - _min);
}

void drawFood()
{
    if(food)
        random(foodX, foodY);
    food = false;
    glColor3f(1.0,0.0,0.0);
    glRectf(foodX, foodY,foodX+1, foodY+1);

}


void drawSnake()
{
    for(int i = snake_length-1; i > 0; i--){
        posX[i] = posX[i-1];
        posY[i] = posY[i-1];
    }
    if(sDirection == UP)
        posY[0]++;
    else if(sDirection == DOWN)
        posY[0]--;
    else if(sDirection == RIGHT)
        posX[0]++;
    else if(sDirection == LEFT)
        posX[0]--;
    for(int i = 0; i < snake_length; i++){
        if(i == 0)
            glColor3f(0.0,1.0,0.0);
        else
            glColor3f(0.0,0.0,1.0);
        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }

    if(posX[0] == 0 || posX[0] == gridX-1 || posY[0] == 0 || posY[0] == gridY-1) // check if head touch red blocks
        gameOver = true;
    if(posX[0] == foodX && posY[0] == foodY){ // check if head touch coins
        score++;
        snake_length++;
        if(snake_length > MAX)
            snake_length = MAX;
        food = true;
    }
    for(int j=1;j<snake_length;j++) // loop on every block in tail
{
        if(posX[j]==posX[0] && posY[j]==posY[0]) // check if head touch tail
            gameOver=true;
        if(posX[j]==foodX && posY[j]==foodY) // check if head touch tail
            food=true;
}
}

