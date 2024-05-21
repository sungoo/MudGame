#pragma once

struct Position {
	int x;
	int y;
};

enum DRECT {
	NONE, LEFT, UP, DOWN, RIGHT, FIN
};

enum THIGN {
	AIR,	//' '
	ST_POS,	//'$'
	EX_POS,	//'+'
	BOX,	//'m'
	EVENT,	//'v'
	SWITCH_ON,	//'o'
	SWITCH_OFF,	//'u'
	BODER,	//'@'
	PLAYER,	//'P'
};

class Element
{
public:
	Position m_pos;
	THIGN spec;

	Element();
	Element(Position pos, THIGN spec);
	Element(int x, int y, THIGN spec);
	virtual ~Element();

	char Spec2Char();
};