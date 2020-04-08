#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawSolidTeapot()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4f, 0.8f, 0.6f);

	glutSolidTeapot(0.5f);

	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3주차 과제 2 - 주전자 (1)");

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(0, 0, 0, 5, 5, 15, 0, 1, 0);

	glutDisplayFunc(drawSolidTeapot);
	glutMainLoop();

	return 0;
}
