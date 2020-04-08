#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawSolidCone()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4f, 0.8f, 0.6f);

	glutSolidCone(0.3f, 0.7f, 100, 100);

	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3주차 과제 2 - 원뿔 (1)");

	glMatrixMode( GL_MODELVIEW );
	glLoadIdentity();
	gluLookAt(0, 0, 0, 5, 5, 5, 0, 1, 0);

	glutDisplayFunc(drawSolidCone);
	glutMainLoop();

	return 0;
}
