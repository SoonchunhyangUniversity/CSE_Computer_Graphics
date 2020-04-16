#include <stdio.h>
#include <GL/glut.h>
#include <GL/GL.h>
#include <GL/GLU.h>

int FlatShaded, Wireframed;
int ViewX, ViewY;
int LeftButton, RightButton;
GLUquadricObj * obj;

void InitLight()
{
	GLfloat MatDiffuse[] = { 
		0.5,
		0.4,
		0.3,
		1.0
	};
	GLfloat MatSpecular[] = { 
		1.0,
		1.0,
		1.0,
		1.0
	};
	GLfloat MatAmbient[] = { 
		0.5,
		0.4,
		0.3,
		1.0
	};
	GLfloat MatShininess[] = { 5.0 };
	GLfloat LightSpecular[] = { 
		1.0,
		1.0,
		1.0,
		1.0
	};
	GLfloat LightDiffuse[] = { 
		0.8,
		0.8,
		0.8,
		1.0
	};
	GLfloat light_ambient[] = { 
		0.3,
		0.3,
		0.3,
		1.0
	};
	GLfloat light_position[] = {
		-3,
		6,
		3.0,
		0.0
	};

	glShadeModel(GL_SMOOTH);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glPolygonMode(GL_FRONT, GL_FILL);

	glLightfv(GL_LIGHT0, GL_POSITION, light_position);
	glLightfv(GL_LIGHT0, GL_DIFFUSE, LightDiffuse);
	glLightfv(GL_LIGHT0, GL_SPECULAR, LightSpecular);
	glLightfv(GL_LIGHT0, GL_AMBIENT, light_ambient);

	glMaterialfv(GL_FRONT, GL_DIFFUSE, MatDiffuse);
	glMaterialfv(GL_FRONT, GL_SPECULAR, MatSpecular);
	glMaterialfv(GL_FRONT, GL_AMBIENT, MatAmbient);
	glMaterialfv(GL_FRONT, GL_SHININESS, MatShininess);
}

void Keyboard(unsigned char key, int x, int y)
{
	switch (key)
	{
		case 'q':
		case 'Q':
		case '\033':
			exit(0);
			break;

		case 's':
			if (FlatShaded)
			{
				FlatShaded = 0;
				glShadeModel(GL_SMOOTH);
				gluQuadricNormals(obj, GLU_SMOOTH);
			}
			else
			{
				FlatShaded = 1;
				glShadeModel(GL_FLAT);
				gluQuadricNormals(obj, GLU_FLAT);
			}

			glutPostRedisplay();
			break;

		case 'w':
			if (Wireframed)
			{
				Wireframed = 0;
				glDisable(GL_CULL_FACE);
				glPolygonMode(GL_FRONT_AND_BACK, GL_FILL);
			}
			else
			{
				Wireframed = 1;
				glEnable(GL_CULL_FACE);
				glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);
			}

			glutPostRedisplay();
			break;

		default:
			break;
	}
}

void MouseClick(GLint Button, GLint State, GLint X, GLint Y)
{
	if (Button == GLUT_LEFT_BUTTON && State == GLUT_DOWN)
	{
		LeftButton = 1;
	}
	else
	{
		LeftButton = 0;
	}

	if (Button == GLUT_RIGHT_BUTTON && State == GLUT_DOWN)
	{
		RightButton = 1;
	}
	else
	{
		RightButton = 0;
	}
}

void Motion(GLint X, GLint Y)
{
	if (LeftButton == 1)
	{
		ViewX = X / 3;
		ViewY = Y / 3;
	}

	if (RightButton == 1)
	{
		ViewX = -X / 3;
		ViewY = -Y / 3;
	}

	glutPostRedisplay();
}

void Display()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.0, 0.2, 0.0, 0.3, -0.0, -0.5, 0.0, 1.0, 0.0);

	glRotatef(0.0, 0.0, 0.0, 1.0);
	glRotatef(ViewY, 1.0, 0.0, 0.0);
	glRotatef(ViewX, 0.0, 1.0, 0.0);

	glPushMatrix();
		glTranslatef(0.4, 0.0, -0.4);
		glScalef(1.0, 4.0, 1.0);
		glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.4, 0.0, 0.4);
		glScalef(1.0, 4.0, 1.0);
		glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4, 0.0, -0.4);
		glScalef(1.0, 4.0, 1.0);
		glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(-0.4, 0.0, 0.4);
		glScalef(1.0, 4.0, 1.0);
		glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.0, 0.2, 0.0);
		glScalef(10.0, 1.0, 10.0);
		glutSolidCube(0.1);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.3, 0.38, 0.0);
		glRotatef(90, 1.0, 0.0, 0.0);
		obj = gluNewQuadric();
		gluQuadricDrawStyle(obj, GLU_FILL);
		gluCylinder(obj, 0.08, 0.06, 0.13, 10, 10);
	glPopMatrix();

	glPushMatrix();
		glTranslatef(0.3, 0.31, 0.3);
		glRotatef(20, 0.0, 1.0, 0.0);
		glutSolidTeapot(0.1);
	glPopMatrix();

	glFlush();
}

void Reshape(int w, int h)
{
	glViewport(0, 0, (GLsizei) w, (GLsizei) h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char **argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGBA | GLUT_DEPTH);
	glutInitWindowSize(400, 400);
	glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH) - 400) / 2,
		(glutGet(GLUT_SCREEN_HEIGHT) - 400) / 2);
	glutCreateWindow("컴퓨터 그래픽스 4주차 과제 (3)");

	glClearColor(0.529412, 0.807843, 0.980392, 0);
	glMatrixMode(GL_PROJECTION);
	InitLight();
	glutDisplayFunc(Display);
	glutKeyboardFunc(Keyboard);
	glutMouseFunc(MouseClick);
	glutMotionFunc(Motion);
	glutReshapeFunc(Reshape);

	glutMainLoop();

	return 0;
}
