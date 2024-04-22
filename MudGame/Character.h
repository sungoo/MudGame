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

//�Է��� ���� ������ �´��� üũ
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
//ĳ���� �ʱ�ȭ
void InitCharacter(Character& ch);
//ĳ���� ����
void CharacterInput(Character& ch, bool& isChMaded);
//ĳ���� ��������
void QuickChMake(Character& ch, bool& isChMaded);
*/