#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#define WIDTH 400
#define HEIGHT 400

// 흑색 바탕에 백색 사각형 그리기
void drawBlackBackgroundWhiteSquare() 
{
	glClear(GL_COLOR_BUFFER_BIT); // 색상 버퍼 지움

	glBegin(GL_POLYGON);
		glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();
	glFlush();
}

int main()
{
	glutCreateWindow("OpenGL Drawing Example");
	glutDisplayFunc(drawBlackBackgroundWhiteSquare);
	glutMainLoop();

	return 0;
}
