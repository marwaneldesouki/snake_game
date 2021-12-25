#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include <windows.h>
#include <MMsystem.h>
#include <iostream>
using std::fill_n;
using namespace std;

int gridX, gridY;
int snake_length = 5;
int foodX, foodY;
int level  = 1;
int posX[40] = {5,5,5,5,5};
int posY [40]= {5,4,3,2,1};
short sDirection = RIGHT;
bool food = true;
bool win;
extern int score;
extern bool pauseflag;
extern bool mute_sounds;
extern bool gameOver;

void initGrid(int x, int y){
    gridX = x;
    gridY = y;
}

void unit(int x, int y){
    if(x == 0 || y == 0 || x == gridX-1 || y == gridY-1){
        glLineWidth(1.0);
        glColor3f(1.0,0.0,0.0);
    }
    else{
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

void reset(){
    std::fill_n(posX, 40, 0);
    std::fill_n(posY, 40, 0);
    snake_length = 5;
    score = 0;
    sDirection = RIGHT;
    for(int j = 5,i = 0; i<5; i++,j--){
        posX[i]=5;
        posY[i]=j;
    }
}

void drawGrid(){
    for(int x = 0; x < gridX; x++){
        for(int y = 0; y < gridY; y++){
            unit(x,y);
        }
    }
}

void random(int &x, int &y){
    int _maxX = gridX-2;
    int _maxY = gridY-2;
    int _min = 1;
    srand(time(NULL));
    x = _min + rand() % (_maxX - _min);
    y = _min + rand() % (_maxY - _min);
}

void drawFood(){
    if(food)
        random(foodX, foodY);
    food = false;
    glColor3f(1.0,0.0,0.0);
    glRectf(foodX, foodY, foodX+1, foodY+1);

}

void drawSnake(){
   if(!pauseflag){
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
            glColor3f(0.878, 0.878, 0.878);
        else{
            if(level==1)
                glColor3f(0.0,1.0,0.0);
            else if(level==2)
                glColor3f(0.0,1.0,1.0);
            else if(level==3)
                glColor3f(1.0,0.0,1.0);
            else if(level==4)
                glColor3f(1.0,1.0,0.0);
            else if(level==5)
               glColor3f((rand() % 100+1)/100,(rand() % 100+1)/100,(rand() % 100+1)/100);
        }

        glRectd(posX[i],posY[i],posX[i]+1,posY[i]+1);
    }
    if(snake_length == 10 && level == 1){
        win = true;
    }
    else if(snake_length == 15 && level == 2){
        win = true;
    }
    else if(snake_length == 20 && level == 3){
        win = true;
    }
    else if(snake_length == 25 && level == 4){
        win = true;
    }
    else if(snake_length == 30 && level == 5){
        win = true;
    }

    //G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds deso
    //C:\\Users\\Habiba\\Desktop\\Semester 5\\Computer Graphics\\Snake_game\\sounds habiba

    if(posX[0] == 0 || posX[0] == gridX-1 || posY[0] == 0 || posY[0] == gridY-1){  // check if head touch red blocks
        gameOver = true;
        if(!mute_sounds)
        PlaySound(TEXT("G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds\\lose_sound.wav"),NULL,SND_ASYNC);
    }
    if(posX[0] == foodX && posY[0] == foodY){  // check if head touch food
        score++;
        snake_length++;
        if(!mute_sounds)
        PlaySound(TEXT("G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds\\coin_sound.wav"),NULL,SND_ASYNC);
        food = true;
    }
    for(int j = 1; j<snake_length; j++){ // loop on every block in body
        if(posX[j] == posX[0] && posY[j] == posY[0]){ // check if head touch body
                if(!mute_sounds)
            PlaySound(TEXT("G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds\\lose_sound.wav"),NULL,SND_ASYNC);
            gameOver=true;
        }
        if(posX[j]==foodX && posY[j]==foodY) // check if body touch food
            food=true;
    }
}
else
    pauseflag = false;
}
