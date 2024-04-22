#pragma once
#include <iostream>
#include <fstream>
#include <string>
#define WID 40
#define HIG 20
using namespace std;

struct Position {
	int x;
	int y;
};

enum DRECT {
	NONE ,LEFT, UP, DOWN, RIGHT, FIN
};

enum THIGN {
	AIR,	//' '
	ST_POS,	//'$'
	EX_POS,	//'+'
	BOX,	//'m'
	EVENT,	//'v'
	SWITCH,	//'o', 'u'

	BODER,	//'@'
};

struct MAP {
	Position start;
	Position end;
	Position player;

	char map[HIG][WID];

	int mapTag;
	int next;
};

//맵 초기화
void InitMap(MAP& map);
//파일로부터 맵 불러오기
void RoadMap(MAP& map, string fileName);
//맵 업데이트
void UpdateMap(MAP& map);

//요소 구분시키기
THIGN decideThings(char element);

//요소의 이동
void Move(Position& targit,DRECT dir, MAP& map);

//이동 입력 받기
DRECT moveInput();