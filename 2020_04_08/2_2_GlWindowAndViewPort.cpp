#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void glWindowAndViewPort() //디스플레이콜백함수 
{
	glClear(GL_COLOR_BUFFER_BIT);//GL 상태변수설정
	glViewport(0, 0, 300, 300); 
	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_POLYGON); //입력기본요소정의
	    glVertex3f(-0.5, -0.5, 0.0);
		glVertex3f(0.5, -0.5, 0.0);
		glVertex3f(0.5, 0.5, 0.0);
		glVertex3f(-0.5, 0.5, 0.0);
	glEnd();

	glFlush();
}

int main(int argc, char** argv) 
{
	glutInit(&argc,argv); //GLUT 윈도우함수
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowSize(300, 300);
	glutInitWindowPosition(0, 0);
	glutCreateWindow("OpenGL Sample Drawing");

	glClearColor(0.0, 0.0, 0.0, 1.0); //GL 상태변수설정
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

	glutDisplayFunc(glWindowAndViewPort); //GLUT 콜백함수등록
	glutMainLoop(); //이벤트루프진입

	return 0;
}
