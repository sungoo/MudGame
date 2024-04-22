#include "Display.h"

//�ٹ� Ÿ��Ʋ ���
string SelectTitle(SCENE scene) {
    string title;

    switch (scene)
    {
    case SCENE::TITLE_SCENE:
        title = "���ξ��� �ޡ�";
        break;
    case SCENE::MAIN_SCENE:
        title = "�ڸ��� ���ӡ�";
        break;
    case SCENE::INPUT_SCENE:
        title = "��ĳ���� ������";
        break;
    case SCENE::TOTAL_SCENE:
        title = "��ĳ���� Ȯ�Ρ�";
        break;
    case SCENE::QUIT:
        title = "�ڰ��� ����.��";
        break;
    default:
        title = "�������� �ʴ� �޴��Դϴ�. �ٽ� �õ����ּ���.";
        break;
    }

    return title;
}

void displayTitle(string title) {
    int screenWidth = 40;

    FillLine('=', screenWidth);
    CenterLetter('-', screenWidth, title);
    FillLine('=', screenWidth);
    cout << endl;
}

void displayMain(Character& ch, bool& isChMaded, MAP map) {
    if (!isChMaded) {
        cout << "ĳ���Ͱ� �������� �ʽ��ϴ�. ĳ���͸� ���� ������ּ���." << endl;
        return;
    }
    while (true)
    {
        system("cls");
        displayMap(map);
        displayCharacter(ch);
        DRECT dir = moveInput();

        if (dir == DRECT::FIN) break;

        Move(map.player, dir, map);
    }
}

void displayInput(Character& ch, bool& isChMaded) {
    char select = ' ';

    if (isChMaded) {
        cout << "ĳ���Ͱ� �̹� �����մϴ�.\n�缳���Ͻðڽ��ϱ�?" << endl;
        cout << "    Y    /    N    " << endl;
        cin >> select;
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        switch (select) {
        case 'Y':
        case 'y':
            CharacterInput(ch, isChMaded);
            break;
        case 'N':
        case 'n':
            cout << "ĳ���� ������ ����մϴ�." << endl;
            break;
        default:
            break;
        }
    }
    else {
        CharacterInput(ch, isChMaded);
    }
}

void displayCharacter(Character ch) {
    cout << "      ü��  ����  ���ݷ�  ����  �ӵ�" << endl;
    cout << ch.name << "   " << ch.hp << "/" << ch.MAX_hp << "   " << ch.mp << "/" << ch.MAX_mp << "    " << ch.atk << "      " << ch.def << "     " << ch.speed << endl;
}

void displayMap(MAP m) {
    for (int i = 0; i < HIG; i++) {
        for (int j = 0; j < WID; j++) {
            if (i == m.player.y && j == m.player.x)
                cout << 'P';
            else
                cout << m.map[i][j];
        }
        cout << "\n";
    }
    cout << "\nmap tag : " << m.mapTag << "  |  next : " << m.next << endl;
}