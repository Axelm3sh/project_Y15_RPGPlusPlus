/******************************************************
 * AUTHOR	: Samuel Yeaw
 * DATE		: Mar 22, 2015
 * NAME		: Area.cpp
 ******************************************************/

#include "Area.h"

// CONSTRUCTOR
Area::Area()
{
	name.clear();
	description.clear();
	options.clear();
}

// DESTRUCTOR
Area::~Area()
{

}

// Sets the name of the area
void Area::SetName(string aName)
{
	name = aName;
}

// Sets the description of the area
void Area::SetDescription(string aDescription)
{
	description = aDescription;
}

// Sets the options of the area
void Area::SetOptions(vector<string> someOptions)
{
	options = someOptions;
}

// Set the area to the north
void Area::SetNorth(string anArea)
{
	north = anArea;
}

// Set the area to the south
void Area::SetSouth(string anArea)
{
	south = anArea;
}

// Set the area to the east
void Area::SetEast(string anArea)
{
	east = anArea;
}

// Set the area to the west
void Area::SetWest(string anArea)
{
	west = anArea;
}

// Returns the name of the area
string Area::GetName()			const
{
	return name;
}

// Returns the description of the area
string Area::GetDescription()	const
{
	return description;
}

// Returns the area to the north
string Area::GetNorth()			const
{
	return north;
}

// Returns the area to the south
string Area::GetSouth()			const
{
	return south;
}

// Returns the area to the east
string Area::GetEast()			const
{
	return east;
}

// Returns the area to the west
string Area::GetWest()			const
{
	return west;
}

void Area::Print()				const
{
	int optionSize;
	int index;

	cout << name 		<< endl;
	cout << description << endl;
	cout << endl;

	optionSize = options.size();

	for(index = 0; index < optionSize; index++)
	{
		cout << options[index];
		cout << endl;
	}

	if(north != "none")
	{
		cout << "north ";
	}
	else if(south != "none")
	{
		cout << "south ";
	}
	else if(east != "none")
	{
		cout << "east ";
	}
	else if(west != "none")
	{
		cout << "west ";
	}

	cout << endl;
}
