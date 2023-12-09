#ifndef BINGORPG_WINDOW_H
#define BINGORPG_WINDOW_H

#include <iostream>
#include "SDL.h"
#include "SDL_image.h"
#include "SDL_ttf.h"

using namespace std;

class Window {
    int frameCount = 0;
    static string bar(int n);
public:
    static SDL_Renderer* renderer;
    static SDL_Window *window;
    static int frame;
    Window();
    static SDL_Texture* LoadTexture(const char* texture);
    void frameCal(int& frame);
    static void UI();
};

#endif
