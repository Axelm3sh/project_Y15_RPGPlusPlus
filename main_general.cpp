#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

// Create a new character
Creature dialogue_newchar()
{
    // Ask for a name and class
    // Name does not use a dialogue since dialogues only request
    // options, not string input. Could be generalised into its
    // own TextInput class, but not really necessary
    cout << "Choose your name" << std::endl;
    string name;
    cin >> name;

    int result = Dialogue(
        "Choose your class",
        {"Fighter", "Rogue"}).activate();

    switch(result)
    {
        // Fighter class favours health and strength
        case 1:
            return Creature(name, 35, 20, 10, 5, 10.0, 1,
                "Fighter");
            break;

        // Rogue class favours dexterity and hit rate
        case 2:
            return Creature(name, 30, 5, 10, 20, 15.0, 1,
                "Rogue");
            break;

        // Default case that should never happen,
        // but it's good to be safe
        default:
            return Creature(name, 30, 10, 10, 10, 10.0, 1,
                "Adventurer");
        break;
    }
}
