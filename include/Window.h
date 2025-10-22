#ifndef WINDOW_H
#define WINDOW_H

class Window {
private:
    void* hwnd;
    void* hdc;
    void* hrc;

public:
    Window();
    bool create(int width, int height, const char* title);
    void swapBuffers();
    void destroy();
    bool initOpenGL();
    void render();
};

#endif