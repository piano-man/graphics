#include<bits/stdc++.h>
#include<GL/glut.h>
#include<ctime>
void init2D(float r , float g , float b){
        glClearColor(r,g,b,1.0);
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        gluOrtho2D(-150.0,150.0,-150.0,150.0);
}

void display(){
	glClear(GL_COLOR_BUFFER_BIT);
	for(int i = 0; i < 50; i++){
	float xtr = rand()%300 - 150;
	float ytr = rand()%300 - 150;
	
	glTranslatef(xtr,ytr,0);
	glColor3f(rand()/((float)RAND_MAX),rand()/((float)RAND_MAX),rand()/((float)RAND_MAX));
	glBegin(GL_LINE_LOOP);
	int a = 4;
	int b = 2;
        for(int i=0;i<360;i++){
		float theta = i*(3.14/180);
		float r = ((a*b)/(sqrt(pow(b,2)*pow(cos(theta),2) + pow(a,2)*pow(sin(theta),2))));
        	glVertex3f(r*cos(theta),r*sin(theta),0);
	}
        glEnd();
	glBegin(GL_LINE_LOOP);
	glVertex3f(4,0,0);
	glVertex3f(8,2,0);
	glVertex3f(8,-2,0);
	glEnd();
	glBegin(GL_LINE_LOOP);
        glVertex3f(0,0,0);
        glVertex3f(-2,4,0);
        glVertex3f(2,4,0);
        glEnd();

	glBegin(GL_LINE_LOOP);
        glVertex3f(0,0,0);
        glVertex3f(-2,-4,0);
        glVertex3f(2,-4,0);
        glEnd();

	glTranslatef(-xtr,-ytr,0);
	}
	glFlush();

}


int main(int argc , char *argv[]){

	srand((unsigned)time(0));
	glutInit(&argc,argv);
        glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
        glutInitWindowSize(800,800);
        glutInitWindowPosition(100,100);
        glutCreateWindow("Oval");
        init2D(0.0 , 0.0 , 0.0);
        glutDisplayFunc(display);
        glutMainLoop();
}  
