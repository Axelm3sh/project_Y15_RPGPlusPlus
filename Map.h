/******************************************************
 * AUTHOR	: Samuel Yeaw
 * DATE		: Mar 22, 2015
 * NAME		: Map.h
 ******************************************************/

#ifndef MAP_H_
#define MAP_H_

// PRE-PROCESSOR DIRECTIVES

#include <fstream>
#include <string>
#include <vector>
#include "Area.h"
using namespace std;

/******************************************************
 * CLASS Map
 * ----------------------------------------------------
 * This class represents a collection of areas that
 * can be navigated through
 ******************************************************/
class Map
{
private:
	/*ATTRIBURES*/
	string			mapName;
	vector<Area>	areas;
	Area			currentPosition;

	/*PRIVATE METHODS*/
	bool SearchAndSetArea(string anArea);
public:
	/*METHODS*/
	Map();
	~Map();

	// MUTATORS
	void LoadMap(ifstream& inFile);
	bool GoNorth();
	bool GoSouth();
	bool GoEast();
	bool GoWest();

	// ACCESSORS
	void Print()	const;
};

#endif /* MAP_H_ */
