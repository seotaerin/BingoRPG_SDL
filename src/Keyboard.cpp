#include "Keyboard.h"
#include "Pointer.h"

bool Keyboard::keyPressed= false;
bool Keyboard::upKeyPressed= false;

//currentSituation에 따라 키보드가 다르게 입력되도록 하는 함수 (1 빙고판에서 이동 2 전투 3 아이템 구매)
void Keyboard::keyboardInput(SDL_Event e, int currentSituation)
{
    if (e.type == SDL_KEYDOWN) {
        upKeyPressed = true; //키가 한번에 한번씩만 눌리도록
        switch(e.key.keysym.sym)
        {
            case SDLK_UP://위로 이동
                if(currentSituation==1||currentSituation==3)
                {
                    if(Pointer::player->level1Access[Player::yPos-1][Player::xPos]!=0&&Player::yPos-1>=0)
                    {
                        Player::characterY -=32;
                        Player::yPos-=1;
                    }
                }
                break;
            case SDLK_DOWN: //아래로 이동
                if(currentSituation==1||currentSituation==3)
                {
                    if(Pointer::player->level1Access[Player::yPos+1][Player::xPos]!=0&&Player::yPos+1<=27)
                    {
                        Player::characterY += 32;
                        Player::yPos+=1;
                    }
                }
                break;
            case SDLK_LEFT: //왼쪽으로 이동
                if(currentSituation==1||currentSituation==3)
                {
                    if(Pointer::player->level1Access[Player::yPos][Player::xPos-1]!=0&&Player::xPos-1>=0)
                    {
                        Player::characterX -=32;
                        Player::xPos-=1;
                        Pointer::player->flip= true; //왼쪽으로 갈때 캐릭터 뒤집음
                    }
                }
                break;
            case SDLK_RIGHT: //오른쪽으로 이동
                if(currentSituation==1||currentSituation==3)
                {
                    if(Pointer::player->level1Access[Player::yPos][Player::xPos+1]!=0&&Player::xPos+1<=28)
                    {
                        Player::characterX += 32;
                        Player::xPos+=1;
                        Pointer::player->flip= false; //뒤집은거 원래대로
                    }
                }
                break;
            case SDLK_1: // 2(전투상황)일때는 공격 3(상점)일때는 아이템 구매
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(3);
                    if (Pointer::fight->playerattck(0) == 1) Pointer::fightEndCall();
                }
                if(currentSituation==3) Shop::buyItem(1);
                break;
            case SDLK_2:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(3);
                    if (Pointer::fight->playerattck(1) == 1) Pointer::fightEndCall();
                }
                if(currentSituation==3) Shop::buyItem(2);
                break;
            case SDLK_3:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(3);
                    if (Pointer::fight->playerattck(2) == 1) Pointer::fightEndCall();
                }
                if(currentSituation==3) Shop::buyItem(3);
                break;
            case SDLK_4:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(3);
                    if (Pointer::fight->playerattck(3) == 1) Pointer::fightEndCall();
                }
                if(currentSituation==3) Shop::buyCloak(1);
                break;
            case SDLK_5: //3(상점)일때 아이템 구매
                if(currentSituation==3) Shop::buyCloak(2);
                break;
            case SDLK_6:
                if(currentSituation==3) Shop::buyCloak(3);
                break;
            case SDLK_q:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(4);
                    Pointer::fight->monsterattack();
                }
                break;
            case SDLK_w: //2(전투상황)일때 아이템사용
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(5);
                    Pointer::fight->monsterattack();
                }
                break;
            case SDLK_e:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(6);
                    Pointer::fight->monsterattack();
                }
                break;
            case SDLK_r:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(7);
                    Pointer::fight->monsterattack();
                }
                break;
            case SDLK_a:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(1);
                }
                break;
            case SDLK_s:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(2);
                }
                break;
            case SDLK_d:
                if(currentSituation==2)
                {
                    Pointer::renderingFightScene(1);
                    Pointer::fight->ItemUse(3);
                }
                break;
        }
    }
    else if (e.type == SDL_KEYUP) upKeyPressed = false; //키가 한번에 한번씩만 눌리도록
}
