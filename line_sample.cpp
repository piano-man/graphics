#include <GL/glut.h>
void init2D(float r, float g, float b)
{
	// glClearColor sets the colour to clear the
	//buffer to.
	glClearColor(r, g, b, 0.0);

	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
	// clear the buffers currently enabled for
	//color writing.
		glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_LINES);

	glVertex2i(0, 0);
	glVertex2i(1366, 768);
	glEnd();
	glFlush();
}
int main(int argc, char *argv[])
{

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE |
			GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("line drawing in opengl");
	init2D(0.0, 0.0, 0.0);

	glutDisplayFunc(display);
	glutMainLoop();
	return 0;
}
