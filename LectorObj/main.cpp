//#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>

#include "objeto.hpp"
#include "vertice.hpp"
#include "cara.hpp"

using std::cout; using std::cerr;
using std::endl; using std::string;
using std::ifstream; using std::vector;


vector<unsigned int> indices;
objeto cube("mexichango.obj", indices);


void display(void)
{
	/*  clear all pixels  */
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT)
	glBegin(GL_QUADS);
	for (auto const& i : indices) {

		if (i % 2 == 0)
		{
			glColor3f(0.0f, 1.0f, 0.0f);
		}
		else
		{
			glColor3f(0.0f, 0.0f, 1.0f);
		}
		glVertex3f(cube.vertices[i].x, cube.vertices[i].y, cube.vertices[i].z);
	}
	glEnd();

	glutSwapBuffers();
	glFlush();
}


void init(void)
{
	/*  select clearing (background) color       */
	glClearColor(0.0, 0.0, 0.0, 0.0);

	/*  initialize viewing values  */
	glEnable(GL_DEPTH_TEST);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	gluPerspective(45.0, 800.0 / 600.0, 0.1, 100.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(5, 4, 5,
		-1, -1, 0,
		0.0, 1.0, 0.0);
}

/*
 *  Declare initial window size, position, and display mode
 *  (single buffer and RGBA).  Open window with "hello"
 *  in its title bar.  Call initialization routines.
 *  Register callback function to display graphics.
 *  Enter main loop and process events.
 */
int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(800, 600);
	glutInitWindowPosition(100, 100);
	glutCreateWindow("Hola");

	init();

	glutDisplayFunc(display);
	glutIdleFunc(display);
	glutMainLoop();

	return 0;   /* ISO C requires main to return int. */
}

