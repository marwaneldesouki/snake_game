#include <GL/gl.h>
#include <GL/glut.h>
#include <cstdlib>
#include <ctime>
#include "game.h"
#include <windows.h>
#include <MMsystem.h>
#include <iostream>

using namespace std;

bool mute_sounds = false;
bool settingsflag;
bool wflag = true, instflag = false, abtflag = false, pauseflag = false;
float time_= 1000/FPS;
extern int score;
extern int level;
extern bool fullscreen;
extern bool gameOver;
extern bool win;

void drawString(float x,float y,float z,void *font,char *string){ //to draw labels
    char *c;
    glRasterPos3f(x, y,z);
    for (c = string; *c != '\0'; c++){
        glutBitmapCharacter(font, *c);
    }
}

void welcome(){ //main menu
    if(!fullscreen){
        glColor3f(1.0,0.0,0.0);
        drawString(17,36,0,GLUT_BITMAP_TIMES_ROMAN_24,"WELCOME");
        drawString(20,34,0,GLUT_BITMAP_HELVETICA_18,"TO");
        drawString(16,32,0,GLUT_BITMAP_TIMES_ROMAN_24,"SNAKE GAME");

        glColor3f((rand() % 100+1)/10,(rand() % 100+1)/10,(rand() % 100+1)/10);

        drawString(7,28,0,GLUT_BITMAP_9_BY_15,"By{Marwan ElDesouki,Habiba Amr,Ahmed Shaarawy}");//

        // button 1 .. PLAY
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,21.5,28.5,26.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,22,28,26);
        glColor3f(0.137,0.137,0.556);
        drawString(18.5,23.5,0,GLUT_BITMAP_HELVETICA_18,"PLAY");
//

        // button 2 .. instructions
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,14.5,28.5,19.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,15,28,19);
        glColor3f(0.137,0.137,0.556);
        drawString(16,16.5,0,GLUT_BITMAP_HELVETICA_18,"INSTRUCTIONS");
//

        // button 3 .. settings
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,7.5,28.5,12.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,8,28,12);
        glColor3f(0.137,0.137,0.556);
        drawString(17.5,9.5,0,GLUT_BITMAP_HELVETICA_18,"SETTINGS");
//

        // button 4 .. exit
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,0.5,28.5,5.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,1,28,5);
        glColor3f(0.137,0.137,0.556);
        drawString(19,2.5,0,GLUT_BITMAP_HELVETICA_18,"EXIT");
//
    }
    else{
        glColor3f(1.0,0.0,0.0);
        drawString(19,36,0,GLUT_BITMAP_TIMES_ROMAN_24,"WELCOME");
        drawString(20,34,0,GLUT_BITMAP_HELVETICA_18,"TO");
        drawString(18.7,32,0,GLUT_BITMAP_TIMES_ROMAN_24,"SNAKE GAME");

        glColor3f((rand() % 100+1)/10,(rand() % 100+1)/10,(rand() % 100+1)/10);

        drawString(15,28,0,GLUT_BITMAP_9_BY_15,"By{Marwan ElDesouki,Habiba Amr,Ahmed Shaarawy}");//

        // button 1 .. PLAY
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,21.5,28.5,26.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,22,28,26);
        glColor3f(0.137,0.137,0.556);
        drawString(20,23.5,0,GLUT_BITMAP_HELVETICA_18,"PLAY");
//

        // button 2 .. instructions
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,14.5,28.5,19.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,15,28,19);
        glColor3f(0.137,0.137,0.556);
        drawString(19,16.5,0,GLUT_BITMAP_HELVETICA_18,"INSTRUCTIONS");
//

        // button 3 .. settings
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,7.5,28.5,12.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,8,28,12);
        glColor3f(0.137,0.137,0.556);
        drawString(19.5,9.5,0,GLUT_BITMAP_HELVETICA_18,"SETTINGS");
//

        // button 4 .. exit
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,0.5,28.5,5.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,1,28,5);
        glColor3f(0.137,0.137,0.556);
        drawString(20,2.5,0,GLUT_BITMAP_HELVETICA_18,"EXIT");
    }
    glutPostRedisplay();
}

