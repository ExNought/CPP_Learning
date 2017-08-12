// StandardTypetesting.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <cmath>
//#include <string>
using namespace std; //Only written to get into the habit of including it automatically. 
					 //For the next couple chapters I will still write std::[...]
					 //Once I feel like this has gone into muscle memory,
					 //I will probably leave out the std::


//An example for a method being able to return constants.
constexpr double square(double x)
{
	return x*x;
}

//This isn't used to out the results rather than checking
//if the synthax is correct and the result comes in as expected!
//I don't need to see that in console. I am ok with only checking this in the debugger.
void basic_Arithmetics()
{
	double d = 1.12345;
	double d_res;
	int i = 12;
	int i_res;
	d_res = d + i;
	i_res = d*i; //This truncates the number. Int is not capable of storing comma-separated numbers
			     //Remember that you have to round this yourself if you want it, 
			     //before putting it into a string!

	//further more detailed testing:
	double d1 = 3.4;
	double d2{ 2.3 };
	//double d3{ 2.2, 2.3, 2.4 }; This is not possible! Curly brackets use the constructor based 
	//assigning. This is available for all basic types. As a result of that. 
	//You have to watch out for the same traps as in usual classes.
	
	//The book is also using complex and vector. But I only get errors when using them. 
	//So I will ignore them until I know more about them ;)

	int i1 = 7.2; //This results in i1 = 7
	//int i2 {7.2}; Results in an error due to conversion.
	//int i3 = {7.2}; Is virtually identical to i2.

	auto b = true; //bool
	auto ch = 'a'; //char
	auto in = 3; //int
	//etc...

	//Best practice: 
	// - If you can avoid any confusion with explicitly stating the type, state it. 
	// - If you need to be sure a certain scope is set. Use explicit init.

	//CPP can use certain lazy arithmetics, just like C#. Here are some:

	int x = 0;
	x += 3;
	x++;
	++x; //Here this is identical to x++. Check if this is true for loops...
	x *= 2;
	x /= 2;
	//etc...

	const double test = 3.14; //Is constant ...
	int r = 3;
	constexpr double test2 = square(3.14);
	//constexpr double test2 = 1.4*square(test); Not sure why this doesn't work ... look into it!
	//constexpr double test2 = pow(test,2)*; This doesn't work since pow doesn't support constant 
	//expressions! But this is uesd to make certain data constant at RUNTIME. E.g. timezones?
	//You can also use const for this, but certexpr is stored in memory and is faster. 
	//According to the book.


}


int main()
{
	std::cout << "Size of a char: " << sizeof(char) << " Byte\n";
	std::cout << "Size of a string: " << sizeof(std::string) << " Byte\n";
	std::cout << "Size of a int: " << sizeof(int) << " Byte\n";
	std::cout << "Size of a single: " << sizeof(short) << " Byte\n"; 
	std::cout << "Size of a double: " << sizeof(double) << " Byte\n";

	basic_Arithmetics();
}

