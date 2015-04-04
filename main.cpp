/******************************************************
 * AUTHOR	: Samuel Yeaw
 * DATE		: Mar 22, 2015
 * NAME		: main.cpp
 ******************************************************/

#include "Header.h"

int main()
{
	// VARIABLE DECLARATIONS
	ifstream	inFile;
	string		command;
	Map 		map;
	Creature	player;

	// LOAD MAP
	inFile.open("TestMap.txt");
	map.LoadMap(inFile);
	inFile.close();

	// LOOP - Screen is displayed
	map.Print();
	player.Print();
	cout << "-> ";
	getline(cin, command);
	cout << endl;

	while(command != "exit")
	{
		if(command == "north")
		{
			map.GoNorth();
		}
		else if(command == "south")
		{
			map.GoSouth();
		}
		else if(command == "east")
		{
			map.GoEast();
		}
		else if(command == "west")
		{
			map.GoWest();
		}
		else
		{
			cout << "*** Invalid Command ***\n\n";
		}

		map.Print();
		player.Print();
		cout << "-> ";
		getline(cin, command);
		cout << endl;
	}

	return 0;
}
