#include "Position.h"

Element::Element() {
	this->m_pos.x = 0;
	this->m_pos.y = 0;
	this->spec = THIGN::AIR;
}

Element::Element(int x, int y, THIGN spec)
{
	m_pos.x = x;
	m_pos.y = y;
	this->spec = spec;
}

Element::Element(Position pos, THIGN spec) {
	this->m_pos.x = pos.x;
	this->m_pos.y = pos.y;
	this->spec = spec;
}

Element::~Element() {

}

char Element::Spec2Char() {
	char temp;
	switch (spec)
	{
	case AIR:
		temp = ' ';
		break;
	case ST_POS:
		temp = '$';
		break;
	case EX_POS:
		temp = '+';
		break;
	case BOX:
		temp = 'm';
		break;
	case EVENT:
		temp = 'v';
		break;
	case SWITCH_ON:
		temp = 'o';
		break;
	case SWITCH_OFF:
		temp = 'u';
		break;
	case BODER:
		temp = '@';
		break;
	case PLAYER:
		temp = 'P';
		break;
	default:
		temp = ' ';
		break;
	}

	return temp;
}