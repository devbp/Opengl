     
 
// ----------------------------------------------------------
// Includes
// ----------------------------------------------------------
#include <stdio.h>
#include <stdarg.h>
#include <math.h>
#define KEY_ESC 27
#define KEY_X 120
#define KEY_Y 121
#define KEY_Z 122
#define GL_GLEXT_PROTOTYPES
#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif
 
// ----------------------------------------------------------
// Function Prototypes
// ----------------------------------------------------------
void display();
void specialKeys();
 
// ----------------------------------------------------------
// Global Variables
// ----------------------------------------------------------
double rotate_y=0; 
double rotate_x=0;
double rotate_z=0;
double translate_x=0;
double translate_y=0;
double translate_z=-5;
double scale_x=1;
double scale_y=1;
double scale_z=1;
 
// ----------------------------------------------------------
// display() Callback function
// ----------------------------------------------------------

void rotate()
{
// Rotate when user changes rotate_x and rotate_y
  glRotatef( rotate_x, 1.0, 0.0, 0.0 );
  glRotatef( rotate_y, 0.0, 1.0, 0.0 );
  glRotatef(rotate_z, 0.0,0.0,1.0); 
  // Other Transformations


}



void translate()
{
// Other Transformations
   
   glTranslatef( translate_x, 0.0, 0.0 );      // Not included
   glTranslatef(0.0,translate_y,0.0);
   glTranslatef(0.0,0.0,translate_z);
  // glRotatef( 180, 0.0, 1.0, 0.0 );    // Not included
 


}

void resize()
{
glScalef(scale_x,scale_y,scale_z);
}


void reshape (int width, int height) {  
glViewport(0, 0, (GLsizei)width, (GLsizei)height); // Set our viewport to the size of our window  
glMatrixMode(GL_PROJECTION); // Switch to the projection matrix so that we can manipulate how our scene is viewed  
glLoadIdentity(); // Reset the projection matrix to the identity matrix so that we don't get any artifacts (cleaning up)  
gluPerspective(60, (GLfloat)width / (GLfloat)height, 1.0, 100.0); // Set the Field of view angle (in degrees), the aspect ratio of our window, and the new and far planes  
//glFrustum(-1.0,1.0,-1.0,1.0,1.5,20.0);
glMatrixMode(GL_MODELVIEW); // Switch back to the model view matrix, so that we can start drawing shapes correctly  
}  

void showpoints()
{
//translate();
/*glPointSize(10.0f);  
glBegin(GL_POINTS); // Start drawing a point primitive  
glVertex3f(-1.0f, -1.0f, 0.0f); // The bottom left corner  
glVertex3f(-1.0f, 1.0f, 0.0f); // The top left corner  
glVertex3f(1.0f, 1.0f, 0.0f); // The top right corner  
glVertex3f(1.0f, -1.0f, 0.0f); // The bottom right corner  
glEnd();*/

glPointSize(10.0f);  
glBegin(GL_POINTS); // Start drawing a point primitive 
glColor3f(1.0,1.0,1.0); 
glVertex3f(0.0f, 0.0f, -5.0f); // The bottom left corner 
glEnd();
}


