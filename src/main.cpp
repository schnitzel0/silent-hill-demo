#include <GL/glut.h>
#include <iostream>
#include "Player.h"

Player player;

void display() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    // Устанавливаем камеру игрока
    player.updateCamera();

    // Отрисовка пола
    glBegin(GL_QUADS);
    glColor3f(0.3f, 0.3f, 0.3f);
    glVertex3f(-10.0f, 0.0f, -10.0f);
    glVertex3f(-10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, 10.0f);
    glVertex3f(10.0f, 0.0f, -10.0f);
    glEnd();

    // Отрисовка тестовой стены
    glPushMatrix();
    glColor3f(0.5f, 0.2f, 0.2f);
    glTranslatef(0.0f, 1.0f, -3.0f);
    glutSolidCube(2.0);
    glPopMatrix();

    glutSwapBuffers();
}

void reshape(int width, int height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)width / height, 0.1, 100.0);
    glMatrixMode(GL_MODELVIEW);
}

void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':
    case 'W':
        player.moveForward();
        break;
    case 's':
    case 'S':
        player.moveBackward();
        break;
    case 'a':
    case 'A':
        player.moveLeft();
        break;
    case 'd':
    case 'D':
        player.moveRight();
        break;
    case 27: // ESC
        exit(0);
        break;
    }
    glutPostRedisplay();
}

void specialKeys(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        player.rotate(-0.05f, 0.0f);
        break;
    case GLUT_KEY_RIGHT:
        player.rotate(0.05f, 0.0f);
        break;
    case GLUT_KEY_UP:
        player.rotate(0.0f, 0.05f);
        break;
    case GLUT_KEY_DOWN:
        player.rotate(0.0f, -0.05f);
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    std::cout << "Silent Hill Demo - Starting..." << std::endl;
    std::cout << "Controls: WASD - movement, Arrows - look around" << std::endl;

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Silent Hill Demo - Player Movement");

    glEnable(GL_DEPTH_TEST);
    glClearColor(0.1f, 0.1f, 0.1f, 1.0f);

    glutDisplayFunc(display);
    glutReshapeFunc(reshape);
    glutKeyboardFunc(keyboard);
    glutSpecialFunc(specialKeys);

    std::cout << "Player movement system initialized!" << std::endl;

    glutMainLoop();
    return 0;
}
