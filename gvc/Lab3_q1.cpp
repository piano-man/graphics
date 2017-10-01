#include <GL/glut.h> 
void initGL() {
glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}
void display() {
glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
glMatrixMode(GL_MODELVIEW); 
glLoadIdentity();                
glTranslatef(1.5f, 0.0f, -7.0f);  

glBegin(GL_QUADS);    
	  //top
	  glColor3f(0.0f, 1.0f, 0.0f);     // Green
      glVertex3f( 1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f, -1.0f);
      glVertex3f(-1.0f, 1.0f,  1.0f);
      glVertex3f( 1.0f, 1.0f,  1.0f);
 
      //Bottom face (y = -1.0f)
      glColor3f(1.0f, 0.5f, 0.0f);     // Orange
      glVertex3f( 1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f( 1.0f, -1.0f, -1.0f);
 
      // Front face  (z = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Red
      glVertex3f( 1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f,  1.0f, 1.0f);
      glVertex3f(-1.0f, -1.0f, 1.0f);
      glVertex3f( 1.0f, -1.0f, 1.0f);
 
      // Back face (z = -1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Yellow
      glVertex3f( 1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f( 1.0f,  1.0f, -1.0f);
 
      // Left face (x = -1.0f)
      glColor3f(0.0f, 0.0f, 1.0f);     // Blue
      glVertex3f(-1.0f,  1.0f,  1.0f);
      glVertex3f(-1.0f,  1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f, -1.0f);
      glVertex3f(-1.0f, -1.0f,  1.0f);
 
      // Right face (x = 1.0f)
      glColor3f(1.0f, 0.0f, 0.0f);     // Magenta
      glVertex3f(1.0f,  1.0f, -1.0f);
      glVertex3f(1.0f,  1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f,  1.0f);
      glVertex3f(1.0f, -1.0f, -1.0f);
glEnd();

glLoadIdentity();
glTranslatef(-1.5f, 0.0f, -6.0f);

glBegin(GL_TRIANGLES);

glColor3f(1.0f, 0.0f, 0.0f);    
glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.0f);     
glVertex3f(-1.0f, -1.0f, 1.0f);
glColor3f(0.0f, 0.0f, 1.0f);    
glVertex3f(1.0f, -1.0f, 1.0f);

glColor3f(1.0f, 0.0f, 0.0f);     
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 0.0f, 1.0f);    
glVertex3f(1.0f, -1.0f, 1.0f);
glColor3f(0.0f, 1.0f, 0.0f);     
glVertex3f(1.0f, -1.0f, -1.0f);

glColor3f(1.0f, 0.0f, 0.0f);     
glVertex3f(0.0f, 1.0f, 0.0f);
glColor3f(0.0f, 1.0f, 0.0f);     
glVertex3f(1.0f, -1.0f, -1.0f);
glColor3f(0.0f, 0.0f, 1.0f);    
glVertex3f(-1.0f, -1.0f, -1.0f);

glColor3f(1.0f,0.0f,0.0f);     
glVertex3f( 0.0f, 1.0f, 0.0f);
glColor3f(0.0f,0.0f,1.0f);      
glVertex3f(-1.0f,-1.0f,-1.0f);
glColor3f(0.0f,1.0f,0.0f);       
glVertex3f(-1.0f,-1.0f, 1.0f);
glEnd();   
glutSwapBuffers();  
}
 

void reshape(GLsizei width, GLsizei height) { 
if (height == 0) height = 1;               
GLfloat aspect = (GLfloat)width / (GLfloat)height;
glViewport(0, 0, width, height);
glMatrixMode(GL_PROJECTION);  
glLoadIdentity();             
gluPerspective(45.0f, aspect, 0.1f, 100.0f);
}

int main(int argc, char** argv) {
glutInit(&argc, argv);            
glutInitDisplayMode(GLUT_DOUBLE); 
glutInitWindowSize(640, 480);  
glutInitWindowPosition(50, 50);
glutCreateWindow("3-D Shapes");  
glutDisplayFunc(display);   
glutReshapeFunc(reshape);  
initGL();                     
glutMainLoop();   
return 0;
}



