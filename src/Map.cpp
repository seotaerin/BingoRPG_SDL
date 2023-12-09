#include "Map.h"
#include "Window.h"
#include "Monster.h"

int Map::bingocount=0;
bool Map::map1clearTF = false;
bool Map::map2clearTF = false;
bool Map::map3clearTF = false;
bool Map::map4clearTF = false;
bool Map::map5clearTF = false;
bool Map::map6clearTF = false;
bool Map::map7clearTF = false;
bool Map::map8clearTF = false;
bool Map::map9clearTF = false;

//생성자에서 맵클리어 정보 초기화, 맵에 쓸 타일맵 이미지 불러옴
Map::Map()
{
    bingocount=0;
    map1clearTF= false;
    map2clearTF= false;
    map3clearTF= false;
    map4clearTF= false;
    map5clearTF= false;
    map6clearTF= false;
    map7clearTF= false;
    map8clearTF= false;
    map9clearTF= false;
    stonFloor=Window::LoadTexture("stoneFloor.png");//0
    wallT=Window::LoadTexture("wallT.png");//1
    wallLConer=Window::LoadTexture("wallLConer.png");//2
    wallRConer=Window::LoadTexture("wallRCorner.png");//3
    wallLBConer=Window::LoadTexture("wallLBCorner.png");//4
    wallRBConer=Window::LoadTexture("wallRBCorner.png");//5
    wallB=Window::LoadTexture("wallB.png");//6
    wallL=Window::LoadTexture("wallL.png");//7
    wallR=Window::LoadTexture("wallR.png");//8
    wallLM=Window::LoadTexture("wallLM.png");//9
    wallRM=Window::LoadTexture("wallRM.png");//10
    wallM=Window::LoadTexture("wallM.png");//11
    wallMB=Window::LoadTexture("wallMB.png");//12
    bingo=Window::LoadTexture("bingo.png");//13
    wallDoorC=Window::LoadTexture("wallDoorC.png");//15
    wallDoorOL=Window::LoadTexture("wallDoor+.png");//16
    wallDoorSideC=Window::LoadTexture("wallDoorSideC.png");//18
    shop=Window::LoadTexture("shop.png");
    mapImgLoc={0,0,64,64};
    shopSize = { 30, 600, 175, 124 };
    for(int row=0; row<15; row++) for(int column=0; column<15; column++) map[row][column] = lvl1[row][column];
}

//타일맵 숫자에 따라 맵을 렌더링하는 함수
void Map::DrawMap() {
    int number=0;
    for(int row=0; row<15; row++)
    {
        for(int column=0; column<15; column++)
        {
            number=map[row][column];
            mapImgLoc.x=column*64;
            mapImgLoc.y=row*64;
            switch (number) {
                case 0:
                    SDL_RenderCopy(Window::renderer, stonFloor, nullptr, &mapImgLoc);
                    break;
                case 1:
                    SDL_RenderCopy(Window::renderer, wallT, nullptr, &mapImgLoc);
                    break;
                case 2:
                    SDL_RenderCopy(Window::renderer, wallLConer, nullptr, &mapImgLoc);
                    break;
                case 3:
                    SDL_RenderCopy(Window::renderer, wallRConer, nullptr, &mapImgLoc);
                    break;
                case 4:
                    SDL_RenderCopy(Window::renderer, wallLBConer, nullptr, &mapImgLoc);
                    break;
                case 5:
                    SDL_RenderCopy(Window::renderer, wallRBConer, nullptr, &mapImgLoc);
                    break;
                case 6:
                    SDL_RenderCopy(Window::renderer, wallB, nullptr, &mapImgLoc);
                    break;
                case 7:
                    SDL_RenderCopy(Window::renderer, wallL, nullptr, &mapImgLoc);
                    break;
                case 8:
                    SDL_RenderCopy(Window::renderer, wallR, nullptr, &mapImgLoc);
                    break;
                case 9:
                    SDL_RenderCopy(Window::renderer, wallLM, nullptr, &mapImgLoc);
                    break;
                case 10:
                    SDL_RenderCopy(Window::renderer, wallRM, nullptr, &mapImgLoc);
                    break;
                case 11:
                    SDL_RenderCopy(Window::renderer, wallM, nullptr, &mapImgLoc);
                    break;
                case 12:
                    SDL_RenderCopy(Window::renderer, wallMB, nullptr, &mapImgLoc);
                    break;
                case 13:
                    SDL_RenderCopy(Window::renderer, bingo, nullptr, &mapImgLoc);
                    break;
                case 14:
                    SDL_RenderCopy(Window::renderer, wallBM, nullptr, &mapImgLoc);
                    break;
                case 15:
                    SDL_RenderCopy(Window::renderer, wallDoorC, nullptr, &mapImgLoc);
                    break;
                case 16:
                    SDL_RenderCopy(Window::renderer, wallDoorOL, nullptr, &mapImgLoc);
                    break;
                case 18:
                    SDL_RenderCopy(Window::renderer, wallDoorSideC, nullptr, &mapImgLoc);
                    break;
                default:
                    break;
            }
        }
    }
    SDL_RenderCopy(Window::renderer, shop, nullptr, &shopSize);
}

