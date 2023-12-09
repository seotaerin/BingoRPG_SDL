#ifndef BINGORPG_MONSTER_H
#define BINGORPG_MONSTER_H

#include "SDL.h"

class Monster {
    SDL_Texture* monsterTexture_l;
    SDL_Texture* monsterTexture_f;
    SDL_Texture* monsterTexture_w;
    SDL_Texture* bossTexture;
    SDL_Rect monsterFra{};
    SDL_Rect monsterPos1 = { 195, 630, 128, 128 };
    SDL_Rect monsterPos2 = { 195, 310, 128, 128 };
    SDL_Rect monsterPos3 = { 195, 26, 128, 128 };
    SDL_Rect monsterPos4 = { 515, 630, 128, 128 };
    SDL_Rect monsterPos5 = { 515, 310, 128, 128 };
    SDL_Rect monsterPos6 = { 515, 26, 128, 128 };
    SDL_Rect monsterPos7 = { 835, 630, 128, 128 };
    SDL_Rect monsterPos8 = { 835, 310, 128, 128 };
    SDL_Rect monsterPos9 = { 835, 26, 128, 128 };
    SDL_Rect FightPos = { 600, 610, 300, 300 };//스프라이트
    SDL_Rect bossFightPos = { 500, 400, 500, 500 };//스프라이트
    SDL_Rect bossFra{};
    SDL_Rect destRectBoss = { 350, 300, 258, 258 };
public:
    Monster();
    static int monsterType;
    static bool bossAppear;
    static bool gameClear;
    static void monsterDie(int yPos, int xPos);
    static void monsterTypeSet(int yPos, int xPos);
    void monsterDraw(int frame, int now);
};

#endif //BINGORPG_MONSTER_H
