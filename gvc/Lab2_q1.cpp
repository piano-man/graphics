#include <GL/glut.h>

GLfloat rtri = 90;
void init2D(float r, float g, float b)
{

	glClearColor(r, g, b, 0.0);

	glMatrixMode(GL_MODELVIEW);

	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{


	
	glClear(GL_COLOR_BUFFER_BIT);
	

	glColor3f(0.0, 1.0, 1.0);

	for(int i = 1;i <= 2;i++){
		glBegin(GL_TRIANGLES);
		glVertex3f(85.0f, 157.32f, 0.0f);
		glVertex3f(115.0f, 174.64f, 0.0f);
		glVertex3f(115.0f, 140.0, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(55.0, 157.32, 0.0f);
		glVertex3f(145.0, 157.32, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(85.0, 140.0, 0.0f);
		glVertex3f(85.0, 174.64, 0.0f);
		glEnd();

		glBegin(GL_TRIANGLES);
		glVertex3f(85.0f, 42.68f, 0.0f);
		glVertex3f(115.0f, 25.36f, 0.0f);
		glVertex3f(115.0f, 60.0f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(55.0, 42.68f, 0.0f);
		glVertex3f(145.0, 42.68f, 0.0f);
		glEnd();

		glBegin(GL_LINES);
		glVertex3f(85.0f, 60.0f, 0.0f);
		glVertex3f(85.0f, 25.36, 0.0f);
		glEnd();

		if(i==1){
			glTranslatef(100.0f, 100.0f, 0.0f);
			glRotatef(rtri,0.0f,0.0f, -1.0f);
			glTranslatef(-100.0f, -100.0f, 0.0f);
		}
		glutSwapBuffers();
	}
	
	
}

int main(int argc, char *argv[])
{

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE |
	GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Transistors");
	init2D(0.0, 0.0, 0.0);

	glutDisplayFunc(display);
	glutMainLoop();
}