void instruction(){ //instructions_page
    if(!fullscreen){
        glColor3f(0.137,0.137,0.556);
        glRectf(4.5,38.5,35.5,6.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(5,38,35,7);
        glColor3f(0.137,0.137,0.556);
        drawString(15,36,0,GLUT_BITMAP_TIMES_ROMAN_24,"HOW TO PLAY");
        drawString(5.2,34,0,GLUT_BITMAP_HELVETICA_18,"- You will use the directions button in the computer ");
        drawString(6,32,0,GLUT_BITMAP_HELVETICA_18,"to play.");
        drawString(5.2,30,0,GLUT_BITMAP_HELVETICA_18,"- UP Button to move up.");
        drawString(5.2,28,0,GLUT_BITMAP_HELVETICA_18,"- DOWN Button to move down.");
        drawString(5.2,26,0,GLUT_BITMAP_HELVETICA_18,"- RIGHT Button to move right.");
        drawString(5.2,24,0,GLUT_BITMAP_HELVETICA_18,"- LEFT Button to move left.");
        drawString(5.2,22,0,GLUT_BITMAP_HELVETICA_18,"- ESC & BACKSPACE to Pause the game.");
        drawString(5.2,20,0,GLUT_BITMAP_HELVETICA_18,"- F or f to FullScreen the game.");
        drawString(5.2,18,0,GLUT_BITMAP_HELVETICA_18,"- The game is 5 LEVELS");
        drawString(5.2,16,0,GLUT_BITMAP_HELVETICA_18,"- Level 1 will be reached when the score is 5");
        drawString(5.2,14,0,GLUT_BITMAP_HELVETICA_18,"- Level 2 will be reached when the score is 10");
        drawString(5.2,12,0,GLUT_BITMAP_HELVETICA_18,"- Level 3 will be reached when the score is 15");
        drawString(5.2,10,0,GLUT_BITMAP_HELVETICA_18,"- Level 4 will be reached when the score is 20");
        drawString(5.2,8,0,GLUT_BITMAP_HELVETICA_18,"- Level 5 will be reached when the score is 25");
        glColor3f(0.196,0.196,0.8);
        glRectf(13,1,28,5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13.5,1.5,27.5,4.5);
        glColor3f(0.137,0.137,0.556);
        drawString(18,2.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");
    }
    else{
        glColor3f(0.137,0.137,0.556);
        glRectf(4.5,38.5,35.5,6.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(5,38,35,7);
        glColor3f(0.137,0.137,0.556);
        drawString(18,35,0,GLUT_BITMAP_TIMES_ROMAN_24,"HOW TO PLAY");
        drawString(14,32,0,GLUT_BITMAP_HELVETICA_18,"- You will use the directions button in the computer to play.");
        drawString(14,30,0,GLUT_BITMAP_HELVETICA_18,"- UP Button to move up.");
        drawString(14,28,0,GLUT_BITMAP_HELVETICA_18,"- DOWN Button to move down.");
        drawString(14,26,0,GLUT_BITMAP_HELVETICA_18,"- RIGHT Button to move right.");
        drawString(14,24,0,GLUT_BITMAP_HELVETICA_18,"- LEFT Button to move left.");
        drawString(14,22,0,GLUT_BITMAP_HELVETICA_18,"- ESC & BACKSPACE to pause the game.");
        drawString(14,20,0,GLUT_BITMAP_HELVETICA_18,"- F or f to FullScreen the game.");
        drawString(14,18,0,GLUT_BITMAP_HELVETICA_18,"- The game is 5 LEVELS");
        drawString(14,16,0,GLUT_BITMAP_HELVETICA_18,"- Level 1 will be reached when the score is 5");
        drawString(14,14,0,GLUT_BITMAP_HELVETICA_18,"- Level 2 will be reached when the score is 10");
        drawString(14,12,0,GLUT_BITMAP_HELVETICA_18,"- Level 3 will be reached when the score is 15");
        drawString(14,10,0,GLUT_BITMAP_HELVETICA_18,"- Level 4 will be reached when the score is 20");
        drawString(14,8,0,GLUT_BITMAP_HELVETICA_18,"- Level 5 will be reached when the score is 25");
        glColor3f(0.196,0.196,0.8);
        glRectf(13,1,28,5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13.5,1.5,27.5,4.5);
        glColor3f(0.137,0.137,0.556);
        drawString(19.5,2.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");
    }

    glutPostRedisplay();
}

void settings(){
    if(!fullscreen){
//container
        glColor3f(0.137,0.137,0.556);//border color
        glRectf(4.5,35.5,35.5,9.5);//border

        glColor3f(0.8,0.8,0.8);//box color
        glRectf(5,35,35,10);//box

        glColor3f(0.137,0.137,0.556);//label color
        drawString(19,33,0,GLUT_BITMAP_TIMES_ROMAN_24,"SETTINGS");//settings label
//


//mute button_label
        glColor3f(0.137,0.137,0.556);
        glRectf(7,28,8,27);
        if(mute_sounds){ //true-> unhide gray box ~ else hide gray box
            glColor3f(0.8,0.8,0.8);
            glRectf(7.2,27.8,7.8,27.1);
        }

        glColor3f(0.137,0.137,0.556);
        drawString(8.5,27,0,GLUT_BITMAP_TIMES_ROMAN_24,"MUTE");
//

//back button
        glColor3f(0.196,0.196,0.8);
        glRectf(13,1,28,5);

        glColor3f(0.8,0.8,0.8);
        glRectf(13.5,1.5,27.5,4.5);

        glColor3f(0.137,0.137,0.556);
        drawString(18,2.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");
//
    }
    else{
        //container
        glColor3f(0.137,0.137,0.556);//border color
        glRectf(4.5,35.5,35.5,9.5);//border

        glColor3f(0.8,0.8,0.8);//box color
        glRectf(5,35,35,10);//box

        glColor3f(0.137,0.137,0.556);//label color
        drawString(19,33,0,GLUT_BITMAP_TIMES_ROMAN_24,"SETTINGS");//settings label
//


//mute button_label
        glColor3f(0.137,0.137,0.556);
        glRectf(7,28,8,27);
        if(mute_sounds){ //true-> unhide gray box ~ else hide gray box
            glColor3f(0.8,0.8,0.8);
            glRectf(7.2,27.8,7.8,27.1);
        }

        glColor3f(0.137,0.137,0.556);
        drawString(8.5,27,0,GLUT_BITMAP_TIMES_ROMAN_24,"MUTE");
//

//back button
        glColor3f(0.196,0.196,0.8);
        glRectf(13,1,28,5);

        glColor3f(0.8,0.8,0.8);
        glRectf(13.5,1.5,27.5,4.5);

        glColor3f(0.137,0.137,0.556);
        drawString(19.5,2.5,0,GLUT_BITMAP_TIMES_ROMAN_24,"BACK");
//

    }
    glutPostRedisplay();
}

void game_page(){
    glClear(GL_COLOR_BUFFER_BIT); //clear buffer to new background color
    drawGrid();
    drawSnake();
    drawFood();
    glutSwapBuffers(); // swap buffers of the current window
    glutKeyboardFunc(keyboard);
    if(gameOver){
        char _score[10];
        itoa(score,_score,10); //convert score from int to char>string
        char text[50] = "Your Score: ";
        strcat(text,_score); //concatenate text to score
        MessageBox(NULL, text,"GAME OVER",0);
        wflag = true;//welcome_flag
        reset();//to reset snake_score
        welcome();
        win = false;

    }
    else if(win && level == 5){
        char _score[10];
        char _level[10];
        itoa(score,_score,10); //convert score from int to char>string
        itoa(level,_level,10);
        char text[50] = "Your Score: ";
        char msg_txt[50] = "\nYour ARE IN LEVEL #";
        strcat(text,_score); //concatenate text to score
        strcat(msg_txt,_level);
        strcat(text,msg_txt);
        MessageBox(NULL, "CONGRATULATIONS YOU FINISHED THE GAME","Mabrrrooooook khalleess",0);
        win = false;
        wflag = true;
        reset();
        level = 1;
        welcome();
    }
    else if(win){
        char _score[10];
        char _level[10];
        level++;
        itoa(score,_score,10); //convert score from int to char>string
        itoa(level,_level,10);
        char text[50] = "Your Score: ";
        char msg_txt[50] = "\nYOU ARE GOING TO LEVEL #";
        strcat(text,_score); //concatenate text to score
        strcat(msg_txt,_level);
        strcat(text,msg_txt);
        if(!mute_sounds)
            PlaySound(TEXT("G:\\gam3a\\Computer Graphics\\sec\\Snake_game\\sounds\\win_sound.wav"),NULL,SND_ASYNC);
        MessageBox(NULL, text,"Bravoo 3leek",0);
        win = false;
        reset();
    }

}

void pause(){
    if(!fullscreen){
        // button 1 .. resume
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,21.5,28.5,26.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,22,28,26);
        glColor3f(0.137,0.137,0.556);
        drawString(17.5,23.5,0,GLUT_BITMAP_HELVETICA_18,"RESUME");
        // button 2 .. instructions
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,14.5,28.5,19.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,15,28,19);
        glColor3f(0.137,0.137,0.556);
        drawString(18.5,16.5,0,GLUT_BITMAP_HELVETICA_18,"QUIT");
    }
    else{
        // button 1 .. resume
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,21.5,28.5,26.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,22,28,26);
        glColor3f(0.137,0.137,0.556);
        drawString(19.5,23.5,0,GLUT_BITMAP_HELVETICA_18,"RESUME");
        // button 2 .. instructions
        glColor3f(0.196,0.196,0.8);
        glRectf(12.5,14.5,28.5,19.5);
        glColor3f(0.8,0.8,0.8);
        glRectf(13,15,28,19);
        glColor3f(0.137,0.137,0.556);
        drawString(20,16.5,0,GLUT_BITMAP_HELVETICA_18,"QUIT");
    }
    glutPostRedisplay();
}

void timer(int){
    glutPostRedisplay();
    glutTimerFunc(time_, timer,0);
}

void display(){
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // clears the color and depth buffers
    if(wflag == true){
        welcome();
        glFlush(); // empties all commands in these buffers
        glutSwapBuffers();
    }
    else if (instflag == true){
        instruction();
        glFlush();
        glutSwapBuffers();
    }
    else if (settingsflag == true){
        settings();
        glFlush();
        glutSwapBuffers();
    }
    else if (pauseflag == true){
        pause();
        glFlush();
        glutSwapBuffers();
    }
    else{
        game_page();
        gameOver = false;
    }
}

void mouse_event(int button, int state, int x, int y){
    if(button == GLUT_LEFT_BUTTON && state == GLUT_DOWN){
        if(((x>=196&&x<=419) && (y>=212&&y<=264) || (x>=502&&x<=1072) && (y>=287&&y<=359)) && wflag){   //start button in home_page
            wflag = false;
            instflag = false;
            pauseflag = false;
            settingsflag = false;
            game_page();
            cout<<"mouse_welcome"<<endl;
        }
        else if(((x>=197&&x<=417) && (y>=318&&y<=370) || (x>=502&&x<=1069) && (y>=461&&y<=533)) && wflag){   //instructions button in home_page
            instflag = true;
            wflag = false;
            settingsflag = false;
            instruction();
            cout<<"mouse_inst"<<endl;
        }
        else if(((x>=196&&x<=419) && (y>=421&&y<=474) || (x>=505&&x<=1069) && (y>=612&&y<=684))  && wflag){   //settings button in home_page
            wflag = false;
            instflag = false;
            pauseflag = false;
            settingsflag = true;
            settings();
            cout<<"mouse_settings"<<endl;
        }
        else if(((x>=198&&x<=418) && (y>=527&&y<=580) || (x>=507&&x<=1066) && (y>=765&&y<=833)) && wflag){   //exit button in home_page
            exit(0);
            cout<<"mouse_exit"<<endl;
        }
        else if(((x>=108&&x<=117) && (y>=182&&y<=191) || (x>=273&&x<=303) && (y>=264&&y<=275)) && settingsflag){   //mute button in settings_page
            pauseflag = false;
            wflag = false;
            instflag = false;
            if(mute_sounds){
                mute_sounds = false;
            }
            else
                mute_sounds = true;

            cout<<"mute"<<endl;

        }
        else if(((x>=203&&x<=408) && (y>=549&&y<=762)|| (x>=521&&x<=1051) && (y>=772&&y<=824)) && (instflag||settingsflag)){   //back button
            wflag = true;
            instflag = false;
            pauseflag = false;
            settingsflag = false;
            welcome();
            cout<<"mouse_back"<<endl;
        }
        else if(((x>=198&&x<=418) && (y>=213&&y<=267) || (x>=505&&x<=1066) && (y>=309&&y<=381)) && pauseflag){   //resume button in pause_page
            pauseflag = false;
            wflag = false;
            instflag = false;
            settingsflag = false;
            game_page();
            cout<<"resume_pause"<<endl;
        }

        else if(((x>=200&&x<=418) && (y>=315&&y<=370) || (x>=502&&x<=1068) && (y>=462&&y<=531)) && pauseflag){   //QUIT button in pause_page
            pauseflag = false;
            wflag = true;
            instflag = false;
            abtflag = false;
            welcome();
            reset();
            cout<<"quit_pause"<<endl;

        }
        cout<<x<<endl<<y<<endl;
    }
}
