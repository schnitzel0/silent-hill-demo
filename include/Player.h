#ifndef PLAYER_H
#define PLAYER_H
class Player {
private:
    float posX, posY, posZ;    // Позиция игрока
    float yaw, pitch;          // Повороты камеры
    float moveSpeed;           // Скорость движения

public:
    Player();

    // Движение
    void moveForward();
    void moveBackward();
    void moveLeft();
    void moveRight();

    // Поворот камеры
    void rotate(float deltaYaw, float deltaPitch);

    // Обновление камеры
    void updateCamera();

    // Геттеры
    float getX() const { return posX; }
    float getY() const { return posY; }
    float getZ() const { return posZ; }
    float getYaw() const { return yaw; }
    float getPitch() const { return pitch; }
    float getMoveSpeed() const { return moveSpeed; }
};
#endif 
