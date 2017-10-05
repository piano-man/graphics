#include<GL/glut.h>
#include<stdlib.h>
#include<math.h>

const int screenWidth=640;
const int screenHeight=480;


void myInit()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glColor3f(1.0,0.0,0.0);
	glPointSize(3.0);
	//glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	//gluOrtho2D(0.0,(GLdouble)screenWidth,0.0,(GLdouble)screenHeight);

}

//set window
void setWindow(float left,float right,float bottom,float top)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(left,right,bottom,top);
}

//set view port
void setViewport(int left,int right,int bottom,int top)
{
	glViewport(left,right,bottom,top);
}

void myDisplay()
{
	GLfloat x=0;
	glClear(GL_COLOR_BUFFER_BIT);
	setWindow(-10.0,10.0,-1.0,2.0);
	//setViewport(640,0,480,0);
	glBegin(GL_LINE_STRIP);
	for(x=-10.0;x<=10.0;x+=0.25)
	{
		if(x == 0)
			glVertex2f(0,1);
		else
			glVertex2f(x,sin(3.1415*x)/(3.1415*x));
	}
	glEnd();


	glColor3f(1.0,1.0,1.0);
	glBegin(GL_LINE_STRIP);
	glVertex2i(320,480);
	glVertex2i(320,0);
	glEnd();

	glFlush();
}

int main(int argc, char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(640,480);
	glutCreateWindow("sinc function = sin(PI*X)/PI*X");
	glutDisplayFunc(myDisplay);

	myInit();

	glutMainLoop();