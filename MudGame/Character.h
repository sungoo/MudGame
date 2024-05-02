#pragma once
#include <string>
#include "Position.h"
using namespace std;

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
