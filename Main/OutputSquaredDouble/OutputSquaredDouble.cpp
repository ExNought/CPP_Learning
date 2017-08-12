// OutputSquaredDouble.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>

//You can't use functions before defining them. Since the files are read "top to bottom" you HAVE 
//to define a function you want to use later ABOVE the function you are using it in. 
//This will probably result in some interesting structures for methods later down the line...
double square(double x)
{
	return x*x;
}

void out_square(double x)
{
	std::cout << x << " im Quadrat ist: " << square(x) << "\n";
}

int main()
{
	double d = 1.234;
	out_square(d);
}