//전투맵 불러오는 함수
void Map::fightMap()
{
    background=Window::LoadTexture("background.png");
    SDL_Rect destRect = { 0, 0, 960, 960 };
    SDL_RenderCopy(Window::renderer, background, nullptr, &destRect);
}

//빙고 계산하는 함수
void Map::bingoCountCal()
{
    bingocount=0;
    if(map1clearTF&&map2clearTF&&map3clearTF) bingoArray[0]=1;
    if(map4clearTF&&map5clearTF&&map6clearTF) bingoArray[1]=1;
    if(map7clearTF&&map8clearTF&&map9clearTF) bingoArray[2]=1;
    if(map1clearTF&&map4clearTF&&map7clearTF) bingoArray[3]=1;
    if(map2clearTF&&map5clearTF&&map8clearTF) bingoArray[4]=1;
    if(map3clearTF&&map6clearTF&&map9clearTF) bingoArray[5]=1;
    if(map1clearTF&&map5clearTF&&map9clearTF) bingoArray[6]=1;
    if(map3clearTF&&map5clearTF&&map7clearTF) bingoArray[7]=1;
    for(int i : bingoArray) if(i==1) bingocount++;
    if(bingocount>=3) Monster::bossAppear= true;
}

//맵 클리어하면 맵 변경하는 함수
void Map::mapClear()
{
    if(map1clearTF)
    {
        for(int i=10; i<14; i++) lvl1[i][5]=0;
        lvl1[14][5]=6;
        lvl1[9][0]=7;
        for(int i=1; i<5; i++) lvl1[9][i]=0;
        for(int i=10, ii=1; i<14, ii<5; i++,ii++) lvl1[i][ii]=13;
    }
    if(map2clearTF||Monster::bossAppear)
    {
        lvl1[4][0]=7;
        for(int i=1; i<5; i++) lvl1[4][i]=0;
        for(int i=5; i<10; i++) lvl1[i][5]=0;
        for(int i=6; i<10; i++) lvl1[9][i]=0;
        if(map2clearTF) for(int i=5, ii=1; i<9, ii<5; i++,ii++) lvl1[i][ii]=13;
    }
    if(map2clearTF&&map3clearTF)
    {
        for(int i=5; i<10; i++) lvl1[4][i]=0;
    }
    if(map1clearTF&&map4clearTF)
    {
        for(int i=5; i<10; i++) lvl1[i][5]=0;
    }
    if(map4clearTF&&map7clearTF)
    {
        for(int i=5; i<10; i++) lvl1[i][10]=0;
    }
    if(map2clearTF&&map5clearTF)
    {
        for(int i=1; i<5; i++) lvl1[i][5]=0;
        lvl1[0][5]=1;
    }
    if(map5clearTF&&map8clearTF)
    {
        for(int i=1; i<5; i++) lvl1[i][10]=0;
        lvl1[0][10]=1;
    }
    if(map4clearTF&&map5clearTF)
    {
        for(int i=10; i<14; i++) lvl1[9][i]=0;
        lvl1[9][14]=8;
    }
    if(map5clearTF&&map6clearTF)
    {
        for(int i=1; i<14; i++) lvl1[4][i]=0;
        lvl1[4][14]=8;
        lvl1[4][0]=7;

    }
    if(map3clearTF)
    {
        lvl1[4][0]=7;
        lvl1[0][5]=1;
        for(int i=1; i<5; i++) lvl1[4][i]=0;
        for(int i=1; i<4; i++) lvl1[i][5]=0;
        for(int i=1, ii=1; i<5, ii<5; i++,ii++) lvl1[i][ii]=13;
    }
    if(map4clearTF)
    {
        if(map1clearTF)
        {
            for(int i=6; i<10; i++) lvl1[9][i]=0;
            for(int i=10; i<14; i++) lvl1[i][10]=0;
            lvl1[14][10]=6;
            for(int i=10, ii=6; i<14, ii<10; i++,ii++) lvl1[i][ii]=13;
        }
    }
    if(map5clearTF)
    {
        for(int i=5; i<9; i++) lvl1[i][5]=0;
        for(int i=5; i<9; i++) lvl1[i][10]=0;
        for(int i=6; i<10; i++) lvl1[4][i]=0;
        for(int i=5; i<10; i++) lvl1[9][i]=0;
        for(int i=5, ii=6; i<9, ii<10; i++,ii++) lvl1[i][ii]=13;
    }
    if(map6clearTF||Monster::bossAppear)
    {
        lvl1[0][5]=1;
        lvl1[0][10]=1;
        for(int i=1; i<5; i++) lvl1[i][5]=0;
        for(int i=6; i<10; i++) lvl1[4][i]=0;
        for(int i=1; i<4; i++) lvl1[i][10]=0;
        if (map8clearTF||Monster::bossAppear) lvl1[4][10]=0;
        if(map6clearTF) for(int i=1, ii=6; i<5, ii<10; i++,ii++) lvl1[i][ii]=13;
    }
    if(map7clearTF)
    {
        for(int i=10; i<14; i++) lvl1[9][i]=0;
        lvl1[9][14]=8;
        for(int i=10; i<14; i++) lvl1[i][10]=0;
        for(int i=10, ii=11; i<14, ii<15; i++,ii++) lvl1[i][ii]=13;
    }
    if(map8clearTF||Monster::bossAppear)
    {
        lvl1[4][14]=8;
        lvl1[9][14]=8;
        lvl1[9][10]=0;
        for(int i=11; i<14; i++) lvl1[4][i]=0;
        for(int i=11; i<14; i++) lvl1[9][i]=0;
        for(int i=5; i<9; i++) lvl1[i][10]=0;
        if (map9clearTF||Monster::bossAppear) lvl1[4][10]=0;
        if(map8clearTF) for(int i=5, ii=11; i<9, ii<14; i++,ii++) lvl1[i][ii]=13;
    }
    if(map9clearTF)
    {
        if (map8clearTF||map6clearTF)
        {
            lvl1[4][10]=0;
        }
        lvl1[4][14]=8;
        for(int i=1; i<4; i++) lvl1[i][10]=0;
        for(int i=11; i<14; i++) lvl1[4][i]=0;
        lvl1[0][10]=1;
        for(int i=1, ii=11; i<5, ii<14; i++,ii++) lvl1[i][ii]=13;
    }
    for(int row=0; row<15; row++) for(int column=0; column<15; column++) map[row][column] = lvl1[row][column];
}

//게임 클리어하면 문열리게 하는 함수
void Map::GameClear()
{
    lvl1[14][12]=0;
    lvl1[14][13]=0;
    for(int row=0; row<15; row++) for(int column=0; column<15; column++) map[row][column] = lvl1[row][column];
}


