#include <GL/glut.h>

GLfloat rtri = 10; 
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
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
	// clear the buffers currently enabled for
	//color writing.

	
	glClear(GL_COLOR_BUFFER_BIT);

	
	for(int i = 1;i <= 36;i++)
	{
		glBegin(GL_LINE_LOOP);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(0.0, 1.0, 0.0);
		glVertex3f(100.0f, 75.0f, 0.0f);
		glVertex3f(121.65f, 62.5f, 0.0f);
		glVertex3f(121.65f, 87.5f, 0.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);
		//rtri+=10.0f;
		glEnd();
		glTranslatef(100.0f, 100.0f, 0.0f);
		glRotatef(rtri,0.0f,0.0f, -1.0f);
		glTranslatef(-100.0f, -100.0f, 0.0f);
		
		
	}
	glBegin(GL_LINES);
	// glVertext2i takes integer as arguments,
	//we also have other versions for float and double
	//glVertext2f, glVertext2d
	glVertex3f(100.0, 100.0, 0.0f);
	glVertex3f(100.0, 10.0, 0.0f);
	glEnd();

	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	// glVertext2i takes integer as arguments,
	//we also have other versions for float and double
	//glVertext2f, glVertext2d
	glVertex3f(97.0f, 10.0f, 0.0f);
	glVertex3f(103.0f, 10.0f, 0.0f);
	glVertex3f(100.0f, 6.45f, 0.0f);
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

	glutCreateWindow("Flower");
	init2D(0.0, 0.0, 0.0);

	// calls the function display everytime the
	//display needs to be updated
	glutDisplayFunc(display);
	glutMainLoop();
}