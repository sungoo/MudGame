// MudGame.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "Display.h"
#include "Line.h"
#include "Character.h"
#include "Swap.h"

int main()
{
    //변수 선언
    SCENE scene;
    int menu;
    string title;
    Character user;
    MAP map1;

//초기화
    scene = SCENE::TITLE_SCENE;
    menu = 0;
    InitMap(map1);
    RoadMap(map1, "map1.txt");

//개발 요소
    user.QuickCHMade();

//로직
    while (true)
    {
        //화면 clear
        system("cls");

        title = SelectTitle(scene);
        displayTitle(title);

        switch (scene)
        {
        case TITLE_SCENE:
            break;
        case MAIN_SCENE:
            displayMain(user, map1);
            break;
        case INPUT_SCENE:
            displayInput(user);
            break;
        case TOTAL_SCENE:
            user.Display();
            break;
        default:
            break;
        }
        
        cout << "\n메뉴를 입력하세요." << endl;
        for (int i = 0; i < (int)SCENE::SCENE_MAX; i++) {
            cout << " | " << i << ". " << SelectTitle((SCENE)i);
        }cout << "|" << endl;
        
        cin >> menu;
        //입력으로 잘못된 유형의 값을 넣었을 때, 오류를 처리해주는 if문
        if (cin.fail()) {
            cin.clear();
            cin.ignore();
        }
        scene = (SCENE)menu;

        if (scene == SCENE::QUIT) {
            cout << "프로그램을 종료합니다.." << endl;
            break;
        }
    }
    
}