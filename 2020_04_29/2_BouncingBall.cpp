#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <cmath>

GLfloat WHITE[] = { 1, 1, 1 };
GLfloat RED[] = { 1, 0, 0 };
GLfloat BLACK[] = { 0, 0, 0 };
GLfloat GREEN[] = { 0, 1, 0 };
float BallSpeed = 0.05;

class Camera 
{
    double theta;
    double y;
    double dTheta;
    double dy;

    public:
        Camera(): theta(-1.2), y(10), dTheta(0.04), dy(0.2) {}

    double getX()  { return 10 * cos(theta); }
    double getY() { return y; }
    double getZ() { return 10 * sin(theta); }
    void moveRight() { theta += dTheta; }
    void moveLeft()  { theta -= dTheta; }
    void moveUp()  { y += dy; }
    void moveDown() { if (y > dy) y -= dy; }
};

class Ball 
{
    double radius;
    GLfloat * color;
    double maximumHeight;
    double x;
    double y;
    double z;
    int direction;

    public:
        Ball(double r, GLfloat * c, double h, double x, double z):
        radius(r), color(c), maximumHeight(h), direction(-1),
        y(h), x(x), z(z) {}

    void update() 
	{
        y += direction * BallSpeed;

        if (y > maximumHeight) 
		{
            y = maximumHeight;
            direction = -1;
        } 
		else if (y < radius) 
		{
            y = radius;
            direction = 1;
        }

        glPushMatrix();
        glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, color);
        glTranslated(x, y, z);
        glutSolidSphere(radius, 50, 50);
        glPopMatrix();
    }
};

class Board 
{
    int width;
    int depth;

    public:
        Board(int width, int depth): width(width), depth(depth) {}

    double centerx() { return width / 2; }
    double centerz() { return depth / 2; }
    void draw() 
	{
		GLfloat lightPosition[] = { 4, 3, 1, 1 };
        glLightfv(GL_LIGHT0, GL_POSITION, lightPosition);
		glColor3f(1, 1, 1);

        glBegin(GL_POLYGON);
			glVertex3d(width, 0, depth);
			glVertex3d(width, 0, -depth);
			glVertex3d(-width, 0, -depth);
			glVertex3d(-width, 0, depth);
        glEnd();
	}
};

Board board(8, 8); // width, depth가 8인 보드 생성
Camera camera; // 카메라 객체 생성
Ball balls[] = { // 3개의 공 객체 배열 생성
    Ball(0.5, GREEN, 6, 6, 1),
    Ball(0.7, RED, 4, 3, 4),
    Ball(0.4, WHITE, 3, 1, 7)
};

void Init() 
{
    glEnable(GL_DEPTH_TEST);
    glLightfv(GL_LIGHT0, GL_DIFFUSE, WHITE);
    glLightfv(GL_LIGHT0, GL_SPECULAR, WHITE);
    glMaterialfv(GL_FRONT, GL_SPECULAR, WHITE);
    glMaterialf(GL_FRONT, GL_SHININESS, 30);
    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
}

void Display() 
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();
    gluLookAt(camera.getX(), camera.getY(), camera.getZ(),
        board.centerx(), 0.0, board.centerz(),
        0.0, 1.0, 0.0); // 카메라 객체와 보드의 중점 좌표에 맞추어 시점 변환
    board.draw(); // 보드의 draw함수 호출로 보드 렌더링

    for (int i = 0; i < sizeof balls / sizeof(Ball); i++) 
	{
        balls[i].update(); // 공의 위치 갱신
    }

    glFlush();
    glutSwapBuffers();
}

void Reshape(GLint w, GLint h) 
{
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(40.0, GLfloat(w) / GLfloat(h), 1.0, 150.0);
    glMatrixMode(GL_MODELVIEW);
}

void Timer(int v)
{
    glutPostRedisplay();
    glutTimerFunc(1000 / 60, Timer, v);
}

void Special(int key, int, int) 
{
    switch (key) 
	{
		case GLUT_KEY_LEFT:
			// 키보드 왼쪽 방향키 클릭시 카메라 시점 왼쪽으로 이동
			camera.moveLeft();
			break;
		case GLUT_KEY_RIGHT:
			// 오른쪽 방향키 클릭시 카메라 카메라 시점 오른쪽으로 이동
			camera.moveRight();
			break;
		case GLUT_KEY_UP:
			// 키보드 위쪽 방향키 클릭시 카메라 시점 위로 이동
			camera.moveUp();
			break;
		case GLUT_KEY_DOWN:
			// 키보드 아래쪽 방향키 클릭시 카메라 시점 아래로 이동
			camera.moveDown();
			break;
    }

    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
		case 'Q':
		case '\033':
			// 키보드 q버튼 누를 시 프로그램 종료
			exit(0);
			break;

		case 's':
		case 'S':
			// 키보드 s버튼 누를 시 솔리드 모드 변환
			glDisable(GL_CULL_FACE);
			glPolygonMode(GL_FRONT, GL_FILL);
			glutPostRedisplay();
			break;

		case 'W':
		case 'w':
			// 키보드 w버튼 누를 시 와이어 프레임 모드 변환
			glEnable(GL_CULL_FACE);
			glPolygonMode(GL_FRONT, GL_LINE);
			glutPostRedisplay();
			break;

		case 'u':
		case'U':
			// 키보드 u버튼 누를 시 공 속도 0.01 증가
			BallSpeed += 0.01;
			glutPostRedisplay();
			break;

		case 'd':
		case 'D':
			// 키보드 d버튼 누를 시 공 속도 0.01 감소
			BallSpeed -= 0.01;
			glutPostRedisplay();
			break;

		default:
			break;
	}
}

int main(int argc, char ** argv) 
{
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowPosition(80, 80);
    glutInitWindowSize(800, 600);
    glutCreateWindow("컴퓨터그래픽스 6주차 과제");
    glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
    glutReshapeFunc(Reshape);
    glutSpecialFunc(Special);
    glutTimerFunc(100, Timer, 0);
    Init();
    glutMainLoop();
}
