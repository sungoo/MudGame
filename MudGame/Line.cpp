#include "Line.h"

//한 줄을 원하는 칸 만큼 원하는 문자로 채우기
void FillLine(char ch, int length, bool change) {
    for (int i = 0; i < length; i++) {
        cout << ch;
    }
    if (change)
        cout << endl;
}

//중앙에 원하는 문자열을 넣고 가운데 정렬하기
void CenterLetter(char ch, int length, string letter) {
    FillLine(ch, length / 2 - letter.length() / 2 - 1, false);
    cout << letter;
    FillLine(ch, length / 2 - letter.length() / 2, true);
}

//체크표시 생성
char Check(bool mark) {
    if (mark)
        return 'v';
    else
        return ' ';
}