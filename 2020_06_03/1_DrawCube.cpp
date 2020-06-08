#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

void SetUpRC();
void RenderScene();
void ReshapeScene(int width, int height);

int main()
{
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(500, 500);
	glutCreateWindow("Example1");
	glutDisplayFunc(RenderScene);
	glutReshapeFunc(ReshapeScene);
	SetUpRC();
	glutMainLoop();

	return 0;
}

void SetUpRC()
{
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
	glShadeModel(GL_FLAT);
}

void RenderScene()
{
	glClear(GL_COLOR_BUFFER_BIT);

	gluLookAt(0, 0, 0, 5, 5, 5, 0, 2, 0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	glBegin(GL_TRIANGLE_STRIP);
	    glColor3ub(0, 114, 188);
		glVertex3f(-25, -25, 0);
		glVertex3f(25, -25, 0);
		glVertex3f(-25, 25, 0);

	    glColor3ub(0, 52, 113);
		glVertex3f(25, 25, 0);

	    glColor3ub(120, 0, 0);
		glVertex3f(-25, 25, 50);

	    glColor3ub(0, 120, 0);
		glVertex3f(25, 25, 50);

	    glColor3ub(0, 0, 120);
		glVertex3f(-25, -25, 50);

	    glColor3ub(120, 120, 0);
		glVertex3f(25, -25, 50);

		glColor3ub(120, 0, 120);
		glVertex3f(-25, -25, 0);

		glColor3ub(0, 120, 120);
		glVertex3f(25, -25, 0);

		glColor3ub(120, 120, 120);
		glVertex3f(25, 25, 0);
	glEnd();

	glFlush();
}

void ReshapeScene(int width, int height)
{
    float fRange = 100.0f;
	glViewport(0, 0, width, height);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	if (width <= height)
	{
	    glOrtho(
			-fRange, 
			fRange, 
			-fRange * height / width, 
			fRange * height / width, 
			-fRange, 
			fRange
		);
	}
	else
	{
	    glOrtho(
			-fRange * width / height,
			fRange * width / height, 
			-fRange, 
			fRange, 
			-fRange, 
			fRange
		);    
	}
}
