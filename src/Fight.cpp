#include "Pointer.h"

using namespace std;

bool Fight::fightStart= false;

//생성자에서 몬스터체력을 정함
Fight::Fight()
{
    srand(time(nullptr));
    potionPower=0;
    if(Monster::bossAppear) monsterhp = 200;
    else if(Map::bingocount>=2) monsterhp =rand() % 21 + 140;
    else if(Map::bingocount>=1) monsterhp =rand() % 21 + 120;
    else monsterhp = rand() % 21 + 100;
    temMonterHp=monsterhp;
}

//전투맵에서 UI를 띄우는 함수
void Fight::UI()
{
    std::string ch = "HP = " + std::to_string(Player::Playerhp);
    char* chHP = &ch[0];
    Pointer::text->textRender(chHP, 200, 600, 28);

    ch = "MP = " + std::to_string(Player::Playermp);
    char* chMP = &ch[0];
    Pointer::text->textRender(chMP, 200, 650, 28);

    ch = "HP = " + std::to_string(monsterhp);
    char* chHP_m = &ch[0];
    if(Monster::bossAppear) Pointer::text->textRender(chHP_m, 690, 450, 28);
    else Pointer::text->textRender(chHP_m, 700, 700, 28);

    Pointer::text->textRender((char*)"1. 공격 2. 파이어볼(MP 5) 3. 아쿠아스피어(MP 5) 4. 리프스톰(MP 5)", 35, 50, 28);
    Pointer::text->textRender((char*)"Q. 망토 벗기 W. 불의 망토 E. 물의 망토 R. 풀의 망토 입기", 35, 100, 28);
    ch = "A. HP포션("+std::to_string(Player::hpPotion)+") S. MP포션("+std::to_string(Player::mpPotion)+") D.공격력 강화(" + std::to_string(Player::attackPotion)+")";
    char* potionCount = &ch[0];
    Pointer::text->textRender(potionCount, 35, 150, 28);
}

//플레이어가 공격할때 계산할 함수
int Fight::playerattck(int type)
{
    ALLPlayerATK = 0;

    switch (type) {
        case 0:
            skillType=0;
            break;
        case 1:
            skillType=1;
            break;
        case 2:
            skillType=2;
            break;
        case 3:
            skillType=3;
            break;
        default:
            break;
    }

    if((type!=0&&Player::Playermp >= 5)||type==0)
    {
        if(type==0) ALLPlayerATK = (rand() % 11 + 20)*playerTypeAttack()+potionPower;
        else if(type!=0)
        {
            Player::Playermp -= 5;
            ALLPlayerATK = (rand() % 11 + 20)*1.15*playerTypeAttack()+potionPower;
        }

        monsterhp = monsterhp - ALLPlayerATK;

        std::string ch =  std::to_string(ALLPlayerATK)+"만큼 피해를 입혔습니다.";
        system = &ch[0];
        Text::notBlink= true;
        Pointer::text->textRender(system, 300, 250, 28);
        Text::notBlink= false;
    }
    else {
        Text::notBlink= true;
        Pointer::text->textRender((char*)"MP가 부족합니다.", 300, 250, 28);
        Text::notBlink= false;
        if (monsterhp > 0) monsterattack();
        Player::Playermp += 3;
        return 0;
    }

    if (monsterhp > 0) monsterattack(); //몬스터가 살아있으면 몬스터가 공격을 하도록
    else if (monsterhp <= 0) return 1; //몬스터가 죽었으면 리턴1을 하고 종료

    Player::Playermp += 2;
    if (Player::Playermp > 20) Player::Playermp = 20;
    return 0;
}

//몬스터가 공격할때 공격력을 계산할 함수
void Fight::monsterattack()
{
    std::string ch = "몬스터가 공격을 시도합니다.";
    system = &ch[0];
    Text::notBlink= true;
    Pointer::text->textRender(system, 300, 300, 28);
    Text::notBlink= false;

    monterATK = (rand() % 11 + 20)*monsterTypeAttack();

    Player::Playerhp = Player::Playerhp - monterATK;

    ch = std::to_string(monterATK)+"만큼 피해를 입었습니다.";
    system = &ch[0];
    Text::notBlink= true;
    Pointer::text->textRender(system, 300, 350, 28);
    Text::notBlink= false;
}

