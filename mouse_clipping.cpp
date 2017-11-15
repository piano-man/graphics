#include<GL/glut.h>
#include<stdio.h>
#include<math.h>
#include<bits/stdc++.h>

using namespace std;

float r1 = 0.556863; 
float g1  = 0.137255;
float b1  = 0.419608;
int n,n1=6;
int X[100],Y[100];
int X1[100],Y1[100];
int s = 0;
int r = 0;
int q = 0;
const int MAX_POINTS = 100;
int poly_size;
int privar;
int poly_points[100][2]; 
int clipper_size;
int clipper_points[100][2]; 

void init()
{
	glClearColor(0.0,0.0,0.0,0.0);
	glMatrixMode(GL_PROJECTION);
	//glLoadIdentity();
	gluOrtho2D(0,500,0,500);
}
int round1(double number)
{
	return (number>=0) ? (int)(number+0.5):(int)(number-0.5);
}
void setPixel(GLint x,GLint y)
{
	//glColor3f(0,1,1);
	glBegin(GL_POINTS);
	glVertex2f(x,y);
	glEnd();
}
void LineWithDDA(int x0,int y0,int x1,int y1)
{
	int dy=y1-y0;
	int dx=x1-x0;
	int steps,i;
	float xinc,yinc,x=x0,y=y0;
	if(abs(dx)>abs(dy))
	{
		steps=abs(dx);
	}
	else
	{
		steps=abs(dy);
	}
	xinc=(float)dx/(float)steps;
	yinc=(float)dy/(float)steps;
	setPixel(round1(x),round1(y));
	for(i=0;i<steps;i++)
	{
		x+=xinc;
		y+=yinc;
		setPixel(round1(x),round1(y));
	}
	glutSwapBuffers();
}
int k=1,k1=1;

