#include "Character.h"
#include "Display.h"
#include "Line.h"

//입력한 값이 범위에 맞는지 체크
bool IsInRange(int input) {
    if (input >= 0)
        return true;
    else
        return false;
}
//캐릭터 초기화
void InitCharacter(Character& ch) {
    ch.name = "000";
    ch.MAX_hp = 0;
    ch.MAX_mp = 0;
    ch.hp = 0;
    ch.mp = 0;
    ch.atk = 0;
    ch.def = 0;
    ch.speed = 0;
    ch.Total_point = 200;
}
//캐릭터 생성
void CharacterInput(Character& ch, bool& isChMaded) {
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
        displayCharacter(ch);
        FillLine(' ', 50, false);
        cout << "포인트 : " << ch.Total_point-usedPoint << endl;

        //모든 값 저장 완료, 사용 가능 포인트 모두 소모.
        if (updateDone&&ch.Total_point==usedPoint) {
            cout << "캐릭터 생성 완료!" << endl;
            break;
        }

        if (usedPoint < ch.Total_point) {
            cout << "사용할 수 있는 포인트가 남아있습니다. 전부 소모해주세요." << endl;
        }
        else if (usedPoint > ch.Total_point) {
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
            cin >> ch.name;
            isAllUpdated[NAME] = true;
            break;
        case M_HP:
            cout << "최대 HP : ";
            cin >> inputTEMP;
            if(IsInRange(inputTEMP))
                ch.MAX_hp = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            ch.hp = ch.MAX_hp;
            isAllUpdated[M_HP] = true;
            break;
        case M_MP:
            cout << "최대 MP : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                ch.MAX_mp = inputTEMP;
            else {
                inputTEMP = -1;
                break;
            }
            ch.mp = ch.MAX_mp;
            isAllUpdated[M_MP] = true;
            break;
        case ATK:
            cout << "공격력 : ";
            cin >> inputTEMP;
            if (IsInRange(inputTEMP))
                ch.atk = inputTEMP;
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
                ch.def = inputTEMP;
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
                ch.speed = inputTEMP;
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

        usedPoint = ch.MAX_hp + ch.MAX_mp + ch.atk + ch.def + ch.speed;
    }

    isChMaded = true;
}

void QuickChMake(Character& ch, bool& isChMaded) {
    ch.name = "aaa";
    ch.MAX_hp = 40;
    ch.MAX_mp = 40;
    ch.hp = 40;
    ch.mp = 40;
    ch.atk = 40;
    ch.def = 40;
    ch.speed = 40;
    ch.Total_point = 200;

    isChMaded = true;
}