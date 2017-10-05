#include <GL/glut.h>

GLfloat rtri = 15; 
GLfloat line_angle = 45;

void init2D(float r, float g, float b)
{

	glClearColor(r, g, b, 0.0);

	glMatrixMode(GL_PROJECTION);
	



	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
	

	
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

		glColor3f(x, 0.0, y);
		glVertex3f(100.0f, 50.0f, 0.0f);
		//glVertex3f(1.65f, 62.5f, 0.0f);
		 glColor3f(x, 0.0f, y);
		glVertex3f(113.0f, 51.5f, 0.0f);
		glColor3f(0.0f, 1.0f, 0.0f);
		glVertex3f(100.0f, 100.0f, 0.0f);

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

	glutSwapBuffers();
	//glutPostRedisplay();
}
int main(int argc, char *argv[])
{

	glutInit(&argc,argv);

	glutInitDisplayMode(GLUT_SINGLE |
	GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("roulette wheel");
	init2D(0.0, 0.0, 0.0);


	glutDisplayFunc(display);
	glutMainLoop();
}