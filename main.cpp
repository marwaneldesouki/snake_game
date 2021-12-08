#include <GL/gl.h>
#include <GL/glut.h>

void init(){
glClearColor(0.0,0.0,0.0,1.0); //background_color

}

void display(){
glClear(GL_COLOR_BUFFER_BIT); //clear buffer to new background color
glutSwapBuffers();
}

void reshape_callback(int w,int h){ //some options in size of window
glViewport(0,0,(GLsizei)w,(GLsizei)h);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
glOrtho(0.0,40.0,0.0,40.0,-1.0,1.0);
glMatrixMode(GL_MODELVIEW);
}
int main(int argc,char **argv){

glutInit(&argc,argv); //just initiate
glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //display_mode
glutInitWindowPosition(500,500); //height_width
glutCreateWindow("Snake Game"); //window_title
glutDisplayFunc(display); //display
glutReshapeFunc(reshape_callback); //reshape window to max,min
init();
glutMainLoop();
return 0;


}
