#pragma once
#include <string>
using namespace std;

struct Character {
    string name;
    unsigned int MAX_hp;
    unsigned int MAX_mp;
    unsigned int hp;
    unsigned int mp;
    unsigned int atk;
    unsigned int def;
    unsigned int speed;
    int Total_point;
};
//캐릭터 초기화
void InitCharacter(Character& ch);
//캐릭터 생성
void CharacterInput(Character& ch, bool& isChMaded);
//캐릭터 빠른생성
void QuickChMake(Character& ch, bool& isChMaded);