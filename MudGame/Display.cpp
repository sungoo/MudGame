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

void displayMain(Character& ch, MAP map) {
    if (!ch.isChMaded) {
        cout << "ĳ���Ͱ� �������� �ʽ��ϴ�. ĳ���͸� ���� ������ּ���." << endl;
        return;
    }
    while (true)
    {
        system("cls");
        displayMap(map);
        ch.Display();
        DRECT dir = moveInput();

        if (dir == DRECT::FIN) break;

        Move(map.player, dir, map);
    }
}

void displayInput(Character& ch) {
    char select = ' ';

    if (ch.isChMaded) {
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
            ch.Input();
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
        ch.Input();
    }
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