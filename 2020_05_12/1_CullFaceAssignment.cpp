#include <iostream>
#include <stdlib.h>
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>

void drawSolidCube() {
    glColor4f(1, 0, 0, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(-0.500000, -0.500000, 0.500000);
		glVertex3f(0.500000, -0.500000, 0.500000);
		glVertex3f(0.500000, 0.500000, 0.500000);
		glVertex3f(-0.500000, 0.500000, 0.500000);
    glEnd();

    glColor4f(0, 1, 0, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(-0.500000, 0.500000, -0.500000);
		glVertex3f(0.500000, 0.500000, -0.500000);
		glVertex3f(0.500000, -0.500000, -0.500000);
		glVertex3f(-0.500000, -0.500000, -0.500000);
    glEnd();

    glColor4f(0, 0, 1, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(-0.500000, 0.500000, 0.500000);
		glVertex3f(0.500000, 0.500000, 0.500000);
		glVertex3f(0.500000, 0.500000, -0.500000);
		glVertex3f(-0.500000, 0.500000, -0.500000);
    glEnd();

    glColor4f(1, 1, 0, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(-0.500000, -0.500000, -0.500000);
		glVertex3f(0.500000, -0.500000, -0.500000);
		glVertex3f(0.500000, -0.500000, 0.500000);
		glVertex3f(-0.500000, -0.500000, 0.500000);
    glEnd();

    glColor4f(1, 0, 1, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(0.500000, -0.500000, 0.500000);
		glVertex3f(0.500000, -0.500000, -0.500000);
		glVertex3f(0.500000, 0.500000, -0.500000);
		glVertex3f(0.500000, 0.500000, 0.500000);
    glEnd();

    glColor4f(0, 1, 1, 0.7);
    glBegin(GL_QUADS);
		glVertex3f(-0.500000, -0.500000, -0.500000);
		glVertex3f(-0.500000, -0.500000, 0.500000);
		glVertex3f(-0.500000, 0.500000, 0.500000);
		glVertex3f(-0.500000, 0.500000, -0.500000);
    glEnd();
}

void display(void) {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glClear(GL_COLOR_BUFFER_BIT);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(30.0, 1.0, 1.0, 20.0);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(2.0, 2.0, 3.0,
              0.0, 0.0, 0.0,
              0.0, 1.0, 0.0);
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    drawSolidCube();
    glutSwapBuffers();
}

void Keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'q':
    case 'Q':
    case '\0.7':
        exit(0);
        break;

    case 'f':
        std::cout << "f is down" << std::endl;
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
        glutPostRedisplay();
        break;

	case 'g':
		std::cout << "g is down" << std::endl;
        glEnable(GL_CULL_FACE);
        glCullFace(GL_BACK);
		std::cout << "GL_BACK" << std::endl;
		glutPostRedisplay();
		_sleep(2000);
		glCullFace(GL_FRONT);
		std::cout << "GL_FRONT" << std::endl;
        glutPostRedisplay();
		break;

    case 'b':
        std::cout << "b is down" << std::endl;
        glEnable(GL_CULL_FACE);
        glCullFace(GL_FRONT);
        glutPostRedisplay();
        break;

    case 'a':
        std::cout << "a is down" << std::endl;
        glDisable(GL_CULL_FACE);
        glutPostRedisplay();
        break;

    default:
        break;
    }
}

int main(int argc, char ** argv) {
    glutInit( & argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE | GLUT_DEPTH);
    glutInitWindowSize(400, 400);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 400)/2, 
                    	   (glutGet(GLUT_SCREEN_HEIGHT) - 400)/2);
    glutCreateWindow("컴퓨터그래픽스 과제 8주차");
    glutDisplayFunc(display);
    glutKeyboardFunc(Keyboard);
    glutMainLoop();

    return 0;
}
