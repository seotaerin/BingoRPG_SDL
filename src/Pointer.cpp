#include "Pointer.h"

//다른 클래스에서 쓰게 될 포인터들을 스태틱으로
Window* Pointer::window=new Window();
Player* Pointer::player=new Player();
Monster* Pointer::monster=new Monster;
Map* Pointer::map=new Map();
Fight* Pointer::fight;
Text* Pointer::text=new Text;

//빙고판 렌더링할 것들 묶음
void Pointer::renderingScene()
{
    int playerAnim;
    if (Keyboard::keyPressed) playerAnim=2;
    else if(!Keyboard::keyPressed) playerAnim=1;
    map->DrawMap(); //맵 렌더
    monster-> monsterDraw(Window::frame,1);//몬스터 렌더
    player->playerDraw(Window::frame, 1, playerAnim);//플레이어 렌더
    Window::UI();//ui 렌더
}

//싸울때 렌더링할 것들 묶음
void Pointer::renderingFightScene(int anim)
{
    map->fightMap();
    monster->monsterDraw(Window::frame,2);
    player->playerDraw(Window::frame, 2, anim);
    fight->UI();
}

//싸움이 시작될때 파이트 객체 생성하는 함수
void Pointer::fightStartCall()
{
    if(!Fight::fightStart)
    {
        Monster::monsterTypeSet(Player::yPos, Player::xPos);
        fight=new Fight();
    }
    Fight::fightStart=true;
}

//싸움이 끝날때 파이트 객체 삭제하고 몬스터 죽음, 맵클리어 정보등 불러오는 함수
void Pointer::fightEndCall()
{
    Monster::monsterDie(Player::yPos, Player::xPos);
    player->level1Access[Player::yPos][Player::xPos] = 1;
    fight->addgold();
    player->GameClear();
    if(Monster::bossAppear) Monster::bossAppear= false;

    map->bingoCountCal();
    map->mapClear();
    player->mapClear();

    if(Fight::fightStart)
    {
        delete fight;
        Fight::fightStart= false;
    }
}

//게임오버씬 렌더링하고 몬스터, 맵, 플레이어 객체를 삭제하고 다시 생성하는 함수
void Pointer::gameOverScene()
{
    SDL_RenderClear(Window::renderer);
    SDL_Texture* blood = Window::LoadTexture("died.png");
    SDL_Rect destRect = { 0, 0, 960, 960 };
    SDL_RenderCopy(Window::renderer, blood, nullptr, &destRect);
    SDL_RenderPresent(Window::renderer);
    SDL_Delay(700);

    delete monster;
    delete map;
    delete player;
    map=new Map();
    monster=new Monster;
    player=new Player();
}

//게임클리어씬 렌더링하는 함수
void Pointer::gameClearScene()
{
    SDL_Texture* clear = Window::LoadTexture("clear.png");
    SDL_Rect destRect = { 0, 0, 960, 960 };
    SDL_RenderCopy(Window::renderer, clear, nullptr, &destRect);
    SDL_RenderPresent(Window::renderer);
    SDL_Delay(10000);
}

