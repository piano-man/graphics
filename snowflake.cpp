#include <GL/glut.h>
#include <math.h>
#include<stdio.h>
#include<stdlib.h>


GLfloat oldx=-0.7,oldy=0.5;
int num=0;
void mouse( int button, int state, int x, int y )
{
    if( button == GLUT_LEFT_BUTTON && state == GLUT_UP )
    {
        num++;
    }
    
    glutPostRedisplay();
    
}

void init2D()
{
	glMatrixMode(GL_MODELVIEW);
	gluOrtho2D(0.0, 100.0, 0, 100.0);
	glClearColor (0.0, 0.0, 0.0,0.0);
		glColor3f(0.0,0.0,0.0);
}
void drawkoch(GLfloat dir,GLfloat len,GLint iter) {
	GLdouble dirRad = 0.0174533 * dir;  
	GLfloat newX = oldx + len * cos(dirRad);
	GLfloat newY = oldy + len * sin(dirRad);
	if (iter==0) {
		glVertex2f(oldx, oldy);
		glVertex2f(newX, newY);
		oldx = newX;
		oldy = newY;
	}
	else {
		iter--;
		//draw the four parts of the side _/\_ 
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
		dir -= 120.0;
		drawkoch(dir, len, iter);
		dir += 60.0;
		drawkoch(dir, len, iter);
	}
}

void mydisplay(){
	 glClear( GL_COLOR_BUFFER_BIT );
	 glBegin(GL_LINES);
	 glColor3f(1.0, 1.0, 1.0); // make it red
	 
     int i;
     float l1=0.5;
     float l2=0.5;
     float l3=0.5;
	 
     for(i=1;i<num;i++)
     {
         l1=l1/4;
         l2=l2/4;
         l3=l3/4;
     }
     
     printf("%f",l1);
     printf("%f",l2);
     printf("%f",l3);

        drawkoch(0.0,l1,num);
	    drawkoch(-120.0, l2, num);
	    drawkoch(120.0,l3,num);
        glEnd();
	    glFlush(); 
       

     
	 /*drawkoch(0.0,0.05,3);
	 drawkoch(-120.0, 0.05, 3);
	 drawkoch(120.0,0.05,3);
	 /* 
	 glEnd();
	 glFlush();*/ 
}

int main(int argc, char** argv)
{
      
     
	glutInit(&argc,argv); 
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);      
	glutInitWindowSize(500,500);    	
	glutInitWindowPosition(0,0); 
	glutCreateWindow("Koch Snowflake - Marcus Young");     
glutMouseFunc( mouse );
	glutDisplayFunc(mydisplay);  
	glutMainLoop();
}
