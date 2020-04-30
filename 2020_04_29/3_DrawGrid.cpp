#include <GL/glut.h>
#include <GL/GL.H>
#define WIDTH 400
#define HEIGHT 400
#define OFFSET 200

float x = 0;
float y = 0;

void init (void)
{
    glClearColor (1.0, 1.0, 1.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
    glMatrixMode (GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);

    glMatrixMode (GL_MODELVIEW);
    glLoadIdentity();
}

void drawline (float x1, float y1, float x2, float y2)
{
    glBegin (GL_LINES);
    glVertex2f (x1, y1);
    glVertex2f (x2, y2);
    glEnd();
}

 void drawSquare()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
    glColor3f(0.0, 0.0, 0.0);

    int xsize = 0, ysize = 0;

    for(int j = 0;j < 10;j++)
    {
        xsize=0;

        for(int i=0;i<10;i++)
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

void display()
{
    drawSquare();

    glFlush();
    glutSwapBuffers();
}

int main (int argc, char **argv)
{
    glutInit (&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGBA);
    glutInitWindowSize (WIDTH, HEIGHT);
    glutCreateWindow ("컴퓨터그래픽스 과제 6주차");
    init();
    glutDisplayFunc (display);
    glDisable (GL_TEXTURE_2D);

    glutMainLoop();

    return 0;
}
