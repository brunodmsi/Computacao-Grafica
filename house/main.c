#include <stdlib.h>
#include <GL/glut.h>

#define TotalPoints 12

GLfloat win;

float Points[TotalPoints][2] = {
  {2, 2.5},
  {2, 4.5},
  {1, 4.5},
  {2, 6},
  {2.2, 6},
  {2.2, 7},
  {4, 7},
  {4, 6},
  {6.5, 6},
  {7.5, 4.5},
  {6.5, 4.5},
  {6.5, 2.5}
};

void manageSpecialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_UP:
			if (win != 20.0f) win -= 20.0f;
			else break;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;
	}

	glutPostRedisplay();
}

void translate(char key) {
  for (int i = 0; i < TotalPoints; i++) {
    if (key == 'w') Points[i][1] += 1;
    if (key == 's') Points[i][1] -= 1;
    if (key == 'd') Points[i][0] += 1;
    if (key == 'a') Points[i][0] -= 1;
  }
}

void manageKeyboard(int key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;

		case 'R':
		case 'r':
			win = 200.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;

		case 'W':
		case 'w':
      translate('w');
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;

		case 's':
		case 'S':
      translate('s');
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;

		case 'A':
		case 'a':
      translate('a');
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;

		case 'D':
		case 'd':
      translate('d');
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win, win, -win, win);
			break;
	}

	glutPostRedisplay();
}

void drawOnScreen(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(3.0f);
	glBegin(GL_LINE_LOOP);
	
  for (int i = 0; i < TotalPoints; i++) {
    glVertex2f(Points[i][0], Points[i][1]);
  }

	glEnd();
	
	glutSwapBuffers();
}

void start(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	win = 10.0f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-win, win, -win, win);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Desenhador de Linha");
	glutDisplayFunc(drawOnScreen);
	glutSpecialFunc(manageSpecialKeys);
	glutKeyboardFunc(manageKeyboard);
	start();
	glutMainLoop();
}
