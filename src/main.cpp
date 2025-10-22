#include <iostream>
#include "Window.h"
#include "Player.h"

int main() {
    std::cout << "========================================" << std::endl;
    std::cout << "Silent Hill Demo - Window System" << std::endl;
    std::cout << "========================================" << std::endl;

    Window window;
    Player player;

    std::cout << "Initializing game systems..." << std::endl;

    if (window.create(800, 600, "Silent Hill Demo")) {
        std::cout << "✅ Window created successfully!" << std::endl;
        std::cout << "✅ Player system initialized!" << std::endl;

        // Простой игровой цикл (3 итерации)
        for (int i = 0; i < 3; ++i) {
            std::cout << "--- Frame " << (i + 1) << " ---" << std::endl;
            window.render();
            window.swapBuffers();

            // Демонстрация движения игрока
            player.moveForward();
        }

        window.destroy();
        std::cout << "✅ Game shutdown complete!" << std::endl;
    }
    else {
        std::cout << "❌ Failed to create window!" << std::endl;
    }

    std::cout << "========================================" << std::endl;
    return 0;
}