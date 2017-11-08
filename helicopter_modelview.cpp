#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;

void init2D(float r , float g , float b){
	glClearColor(r,g,b,0.0);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(-400.0,400.0,-400.0,400.0);
}


/*void reshape(int width, int height) {
  glViewport(0, 0, width, height);
  glMatrixMode(GL_PROJECTION);
  glLoadIdentity();
  gluOrtho2D(0, 1, 0, 1);
}*/

GLfloat randomFloat() {
    return (GLfloat)rand() / RAND_MAX;
}

void drawHelicopter()
{
    glBegin(GL_LINE_LOOP);
    //glRasterPos3f(randomFloat(), randomFloat(), 0.0);
    glColor3f(randomFloat(), randomFloat(), randomFloat());
	int a = 4;
	int b = 2;
    for(int i=0;i<360;i++)
    {
       float rad = i * (3.14159/180.0);
       glVertex2f ( cos ( rad ) * 200, sin ( rad ) * 100 );
       //cout<<cos(rad)*200<<","<<sin(rad)*100<<endl;
    }
    glEnd();

    glBegin(GL_LINE_LOOP);
    
    glVertex2f(200.0,0.0);
    glVertex2f(300.0,100.0);
    glVertex2f(300.0,-100.0);    
    
    glEnd();
        glBegin(GL_LINE_LOOP);
    
    glVertex2f(0.0,0.0);
    glVertex2f(-150.0,200.0);
    glVertex2f(150.0,200.0);    
    
    glEnd();
        glBegin(GL_LINE_LOOP);
    
    glVertex2f(0.0,0.0);
    glVertex2f(150.0,-200.0);
    glVertex2f(-150.0,-200.0);    
    
    glEnd();  

}

void display() {
	
    glClear(GL_COLOR_BUFFER_BIT);

  for (int i = 0; i < 20; i++) {
        glViewport(randomFloat()*650, randomFloat()*650, 40, 40);
        drawHelicopter();
   }

    glFlush();
}

int main(int argc , char *argv[]){
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650,650);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Helicopter");
	init2D(0.0 , 0.0 , 0.0);
	glutDisplayFunc(display);
	glutMainLoop();  	
}