/******************************************************
 * AUTHOR	: Samuel Yeaw
 * DATE		: Mar 22, 2015
 * NAME		: Area.h
 ******************************************************/

#ifndef AREA_H_
#define AREA_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
#include <string>
#include <vector>
using namespace std;

/******************************************************
 * CLASS Area
 * ----------------------------------------------------
 * This class represents a single area in a map. It
 * includes the area name, description, and a list of
 * possible options
 ******************************************************/
class Area
{
private:
	/*ATTRIBUTES*/
	// Each area has a name, a description, and the names of all the
	// areas it leads to. It also contains a list of the options
	// the player can choose
	string 			name;			// Name of the area
	string 			description;	// Description of the area
	string			north;			// Area to the north
	string			south;			// Area to the south
	string			east;			// Area to the east
	string			west;			// Area to the west
	vector<string> 	options;		// Options the player can choose

public:
	/*METHODS*/
	Area();						// Default Constructor
	~Area();					// Destructor

	// MUTATORS
	void SetName(string aName);						// Set the area's name
	void SetDescription(string aDescription);		// Set the area's description
	void SetOptions(vector<string> someOptions);	// Set the area's options
	void SetNorth(string anArea);					// Set the north area
	void SetSouth(string anArea);					// Set the south area
	void SetEast(string anArea);					// Set the east area
	void SetWest(string anArea);					// Set the west area

	// ACCESSORS
	string GetName()		const;				// Returns the area's name
	string GetDescription()	const;				// Returns the area's description
	string GetNorth()		const;				// Returns the north area
	string GetSouth()		const;				// Returns the south area
	string GetEast()		const;				// Returns the east area
	string GetWest()		const;				// Returns the west area
	void   Print()			const;				// Prints the area's info to
												// the screen
};

#endif /* AREA_H_ */
