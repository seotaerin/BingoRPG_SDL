#ifndef BINGORPG_TEXT_H
#define BINGORPG_TEXT_H

#include <SDL_ttf.h>

class Text {
    TTF_Font* font{};
    SDL_Color textColor={230, 230, 230, 255};
    SDL_Surface* textSurface{};
    SDL_Texture* textTexture{};
    SDL_Rect textRect{};
public:
    static bool notBlink;
    Text();
    void textRender(char* str, int x, int y, int size);
};

#endif //BINGORPG_TEXT_H