int x_intersect(int x1, int y1, int x2, int y2,
		int x3, int y3, int x4, int y4)
{
	int num = (x1*y2 - y1*x2) * (x3-x4) -
		(x1-x2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}
int y_intersect(int x1, int y1, int x2, int y2,
		int x3, int y3, int x4, int y4)
{
	int num = (x1*y2 - y1*x2) * (y3-y4) -
		(y1-y2) * (x3*y4 - y3*x4);
	int den = (x1-x2) * (y3-y4) - (y1-y2) * (x3-x4);
	return num/den;
}

void clip(int poly_points[][2], int &poly_size,
		int x1, int y1, int x2, int y2)
{
	int new_points[MAX_POINTS][2], new_poly_size = 0;

	// (ix,iy),(kx,ky) are the co-ordinate values of
	// the points
	for (int i = 0; i < poly_size; i++)
	{
		// i and k form a line in polygon
		int j = (i+1) % poly_size;
		int ix = poly_points[i][0], iy = poly_points[i][1];
		int kx = poly_points[j][0], ky = poly_points[j][1];

		// Calculating position of first point
		// w.r.t. clipper line
		int i_pos = (x2-x1) * (iy-y1) - (y2-y1) * (ix-x1);

		// Calculating position of second point
		// w.r.t. clipper line
		int k_pos = (x2-x1) * (ky-y1) - (y2-y1) * (kx-x1);

		// Case 1 : When both points are inside
		if (i_pos < 0  && k_pos < 0)
		{
			//Only second point is added
			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}

		// Case 2: When only first point is outside
		else if (i_pos >= 0  && k_pos < 0)
		{
			// Point of intersection with edge
			// and the second point is added
			new_points[new_poly_size][0] = x_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;

			new_points[new_poly_size][0] = kx;
			new_points[new_poly_size][1] = ky;
			new_poly_size++;
		}

		// Case 3: When only second point is outside
		else if (i_pos < 0  && k_pos >= 0)
		{
			//Only point of intersection with edge is added
			new_points[new_poly_size][0] = x_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
			new_points[new_poly_size][1] = y_intersect(x1,
					y1, x2, y2, ix, iy, kx, ky);
			new_poly_size++;
		}

		// Case 4: When both points are outside
		else
		{
			//No points are added
		}
	}

	// Copying new points into original array
	// and changing the no. of vertices
	poly_size = new_poly_size;
	for (int i = 0; i < poly_size; i++)
	{
		poly_points[i][0] = new_points[i][0];
		poly_points[i][1] = new_points[i][1];
	}
}

void suthHodgClip(int poly_points[][2], int poly_size,
		int clipper_points[][2], int clipper_size)
{
	if(s==1) return;
	//i and k are two consecutive indexes
	for (int i=0; i<clipper_size; i++)
	{
		int j = (i+1) % clipper_size;

		// We pass the current array of vertices, it's size
		// and the end points of the selected clipper line
		clip(poly_points, poly_size, clipper_points[i][0],
				clipper_points[i][1], clipper_points[j][0],
				clipper_points[j][1]);
	}
	privar = poly_size; 
	// Printing vertices of clipped polygon
	for (int i = 1;i<n1;i++) {
		glColor3f(r1,g1,b1);
		LineWithDDA(X1[i],Y1[i],X1[i+1],Y1[i+1]);
	}
	glColor3f(r1,g1,b1);
	LineWithDDA(X1[1],Y1[1],X1[n1],Y1[n1]);
	for (int i=1; i < poly_size; i++) {
		glColor3f(1.0,1.0,0.0);
		LineWithDDA(poly_points[i-1][0],poly_points[i-1][1],poly_points[i][0],poly_points[i][1]);
		cout << poly_points[i-1][0] << " " <<  poly_points[i-1][1] << endl;

	}
	cout << poly_points[poly_size-1][0] << " " <<  poly_points[poly_size-1][1] << endl;
	glColor3f(1.0,1.0,0.0);
	LineWithDDA(poly_points[poly_size-1][0],poly_points[poly_size-1][1],poly_points[0][0],poly_points[0][1]);
	s++;
}
void Display()
{
	glClearColor(0,0,0,0);
	glClear(GL_COLOR_BUFFER_BIT);
	//LineWithDDA(0,0,50,50);
	glFlush();
}

void mouseClick(int button, int state, int x, int y)
{

	switch(button)
	{
		int xin, yin;
		case GLUT_LEFT_BUTTON:
		if (state == GLUT_DOWN)
		{   
			X[k]=x;
			Y[k]=500-y; //i did this to match the glut coordinate to window coordinate :)
			//LineWithDDA(0,0,x,y);
			if(k==n+1)
			{
				glColor3f(1.0,1.0,0.0);
				LineWithDDA(X[k-1],Y[k-1],X[1],Y[1]);
			}
			else if(k%2==0 && k<n+1)
			{
				glColor3f(1.0,1.0,0.0);
				LineWithDDA(X[k-1],Y[k-1],X[k],Y[k]);
			}
			else if(k>1 && k%2!=0 && k<n+1)
			{
				glColor3f(1.0,1.0,0.0);
				LineWithDDA(X[k-1],Y[k-1],X[k],Y[k]);
			}

			glutSwapBuffers();
			k++; 
		}
		break;
		case GLUT_RIGHT_BUTTON:
		if (state == GLUT_DOWN)
		{   
			X1[k1]=x;
			Y1[k1]=500-y; //i did this to match the glut coordinate to window coordinate :)
			//LineWithDDA(0,0,x,y);
			if(k1==n1+1)
			{
				glColor3f(r1,g1,b1);
				LineWithDDA(X1[k1-1],Y1[k1-1],X1[1],Y1[1]);
			}
			else if(k1%2==0&&k1<n1+1)
			{
				glColor3f(r1,g1,b1);
				LineWithDDA(X1[k1-1],Y1[k1-1],X1[k1],Y1[k1]);
			}
			else if(k1>1 && k1%2!=0&&k1<n1+1)
			{
				glColor3f(r1,g1,b1);
				LineWithDDA(X1[k1-1],Y1[k1-1],X1[k1],Y1[k1]);
			}

			glutSwapBuffers();
			k1++; 
		}
		break;
	}

	if(k>n+1 && k1 >n1+2 && r == 0) {
		int j = 1;
		for(int i=0;i<n;i++) {
			poly_points[i][0] = X[j];
			poly_points[i][1] = Y[j++];
		}
		j=1;
		for(int i=0;i<n1;i++) {
			clipper_points[i][0] = X1[j];
			clipper_points[i][1] = Y1[j++];
		}

		/*for(int i=2;i<=n;i++) {
		  glBegin(GL_LINES);
		  glColor3f(0.0f, 0.0f, 0.0f);
		  glVertex3f(X[i-1], Y[i-1], 0.0f);
		  glVertex3f(X[i], Y[i], 0.0f);
		  glEnd();
		  }
		  glBegin(GL_LINES);
		  glColor3f(0.0f, 0.0f, 0.0f);
		  glVertex3f(X[n], Y[n], 0.0f);
		  glVertex3f(X[1], Y[1], 0.0f);
		  glEnd();*/

		glBegin(GL_POLYGON); 
		glColor3f(0.0f, 0.0f, 0.0f); 
		glVertex3f(0.0, 500.0, 0.0); 
		glVertex3f(500.0, 500.0, 0.0); 
		glVertex3f(500.0, 0.0, 0.0); 
		glVertex3f(0.0, 0.0, 0.0); 
		glEnd(); 
		r++;
		suthHodgClip(poly_points, poly_size, clipper_points,
				clipper_size);
	}
	fflush(stdout);                         // Force output to stdout
	//glFlush();
	//}
	//k++;
	}
void fun()
{
	glColor3f(1.0,1.0,0.0);
	/*glBegin(GL_LINE_LOOP);
	  for(int i=0;i<clipper_size;i++)
	  {
	  glVertex2d(clipper_points[i][0],clipper_points[i][1]);
	  }
	  glEnd();*/

	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<poly_size;i++)
	{
		glVertex2d(poly_points[i][0],poly_points[i][1]);
	}
	glEnd();

	glFlush();
}
void triangle()
{
	glColor3f(1.0,1.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<clipper_size;i++)
	{
		glVertex2d(clipper_points[i][0],clipper_points[i][1]);
	}
	glEnd();
	glColor3f(1.0,0.0,0.0);
	glBegin(GL_LINE_LOOP);
	for(int i=0;i<privar;i++)
	{
		glVertex2d(poly_points[i][0],poly_points[i][1]);
	}
	glEnd();

	glFlush();
}
int main(int argc,char** argv)
{
	printf("Enter no. of points : ");
	scanf("%d",&n);
	printf("Enter no. of points : ");
	scanf("%d",&n1);
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(50,50);

	glutInitWindowSize(500,500);

	glutCreateWindow("Clipping.");

	init();
	
	
	glutDisplayFunc(Display);
	if(q==0) {
		glBegin(GL_POLYGON); 
		glColor3f(0.0f, 0.0f, 0.0f); 
		glVertex3f(0.0, 500.0, 0.0); 
		glVertex3f(500.0, 500.0, 0.0); 
		glVertex3f(500.0, 0.0, 0.0); 
		glVertex3f(0.0, 0.0, 0.0); 
		glEnd(); 
		q++;
	}
	glutMouseFunc(mouseClick);
	poly_size = n;
	clipper_size = n1;
	glutDisplayFunc(fun);
	glutDisplayFunc(triangle);

	glutMainLoop();


	return 0;
}