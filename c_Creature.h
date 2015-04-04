#ifndef C_DIALOGUE_H_
#define C_DIALOGUE_H_

// PRE-PROCESSOR DIRECTIVES

#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <string>
using namespace std;

/*****************************************************
 * CLASS Creature
 * ---------------------------------------------------
 * This class is a base class representing a creature
 * and all of its characteristics
 *****************************************************/
class Creature
{
public:
	/*MEHTODS*/
	Creature(); 					// Default Constructor
	Creature(string	name,
			 int 	health,
			 int 	str,
			 int 	end,
			 int 	dex,
			 double hitRate,
			 unsigned int level,
			 string className);		// NonDefault Constructor
	~Creature();						// Destructor

	// MUTATORS
	void SetName(string aName);		// Sets the name of the creature
	void SetClass(string aClass);	// Sets the class of the character

	// Calculates the experience required to reach a certain level,
	// *in total*
	unsigned int expToLevel(unsigned int level);

	// Level the creature to the next level if it has
	// enough experience to do so, returning true if it could
	// level up and false otherwise.
	bool levelUp();

	// ACCESSORS
	string GetName()	const;		// Returns the name of the creature
	string GetClass()	const;		// Returns the class of the creature
	int GetStrength()	const;		// Returns the creature's strength
	int GetEndurance()	const;		// Returns the creature's endurance
	int GetDexterity()	const;		// Returns the creature's dexterity
	int GetHealth()		const;		// Returns the creature's health
	int GetMaxHealth()	const;		// Returns the creature's max health
	int GetHitRate()	const;		// Returns the creature's hit rate
	int GetLevel()		const;		// Returns the creature's level
	int GetExperience()	const;		// Returns the creature's experience
	void Print()		const;		// Prints the creature's information to the screen

private:
	/*ATTRIBUTES*/
	// Name of the creature and the name of its class, if it has one
	// Class may be Fighter, Rogue etc
	// I will refer to the class as 'vocation' out of the code,
	// in order to ease confusion
	string creatureName;
	string className;

	// Creature stats. Reasonable values are in parentheses
	int health;     // Current hit points (10-1000+)
	int maxHealth;  // Maximum hit points (10-1000+)
	int str;        // Strength. Determines damage in battle (1-100)
	int end;        // Endurance. Determines maximum health (1-100)
	int dex;        // Dexterity. Determines speed in battle (1-100)
	double hitRate; // Modifier to hit chance. (1-150)

	// Current level of the creature.
	// Determines the amount of experience that it gives to the
	// victor when defeated (see Battle class for more)
	// and the amount of experience required to level up again.
	// Upon leveling up the creature will gain stat improvements.
	// 1-50 is reasonable
	unsigned int level;

	// Current experience. 0-1M is reasonable, see the levelup() function
	// for a decent scale
	unsigned int experience;
};

#endif /* CREATURE_H */
