#include<bits/stdc++.h>
#include <GL/glut.h>
using namespace std;
void calc(GLfloat a[2], GLfloat b[2], GLfloat c[2],int depth,int flag)
{
	GLfloat mab[2],mac[2],mcb[2];
	int j;
	if(depth == 0){
//		glColor3f(1.0,0.0,1.0);
//		glColor3f(((float)rand())/RAND_MAX,((float)rand())/RAND_MAX,((float)rand())/RAND_MAX);
		glVertex2f(a[0],a[1]);
		glVertex2f(b[0],b[1]);
		glVertex2f(c[0],c[1]);
		return;
	}
	mab[0]=(a[0]+b[0])/2;
	mab[1]=(a[1]+b[1])/2;
	mac[0]=(a[0]+c[0])/2;
	mac[1]=(a[1]+c[1])/2;
	mcb[1]=(c[1]+b[1])/2;
	mcb[0]=(c[0]+b[0])/2;
	if(flag == 0){
		glColor3f(1.0,0.0,1.0);
		calc(a, mab, mac, depth-1,1);
//		calc(b, mcb, mab, depth-1,flag);
		glColor3f(0.75,0.5,0.75);
		calc(c, mac, mcb, depth-1,1);
//		calc(a, mab, mac, depth-1,flag);
		glColor3f(0.875,0.25,0.875);
//		calc(c, mac, mcb, depth-1,flag);
		calc(b, mcb, mab, depth-1,0);
		return;
	}
	if(depth == 9)
	glColor3f(1.0,0.0,1.0);
	calc(a, mab, mac, depth-1,flag);
	if(depth == 9)
	glColor3f(0.75,0.5,0.75);
	calc(c, mac, mcb, depth-1,flag);
	if(depth == 9) flag = 0;
	calc(b, mcb, mab, depth-1,flag);
}
void display()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	GLfloat a[2] = {0,0};
	GLfloat b[2] = {50.0,100.0};
	GLfloat c[2] = {100.0,0};
	calc(a,b,c,9,1);
	glEnd();
	glFlush();
}
void init2D()
{
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 100.0, 0, 100.0);
	glClearColor (0.0, 0.0, 0.0,0.0);
		glColor3f(0.0,0.0,0.0);
}
int main(int argc, char *argv[])
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(650, 650);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("LAB10");
	init2D();
	glutDisplayFunc(display);
	glutMainLoop();
}