#include <GL/glut.h>
void init2D(float r, float g, float b)
{
// glClearColor sets the colour to clear the
//buffer to.
glClearColor(r, g, b, 0.0);
// used to set up the view volume,
//GL_MODELVIEW can be used to set up viewing
//transformation
//glMatrixMode(GL_PROJECTION);
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
glColor3f(0.0, 0.0, 0.0);
glBegin(GL_TRIANGLES);

glVertex3f(80.0f, 130.0f, 0.0f); //130
glVertex3f(100.0f, 145.0f, 0.0f); //145
glVertex3f(100.0f, 115.0f, 0.0f); //115
glEnd();

glBegin(GL_LINES);

glVertex2f(60.0f, 130.0f); //130
glVertex2f(120.0f, 130.0f); //130
glEnd();

glBegin(GL_LINES);

glVertex2f(80.0f, 145.0f); //145
glVertex2f(80.0f, 115.0f); //115
glEnd();

/////////

glBegin(GL_TRIANGLES);
glVertex3f(80.0f, 50.0f, 0.0f);
glVertex3f(100.0f, 65.0f, 0.0f);
glVertex3f(100.0f, 35.0f, 0.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(60.0f, 50.0f);
glVertex2f(120.0f, 50.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(80.0f, 65.0f);
glVertex2f(80.0f, 35.0f);
glEnd();

/////////

glBegin(GL_TRIANGLES);
glVertex3f(50.0f, 80.0f, 0.0f);
glVertex3f(65.0f, 100.0f, 0.0f);
glVertex3f(35.0f, 100.0f, 0.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(50.0f, 120.0f);
glVertex2f(50.0f, 60.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(65.0f, 80.0f);
glVertex2f(35.0f, 80.0f);
glEnd();

///////

glBegin(GL_TRIANGLES);
glVertex3f(130.0f, 80.0f, 0.0f);
glVertex3f(145.0f, 100.0f, 0.0f);
glVertex3f(115.0f, 100.0f, 0.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(130.0f, 120.0f);
glVertex2f(130.0f, 60.0f);
glEnd();

glBegin(GL_LINES);
glVertex2f(145.0f, 80.0f);
glVertex2f(115.0f, 80.0f);
glEnd();


glFlush();
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
glutInitWindowSize(500, 500);
glutInitWindowPosition(100, 100);
glutCreateWindow("TRIANGLE");
init2D(1.0, 1.0, 1.0);
// calls the function display everytime the
//display needs to be updated
glutDisplayFunc(display);
glutMainLoop();
}
