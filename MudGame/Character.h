#pragma once
#include <string>
#include "Position.h"
using namespace std;

/*
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
*/

//입력한 값이 범위에 맞는지 체크
bool IsInRange(int input);

class Character: public Element {
private:
    string name;
    unsigned int MAX_hp;
    unsigned int MAX_mp;
    unsigned int hp;
    unsigned int mp;
    unsigned int atk;
    unsigned int def;
    unsigned int speed;
    int Total_point;

public:
    bool isChMaded;

    Character();
    ~Character();
    
    void Input();
    void QuickCHMade();
    void Display();
};
/*
//캐릭터 초기화
void InitCharacter(Character& ch);
//캐릭터 생성
void CharacterInput(Character& ch, bool& isChMaded);
//캐릭터 빠른생성
void QuickChMake(Character& ch, bool& isChMaded);
*/