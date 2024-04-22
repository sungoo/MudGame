#include "map.h"

void InitMap(MAP& map) {
	map.start.x = 1;
	map.start.y = 1;
	map.end.x = 38;
	map.end.y = 18;

	map.player = map.start;

	map.mapTag = 0;
	map.next = map.mapTag + 1;

	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == map.start.x && i == map.start.y) 
				map.map[i][j] = '$';
			else if(j == map.end.x && i == map.end.y)
				map.map[i][j] = '+';
			else {
				if(i == 0 || i == HIG-1) 
					map.map[i][j] = '@';
				else if (j == 0 || j == WID-1) 
					map.map[i][j] = '@';
				else
					map.map[i][j] = ' ';
			}
		}
	}

	return;
}

void RoadMap(MAP& map, string fileName) {
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
					map.map[li][cl] = temp[cl];
				}
			}
			else {//20 ���� �� �� ����
				if (li == HIG + 1)
					map.start.y = atoi(temp);
				if (li == HIG + 2)
					map.start.x = atoi(temp);
				if (li == HIG + 4)
					map.end.y = atoi(temp);
				if (li == HIG + 5)
					map.end.x = atoi(temp);
				if (li == HIG + 7)
					map.mapTag = atoi(temp);
				if (li == HIG + 9)
					map.next = atoi(temp);
			}
			li++;
		}
		UpdateMap(map);
	}
	else {
		cout << "���� �ҷ����� ���߽��ϴ�." << endl;
	}
	mapFile.close();
}

void UpdateMap(MAP& map) {
	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == map.start.x && i == map.start.y)
				map.map[i][j] = '$';
			else if (j == map.end.x && i == map.end.y)
				map.map[i][j] = '+';
		}
	}
	map.player = map.start;
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
	case 'u':
		return THIGN::SWITCH;
	case '@':
		return THIGN::BODER;
	default:
		return THIGN::AIR;
	}
}

void Move(Position& targit, DRECT dir, MAP& map) {
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
	if (map.map[curr_y][curr_x] == ' ' || map.map[curr_y][curr_x] == '$') {
		targit.x = curr_x;
		targit.y = curr_y;
		return;
	}
	//�̵���ġ�� ���� �ִٸ�, �ϴ� �̵���Ű�� ����.
	//������ �Ӽ��� ���� ������ ���� ����.
	THIGN element = decideThings(map.map[curr_y][curr_x]);
	//������� class�� �ٲ� �ʿ䰡 ������ ����.
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