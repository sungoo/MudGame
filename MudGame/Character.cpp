#include "Character.h"
#include "Display.h"
#include "Line.h"

bool IsInRange(int input) {
    if (input >= 0)
        return true;
    else
        return false;
}
//ĳ���� �ʱ�ȭ
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
//ĳ���� ����
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
        displayTitle("��ĳ���� ������");
        this->Display();
        FillLine(' ', 50, false);
        cout << "����Ʈ : " << this->Total_point-usedPoint << endl;

        //��� �� ���� �Ϸ�, ��� ���� ����Ʈ ��� �Ҹ�.
        if (updateDone&& this->Total_point==usedPoint) {
            cout << "ĳ���� ���� �Ϸ�!" << endl;
            break;
        }

        if (usedPoint < this->Total_point) {
            cout << "����� �� �ִ� ����Ʈ�� �����ֽ��ϴ�. ���� �Ҹ����ּ���." << endl;
        }
        else if (usedPoint > this->Total_point) {
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
            cin >> this->name;
            isAllUpdated[NAME] = true;
            break;
        case M_HP:
            cout << "�ִ� HP : ";
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
            cout << "�ִ� MP : ";
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
            cout << "���ݷ� : ";
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
            cout << "���� : ";
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
            cout << "��ø : ";
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
            cout << "�߸��� �Է��Դϴ�. �ٽ� �Է����ּ���." << endl;
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
    cout << "      ü��  ����  ���ݷ�  ����  �ӵ�" << endl;
    cout << this->name << "   " << this->hp << "/" << this->MAX_hp << "   " << this->mp << "/" << this->MAX_mp << "    " << this->atk << "      " << this->def << "     " << this->speed << endl;
}