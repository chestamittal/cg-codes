/*
*  Sharyu Dongre 18JE0762 - Program 2
*/

#include<bits/stdc++.h>
#include<GL/glut.h>

using namespace std;

int xstart, xend, ystart, yend;


void Bresenham(void) {
	// clear the buffer to preset values
	glClear(GL_COLOR_BUFFER_BIT);


	int dx = xend - xstart;
	int dy = yend - ystart;

	int error_term = 2 * dy - dx;
	int x = xstart;
	int y = ystart;

	for (int i = 0; i < dx; i++) {
		glBegin(GL_POINTS);
			glVertex2i(x, y);
		glEnd();

		while (error_term > 0) {
			y = y + 1;
			error_term -= 2 * dx;
		}
		x = x + 1;
		error_term += 2 * dy;
	}


	// show as quikly as possible
	glFlush();
}

void init() {
	// set the background color to pink (Red(1) + Green(0) + Blue(1))
	glClearColor(1.0, 0.0, 1.0, 0);

	// set the filling color to blue (Red(0) + Green(0) + Blue(1))
	glColor3f(0.0, 0.0, 1.0);

	gluOrtho2D(0, 500, 0, 500);
}

int main(int argc, char** argv) {
	cout << "Enter Point 1 coordinates : ";
	cin >> xstart >> ystart;
	cout << "Enter Point 2 coordinates : ";
	cin >> xend >> yend;


	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowSize(500, 500);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Bresenham Algorithm Integer");
	init();
	glutDisplayFunc(Bresenham);
	glutMainLoop();

	return 0;
}