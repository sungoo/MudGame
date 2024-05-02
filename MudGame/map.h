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
	//�� �ʱ�ȭ
	void InitMap();
	//���Ϸκ��� �� �ҷ�����
	void RoadMap(string fileName);
	//�� ������Ʈ
	void UpdateMap();
};



//��� ���н�Ű��
THIGN decideThings(char element);

//����� �̵�
void Move(Position& targit,DRECT dir, MAP& map);

//�̵� �Է� �ޱ�
DRECT moveInput();