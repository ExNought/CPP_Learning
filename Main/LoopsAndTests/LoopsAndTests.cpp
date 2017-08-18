// LoopsAndTests.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//


//Here I want to try a multitude of loops and tests. Examples: For, if, switch, while, etc...
//This doesn't strongly differ from c# so you can feel right at home :)
#include "stdafx.h"
#include <iostream>

using namespace std;

//This is a safe if not userfriendly way of handling the answer. There is feedback missing.
bool accept_if()
{
	std::cout << "Do you want to proceed (y or n)?\n";

	char answer = 0;
	std::cin >> answer;			//input. Compare << and >>

	if (answer == 'y')
		return true;
	return false;				//Note: if you only have ONE statement, you can ignore the {}. 
								//But only do this if this doesn't impede the usability.
}

//This exits rather than asks for a repetition. Not bad if you want to make a forgiving delete 
//question for example, though after a while rather frustrating, right?
bool accept_switch()
{
	std::cout << "Do you want to proceed (y or n)?\n";

	char answer = 0;
	std::cin >> answer;

	switch (answer)
	{
	case 'y':
		return true;
	default:
		std::cout << "This is an invalid input. Default value is 'no'\n";
		//Note: I left the return as the result is the same as in 'n'. Works splendid!
	case 'n':
		return false;
	}
}

//Probably the userfriendliest of the bunch ;)
bool accept_while()
{
	int tries = 0;
	
	while(tries < 4)
	{
		//exatly like before but inside the while so the question gets asked again.
		std::cout << "Do you want to proceed (y or n)?\n";

		char answer = 0;
		std::cin >> answer;

		//Similar to the one in accept_switch, but this time default gets treated completely solo.
		switch (answer)
		{
		case 'y':
			return true;
		case 'n':
			return false;
		default:
			std::cout << "Sorry, this input is invalid!\n";
			++tries; //you could also manually add +1 or use tries++. This is so the question won't
					 //loop forever. Sometimes both a 'y' and a 'n' can be broken ;)
		}
	}
	std::cout << "You weren't able to input ANYTHING useful."
			" I won't allow this. So default is 'no'";
	return false;
}


int main()
{
	std::cout << accept_if() << "\n";
	std::cout << accept_switch() << "\n";
	std::cout << accept_while() << "\n";
    return 0;
}