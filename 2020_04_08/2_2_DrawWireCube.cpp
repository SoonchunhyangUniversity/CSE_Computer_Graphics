#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawWireCube()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.4f, 0.8f, 0.6f);

	glutWireCube(1);

	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("3주차 과제 2 - 정육면체 (2)");

	glutDisplayFunc(drawWireCube);
	glutMainLoop();

	return 0;
}