void showcube()
{


    GLfloat cube[] = {     0.5f, -0.5f,-0.5f,  
      			       0.5f, 0.5f,-0.5f,
      			       -0.5f,  0.5f,-0.5f,
                              -0.5f,  -0.5f,-0.5f,
 
                               0.5, -0.5, 0.5,
                               0.5,  0.5, 0.5,
                               -0.5,  0.5, 0.5,
                               -0.5, -0.5, 0.5,

                                0.5, -0.5, -0.5,
				0.5,  0.5, -0.5,
				0.5,  0.5,  0.5,
				0.5, -0.5,  0.5,


                               
				 -0.5, -0.5,  0.5,
				-0.5,  0.5,  0.5,
				-0.5,  0.5, -0.5,
				 -0.5, -0.5, -0.5,
    
    0.5,  0.5,  0.5,
    0.5,  0.5, -0.5,
   -0.5,  0.5, -0.5,
   -0.5,  0.5,  0.5,
  
 
  
  
   
    0.5, -0.5, -0.5,
    0.5, -0.5,  0.5,
   -0.5, -0.5,  0.5,
   -0.5, -0.5, -0.5,};


   float color[]={1.0,0.0,0.0,
                  0.0,1.0,0.0,
                  1.0,0.0,0.0,
                  0.0,1.0,0.0,

                  0.0,0.0,1.0,
                  1.0,0.0,0.0,
                  1.0,0.0,0.0,
                  0.0,1.0,0.0,
  
                 1.0,1.0,1.0,
                  1.0,0.0,1.0,
                  1.0,0.0,0.0,
                  0.0,1.0,0.0,

                  1.0,0.0,0.0,
                  0.0,0.0,0.0,
                  1.0,0.0,0.0,
                  0.0,1.0,0.0,

                  0.0,1.0,1.0,
                  1.0,0.0,0.0,
                  1.0,0.0,0.0,
                  0.0,1.0,0.0,
  
                 1.0,1.0,1.0,
                  1.0,0.0,1.0,
                  1.0,1.0,0.0,
                  1.0,1.0,0.0,
};
	// Tell OpenGL where the vertex data is stored.
	glEnableClientState( GL_VERTEX_ARRAY);
        glEnableClientState( GL_COLOR_ARRAY);
       glVertexPointer( 3, GL_FLOAT,0,cube); 
       glColorPointer( 3, GL_FLOAT,0,color);
     
//render the geometry

//glDrawElements(GL_QUADS,8,GL_INT,&indices);
glDrawArrays( GL_QUADS, 0, 24 );
glDisableClientState(GL_VERTEX_ARRAY);
glDisableClientState(GL_COLOR_ARRAY);




/*
 //Multi-colored side - FRONT
  glBegin(GL_POLYGON);
 
  glColor3f( 1.0, 0.0, 0.0 );     glVertex3f(  0.5, -0.5, -0.5 );      // P1 is red
  glColor3f( 0.0, 1.0, 0.0 );     glVertex3f(  0.5,  0.5, -0.5 );      // P2 is green
  glColor3f( 0.0, 0.0, 1.0 );     glVertex3f( -0.5,  0.5, -0.5 );      // P3 is blue
  glColor3f( 1.0, 0.0, 1.0 );     glVertex3f( -0.5, -0.5, -0.5 );      // P4 is purple
  glEnd();
 
  // White side - BACK
  glBegin(GL_POLYGON);
  glColor4f(   1.0,  1.0, 1.0,0.5);
  glVertex3f(  0.5, -0.5, 0.5 );
  glVertex3f(  0.5,  0.5, 0.5 );
  glVertex3f( -0.5,  0.5, 0.5);
  glVertex3f( -0.5, -0.5, 0.5);
  glEnd();
 
  // Purple side - RIGHT
  glBegin(GL_POLYGON);
  glColor4f(  1.0,  0.0,  1.0,0.5 );
  glVertex3f( 0.5, -0.5, -0.5 );
  glVertex3f( 0.5,  0.5, -0.5 );
  glVertex3f( 0.5,  0.5,  0.5 );
  glVertex3f( 0.5, -0.5,  0.5 );
  glEnd();
 
  // Green side - LEFT
  glBegin(GL_POLYGON);
  glColor4f(   0.0,  1.0,  0.0,0.5);
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
 
  // Blue side - TOP
  glBegin(GL_POLYGON);
  glColor4f(   0.0,  0.0,  1.0,1 );
  glVertex3f(  0.5,  0.5,  0.5 );
  glVertex3f(  0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5, -0.5 );
  glVertex3f( -0.5,  0.5,  0.5 );
  glEnd();
 
  // Red side - BOTTOM
  glBegin(GL_POLYGON);
  glColor4f(   1.0,  0.0,  0.0,0.3);
  glVertex3f(  0.5, -0.5, -0.5 );
  glVertex3f(  0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5,  0.5 );
  glVertex3f( -0.5, -0.5, -0.5 );
  glEnd();
*/




}

 



