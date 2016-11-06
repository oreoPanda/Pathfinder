/*
 * Field.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: i_fly_gliders
 */

#include "Field.h"

namespace pathfinding {

Field::Field(unsigned int x, unsigned int y)
	:state(Field::INACTIVE),
	 distance(0),
	 parent(nullptr)
{

}

Field::~Field()
{

}

bool Field::activate()
{
	if(this->state != Field::INACTIVE){
		return false;
	}
	else{
		this->state = Field::ACTIVE;
		return true;
	}
}

unsigned int Field::get_distancetostart()
{
	return this->distance;
}

Field::FieldState Field::get_state()
{
	return this->state;
}

bool Field::pass()
{
	if(this->state != Field::ACTIVE){
		return false;
	}
	else{
		this->state = Field::PASSED;
		return true;
	}
}

void Field::set_distancetostart(unsigned int d)
{
	this->distance = d;
}

void Field::set_parent(const Field* parent)
{
	this->parent = parent;
}

unsigned int Field::x()
{
	return this->pos.x;
}

unsigned int Field::y()
{
	return this->pos.y();
}

} /* namespace pathfinding */
