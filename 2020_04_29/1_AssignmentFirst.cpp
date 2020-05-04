#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#define WIDTH 300
#define HEIGHT 300

void DrawObject(GLfloat red, GLfloat green, GLfloat blue)
{
	glColor3f(red, green, blue);

	glPushMatrix();
		glTranslatef(-10, 10, 0);
		glBegin(GL_LINES);
			glVertex2i(10, 10);
			glVertex2i(10, -10);
		glEnd();
	glPopMatrix();

	glBegin(GL_LINES);
		glVertex2i(10, 10);
		glVertex2i(-10, 10);
	glEnd();

	glPushMatrix();
		glTranslatef(2.8, 10, 0);
		glRotatef(45, 0, 0, 1);
		glBegin(GL_LINES);
			glVertex2i(-9.5, 9.5);
			glVertex2i(5, 9.5);
		glEnd();
	glPopMatrix();
}

 void DrawSquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(1.0, 1.0, 1.0);

    int xsize = 0, ysize = 0;

    for(int j = 0;j < 10;j++)
    {
        xsize=0;

        for(int i = 0;i < 10; i++)
        {
             glBegin(GL_POLYGON);
               glVertex3f(-50.0 + xsize, -50.0 + ysize, 0.0);
               glVertex3f(-40.0 + xsize, -50.0 + ysize, 0.0);
               glVertex3f(-40.0 + xsize, -40.0 + ysize, 0.0);
               glVertex3f(-50.0 + xsize, -40.0 + ysize, 0.0);
            glEnd();

         xsize += 10.0;
      }

      ysize += 10.0;
   }

   glFlush();
}

void Display() 
{
    // Draw red object in {0}
    DrawObject(1.0, 0.0, 0.0);
	glPushMatrix(); // Push {0} coord. sys.
	{
	    // Move to {1} coord. sys.
        glTranslatef(2.0, 3.0, 0.0);
		// Draw red object in {1}
		DrawObject(0.0, 1.0, 0.0);

		glPushMatrix();  // Push {1} coord. sys.
		{
		    // Move to {2} coord. system.
		    glTranslatef(-4.0, -2.0, 0.0);
			glRotatef(45.0, 0.0, 0.0, 1.0);
			// Draw blue object in {2}
			DrawObject(0.0, 1.0, 1.0);
		}
		glPopMatrix(); // Return to {1} coord. sys.

		// Move to {3} coord. sys.
		glTranslatef(1.0, -4.0, 0.0);
		glRotatef(-90.0, 0.0, 0.0, 1.0);
		// Draw yellow object in {3}
		DrawObject(1.0, 1.0, 0.0);
	}
	glPopMatrix(); // Return to {0} coord. sys.
}

void MyDisplay()
{
    DrawSquare();

	glPushMatrix();
		glTranslatef(0, -10, 0);
		Display();
	glPopMatrix();

	glFlush();
    glutSwapBuffers();
}

void init (void)
{
    glClearColor (0, 0, 0, 1);
    glClear(GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

int main(int argc, char **argv) 
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("컴퓨터그래픽스 6주차 과제");
	init();
    glutDisplayFunc(MyDisplay);
	glDisable (GL_TEXTURE_2D);
    glutMainLoop();
}
