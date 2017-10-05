#include <GL/glut.h>
#include <bits/stdc++.h>
using namespace std;
float pt[6][2];

void init2D(float r, float g, float b)
{
    glClearColor(r, g, b, 0.0);
    glMatrixMode(GL_MODELVIEW);
    gluOrtho2D(0.0, 200.0, 0.0, 200.0);
}
void display(void)
{    
    glClear(GL_COLOR_BUFFER_BIT);
    
    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_LINE_LOOP);
    glVertex3f(pt[0][0], pt[0][1], 0);
    glVertex3f(pt[1][0], pt[1][1], 0);
    glVertex3f(pt[2][0], pt[2][1], 0);
    glVertex3f(pt[3][0], pt[3][1], 0);
    glVertex3f(pt[4][0], pt[4][1], 0);
    glVertex3f(pt[5][0], pt[5][1], 0);
    
    glEnd();
    glutSwapBuffers();
}
double perpDot( float x1,float y1,float x2,float y2 )
{
    return (x1 * y2) - (y1 * x2);
}
int main(int argc, char *argv[])
{
    for (int i = 0; i < 6; i++) {
        cin >> pt[i][0]; cin >> pt[i][1];
        pt[i][0] *= 1.0;
        pt[i][1] *= 1.0;
    }
    
int i;
    for( i=0;i<6;i++)
    {
        int p1;
        int p2;
        int p3;
        
        p1=i;

        p2=(i+1)%6;
        p3=(i+2)%6;
        cout << p1;
        cout << p2;
        cout << p3;
        float val = perpDot(pt[p2][0]-pt[p1][0],pt[p2][1]-pt[p1][1],pt[p3][0]-pt[p2][0],pt[p3][1]-pt[p2][1]);
        cout << val;
        if(val<0){
            
            cout << "concave";
            break;
        }
        

    }
    if(i==6){
        cout << "convex";
    }
  

    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon");
    init2D(0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutMainLoop();
}