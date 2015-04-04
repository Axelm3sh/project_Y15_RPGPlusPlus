/*
 * m_Dialogue.cpp
 *
 *  Created on: Feb 25, 2015
 *      Author: Dan
 */
#include "c_Dialogue.h"


Dialogue::Dialogue()
{

}
Dialogue::~Dialogue()
{

}

Dialogue::Dialogue(string text, vector<string> selections)
{
	description = text;
	choices = selections;
}

int Dialogue::Activate()
{
	// Output the information
	    cout << description << endl;

	    // Output and number the choices
	    for(int i = 0; i < choices.size(); ++i)
	    {
	        cout << i+1 << ": " << choices[i] << endl;
	    }

	    int userInput = -1;

	    // Repeatedly read input from stdin until a valid option is
	    // chosen
	    while(true)
	    {
	        cin >> userInput;
	        // 'Valid' means within the range of numbers outputted
	        if(userInput >= 0 && userInput <= choices.size())
	        {
	            return userInput;
	        }
	    }

	    return 0;
}


