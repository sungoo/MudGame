#include "map.h"

void MAP::InitMap() {
	start.m_pos.x = 1;
	start.m_pos.y = 1;
	end.m_pos.x = 38;
	end.m_pos.y = 18;

	player = start;

	mapTag = 0;
	next = mapTag + 1;

	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == start.m_pos.x && i == start.m_pos.y) 
				map[i][j] = '$';
			else if(j == end.m_pos.x && i == end.m_pos.y)
				map[i][j] = '+';
			else {
				if(i == 0 || i == HIG-1) 
					map[i][j] = '@';
				else if (j == 0 || j == WID-1) 
					map[i][j] = '@';
				else
					map[i][j] = ' ';
			}
		}
	}

	return;
}

void MAP::RoadMap(string fileName) {
	ifstream mapFile;
	string data;
	int li = 0;	//��

	mapFile.open(fileName, fstream::in);
	if (mapFile.is_open()) {
		//�ٴ����� �б�
		while (getline(mapFile, data))
		{
			const char* temp = data.c_str();
			//0~19 ������ �� ������� ����
			if (li < HIG) {
				for (int cl = 0; cl < WID; cl++) {
					//��� ���� ������Ʈ
					map[li][cl] = temp[cl];
					//���� ���� ������Ʈ
					things[li][cl] = Element(li, cl, decideThings(temp[cl]));
				}
			}
			else {//20 ���� �� �� ����
				if (li == HIG + 1)
					start.m_pos.y = atoi(temp);
				if (li == HIG + 2)
					start.m_pos.x = atoi(temp);
				if (li == HIG + 4)
					end.m_pos.y = atoi(temp);
				if (li == HIG + 5)
					end.m_pos.x = atoi(temp);
				if (li == HIG + 7)
					mapTag = atoi(temp);
				if (li == HIG + 9)
					next = atoi(temp);
			}
			li++;
		}
		UpdateMap();
	}
	else {
		cout << "���� �ҷ����� ���߽��ϴ�." << endl;
	}
	mapFile.close();
}

void MAP::UpdateMap() {
	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == start.m_pos.x && i == start.m_pos.y) {
				map[i][j] = '$';
				things[i][j] = start;
			}
			else if (j == end.m_pos.x && i == end.m_pos.y) {
				map[i][j] = '+';
				things[i][j] = end;
			}
		}
	}
	player.m_pos = start.m_pos;
}

void MAP::Move(Position& targit, DRECT dir) {
	int curr_x = targit.x;
	int curr_y = targit.y;

	switch (dir)
	{
	case NONE:
		break;
	case LEFT:
		curr_x--;
		break;
	case UP:
		curr_y--;
		break;
	case DOWN:
		curr_y++;
		break;
	case RIGHT:
		curr_x++;
		break;
	}
	//�̵��Ϸ��� ��ġ�� �� ������ �ٱ�
	if (curr_x<0 || curr_x>WID || curr_y<0 || curr_y>HIG)
		return;
	//�̵��Ϸ��� ��ġ�� ���� �������� �̵�
	if (map[curr_y][curr_x] == ' ' || map[curr_y][curr_x] == '$') {
		targit.x = curr_x;
		targit.y = curr_y;
		return;
	}
	//�̵���ġ�� ���� �ִٸ�, �ϴ� �̵���Ű�� ����.
	//������ �Ӽ��� ���� ������ ���� ����.
	THIGN element = decideThings(map[curr_y][curr_x]);
	//������� class�� �ٲ� �ʿ䰡 ������ ����.
}

void MAP::Compare()
{
	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			map[i][j] = things[i][j].Spec2Char();
		}
	}
}


THIGN decideThings(char element) {
	switch (element)
	{
	case ' ':
		return THIGN::AIR;
	case '$':
		return THIGN::ST_POS;
	case '+':
		return THIGN::EX_POS;
	case 'm':
		return THIGN::BOX;
	case 'v':
		return THIGN::EVENT;
	case 'o':
		return THIGN::SWITCH_ON;
	case 'u':
		return THIGN::SWITCH_OFF;
	case '@':
		return THIGN::BODER;
	default:
		return THIGN::AIR;
	}
}

DRECT moveInput() {
	DRECT dir = DRECT::NONE;
	char input = ' ';

	cout << "How to move : \n" << "a : Left  |  w : Up  |  s : Down  |  d : Right  |  q : Quit" << endl;

	cin >> input;
	switch (input)
	{
	//Left
	case 'a':
	case 'A':
		dir = LEFT;
		break;
	//UP
	case 'w':
	case 'W':
		dir = UP;
		break;
	//Down
	case 's':
	case 'S':
		dir = DOWN;
		break;
	//Right
	case 'd':
	case 'D':
		dir = RIGHT;
		break;
	//Quit
	case 'q':
	case 'Q':
		dir = FIN;
		break;
	default:
		dir = NONE;
		break;
	}

	return dir;
}