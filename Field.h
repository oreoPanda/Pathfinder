/*
 * Field.h
 *
 *  Created on: Nov 5, 2016
 *      Author: i_fly_gliders
 */

#ifndef FIELD_H_
#define FIELD_H_

namespace pathfinding {

class Field {
public:
	enum FieldState{
		ACTIVE,
		INACTIVE,
		PASSED
	};
	struct Position{
		unsigned int x;
		unsigned int y;
	};
	Field(unsigned int x, unsigned int y);
	virtual ~Field();
	bool activate();
	unsigned int get_distancetostart();
	FieldState get_state();
	bool pass();
	void set_distancetostart(unsigned int d);
	void set_parent(const Field* parent);
	unsigned int x();
	unsigned int y();

private:
	FieldState state;
	int distance;
	const Field *parent;
	Position pos;
};

} /* namespace pathfinding */

#endif /* FIELD_H_ */
