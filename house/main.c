#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>

#define TotalPoints 12

GLfloat win;
GLfloat Points[TotalPoints][2] = {
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
  {6.5, 2.5},
	{2, 2.5}
};

void scale(int key) {
	float scaleX = 1.05f, scaleY = 1.05f;

	for (int i = 0; i < TotalPoints; i++) {
    if (key == GLUT_KEY_UP) {
			Points[i][0] *= scaleX;
			Points[i][1] *= scaleY;
		}

    if (key == GLUT_KEY_DOWN) {
			Points[i][0] /= scaleX;
			Points[i][1] /= scaleY;
		}
  }
}

void manageSpecialKeys(int key, int x, int y) {
	scale(key);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D (-win, win, -win, win);

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

void mirror(int key) {
	for (int i = 0; i < TotalPoints; i++) {
    if (key == '1') Points[i][0] *= -1;
    if (key == '2') Points[i][1] *= -1;
  }
}

void rotation(int angleRad) {
	for (int i = 0; i < TotalPoints; i++) {
		// glVertex2f(
		Points[i][0] = (Points[i][0] * cos(angleRad)) - (Points[i][1] * sin(angleRad));
		Points[i][1] = (Points[i][0] * sin(angleRad)) + (Points[i][1] * cos(angleRad));
		// );
  }
}

void shearing(int key) {
	for (int i = 0; i < TotalPoints; i++) {
    if (key == 'n') {
			if (i == 0 || i == TotalPoints - 1) continue;
			Points[i][0] += 2;
		}

    if (key == 'm') {
			if (i == 0 || i == TotalPoints - 1) continue;
			Points[i][1] += 2;
		}
  }
}

void manageKeyboard(int key, int x, int y) {
	switch(key) {
		case 27:
			exit(0);
			break;		

		case 'e':
		case 'E':
			rotation(5);

		case 'q':
		case 'Q':
			rotation(-5);
	}

	translate(key);
	mirror(key);
	shearing(key);

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
