#include "Character.h"
#include "Display.h"
#include "Line.h"

//�Է��� ���� ������ �´��� üũ
bool IsInRange(int input) {
    if (input >= 0)
        return true;
    else
        return false;
}
//ĳ���� �ʱ�ȭ
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
//ĳ���� ����
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
        displayTitle("��ĳ���� ������");
        displayCharacter(ch);
        FillLine(' ', 50, false);
        cout << "����Ʈ : " << ch.Total_point-usedPoint << endl;

        //��� �� ���� �Ϸ�, ��� ���� ����Ʈ ��� �Ҹ�.
        if (updateDone&&ch.Total_point==usedPoint) {
            cout << "ĳ���� ���� �Ϸ�!" << endl;
            break;
        }

        if (usedPoint < ch.Total_point) {
            cout << "����� �� �ִ� ����Ʈ�� �����ֽ��ϴ�. ���� �Ҹ����ּ���." << endl;
        }
        else if (usedPoint > ch.Total_point) {
            cout << "��� ������ ����Ʈ�� �ʰ��Ͽ����ϴ�. �Ѵ� ���� �ٿ��ּ���." << endl;
        }

        cout << "�ٲٰ��� �ϴ� ��Ҹ� �����ϼ���." << endl;
        cout << Check(isAllUpdated[NAME]) << "1. �̸�  |  " << Check(isAllUpdated[M_HP]) << "2. ü��  |  " << Check(isAllUpdated[M_MP]) << "3. ���ŷ�  |  " << Check(isAllUpdated[ATK]) << "4. ���ݷ�  |  " << Check(isAllUpdated[DEF]) << "5. ����  |  " << Check(isAllUpdated[SPD]) << "6. ��ø\n" << endl;

        if (inputTEMP != -1) {
            cin >> select;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "���� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;
            }
        }
        else
            cout << "���� �߸��Ǿ����ϴ�. �ٽ� �Է����ּ���." << endl;

        element = (CH_E)(select-1);

        switch (element)
        {
        case NAME:
            cout << "�̸� : ";
            cin >> ch.name;
            isAllUpdated[NAME] = true;
            break;
        case M_HP:
            cout << "�ִ� HP : ";
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
            cout << "�ִ� MP : ";
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
            cout << "���ݷ� : ";
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
            cout << "���� : ";
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
            cout << "��ø : ";
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
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
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