#ifndef BINGORPG_POINTER_H
#define BINGORPG_POINTER_H

#include <SDL.h>

#include "Window.h"
#include "Player.h"
#include "Map.h"
#include "Monster.h"
#include "Fight.h"
#include "Shop.h"
#include "Text.h"
#include "Keyboard.h"

class Pointer {
public:
    static Window* window;
    static Player* player;
    static Monster* monster;
    static Map* map;
    static Fight* fight;
    static Text* text;
    static void renderingScene();
    static void renderingFightScene(int anim);
    void static fightStartCall();
    void static fightEndCall();
    static void gameOverScene();
    static void gameClearScene();
};


#endif //BINGORPG_POINTER_H
