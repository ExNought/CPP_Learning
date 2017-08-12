// StandardTypetesting.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
//#include <string>
using namespace std; //Only written to get into the habit of including it automatically. 
					 //For the next couple chapters I will still write std::[...]
					 //Once I feel like this has gone into muscle memory,
					 //I will probably leave out the std::

int main()
{
	std::cout << "Size of a char: " << sizeof(char) << " Byte\n";
	std::cout << "Size of a string: " << sizeof(std::string) << " Byte\n";
	std::cout << "Size of a int: " << sizeof(int) << " Byte\n";
	std::cout << "Size of a single: " << sizeof(short) << " Byte\n"; 
	std::cout << "Size of a double: " << sizeof(double) << " Byte\n";
}

