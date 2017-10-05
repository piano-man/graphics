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

int main(int argc, char *argv[])
{
    for (int i = 0; i < 6; i++) {
        cin >> pt[i][0]; cin >> pt[i][1];
        pt[i][0] *= 1.0;
        pt[i][1] *= 1.0;
    }
    //check for convex or concave
    int sn[8];    
    for (int i = 0; i < 6; i++){
        int a = pt[(i + 1) % 6][0] - pt[i][0];
        int b = pt[(i + 1) % 6][1] - pt[i][1];
        int c = pt[(i + 2) % 6][0] - pt[(i + 1) % 6][0];
        int d = pt[(i + 2) % 6][1] - pt[(i + 1) % 6][1];
        int ca = (a * d) - (b * c);
        if (ca < 0) sn[i] = -1;
        else if (ca > 0) sn[i] = 1;
        else sn[i] = 0; 
    }
    int f = 1;
    for (int i = 1; i < 6; i++) {
        if (sn[i] != sn[i - 1]) {
            f = 0;
            break;
        }
    }
    if (f) cout << "convex\n";
    else cout << "concave\n";
    glutInit(&argc,argv);
    
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(650, 650);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Polygon");
    init2D(0.0, 0.0, 0.0);

    glutDisplayFunc(display);
    glutMainLoop();
}