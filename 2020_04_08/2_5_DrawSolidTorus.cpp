#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawSolidTorus()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4f, 0.8f, 0.6f);

	glutSolidTorus(0.1f, 0.4f, 100, 100);

	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3주차 과제 2 - 원환체 (1)");

	glutDisplayFunc(drawSolidTorus);
	glutMainLoop();

	return 0;
}
