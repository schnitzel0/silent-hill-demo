#include "Player.h"
#include <GL/glut.h>
#include <cmath>

Player::Player() {
    posX = 0.0f;
    posY = 1.0f;    // ���� ������
    posZ = 5.0f;
    yaw = 0.0f;
    pitch = 0.0f;
    moveSpeed = 0.1f;
}

void Player::moveForward() {
    posX += moveSpeed * sin(yaw);
    posZ -= moveSpeed * cos(yaw);
}

void Player::moveBackward() {
    posX -= moveSpeed * sin(yaw);
    posZ += moveSpeed * cos(yaw);
}

void Player::moveLeft() {
    posX -= moveSpeed * cos(yaw);
    posZ -= moveSpeed * sin(yaw);
}

void Player::moveRight() {
    posX += moveSpeed * cos(yaw);
    posZ += moveSpeed * sin(yaw);
}

void Player::rotate(float deltaYaw, float deltaPitch) {
    yaw += deltaYaw;
    pitch += deltaPitch;

    // ������������ ���� ������ �� ���������
    if (pitch > 1.5f) pitch = 1.5f;
    if (pitch < -1.5f) pitch = -1.5f;
}

void Player::updateCamera() {
    // ������ �����, � ������� ������� ������
    float lookX = posX + sin(yaw) * cos(pitch);
    float lookY = posY + sin(pitch);
    float lookZ = posZ - cos(yaw) * cos(pitch);

    // ��������� ������
    gluLookAt(posX, posY, posZ,    // ������� ������
        lookX, lookY, lookZ, // ����� ���� �������
        0.0f, 1.0f, 0.0f);   // ������ �����
}
