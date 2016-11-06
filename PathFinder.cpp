/*
 * PathFinder.cpp
 *
 *  Created on: Nov 5, 2016
 *      Author: i_fly_gliders
 */

#include "PathFinder.h"

namespace pathfinding {

PathFinder::PathFinder()
	:activelist(),
	 board(Field, Field, Field, Field, Field,
		   Field, Field, Field, Field, Field,
		   Field, Field, Field, Field, Field,
		   Field, Field, Field, Field, Field,
		   Field, Field, Field, Field, Field),
	 goal(&board[4][4]),
	 startpoint(&board[0][0])
{
	activelist.push_back(startpoint);
}

PathFinder::~PathFinder()
{

}

void PathFinder::findPath()
{
	if(this->startpoint == this->goal){
		return;
	}
	do{
		/*for each field in activelist, activate the neighbors*/
		for(int i = 0; i < activelist.size(); i++){
			/*store position of current field*/
			Field* cur = activelist.at(i);
			unsigned int curx = cur->x();
			unsigned int cury = cur->y();

			/*store pointers to neighbors*/
			Field* right = board[curx+1][cury];
			Field* below = board[curx][cury+1];
			Field* left = board[curx-1][cury];
			Field* above = board[curx][cury-1];

			/*activate neighbors*/
			if(right->activate() ){
				right->set_distancetostart(cur->get_distancetostart() +1);
				right->set_parent(cur);
				this->new_activelist.push_back(right);
			}if(below->activate()){
				below->set_distancetostart(cur->get_distancetostart() +1);
				below->set_parent(cur);
				this->new_activelist.push_back(below);
			}if(left->activate()){
				left->set_distancetostart(cur->get_distancetostart() +1);
				left->set_parent(cur);
				this->new_activelist.push_back(left);
			}if(above->activate()){
				above->set_distancetostart(cur->get_distancetostart() +1);
				above->set_parent(cur);
				this->new_activelist.push_back(above);
			}
		}
		this->activelist = this->new_activelist();	//TODO check for leaks
	}
	while(1);	//TODO cancellation expression
}

} /* namespace pathfinding */
