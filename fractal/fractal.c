#include <GL/glut.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>

void myinit() {
	glClearColor(0.0,0.0,0.0,0.0);
}

void ChangeSize(GLsizei w,GLsizei h) {
	glViewport(0,0,w,h);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	GLfloat x=2.0;

	if (w <= h)
		glOrtho(-x, x, -x * (GLfloat) h / (GLfloat) w, x* (GLfloat) h / (GLfloat) w, -100.0, 100.0);
	else 
		glOrtho(-x / (GLfloat) h* (GLfloat) w, x / (GLfloat) h * (GLfloat) w, -x, x, -100.0, 100.0);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

typedef struct Handler {
	float real;
	float virt;
} Handler;

Handler handMult(Handler a, Handler b) {
	Handler obj;
	obj.real= a.real * b.real - a.virt * b.virt;
	obj.virt = a.real * b.virt + a.virt * b.real;
	return obj;
}

Handler handAdd(Handler a, Handler b) {
	Handler obj;
	obj.real = a.real + b.real;
	obj.virt = a.virt + b.virt;
	return obj;
}

float mathematics(Handler a) {
	return sqrt(a.real * a.real + a.virt * a.virt);
}

float handlerFunc(Handler a, int iter, Handler input) {
	if(iter) {
		Handler d = handAdd(handMult(a, a), input);
		Handler e = handAdd(handMult(d, d), input);
		return handlerFunc(e, --iter, input);
	}	else return (int) (mathematics(a) / 4 * 10);
}

void RenderScene() {
	glClear(GL_COLOR_BUFFER_BIT);
	float i, j;
	glBegin(GL_POINTS);
	float d;
	Handler a;

  int ok;
  float real, virt;
  printf("Insira um numero para afetar a complicacao do padrao -> ");
  if (scanf("%f", &real) == 1) ok = 0;
  else printf("Input precisa ser um float");
  
  printf("Insira um numero para afetar a simetria -> ");
  if (scanf("%f", &real) == 1) ok = 0;
  else printf("Input precisa ser um float");

  Handler input = {
    real,
    virt  
  };

	//draw the fractal point
	for(i =- 2; i <= 2; i += 0.01)
		for(j =- 2; j  <=2; j += 0.01) {
			a.real = i;
			a.virt = j;
			d = handlerFunc(a, 6, input);
			d = d / 10;
			glColor3f(d,d*1.2,d*1.5);
			glVertex2f(i,j);
		}

	glEnd();
	glFlush();
}

int main(int argc,char *argv[]) {
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(50, 100);
	glutInit(&argc,argv);
	glutCreateWindow("Fractal");
	
	myinit();

	glutReshapeFunc(ChangeSize);
	glutDisplayFunc(RenderScene);

	glutMainLoop();

	return 0;
}
