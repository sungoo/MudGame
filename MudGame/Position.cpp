#include "Position.h"

Element::Element() {
	this->m_pos.x = 0;
	this->m_pos.y = 0;
	this->spec = THIGN::AIR;
}

Element::Element(Position pos, THIGN spec) {
	this->m_pos.x = pos.x;
	this->m_pos.y = pos.y;
	this->spec = spec;
}