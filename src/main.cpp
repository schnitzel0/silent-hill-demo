#include <iostream>
#include <GL/glut.h>

using namespace std;

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
}

int main(int argc, char** argv) {
    cout << "Silent Hill Demo - Starting..." << endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Silent Hill Demo - Lab 8");

    glutDisplayFunc(display);

    cout << "Window created successfully!" << endl;
    cout << "Lab 8: OpenGL Game Development" << endl;

    glutMainLoop();
    return 0;
}
