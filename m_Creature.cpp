#include "c_Creature.h"

// Default Constructor
Creature::Creature()
{
	creatureName.clear();
	className.clear();

	health		= 10;
	maxHealth	= 10;
	str			= 10;
	end			= 10;
	dex			= 10;
	hitRate		= 0;
	level		= 1;
	experience	= 0;
}
//NonDefault Constructor
Creature::Creature(string cName, int cHealth, int cStr, int cEndr,
    int cDex, double cHitRate, unsigned int cLevel = 1, string cClassName = "")
{
    creatureName = cName;
    health = cHealth;
    maxHealth = cHealth;
    str = cStr;
    end = cEndr;
    dex = cDex;
    hitRate = cHitRate;
    className = cClassName;
    level = cLevel;
    experience = 0;
}

// Destructor
Creature::~Creature()
{

}

// Sets the name of the creature
void Creature::SetName(string aName)
{
	creatureName = aName;
}

// Sets the class of the creature
void Creature::SetClass(string aClass)
{
	className = aClass;
}

// Calculates the experience required to reach a certain level,
// *in total*
unsigned int Creature::expToLevel(unsigned int level)
{
	// Exp to level x = 128*x^2
	return 128 * level * level;
}

// Level the creature to the next level if it has
// enough experience to do so, returning true if it could
// level up and false otherwise.
bool Creature::levelUp()
{

	bool levelAccquired = false;
    // We want the experience to the next level,
    // not the current level
    if(experience >= expToLevel(level+1))
    {
        // Advance to the next level
        ++level;

        // Variables to keep track of stat changes. Neater than
        // having a bunch of stat increases all over the place,
        // and removes the issue of the next level's stats
        // affecting themselves (increasing endurance then
        // increasing health based on the boosted instead of
        // the original value, for example
        unsigned int healthBoost = 0;
        unsigned int strBoost = 0;
        unsigned int endBoost = 0;
        unsigned int dexBoost = 0;

        // Give a large boost to health every third level
        if(level % 3 == 0)
        {
            // Randomly increase health, but always give a
            // chunk proportional to the creature's endurance
            healthBoost = 10 + (rand() % 4) + end / 4;
        }
        else
        {
            // Just increase health by a small amount
            healthBoost = end / 4;
        }
        // If the creature is a fighter, then favour strength and
        // endurance boosts over dexterity, but increase dexterity
        // 50% of the time too
        if(className == "Fighter")
        {
            strBoost = 1;
            endBoost = 1;
            if(rand() % 2 == 0) dexBoost = 1;
        }
        // Same as for fighter but favour dexterity and endurance
        // instead. Rogue's favour endurance too in order to keep
        // them at roughly the same capability
        else if(className == "Rogue")
        {
            endBoost = 1;
            dexBoost = 1;
            if(rand() % 2 == 0) strBoost = 1;
        }

        // Adjust all of the variables accordingly
        maxHealth += healthBoost;
        str += strBoost;
        end += endBoost;
        dex += dexBoost;

        // Tell the user that they grew a level, what the boosts
        // were and what their stats are now
        cout << creatureName << " grew to level " << level << "!\n";
        cout << "HP +" << healthBoost << " -> " << maxHealth << endl;
        cout << "Str +" << strBoost << " -> " << str << endl;
        cout << "End +" << endBoost << " -> " << end << endl;
        cout << "Dex +" << dexBoost << " -> " << dex << endl;
        cout << "----------------\n";

        levelAccquired = true;
    }

    return levelAccquired;
}

// Returns the name of the creature
string Creature::GetName()		const
{
	return creatureName;
}

// Returns the class of the creature
string Creature::GetClass()		const
{
	return className;
}

// Returns the creature's strength
int Creature::GetStrength()		const
{
	return str;
}

// Returns the creature's endurance
int Creature::GetEndurance()	const
{
	return end;
}

// Returns the creature's dexterity
int Creature::GetDexterity()	const
{
	return dex;
}

// Returns the creature's health
int Creature::GetHealth()		const
{
	return health;
}

// Returns the creature's max health
int Creature::GetMaxHealth()	const
{
	return maxHealth;
}

// Returns the creature's hit rate
int Creature::GetHitRate()		const
{
	return hitRate;
}

// Returns the creature's level
int Creature::GetLevel()		const
{
	return level;
}

// Returns the creature's experience
int Creature::GetExperience()	const
{
	return experience;
}

// Prints the creature's information to the screen
void Creature::Print()			const
{
	cout << creatureName ;
	cout << " LEVEL: " 	<< level;
	cout << " HEALTH: " << health 		<< '/' 	<< maxHealth;
	cout << " EXP: "	<< experience 	<< endl;
}
