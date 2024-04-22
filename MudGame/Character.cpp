#include "Character.h"
#include "Display.h"
#include "Line.h"

bool IsInRange(int input) {
    if (input >= 0)
        return true;
    else
        return false;
}
//캐릭터 초기화
Character::Character() {
    this->name = "000";
    this->MAX_hp = 0;
    this->MAX_mp = 0;
    this->hp = 0;
    this->mp = 0;
    this->atk = 0;
    this->def = 0;
    this->speed = 0;
    this->Total_point = 200;

    this->isChMaded = false;
}
Character::~Character() {

}
//캐릭터 생성
void Character::Input() {
    CH_E element = CH_E::MAXIMUM;
    bool isAllUpdated[CH_E::MAXIMUM] = { false, };
    bool updateDone = false;
    int select = 0;
    int usedPoint = 0;
    int inputTEMP = 0;

    while (true)
    {
        system("cls");
        displayTitle("★캐릭터 생성★");
        this->Display();
        FillLine(' ', 50, false);
        cout << "포인트 : " << this->Total_point-usedPoint << endl;

        //모든 값 저장 완료, 사용 가능 포인트 모두 소모.
        if (updateDone&& this->Total_point==usedPoint) {
            cout << "캐릭터 생성 완료!" << endl;
            break;
        }

        if (usedPoint < this->Total_point) {
            cout << "사용할 수 있는 포인트가 남아있습니다. 전부 소모해주세요." << endl;
        }
        else if (usedPoint > this->Total_point) {
            cout << "사용 가능한 포인트를 초과하였습니다. 넘는 값을 줄여주세요." << endl;
        }

        cout << "바꾸고자 하는 요소를 선택하세요." << endl;
        cout << Check(isAllUpdated[NAME]) << "1. 이름  |  " << Check(isAllUpdated[M_HP]) << "2. 체력  |  " << Check(isAllUpdated[M_MP]) << "3. 정신력  |  " << Check(isAllUpdated[ATK]) << "4. 공격력  |  " << Check(isAllUpdated[DEF]) << "5. 방어력  |  " << Check(isAllUpdated[SPD]) << "6. 민첩\n" << endl;

        if (inputTEMP != -1) {
            cin >> select;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "값이 잘못되었습니다. 다시 입력해주세요." << endl;
            }
        }
        else
            cout << "값이 잘못되었습니다. 다시 입력해주세요." << endl;

        element = (CH_E)(select-1);

        switch (element)
        {
        case NAME:
            cout << "이름 : ";
            cin >> this->name;
            isAllUpdated[NAME] = true;
            break;
        case M_HP:
            cout << "최대 HP : ";
            cin >> inputTEMP;
            if(IsInRange(inputTEMP))
                this->MAX_hp = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            this->hp = this->MAX_hp;
            isAllUpdated[M_HP] = true;
            break;
        case M_MP:
            cout << "최대 MP : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                this->MAX_mp = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            this->mp = this->MAX_mp;
            isAllUpdated[M_MP] = true;
            break;
        case ATK:
            cout << "공격력 : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                this->atk = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            isAllUpdated[ATK] = true;
            break;
        case DEF:
            cout << "방어력 : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                this->def = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            isAllUpdated[DEF] = true;
            break;
        case SPD:
            cout << "민첩 : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                this->speed = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            isAllUpdated[SPD] = true;
            break;
        default:
            cout << "잘못된 입력입니다. 다시 입력해주세요." << endl;
            break;
        }

        if (isAllUpdated[NAME] && isAllUpdated[M_HP] && isAllUpdated[M_MP] && isAllUpdated[ATK] && isAllUpdated[DEF] && isAllUpdated[SPD]) updateDone = true;

        usedPoint = this->MAX_hp + this->MAX_mp + this->atk + this->def + this->speed;
    }

    this->isChMaded = true;
}

void Character::QuickCHMade() {
    this->name = "aaa";
    this->MAX_hp = 40;
    this->MAX_mp = 40;
    this->hp = 40;
    this->mp = 40;
    this->atk = 40;
    this->def = 40;
    this->speed = 40;
    this->Total_point = 200;

    isChMaded = true;
}

void Character::Display() {
    cout << "      체력  마력  공격력  방어력  속도" << endl;
    cout << this->name << "   " << this->hp << "/" << this->MAX_hp << "   " << this->mp << "/" << this->MAX_mp << "    " << this->atk << "      " << this->def << "     " << this->speed << endl;
}