//플레이어와 몬스터 타입을 기준으로 플레이어 공격력에 곱할 숫자 계산
float Fight::playerTypeAttack() {
    if(skillType==0) return 1;
    else if(Monster::bossAppear) return 1.3;
    else if(Monster::monsterType==skillType) return 1.2;
    else if(Monster::monsterType==1&&skillType==2) return 2;//몬스터 불 < 플레이어 물
    else if(Monster::monsterType==2&&skillType==3) return 2;//몬스터 물 < 플레이어 풀
    else if(Monster::monsterType==3&&skillType==1) return 2; //몬스터 풀 < 플레이어 불
    else if(Monster::monsterType==1&&skillType==3) return 0.5; //몬스터 불 < 플레이어 풀
    else if(Monster::monsterType==2&&skillType==1) return 0.5; //몬스터 물 < 플레이어 불
    else if(Monster::monsterType==3&&skillType==2) return 0.5; //몬스터 풀 < 플레이어 물
    else return 1;
}

//플레이어와 몬스터 타입을 기준으로 몬스터 공격력에 곱할 숫자 계산
float Fight::monsterTypeAttack() {
    if(Monster::bossAppear) return 1.5;
    else if(Monster::monsterType==Player::playerType||Player::playerType==0) return 1;
    else if(Monster::monsterType==1&&Player::playerType==2) return 0.5;//몬스터 불 < 플레이어 물
    else if(Monster::monsterType==2&&Player::playerType==3) return 0.5;//몬스터 물 < 플레이어 풀
    else if(Monster::monsterType==3&&Player::playerType==1) return 0.5; //몬스터 풀 < 플레이어 불
    else if(Monster::monsterType==1&&Player::playerType==3) return 2; //몬스터 불 < 플레이어 풀
    else if(Monster::monsterType==2&&Player::playerType==1) return 2; //몬스터 물 < 플레이어 불
    else if(Monster::monsterType==3&&Player::playerType==2) return 2; //몬스터 풀 < 플레이어 물
    else return 1;
}

//몬스터 체력을 기준으로 얻을 골드 계산
void Fight::addgold()
{
    if(temMonterHp==200) Player::gold+=0;
    else if(temMonterHp>=140) Player::gold+=4;
    else if(temMonterHp>=100) Player::gold+=3;
    else Player::gold+=2;
}

//아이템 사용하는 함수 (1 hp 포션 2 mp포션 3 공격력 강화 4-7 망토)
void Fight::ItemUse(int n)//아이템 사용
{
    switch(n)
    {
        case 1:
            if (Player::hpPotion >= 1) {
                Player::Playerhp = Player::Playerhp + 50;
                if(Player::Playerhp>100)  Player::Playerhp=100;
                Player::hpPotion-=1;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"HP포션을 사용하여 HP가 50증가하였습니다.", 200, 250, 28);
                Text::notBlink= false;
            }
            else {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"아이템이 부족합니다.", 200, 250, 28);
                Text::notBlink= false;
            }
            break;
        case 2:
            if (Player::mpPotion >= 1) {
                Player::Playermp = Player::Playermp + 10;
                Player::mpPotion-=1;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"MP포션을 사용하여 MP가 10증가하였습니다.", 200, 250, 28);
                Text::notBlink= false;
            }
            else {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"아이템이 부족합니다.", 200, 250, 28);
                Text::notBlink= false;
            }
            break;
        case 3:
            if (Player::attackPotion >= 1) {
                potionPower+=10;
                Player::attackPotion -= 1;

                Text::notBlink= true;
                Pointer::text->textRender((char*)"공격력 강화 포션을 사용하여 공격력이 10증가하였습니다.", 150, 250, 28);
                SDL_Log("%s", std::to_string(potionPower).c_str());
                Text::notBlink= false;
            }
            else {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"아이템이 부족합니다.", 200, 250, 28);
                Text::notBlink= false;
            }
            break;
        case 4:
            if(Player::playerType!=0)
            {
                Player::playerType=0;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"망토를 벗었습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            else
            {
                Player::playerType=0;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"망토를 입고 있지 않습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            break;
        case 5:
            if(Player::fireCloak)
            {
                Player::playerType=1;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"불의 망토를 입었습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            else
            {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"불의 망토가 없습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            break;
        case 6:
            if(Player::waterCloak) {
                Player::playerType=2;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"물의 망토를 입었습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            else
            {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"물의 망토가 없습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            break;
        case 7:
            if(Player::leafCloak)  {
                Player::playerType=3;
                Text::notBlink= true;
                Pointer::text->textRender((char*)"풀의 망토를 입었습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            else
            {
                Text::notBlink= true;
                Pointer::text->textRender((char*)"풀의 망토가 없습니다.", 300, 250, 28);
                Text::notBlink= false;
                Player::Playermp += 3;
            }
            break;
        default:
            break;
    }
}
