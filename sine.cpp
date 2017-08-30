#include <iostream>
#include <cmath>
#include <GL/glut.h>
using namespace std;

#define SIZE 700
#define PI 3.14159265
void sinegraph();

void drawline(float x1, float y1, float x2, float y2);


int main(int argc, char ** argv)
{
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
  glutInitWindowSize(700,500);
  glutInitWindowPosition(650,100);

sinegraph();

  glutMainLoop();

  return 0;
}

void sinegraph()
{
  float x1, x2, x3, y1, y2;
  char again;

  do
  {
    cout<<"Enter period(number of cycles) you want : ";
    cin>>x3;
    for (int i=-700;i<SIZE;i++)
    {
      x1=((float)i/SIZE);
      x2=(((float)(i+1))/SIZE);
      y1=sin(x1*x3*PI);
      y2=sin(x2*x3*PI);
      drawline(x1,y1,x2,y2);
    }
    glutSwapBuffers();
    cout<<"Do you want to continue to draw? (Y/N) ";
    cin>>again;
  }while(again=='Y' & again=='y');

}

void drawline(float x1, float y1, float x2, float y2)
{
  //x-axis
  glBegin(GL_LINES);
  glColor3f(1.0, 0, 0);
  glVertex2f(-10.0f, 0.0f);
  glVertex2f(10.0f, 0.0f);
  glEnd();

  //y-axis
  glBegin(GL_LINES);
  glColor3f(1.0, 0, 0);
  glVertex2f(0.0f, -10.0f);
  glVertex2f(0.0f, 10.0f);
  glEnd();

  //curve
  glBegin(GL_LINE_STRIP);
  glColor3f(1.0,1.0,1.0);
  glVertex2f(x1,y1);
  glVertex2f(x2,y2);
  glEnd();
}
