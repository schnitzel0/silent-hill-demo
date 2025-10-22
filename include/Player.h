#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
    float posX, posY, posZ;    // ������� ������
    float yaw, pitch;          // �������� ������
    float moveSpeed;           // �������� ��������

public:
    Player();

    // ��������
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();

    // ������� ������
    void rotate(float deltaYaw, float deltaPitch);

    // ���������� ������
    void updateCamera();

    // �������
    float getX() const { return posX; }
    float getY() const { return posY; }
    float getZ() const { return posZ; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getMoveSpeed() const { return moveSpeed; }
};
#endif 
