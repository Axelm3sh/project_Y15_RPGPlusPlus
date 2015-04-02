#ifndef C_DIALOGUE_H_
#define C_DIALOGUE_H_

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

/************************************************************************
 * Class Dialogue
 * ---------------------------------------------------------------------
 * This is a class that controls gameplay using dialogue to present
 * information and choices.
 ************************************************************************/
class Dialogue
{

public:
	Dialogue();
	~Dialogue();

	Dialogue(string text, vector<string> selections);
	int Activate();

private:
	// Initial piece of information that the dialogue displays
	string description;

	// A vector of choices that will be outputted. No numbering is
	// necessary, the dialogue does that automatically
	vector<string> choices;
};

#endif /* C_DIALOGUE_H_ */
