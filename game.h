#ifndef GAME_H_INCLUDED
#define GAME_H_INCLUDED

#define UP 1
#define DOWN -1
#define RIGHT 2
#define LEFT -2

#define COLUMNS 40 //number of columns
#define ROWS 40 //number of rows
#define FPS 10

void reset();
void pause();
void initGrid(int x, int y);
void drawGrid();
void drawSnake();
void drawFood();
void random(int&,int&);
void welcome();
void instruction();
void settings();
void display();
void game_page();
void timer(int);
void mouse_event(int,int,int,int);
void keyboard(unsigned char,int,int);

#endif
