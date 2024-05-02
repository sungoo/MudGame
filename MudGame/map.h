#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Position.h"
#define WID 40
#define HIG 20
using namespace std;

class MAP {
	Position start;
	Position end;
	Position player;

	char map[HIG][WID];

	int mapTag;
	int next;

public:
	//맵 초기화
	void InitMap();
	//파일로부터 맵 불러오기
	void RoadMap(string fileName);
	//맵 업데이트
	void UpdateMap();
};



//요소 구분시키기
THIGN decideThings(char element);

//요소의 이동
void Move(Position& targit,DRECT dir, MAP& map);

//이동 입력 받기
DRECT moveInput();