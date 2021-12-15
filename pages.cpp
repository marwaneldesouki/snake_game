#include <GL/gl.h>
#include<GL/glut.h>
#include <cstdlib>
#include<ctime>
#include "game.h"
#include<windows.h>
#include<MMsystem.h>
#include <iostream>

using namespace std;

extern bool gameOver;
extern int score;


bool wflag = true,instflag=false,abtflag=false;
void drawString(float x,float y,float z,void *font,char *string){
	char *c;
	glRasterPos3f(x, y,z);

	for (c = string; *c != '\0'; c++)
	{
		glutBitmapCharacter(font, *c);

	}
}

void welcome(){
	glColor3f(0,0,0);   //welcome background
	glBegin(GL_POLYGON);
	glVertex3f(0.0,0.0,0.0);
	glVertex3f(40.0,0.0,0.0);
	glVertex3f(40.0,40.0,0.0);
	glVertex3f(0.0,40.0,0.0);
	glEnd();

    glColor3f(1.0,0.0,0.0);
	drawString(17,36,0,GLUT_BITMAP_TIMES_ROMAN_24,"WELCOME");//
	drawString(20,34,0,GLUT_BITMAP_HELVETICA_18,"TO");//
	drawString(16,32,0,GLUT_BITMAP_TIMES_ROMAN_24,"SNAKE GAME");//

    glColor3f(rand()/10,rand(),rand());

	drawString(7,28,0,GLUT_BITMAP_9_BY_15,"By{Marwan ElDesouki,Habiba Amr,Ahmed Shaarawy}");//

	// button 1 .. PLAY
	glColor3f(0.196,0.196,0.8);
	glRectf(12.5,21.5,28.5,26.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(13,22,28,26);

	glColor3f(0.137,0.137,0.556);
	drawString(18.5,23.5,0,GLUT_BITMAP_HELVETICA_18,"PLAY");

	// button 2 .. instructions
	glColor3f(0.196,0.196,0.8);
	glRectf(12.5,14.5,28.5,19.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(13,15,28,19);

	glColor3f(0.137,0.137,0.556);
	drawString(16,16.5,0,GLUT_BITMAP_HELVETICA_18,"INSTRUCTIONS");

	// button 3 .. ABOUT
	glColor3f(0.196,0.196,0.8);
	glRectf(12.5,7.5,28.5,12.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(13,8,28,12);

	glColor3f(0.137,0.137,0.556);
	drawString(18,9.5,0,GLUT_BITMAP_HELVETICA_18,"ABOUT");

	// button 4 .. exit
	glColor3f(0.196,0.196,0.8);
	glRectf(12.5,0.5,28.5,5.5);

	glColor3f(0.8,0.8,0.8);
	glRectf(13,1,28,5);

	glColor3f(0.137,0.137,0.556);
	drawString(19,2.5,0,GLUT_BITMAP_HELVETICA_18,"EXIT");


	glPushMatrix();


}

void instruction(){
glColor3f(0.3,0.56,0.84);   // background
		glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glColor3f(0.137,0.137,0.556);
		glVertex3f(100.0,0.0,0.0);
		glColor3f(0.196,0.196,0.8);
		glVertex3f(100.0,100.0,0.0);
		glVertex3f(0.0,100.0,0.0);
		glEnd();
		glPushMatrix();
		glScalef(0.8,0.8,0);
		glPopMatrix();
		glColor3f(0.137,0.137,0.556);
		glRectf(20.0,20.0,80.0,80.0);
		glColor3f(0.8,0.8,0.8);
		glRectf(21.0,21.0,79.0,79.0);


		glColor3f(0.196,0.196,0.8);
		glRectf(40,5,60,10);
		glColor3f(0.8,0.8,0.8);
		glRectf(40.5,5.5,59.5,9.5);

		glColor3f(0.137,0.137,0.556);
		drawString(46,6,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");

		glColor3f(0.137,0.137,0.556);
		drawString(37,75,0,GLUT_BITMAP_TIMES_ROMAN_24,"HOW TO PLAY");


		glutPostRedisplay();
}
void timer(int){
    glutPostRedisplay();
    glutTimerFunc(1000/FPS, timer,0);
}

void game_page(){
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer to new background color
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers();
    if(gameOver){
        char _score[10];
        itoa(score,_score,10); //convert score from int to char>string
        char text[50] = "Your Score: ";
        strcat(text,_score); //concatenate text to score
        MessageBox(NULL, text,"GAME OVER" ,0);
        wflag=true;
        welcome();
       score = 0;
    }

}

void about(){
		glColor3f(0.3,0.56,0.84);   // background
		glBegin(GL_POLYGON);
		glVertex3f(0.0,0.0,0.0);
		glColor3f(0.137,0.137,0.556);
		glVertex3f(100.0,0.0,0.0);
		glColor3f(0.196,0.196,0.8);
		glVertex3f(100.0,100.0,0.0);
		glVertex3f(0.0,100.0,0.0);
		glEnd();
		glPushMatrix();
		glScalef(0.8,0.8,0);
		glPopMatrix();
		glColor3f(0.137,0.137,0.556);
		glRectf(20.0,20.0,80.0,80.0);
		glColor3f(0.8,0.8,0.8);
		glRectf(21.0,21.0,79.0,79.0);


		glColor3f(0.196,0.196,0.8);
		glRectf(40,5,60,10);
		glColor3f(0.8,0.8,0.8);
		glRectf(40.5,5.5,59.5,9.5);
		glColor3f(0.137,0.137,0.556);
		drawString(46,6,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");

		glColor3f(0.137,0.137,0.556);
		drawString(44,75,0,GLUT_BITMAP_TIMES_ROMAN_24,"ABOUT");
		drawString(21,61,0,GLUT_BITMAP_HELVETICA_18,"");
		drawString(23,53,0,GLUT_BITMAP_HELVETICA_18,"");

		drawString(33,40,0,GLUT_BITMAP_HELVETICA_18," ENJOY PLAYING THE GAME");
		glutPostRedisplay();
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	if(wflag==true)
	{
		welcome();
glFlush();
	glutSwapBuffers();
	}
	else if (instflag == true)
	{
	    instruction();
glFlush();
	glutSwapBuffers();
	}
	else if (abtflag == true)
	{
      about();
glFlush();
	glutSwapBuffers();
	}
	else{

game_page();
gameOver =false;

	}


}

void mouse_event(int button, int state, int x, int y)
{
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
            if((x>=196&&x<=419) &&(y>=212&&y<=264)){ //welcome button in home_page
                wflag = false;
                instflag = false;
                abtflag=false;
                game_page();
                cout<<"mouse_welcome"<<endl;
            }
            else if((x>=197&&x<=417) &&(y>=318&&y<=370)){ //instructions button in home_page
                instflag = true;
                wflag = false;
                abtflag=false;
                instruction();
                cout<<"mouse_inst"<<endl;
            }
            else if((x>=196&&x<=419) &&(y>=421&&y<=474)){ //about button in home_page
                abtflag=true;
                wflag = false;
                instflag = false;
                about();
                cout<<"mouse_about"<<endl;
            }
            else if((x>=622&&x<=912) &&(y>=549&&y<=762) && (instflag||abtflag)){ //back button
                wflag = true;
                instflag = false;
                abtflag=false;
                welcome();
                cout<<"mouse_back"<<endl;
            }
             else if((x>=198&&x<=418) &&(y>=527&&y<=580) && wflag){ //exit button in home_page
                 cout<<"mouse_exit"<<endl;
                exit(0);

            }

cout<<x<<endl<<y<<endl;

    }
}
