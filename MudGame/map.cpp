#include "map.h"

void MAP::InitMap() {
	start.x = 1;
	start.y = 1;
	end.x = 38;
	end.y = 18;

	player = start;

	mapTag = 0;
	next = mapTag + 1;

	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == start.x && i == start.y) 
				map[i][j] = '$';
			else if(j == end.x && i == end.y)
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
	int li = 0;	//행

	mapFile.open(fileName, fstream::in);
	if (mapFile.is_open()) {
		//줄단위로 읽기
		while (getline(mapFile, data))
		{
			const char* temp = data.c_str();
			//0~19 까지는 맵 구성요소 정보
			if (li < HIG) {
				for (int cl = 0; cl < WID; cl++) {
					map[li][cl] = temp[cl];
				}
			}
			else {//20 부턴 맵 상세 정보
				if (li == HIG + 1)
					start.y = atoi(temp);
				if (li == HIG + 2)
					start.x = atoi(temp);
				if (li == HIG + 4)
					end.y = atoi(temp);
				if (li == HIG + 5)
					end.x = atoi(temp);
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
		cout << "맵을 불러오지 못했습니다." << endl;
	}
	mapFile.close();
}

void MAP::UpdateMap() {
	for (int i = 0; i < HIG; i++) {
		for (int j = 0; j < WID; j++) {
			if (j == start.x && i == start.y)
				map[i][j] = '$';
			else if (j == end.x && i == end.y)
				map[i][j] = '+';
		}
	}
	player = start;
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
	//이동하려는 위치가 맵 범위의 바깥
	if (curr_x<0 || curr_x>WID || curr_y<0 || curr_y>HIG)
		return;
	//이동하려는 위치에 무언가 없을때만 이동
	if (map[curr_y][curr_x] == ' ' || map[curr_y][curr_x] == '$') {
		targit.x = curr_x;
		targit.y = curr_y;
		return;
	}
	//이동위치에 무언가 있다면, 일단 이동시키지 않음.
	//무언가의 속성에 따라 정해진 동작 실행.
	THIGN element = decideThings(map[curr_y][curr_x]);
	//여기부턴 class로 바꿀 필요가 있을것 같음.
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