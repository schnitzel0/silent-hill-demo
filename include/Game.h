#ifndef GAME_H
#define GAME_H

class Game {
private:
    bool isRunning;
public:
    Game();
    void run();
    void handleEvents();
    void update();
    void render();
};

#endif
