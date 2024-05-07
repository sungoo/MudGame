#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include "Position.h"
#define WID 40
#define HIG 20
using namespace std;

class MAP {
	Element start;
	Element end;
	Element player;

	//출력용 버퍼
	char map[HIG][WID];
	//요소 정보 버퍼
	Element things[HIG][WID];

	int mapTag;
	int next;

public:
	//맵 초기화
	void InitMap();
	//파일로부터 맵 불러오기
	void RoadMap(string fileName);
	//맵 업데이트
	void UpdateMap();
	//요소의 이동
	void Move(Position& targit, DRECT dir);
	//객체의 위치에 따라 맵 업데이트
	//=>things의 정보를 출력용 map(char[][])에 업데이트
	void Compare(Element targit);
};

//요소 구분시키기
THIGN decideThings(char element);

//이동 입력 받기
DRECT moveInput();