void display(){
 glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
  //  Clear screen and Z-buffer
  glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
 


  // Reset transformations
  glMatrixMode(GL_MODELVIEW);
glPushMatrix();
  //translate();
 showpoints();
 glPopMatrix();

 /*glLoadIdentity();
//	gluLookAt(0.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);
 
glLoadIdentity();*/
//	gluLookAt(5.0,0.0,5.0,0.0,0.0,0.0,0.0,1.0,0.0);	
glLoadIdentity();
glPushMatrix();
translate();
rotate();  
resize();
showcube();
GLfloat modelMatrix[16];
GLfloat vertexMatrix[16]={1,2,3,0,1,2,3,4,5,6,7,8,9,0,0,0};
glPushMatrix();
glMultMatrixf(vertexMatrix);
//glLoadMatrixf(currentMatrix);
glGetFloatv (GL_MODELVIEW_MATRIX, modelMatrix);
printf("\nVertex Matrix \n");
 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 4; j++) {
    printf("%f ", modelMatrix[j * 4 + i]);
  }
  printf("\n");
}
glPopMatrix();
//glMultMatrixf(vertexMatrix);
glGetFloatv (GL_MODELVIEW_MATRIX, modelMatrix);
glPopMatrix();
// glScalef( scale_x, 0.0, 0.0 );          // Not included
 

  printf("\nTransformation matrix after moving \n");
 for (int i = 0; i < 4; i++) {
  for (int j = 0; j < 4; j++) {
    printf("%f ", modelMatrix[j * 4 + i]);
  }
  printf("\n");
}
 
  glFlush();
  glutSwapBuffers();
 
}
 
// ----------------------------------------------------------
// specialKeys() Callback Function
// ----------------------------------------------------------
void specialKeys( int key, int x, int y ) {
 
  switch(key)
{
case GLUT_KEY_RIGHT:
    rotate_y += 5;
 break;
case GLUT_KEY_LEFT:
    rotate_y -= 5;
  break;

case GLUT_KEY_UP:
    rotate_x += 5;
 break;

case GLUT_KEY_DOWN:
    rotate_x -= 5;
   break;

case GLUT_KEY_PAGE_UP:
    rotate_z += 5;
 break;

case GLUT_KEY_PAGE_DOWN:
    rotate_z -= 5;
 break;
case GLUT_KEY_F1:
    translate_x -= 0.5;
 break;

case GLUT_KEY_F2:
    translate_x += 0.5;
 break;

case GLUT_KEY_F3:
    translate_y -= 0.5;
 break;

case GLUT_KEY_F4:
    translate_y += 0.5;
 break;
case GLUT_KEY_F5:
    translate_z -= 0.5;
 break;

case GLUT_KEY_F6:
    translate_z += 0.5;
 break;
case GLUT_KEY_F7:
    scale_x =scale_x*1.3;
    //scale_y=scale_y*2;
    //scale_z=scale_z*2;
 break;
case GLUT_KEY_F8:
scale_x=scale_x*0.3;
break;
default:
printf("press correct key");
break;

}
 
  //  Request display update
  glutPostRedisplay();
 
}


void window_key(unsigned char key, int x, int y) 
{  
  switch (key) {    
  case KEY_ESC:  
    exit(1);                      
    break; 
    
  default:
    printf ("Pressing %d doesn't do anything.\n", key);
    break;
  }    
}
 
// ----------------------------------------------------------
// main() function
// ----------------------------------------------------------
int main(int argc, char* argv[]){
 
  //  Initialize GLUT and process user parameters
  glutInit(&argc,argv);
 
  //  Request double buffered true color window with Z-buffer
  glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);
 glEnable(GL_BLEND); //enable the blending
 
  // Create window
  glutCreateWindow("Awesome Cube");
 
  //  Enable Z-buffer depth test
  glEnable(GL_DEPTH_TEST);
 
  // Callback functions
 
 glutDisplayFunc(display);
 
glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for rendering  
  glutSpecialFunc(specialKeys);
  glutKeyboardFunc(window_key);
  //glutReshapeFunc(reshape); // Tell GLUT to use the method "reshape" for rendering  
  //  Pass control to GLUT for events
  glutMainLoop();
 
  //  Return to OS
  return 0;
 
}

