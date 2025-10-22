#include "Game.h"
#include <iostream>
Game::Game() : isRunning(true) {
    std::cout << "Game initialized" << std::endl;
}

void Game::run() {
    while (isRunning) {
        handleEvents();
        update();
        render();
    }
}

void Game::handleEvents() {
}

void Game::update() {
}

void Game::render() {
}
