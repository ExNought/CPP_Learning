// User-Defined Types.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

//Vector are simple mathematical structures, so they should fit perfectly.
//Along the way I can also train math, yay!
struct Vector
{
	//sz meaning size. Will contain the number of elements.
	int sz;
	//pointer to said elements
	double* elem;
};

//Sets the vectors values in a 'meaningful' way.
void vector_init(Vector& v, int s)
{
	//Creates an array with the number of s doules. This isn't programmed savely as I currently 
	//don't catch anything. No negatives is the most important with that!
	v.elem = new double[s]; 
	v.sz = s;
}

double read_and_sum(int s)
{
	//This is also done as a first test in MAIN
	Vector v;
	vector_init(v, s);
	for (int i = 0; i != s; ++i)
	{
		cout << "Bitte Wert " << i << " von " << s << " eingeben: ";
		cin >> v.elem[i];		//Read into elements
	}

	double sum = 0;
	for (int i = 0; i != s; ++i)
		sum += v.elem[i];

	return sum;
}

void f(Vector v, Vector& rv, Vector* pv)
{
	//Access through name; Standard in C# as well
	int i1 = v.sz;
	//Access through reference; Standard in C# as well
	int i2 = rv.sz;
	//Access through pointer; New to me!
	int i3 = pv->sz;
}

int main()
{
	int temp;
	Vector v;
	Vector* pointer_V = &v;
	cout << "Bitte die Anzahl Elemente definieren";
	cin >> temp;
	//In C# I could use something like vector_init(v, (int)Console.Readline()); to get the job done
	vector_init(v, temp);
	cout << "Die Summe der eingegebenen Daten ist: " << read_and_sum(4);

	//Since I don't CALL pointer_V I don't need the otherwise leading '*'. Intuitive if you think 
	//about it.
	f(v, v, pointer_V);

	//Next chapter: 2.3.2
}

