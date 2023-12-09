#include "Monster.h"
#include "Map.h"
#include "Window.h"
#include "Fight.h"

int Monster::monsterType;
bool Monster::bossAppear;
bool Monster::gameClear;

//생성자에서 몬스터 이미지 설정, 스태틱 변수들도 초기화
Monster::Monster()
{
    monsterType=3;
    bossAppear= false;
    gameClear= false;
    monsterFra = { 0 , 0, 64, 64 };
    monsterTexture_l = Window::LoadTexture("slime.png");
    monsterTexture_f = Window::LoadTexture("slime_fire.png");
    monsterTexture_w = Window::LoadTexture("slime_water.png");
    bossTexture = Window::LoadTexture("boss.png");
}

//몬스터를 맵에 렌더하는 함수
void Monster::monsterDraw(int frame, int now) {
    monsterFra = { frame * 64, 0, 64, 64 };
    bossFra = { frame * 64, 0, 64, 64 };
    switch (now)
    {
        case 1:
            if(!Map::map1clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_l, &monsterFra, &monsterPos1);
            if(!Map::map2clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_f, &monsterFra, &monsterPos2);
            if(!Map::map3clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_w, &monsterFra, &monsterPos3);
            if(!Map::map4clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_w, &monsterFra, &monsterPos4);
            if(!Map::map5clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_l, &monsterFra, &monsterPos5);
            if(!Map::map6clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_f, &monsterFra, &monsterPos6);
            if(!Map::map7clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_l, &monsterFra, &monsterPos7);
            if(!Map::map8clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_f, &monsterFra, &monsterPos8);
            if(!Map::map9clearTF&&!bossAppear) SDL_RenderCopy(Window::renderer, monsterTexture_w, &monsterFra, &monsterPos9);
            break;
        case 2:
            if(bossAppear) SDL_RenderCopy(Window::renderer, bossTexture, &monsterFra, &bossFightPos);
            else
            {
                switch(monsterType)
                {
                    case 1:
                        SDL_RenderCopy(Window::renderer, monsterTexture_f, &monsterFra, &FightPos);
                        break;
                    case 2:
                        SDL_RenderCopy(Window::renderer, monsterTexture_w, &monsterFra, &FightPos);
                        break;
                    case 3:
                        SDL_RenderCopy(Window::renderer, monsterTexture_l, &monsterFra, &FightPos);
                        break;
                    default:
                        break;
                }
            }
            break;
        default:
            break;
    }
    if(Monster::bossAppear&&!Monster::gameClear&&!Fight::fightStart)SDL_RenderCopy(Window::renderer, bossTexture, &bossFra, &destRectBoss);
}

//몬스터가 죽으면 몬스터가 있던 칸을 클리어 상태로 바꿀 함수
void Monster::monsterDie(int yPos, int xPos)
{
    if(yPos==21&& xPos==7&&!Monster::bossAppear) Map::map1clearTF= true;
    if(yPos==11&& xPos==7&&!Monster::bossAppear) Map::map2clearTF= true;
    if(yPos==2&& xPos==7&&!Monster::bossAppear) Map::map3clearTF= true;
    if(yPos==21&& xPos==17&&!Monster::bossAppear) Map::map4clearTF= true;
    if(yPos==11&& xPos==17&&!Monster::bossAppear) Map::map5clearTF= true;
    if(yPos==2&& xPos==17&&!Monster::bossAppear) Map::map6clearTF= true;
    if(yPos==21&& xPos==27&&!Monster::bossAppear) Map::map7clearTF= true;
    if(yPos==11&& xPos==27&&!Monster::bossAppear) Map::map8clearTF= true;
    if(yPos==2&& xPos==27&&!Monster::bossAppear) Map::map9clearTF= true;
}

//몬스터랑 싸움을 시작할때 몬스터 타입을 설정하는 함수
void Monster::monsterTypeSet(int yPos, int xPos)
{
    if(yPos==21&& xPos==7) monsterType=3;
    if(yPos==11&& xPos==7) monsterType=1;
    if(yPos==2&& xPos==7) monsterType=2;
    if(yPos==21&& xPos==17) monsterType=2;
    if(yPos==11&& xPos==17) monsterType=3;
    if(yPos==2&& xPos==17) monsterType=1;
    if(yPos==21&& xPos==27) monsterType=3;
    if(yPos==11&& xPos==27) monsterType=1;
    if(yPos==2&& xPos==27) monsterType=2;
}
