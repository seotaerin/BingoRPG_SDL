#include "Shop.h"
#include "Pointer.h"

using namespace std;

//상점 아이템 목록을 보여주는 함수
void Shop::printStore()
{
    Pointer::text->textRender((char*)"1. HP포션(1)        2. MP포션(1)       3. 공격력 강화 표션(1)", 90, 300, 28);
    Pointer::text->textRender((char*)"4. 불의 망토(2)    5. 물의 망토(2)     6. 풀의 망토(2)", 90, 350, 28);
}

//상점에서 아이템 구매하는 함수 (1 hp포션 2 mp포션 3 공격력 포션)
void Shop::buyItem(int kind)
{
    if(Player::gold>=1)
    {
        Player::gold-=1;

        switch (kind) {
            case 1:
                Player::hpPotion+=1;
                break;
            case 2:
                Player::mpPotion+=1;
                break;
            case 3:
                Player::attackPotion+=1;
                break;
            default:
                break;
        }

        Text::notBlink= true;
        switch (kind) {
            case 1:
                Pointer::text->textRender((char*)"HP포션을 구매했습니다.", 300, 450, 28);
                break;
            case 2:
                Pointer::text->textRender((char*)"HP포션을 구매했습니다.", 300, 450, 28);
                break;
            case 3:
                Pointer::text->textRender((char*)"공격력 강화포션을 구매했습니다.", 300, 450, 28);
                break;
            default:
                break;
        }
        Text::notBlink= false;
    }
    else
    {
        Text::notBlink= true;
        Pointer::text->textRender((char*)"골드가 부족합니다.", 300, 450, 28);
        Text::notBlink= false;
    }
}

//망토 사는 함수 (1 불의 망토 2 물의 망토 3 풀의 망토)
void Shop::buyCloak(int kind)
{
    if(Player::gold>=2)
    {
        switch(kind)
        {
            case 1:
                if(!Player::fireCloak)
                {
                    Player::fireCloak= true;
                    Player::gold-=2;
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"불의 망토를 구매했습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
                else if(Player::fireCloak)
                {
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"이미 가지고 있습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
                break;
            case 2:
                if(!Player::waterCloak)
                {
                    Player::waterCloak= true;
                    Player::gold-=2;
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"물의 망토를 구매했습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
                else if(Player::waterCloak)
                {
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"이미 가지고 있습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
                break;
            case 3:
                if(!Player::leafCloak)
                {
                    Player::leafCloak= true;
                    Player::gold-=2;
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"풀의 망토를 구매했습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
                else if(Player::leafCloak)
                {
                    Text::notBlink= true;
                    Pointer::text->textRender((char*)"이미 가지고 있습니다.", 300, 450, 28);
                    Text::notBlink= false;
                }
            default:
                break;
        }
    }
    else if(Player::gold<2)
    {
        Text::notBlink= true;
        Pointer::text->textRender((char*)"골드가 부족합니다.", 300, 450, 28);
        Text::notBlink= false;
    }
}
