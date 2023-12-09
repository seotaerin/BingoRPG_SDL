#ifndef TEXTRPG_MAP_H
#define TEXTRPG_MAP_H

#include "SDL_image.h"

class Map {
    int map[16][15]{};
    int bingoArray[8]={0, 0,0,0,0,0,0,0};
    SDL_Rect mapImgLoc{};
    SDL_Rect shopSize{};
    SDL_Texture* stonFloor;
    SDL_Texture* wallT;
    SDL_Texture* wallLConer;
    SDL_Texture* wallRConer;
    SDL_Texture* wallLBConer;
    SDL_Texture* wallRBConer;
    SDL_Texture* wallB;
    SDL_Texture* wallL;
    SDL_Texture* wallR;
    SDL_Texture* wallLM;
    SDL_Texture* wallRM;
    SDL_Texture* wallM;
    SDL_Texture* wallMB;
    SDL_Texture* bingo;
    SDL_Texture* wallBM{};
    SDL_Texture* wallDoorC;
    SDL_Texture* wallDoorOL;
    SDL_Texture* background{};
    SDL_Texture* wallDoorSideC;
    SDL_Texture* shop;
public:
    static bool map1clearTF;
    static bool map2clearTF;
    static bool map3clearTF;
    static bool map4clearTF;
    static bool map5clearTF;
    static bool map6clearTF;
    static bool map7clearTF;
    static bool map8clearTF;
    static bool map9clearTF;
    Map();
    void DrawMap();
    void fightMap();
    void bingoCountCal();
    static int bingocount;
    void mapClear();
    void GameClear();


    int lvl1[15][15]={
            {2,1,1,1,1,11,1,1,1,1,11,1,1,1, 3},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {9,15,15,15,15,16,15,15,15,15,16,15,15,15,10},

            {7,0,0,0,0,18,0,0,0,0,18,0,0,0, 8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {9,15,15,15,15,16,15,15,15,15,16,15,15,15,10},

            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {7,0,0,0,0,18,0,0,0,0,18,0,0,0,8},
            {4,0,0,6,6,12,6,6,6,6,12,6,15,15,5},
    };
};

#endif
