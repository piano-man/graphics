#include<GL/glut.h>
#include<stdlib.h>
#include<cmath>
const int screenWidth=640;
const int screenHeight=480;

GLdouble a=0,b=0,c=0,d=0;

void myInit()
{
	glClearColor(1.0,1.0,1.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(3.0);
	//glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-(GLdouble)screenWidth,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);
	a=100;
	b=0.0;
	c=d=100;

}

void myDisplay()
{
	GLdouble i=0;
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_POINTS);
	for(i=-3.5;i<0;i+=0.005)
	{
		GLdouble func=exp(i)*cos(2*3.14159*i);
		glVertex2i(a*i+b,c*func+d);
	}

	for(i=0;i<3.5;i+=0.005)
	{
		GLdouble func=exp(-i)*cos(2*3.14159*i);
		glVertex2i(a*i+b,c*func+d);
	}
	glEnd();

	glFlush();
}





int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("exponential plot");
	glutDisplayFunc(myDisplay);

	myInit();

	glutMainLoop();
}
