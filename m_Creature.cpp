#include "c_Creature.h"

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
