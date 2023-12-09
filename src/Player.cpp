#include "Player.h"
#include "Monster.h"
#include "Map.h"
#include "Window.h"

int Player::characterX;
int Player::characterY;
int Player::xPos;
int Player::yPos;
int Player::Playerhp;
int Player::Playermp;
int Player::hpPotion;
int Player::gold;
int Player::mpPotion;
int Player::attackPotion;
int Player::playerType;
bool Player::fireCloak;
bool Player::waterCloak;
bool Player::leafCloak;

//생성자에서 플레이어 초기상태 설정
Player::Player()
{
    characterX = 100;
    characterY = 845;
    xPos=3;
    yPos=27;
    Playerhp=100;
    Playermp=20;
    gold=0;
    hpPotion=0;
    mpPotion=0;
    attackPotion=0;
    playerType=0;
    fireCloak= false;
    waterCloak= false;
    leafCloak= false;
}

//플레이어 상태에 따라 이미지 바꿀 때 쓰는 함수 (1 idle 2 walk 3 attack)
void Player::playerDraw(int frame, int now, int anim)
{
    switch(anim)
    {
        case 1: //idle
            switch(playerType)
            {
                case 0:
                    characterTexture = Window::LoadTexture("playerIdle_x.png");
                    break;
                case 1:
                    characterTexture = Window::LoadTexture("playerIdle.png");
                    break;
                case 2:
                    characterTexture = Window::LoadTexture("playerIdle_water.png");
                    break;
                case 3:
                    characterTexture = Window::LoadTexture("playerIdle_leaf.png");
                    break;
                default:
                    break;
            }
            break;
        case 2: //walk
            switch (playerType)
            {
                case 0:
                    characterTexture = Window::LoadTexture("playerWalk_x.png");
                    break;
                case 1:
                    characterTexture = Window::LoadTexture("playerWalk.png");
                    break;
                case 2:
                    characterTexture = Window::LoadTexture("playerWalk_water.png");
                    break;
                case 3:
                    characterTexture = Window::LoadTexture("playerWalk_leaf.png");
                    break;
                default:
                    break;
            }
            break;
        case 3: //attack
            switch(playerType)
            {
                case 0:
                    characterTexture = Window::LoadTexture("playerAttack_x.png");
                    break;
                case 1:
                    characterTexture = Window::LoadTexture("playerAttack.png");
                    break;
                case 2:
                    characterTexture = Window::LoadTexture("playerAttack_water.png");
                    break;
                case 3:
                    characterTexture = Window::LoadTexture("playerAttack_leaf.png");
                    break;
                default:
                    break;
            }
            break;
        default:
            break;
    }

    playerFra = { frame * 32, 0, 32, 32 };//캐릭터 스프라이트 프레임 계산

    switch(now) //현재 상황에 따라 캐릭터 크기 설정 (1 빙고판 2 싸움화면)
    {
        case 1:
            playerPos = { characterX, characterY, 75, 75 };
            break;
        case 2:
            flip= false;
            playerPos = { 190, 700, 128, 128 };
            break;
        default:
            break;
    }

    //캐릭터 왼쪽으로 갈때 뒤집기 위한것
    if(flip) SDL_RenderCopyEx(Window::renderer, characterTexture, &playerFra, &playerPos, 0, NULL, SDL_FLIP_HORIZONTAL);
    else SDL_RenderCopy(Window::renderer, characterTexture, &playerFra, &playerPos);

}

//맵을 클리어하면 플레이어가 갈 수 있는 범위를 바꾸기 위한 함수
void Player::mapClear()
{
    if(Map::map1clearTF||Monster::bossAppear)
    {
        for(int i=9; i<19; i++) for(int ii=0; ii<9; ii++) level1Access[i][ii]=1;
        for(int i=19; i<28; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(Map::map2clearTF||Monster::bossAppear)
    {
        for(int i=0; i<10; i++)for(int ii=0; ii<9; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(Map::map3clearTF||Monster::bossAppear)
    {
        for(int i=1; i<10; i++)for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(Map::map4clearTF||Monster::bossAppear)
    {
        for(int i=9; i<19; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
        for(int i=19; i<28; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
    }
    if(Map::map5clearTF||Monster::bossAppear)
    {
        for(int i=0; i<10; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++) for(int ii=1; ii<10; ii++) level1Access[i][ii]=1;
        for(int i=19; i<28; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(Map::map6clearTF||Monster::bossAppear)
    {
        for(int i=1; i<10; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
        for(int i=1; i<10; i++) for(int ii=0; ii<10; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(Map::map7clearTF||Monster::bossAppear)
    {
        for(int i=19; i<28; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++)for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
    }
    if(Map::map8clearTF||Monster::bossAppear)
    {
        for(int i=1; i<10; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
        for(int i=9; i<19; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
        for(int i=19; i<28; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
    }
    if(Map::map9clearTF||Monster::bossAppear)
    {
        for(int i=9; i<19; i++) for(int ii=18; ii<28; ii++) level1Access[i][ii]=1;
        for(int i=1; i<10; i++) for(int ii=9; ii<19; ii++) level1Access[i][ii]=1;
    }
    if(!Map::map2clearTF&&!Monster::bossAppear) level1Access[11][7]=2;
    if(!Map::map3clearTF&&!Monster::bossAppear) level1Access[2][7]=2;
    if(!Map::map4clearTF&&!Monster::bossAppear) level1Access[21][17]=2;
    if(!Map::map5clearTF&&!Monster::bossAppear) level1Access[11][17]=2;
    if(!Map::map6clearTF&&!Monster::bossAppear) level1Access[2][17]=2;
    if(!Map::map7clearTF&&!Monster::bossAppear) level1Access[21][27]=2;
    if(!Map::map8clearTF&&!Monster::bossAppear) level1Access[11][27]=2;
    if(!Map::map9clearTF&&!Monster::bossAppear) level1Access[2][27]=2;
    if(Monster::bossAppear && !Monster::gameClear)
    {
        for(int i=11; i<16;i++) level1Access[13][i]=5;
        for(int i=11; i<16;i++) level1Access[14][i]=5;
    }
}

//게임이 클리어 되면 문쪽에서 탈출할 수 있도록 하는 함수
void Player::GameClear()
{
    if(Monster::bossAppear)
    {
        for(int i=11; i<16;i++) level1Access[13][i]=1;
        for(int i=11; i<16;i++) level1Access[14][i]=1;
        for(int i=24; i<28; i++) level1Access[27][i]=4;
        Monster::gameClear=true;
    }
}
