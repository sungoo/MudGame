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

	//��¿� ����
	char map[HIG][WID];
	//��� ���� ����
	Element things[HIG][WID];

	int mapTag;
	int next;

public:
	//�� �ʱ�ȭ
	void InitMap();
	//���Ϸκ��� �� �ҷ�����
	void RoadMap(string fileName);
	//�� ������Ʈ
	void UpdateMap();
	//����� �̵�
	void Move(Position& targit, DRECT dir);
	//��ü�� ��ġ�� ���� �� ������Ʈ
	//=>things�� ������ ��¿� map(char[][])�� ������Ʈ
	void Compare(Element targit);
};

//��� ���н�Ű��
THIGN decideThings(char element);

//�̵� �Է� �ޱ�
DRECT moveInput();