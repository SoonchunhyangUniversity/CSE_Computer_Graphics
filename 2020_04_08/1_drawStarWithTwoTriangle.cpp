#include <GL/glut.h>
#define WIDTH 400
#define HEIGHT 400

void drawStar()
{
	glClear(GL_COLOR_BUFFER_BIT);

	/* ===========================
	 첫번째 삼각형을 그리는 부분
	============================ */
	glColor4f( 1.0f, 1.0f, 0.0f, 1.0f ); // 삼각형의 색깔 설정
	glTranslatef(-0.1f, 0.1f, 0.0f); // 형태를 맞추기 위해 첫 번째 삼각형 x, y축 이동
	glRotatef(90.0f, 0.0f, 0.0f, 1.0f); // z축을 기준으로 90도 회전

	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.3, 0.0);
		glVertex3f(-0.3, -0.3, 0.0);
		glVertex3f(0.3, -0.3, 0.0);
	glEnd();

	/* ===========================
	 두번째 삼각형을 그리는 부분
	============================ */
	glTranslatef(0.0f, -0.2f, 0.0f); // 형태를 맞추기 위해 두 번째 삼각형 y축 이동
	glRotatef(-180.0f, 0.0f, 0.0f, 1.0f); // z축을 기준으로 -180도 회전

	glBegin(GL_TRIANGLES);
		glVertex3f(0.0, 0.3, 0.0);
		glVertex3f(-0.3, -0.3, 0.0);
		glVertex3f(0.3, -0.3, 0.0);
	glEnd();

	glFlush();
}


int main()
{
	glutInitWindowSize(WIDTH, HEIGHT);
	glutCreateWindow("3주차 과제1 별그리기");
	glutDisplayFunc(drawStar);
	glutMainLoop();

	return 0;
}
