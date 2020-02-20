#include <GL/glut.h>

GLfloat win;
GLfloat panX, panY;

void manageKeyboard(int key, int x, int y) {
	switch(key) {
		case 'R':
		case 'r':
			win = 200.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);

			break;

		case 'W':
		case 'w':
			panX += 20.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
		case 's':
		case 'S':
			panX -= 20.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
		case 'A':
		case 'A':
			panX += 20.0f;
			panY += 20.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
		case 'D':
		case 'd':
			panX -= 20.0f;
			panY -= 20.0f;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
	}

	glutPostRedisplay();
}

void manageSpecialKeys(int key, int x, int y) {
	switch(key) {
		case GLUT_KEY_UP:
			if (win != 20.0f) win -= 20.0f;
			else break;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
		case GLUT_KEY_DOWN:
			if (win != 200.0f) win += 20.0f;
			else break;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;
		case GLUT_KEY_F1:
			win = 200.0;
			glMatrixMode(GL_PROJECTION);
			glLoadIdentity();
			gluOrtho2D (-win+panX, win+panX, -win+panY, win+panY);
			break;	
	}

	glutPostRedisplay();
}

void drawGrid() {
	glColor3f(0.8f, 0.8f, 0.8f);
	glLineWidth(1.0f);
	glBegin(GL_LINES);
	float x = -200;

	for(; x <= 200; x++) {
		glVertex2f(-200, x);
		glVertex2f(200, x);
		glVertex2f(x, -200);
		glVertex2f(x, 200);
	}

	glEnd();

	glColor3f(0.0f, 0.0f, 0.0f);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	glVertex2f(-200, 0);
	glVertex2f(200, 0);
	glVertex2f(0, -200);
	glVertex2f(0, 200);
	glEnd();
}

int p1_x = 0, p1_y = 0;
int p2_x = 0, p2_y = 0;
void drawOnScreen(void) {
	glClear(GL_COLOR_BUFFER_BIT);

	drawGrid();

	glColor3f(1.0f, 0.0f, 0.0f);
	glLineWidth(3.0f);
	glBegin(GL_LINES);
	
	glVertex2f(p1_x, p1_y);
	glVertex2f(p2_x, p2_y);

	glEnd();
	
	glutSwapBuffers();
}

void start(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	win = 200.0f;
	panX = 0.0f;
	panY = 0.0f;
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-win+panX, win+panX, -win+panY, win+panY);
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
	printf("Bem-vindo ao programa que desenha uma linha no plano cartesiano\n\n");
	printf("Para começar você deve inserir os pontos P1(x, y) e P2(x, y) para gerar a linha\n");
	printf("Tenha em mente que o programa é restringido para valores apenas entre -200 e 200.\n\n");

	int check_value = 0;

	do {
		printf("Insira P1(x) -> ");
		scanf("%d", &p1_x);
		printf("Insira P1(y) -> ");
		scanf("%d", &p1_y);
		printf("Insira P2(x) -> ");
		scanf("%d", &p2_x);
		printf("Insira P2(y) -> ");
		scanf("%d", &p2_y);

		if (p1_x > 200 || p1_x < -200 || 
				p1_y > 200 || p1_y < -200 ||
				p2_x > 200 || p2_x < -200 ||
				p2_y > 200 || p2_y < -200
		) {
			printf("Os valores não podem sair do range [-200, 200]. Tente novamente.\n\n");
		} else {
			check_value = 1;
		}
	} while(check_value == 0);

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(720, 720);
	glutInitWindowPosition(300, 300);
	glutCreateWindow("Desenhador de Linha");
	glutDisplayFunc(drawOnScreen);
	glutMouseFunc(manageMouse);
	glutSpecialFunc(manageSpecialKeys);
	glutKeyboardFunc(manageKeyboard);
	start();
	glutMainLoop();
}
