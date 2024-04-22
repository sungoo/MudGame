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
	SWITCH,	//'o', 'u'

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
	virtual ~Element();
};