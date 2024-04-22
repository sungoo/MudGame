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

//�� �ʱ�ȭ
void InitMap(MAP& map);
//���Ϸκ��� �� �ҷ�����
void RoadMap(MAP& map, string fileName);
//�� ������Ʈ
void UpdateMap(MAP& map);

//��� ���н�Ű��
THIGN decideThings(char element);

//����� �̵�
void Move(Position& targit,DRECT dir, MAP& map);

//�̵� �Է� �ޱ�
DRECT moveInput();