#ifndef BINGORPG_Keyboard_H
#define BINGORPG_Keyboard_H

#include <SDL_events.h>

class Keyboard {
public:
    static bool keyPressed;
    static bool upKeyPressed;
    static void keyboardInput(SDL_Event e, int currentSituation);
};

#endif //BINGORPG_Keyboard_H
