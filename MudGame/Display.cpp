#include "Display.h"

//꾸밈 타이틀 출력
string SelectTitle(SCENE scene) {
    string title;

    switch (scene)
    {
    case SCENE::TITLE_SCENE:
        title = "★인어의 달★";
        break;
    case SCENE::MAIN_SCENE:
        title = "★메인 게임★";
        break;
    case SCENE::INPUT_SCENE:
        title = "★캐릭터 생성★";
        break;
    case SCENE::TOTAL_SCENE:
        title = "★캐릭터 확인★";
        break;
    case SCENE::QUIT:
        title = "★게임 종료.★";
        break;
    default:
        title = "존재하지 않는 메뉴입니다. 다시 시도해주세요.";
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
        cout << "캐릭터가 존재하지 않습니다. 캐릭터를 먼저 만들어주세요." << endl;
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
        cout << "캐릭터가 이미 존재합니다.\n재설정하시겠습니까?" << endl;
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
            cout << "캐릭터 설정을 취소합니다." << endl;
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