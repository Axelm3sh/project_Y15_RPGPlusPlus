/******************************************************
 * AUTHOR	: Samuel Yeaw
 * DATE		: Mar 22, 2015
 * NAME		: Map.cpp
 ******************************************************/

#include "Map.h"

Map::Map()
{
	mapName.clear();
	areas.clear();
}

Map::~Map()
{
	for(int i = 0; i < 4; i++)
	{
		areas[i].Print();
	}
}

// Searches for an area and sets the current position
// to it
bool Map::SearchAndSetArea(string anArea)
{
	// VARIABLE DECLARATIONS
	int  index;
	bool validArea;

	index 		= 0;
	validArea	= false;

	// Goes through the vector of areas and checks them
	// with the area name passed as a parameter
	while(index < signed(areas.size()) && !validArea)
	{
		// If there is a match, the current position is
		// set to the new area
		if(areas[index].GetName() == anArea)
		{
			currentPosition = areas[index];
			validArea		= true;
		}
		else
		{
			index++;
		}
	}

	return validArea;
}

void Map::LoadMap(ifstream& inFile)
{
	// VARIABLE DECLARATIONS
	string 			name;
	string 			description;
	string			anOption;
	string			north;
	string			south;
	string			east;
	string			west;
	vector<string>  options;
	Area   			newArea;

	// Get the name of the map
	getline(inFile, mapName);

	// Loop to input each area in the map
	while(!inFile.eof())
	{
		// Get the name and description of the area
		getline(inFile, name);
		getline(inFile, description);

		// Get all the options the user can choose
		// for the area
		getline(inFile, anOption);

		while(anOption != "end")
		{
			options.push_back(anOption);
			getline(inFile, anOption);
		}

		// Get all the directions the user can move to
		getline(inFile, north);
		getline(inFile, south);
		getline(inFile, east);
		getline(inFile, west);

		inFile.ignore(1000, '\n');

		// Set these values in the area
		newArea.SetName(name);
		newArea.SetDescription(description);
		newArea.SetOptions(options);
		newArea.SetNorth(north);
		newArea.SetSouth(south);
		newArea.SetEast(east);
		newArea.SetWest(west);

		// Add the area to the vector of areas
		areas.push_back(newArea);
	}

	// The starting position of the player is set to the
	// first area
	currentPosition = areas[0];
}

// Move the current position to the north
bool Map::GoNorth()
{
	// VARIABLE DECLARATIONS
	bool goNorth;

	// Checks to see if the player can go north,
	// then sets the players position to area to
	// the north
	if(currentPosition.GetNorth() == "none")
	{
		cout << "You cannot go north here... \n\n";
		goNorth = false;
	}
	else
	{
		if(!SearchAndSetArea(currentPosition.GetNorth()))
		{
			cout << "*** Error with Map! ***\n\n";
		}

		goNorth = true;
	}

	return goNorth;
}

// Move the current position to the south
bool Map::GoSouth()
{
	// VARIABLE DECLARATIONS
	bool goSouth;

	// Checks to see if the player can go south,
	// then sets the players position to area to
	// the south
	if(currentPosition.GetSouth() == "none")
	{
		cout << "You cannot go south here... \n\n";
		goSouth = false;
	}
	else
	{
		if(!SearchAndSetArea(currentPosition.GetSouth()))
		{
			cout << "*** Error with Map! ***\n\n";
		}

		goSouth = true;
	}

	return goSouth;
}

// Move the current position to the east
bool Map::GoEast()
{
	// VARIABLE DECLARATIONS
	bool goEast;

	// Checks to see if the player can go east,
	// then sets the players position to area to
	// the east
	if(currentPosition.GetEast() == "none")
	{
		cout << "You cannot go east here... \n\n";
		goEast = false;
	}
	else
	{
		if(!SearchAndSetArea(currentPosition.GetEast()))
		{
			cout << "*** Error with Map! ***\n\n";
		}

		goEast = true;
	}

	return goEast;
}

// Move the current position to the west
bool Map::GoWest()
{
	// VARIABLE DECLARATIONS
	bool goWest;

	// Checks to see if the player can go west,
	// then sets the players position to area to
	// the west
	if(currentPosition.GetWest() == "none")
	{
		cout << "You cannot go west here... \n\n";
		goWest = false;
	}
	else
	{
		if(!SearchAndSetArea(currentPosition.GetWest()))
		{
			cout << "*** Error with Map! ***\n\n";
		}

		goWest = true;
	}

	return goWest;
}

void Map::Print()	const
{
	cout << mapName << ": ";

	currentPosition.Print();


}
