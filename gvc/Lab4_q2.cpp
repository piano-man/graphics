#include <GL/glut.h>

GLfloat rtri = 15; 
GLfloat line_angle = 45;

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

	
	for(int i = 1;i <= 24;i++)
	{
		float x, y;
		if(i%2 == 1){
			x = 1.0f;
			y = 0.0f;
		}
		else{
			x = 0.0f;
			y = 1.0f;
		}
		glBegin(GL_TRIANGLES);
		// co-ordinates of all four vertices of the
		//sqaure
		glColor3f(x, 0.0, y);
		glVertex3f(100.0f, 50.0f, 0.0f);
		//glVertex3f(1.65f, 62.5f, 0.0f);
		 glColor3f(x, 0.0f, y);
		glVertex3f(113.0f, 51.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);
		//glColor3f(1.0f, 0.0f, 0.0f);
		//rtri+=10.0f;
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 85.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 65.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(108.75f, 65.7f, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(100.0f, 85.0f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(103.75f, 85.3f, 0.0f);
		glColor3f(0.0f, 0.0f, 0.0f);
		glVertex3f(108.75f, 65.7f, 0.0f);
		glEnd();

		glTranslatef(100.0f, 100.0f, 0.0f);
		glRotatef(rtri,0.0f,0.0f, -1.0f);
		glTranslatef(-100.0f, -100.0f, 0.0f);
		
	}

	for(int j = 1; j <= 8; j++){
		glBegin(GL_LINES);
		//glColor3f(0.85f, 0.85f, 1.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);
		//glColor3f(0.85f, 0.85f, 1.0f);
		glVertex3f(100.0f, 85.0f, 0.0f);
		glEnd();
		glTranslatef(100.0f, 100.0f, 0.0f);
		glRotatef(line_angle,0.0f,0.0f, -1.0f);
		glTranslatef(-100.0f, -100.0f, 0.0f);
	}
	// glBegin(GL_LINES);
	// // glVertext2i takes integer as arguments,
	// //we also have other versions for float and double
	// //glVertext2f, glVertext2d
	// glVertex3f(100.0, 100.0, 0.0f);
	// glVertex3f(100.0, 10.0, 0.0f);
	// glEnd();

	// glColor3f(0.0, 1.0, 0.0);
	// glBegin(GL_TRIANGLES);
	// // glVertext2i takes integer as arguments,
	// //we also have other versions for float and double
	// //glVertext2f, glVertext2d
	// glVertex3f(97.0f, 10.0f, 0.0f);
	// glVertex3f(103.0f, 10.0f, 0.0f);
	// glVertex3f(100.0f, 6.45f, 0.0f);
	// glEnd();
	
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

	glutCreateWindow("roulette wheel");
	init2D(0.0, 0.0, 0.0);

	// calls the function display everytime the
	//display needs to be updated
	glutDisplayFunc(display);
	glutMainLoop();
}