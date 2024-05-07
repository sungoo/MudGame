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
