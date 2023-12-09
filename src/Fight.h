#ifndef BINGORPG_Fight_H
#define BINGORPG_Fight_H

#include<stdlib.h>
#include<time.h>

class Fight {
    int ALLPlayerATK{};
    int monsterhp;
    int temMonterHp;
    int monterATK{};
    int skillType{};
    char* system{};
public:
    static bool fightStart;
    int potionPower;
    Fight();
    void UI();
    int playerattck(int type);
    void monsterattack();
    float playerTypeAttack();
    float monsterTypeAttack();
    void addgold();
    void ItemUse(int n);
};

#endif //BINGORPG_Fight_H
