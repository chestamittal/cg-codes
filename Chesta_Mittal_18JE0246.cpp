// Chesta Mittal - 18JE0246

#include<bits/stdc++.h>
#include<GL/glut.h>
using namespace std;

double xstart, xend, ystart, yend;

void DDA(void) {
	// clear the buffer to preset values
	glClear(GL_COLOR_BUFFER_BIT);
	double dx = xend - xstart;
	double dy = yend - ystart;
	double slope = double(dy) / double(dx);				
	
	int steps = max(abs(xstart - xend), abs(ystart - yend));
	double x = xstart, y = ystart;
	double xinc = dx / steps;
	double yinc = dy / steps;
	for (int counter = 0; counter <= steps; counter++) {

		// plot a point
		glBegin(GL_POINTS);
		glVertex2i(round(x), round(y));
		glEnd();

		// cout << "Plotted " << x << " " << y << endl;
		x += xinc;
		y += yinc;
	}

	// show as quikly as possible
	glFlush();
}

void init() {
	// set the background color to pink (Red(1) + Green(0) + Blue(1))
	glClearColor(1.0, 0.0, 1.0, 0);

	// set the filling color to blue (Red(0) + Green(0) + Blue(1))
	glColor3f(0.0, 0.0, 1.0);

	gluOrtho2D(0, 640, 0, 480);
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
	glutCreateWindow("DDA");
	init();
	glutDisplayFunc(DDA);
	glutMainLoop();

	return 0;
}