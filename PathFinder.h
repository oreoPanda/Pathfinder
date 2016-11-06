/*
 * PathFinder.h
 *
 *  Created on: Nov 5, 2016
 *      Author: i_fly_gliders
 */

#ifndef PATHFINDER_H_
#define PATHFINDER_H_

#include "Field.h"
#include <vector>

using namespace std;

namespace pathfinding {

class PathFinder {
public:
	PathFinder();
	virtual ~PathFinder();
	void findPath();

private:
	vector<Field*> activelist;
	Field board[5][5];
	Field* const goal;
	vector<Field*> new_activelist;
	Field* const startpoint;
};

} /* namespace pathfinding */

#endif /* PATHFINDER_H_ */
