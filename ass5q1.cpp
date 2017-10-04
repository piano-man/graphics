#include <GL/glut.h>

GLfloat rtri = 45; 
void init2D(float r, float g, float b)
{
	// glClearColor sets the colour to clear the
	//buffer to.
	glClearColor(r, g, b, 0.0);
	// used to set up the view volume,
	//GL_MODELVIEW can be used to set up viewing
	//transformation
	glMatrixMode(GL_PROJECTION);
	//Specifies which matrix stack is the target for subsequent matrix operations.
	//Three values are accepted: GL_MODELVIEW, GL_PROJECTION, and GL_TEXTURE. The initial value is GL_MODELVIEW. Additionally, if the ARB_imaging extension is supported, GL_COLOR is also accepted.


	//glMatrixMode(GL_MODELVIEW);
	// gluOrtho2D specifies the coordinates to
	//be used with the viewport which defaults to the
	//window size.
	gluOrtho2D(-70.0, 70.0, -70.0, 70.0);
}
void display(void)
{
	// clear the buffers currently enabled for
	//color writing.

	
	glClear(GL_COLOR_BUFFER_BIT);

	float x1, y1, x2, y2, x3, y3, x4, y4;
	x1 = -5.0f;
	y1 = -5.0f;
	x2 = -35.0f;
	y2 = -5.0f;
	x3 = -35.0f;
	y3 = -35.0f;
	x4 = -5.0f;
	y4 = -35.0f;	
	//for(int i = 1;i <= 3;i++)
	//{
		glBegin(GL_LINE_LOOP);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x3, y3, 0.0f);
		glVertex3f(x4, y4, 0.0f);
		glEnd();
		
		//rtri+=10.0f;

		y1 *= -1;
		y2 *= -1;
		y3 *= -1;
		y4 *= -1;

		glBegin(GL_LINE_LOOP);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x3, y3, 0.0f);
		glVertex3f(x4, y4, 0.0f);
		glEnd();

		
		// glTranslatef(-20.0f, 20.0f, 0.0f);
		// glRotatef(rtri,0.0f,0.0f, -1.0f);
		// glTranslatef(-20.0f, 20.0f, 0.0f);

		x1 = -20.0f;
		y1 = 41.21f;
		x2 = 1.21f;
		y2 = 20.0f;
		x3 = -20.0f;
		y3 = 1.21f;
		x4 = -41.21f;
		y4 = 20.0f;
		glBegin(GL_LINE_LOOP);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x3, y3, 0.0f);
		glVertex3f(x4, y4, 0.0f);
		glEnd();
		
		x1 = x1 + 2*y1;
		x2 = x2 + 2*y2;
		x3 = x3 + 2*y3;
		x4 = x4 + 2*y4;

		glBegin(GL_LINE_LOOP);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(x1, y1, 0.0f);
		glVertex3f(x2, y2, 0.0f);
		glVertex3f(x3, y3, 0.0f);
		glVertex3f(x4, y4, 0.0f);
		glEnd();
		

	//glFlush();
	glutSwapBuffers();
	//glutPostRedisplay();
}
int main(int argc, char *argv[])
{
	// glutInit will initialize the GLUT library and
	//negotiate a session with the window system.
	glutInit(&argc,argv);
	// Select a display mode with single buffer
	//because its a simple application and Red, green,
	//blue framebuffer
	glutInitDisplayMode(GLUT_SINGLE |
	GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("Squares");
	init2D(0.0, 0.0, 0.0);

	// calls the function display everytime the
	//display needs to be updated
	glutDisplayFunc(display);
	glutMainLoop();
}