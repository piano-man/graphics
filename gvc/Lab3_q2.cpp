#include <GL/glut.h>

GLfloat rtri = 10; 
void init2D(float r, float g, float b)
{
	glClearColor(r, g, b, 0.0);
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{
	glClear(GL_COLOR_BUFFER_BIT);	
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_TRIANGLES);
	glVertex3f(30.0, 185.0, 0.0f);
	glVertex3f(30.0, 135.0, 0.0f);
	glVertex3f(80.0, 185.0, 0.0f);
	//glVertex3f(80.0, 135.0, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(30.0, 135.0, 0.0f);
	glVertex3f(80.0, 185.0, 0.0f);
	glVertex3f(80.0, 135.0, 0.0f);
	glEnd();


	glColor3f(0.0, 1.0, 0.0);
	glBegin(GL_TRIANGLES);
	
	//Squares
	glVertex3f(40.0, 125.0, 0.0f);
	glVertex3f(90.0, 125.0, 0.0f);
	glVertex3f(40.0, 75.0, 0.0f);
	//glVertex3f(90.0, 75.0, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glVertex3f(90.0, 125.0, 0.0f);
	glVertex3f(40.0, 75.0, 0.0f);
	glVertex3f(90.0, 75.0, 0.0f);
	glEnd();

	glColor3f(0.5, 0.5, 0.5);
	glBegin(GL_TRIANGLES);

	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(20.0, 95.0, 0.0f);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(50.0, 95.0, 0.0f);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 65.0, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(50.0, 65.0, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(50.0, 95.0, 0.0f);
	glColor3f(0.0, 0.0, 0.0);
	glVertex3f(20.0, 65.0, 0.0f);
	glColor3f(1.0, 1.0, 1.0);
	glVertex3f(50.0, 65.0, 0.0f);
	glEnd();


	//Triangles
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 0.0f, 1.0f);  
	glVertex3f(105.0f, 80.0f, 0.0f);
	glVertex3f(130.0f, 122.0f, 0.0f);
	glVertex3f(155.0f, 80.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(0.0f, 1.0f, 0.0f);  
	glVertex3f(120.0f, 90.0f, 0.0f);
	glColor3f(1.0f, 0.0f, 0.0f);    
	glVertex3f(170.0f, 90.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f);  
	glVertex3f(145.0f, 45.0f, 1.0f);
	glEnd();

	//hexagon
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);  
	glVertex3f(120.0f, 160.0f, 0.0f);
	glVertex3f(130.0f, 180.0f, 0.0f);
	glVertex3f(130.0f, 140.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);  
	glVertex3f(150.0f, 140.0f, 0.0f);
	glVertex3f(150.0f, 180.0f, 0.0f);
	glVertex3f(160.0f, 160.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);  
	glVertex3f(150.0f, 140.0f, 0.0f);
	glVertex3f(150.0f, 180.0f, 0.0f);
	glVertex3f(130.0f, 140.0f, 0.0f);
	glEnd();
	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 1.0f, 0.0f);  
	glVertex3f(150.0f, 180.0f, 0.0f);
	glVertex3f(130.0f, 180.0f, 0.0f);
	glVertex3f(130.0f, 140.0f, 0.0f);
	glEnd();
	
	glutSwapBuffers();
}
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE |
	GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);

	glutCreateWindow("3-D");
	init2D(0.0, 0.0, 0.0);
	glutDisplayFunc(display);
	glutMainLoop();
}
