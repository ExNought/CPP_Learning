// PointerArraysLoops.cpp : Definiert den Einstiegspunkt für die Konsolenanwendung.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>

using namespace std;

void Pointerfun()
{
	char v[10];																						//Array of 10 characters. Index starts with 0.
	char* p;																						//Pointer to a char-type. This can also be an array! Awsome :O

	p = &v[3];
	char x = *p;

	cout << "The value of X after assigning v[3] via a pointer to X: " << x << endl;				//endl is nicer than \n as this should theoretically be safe for every OS. -- Empty. Thereof you can read the char: ╠
	v[3] = 'H';

	cout << "The value of X after changing v[3]: " << x << endl;									//Did the output change? -- NO. The assignment of x is "by value" not by reference!
	cout << "The value of P after changing v[3]: " << *p << endl;									//Did the output change? -- Of course. This is the reference to the changed value!

	x = 'A';

	cout << "The value of X after changing X: " << x << endl;										//Did it change now? -- Yes. X is it's own object now. Therefore independent!
	cout << "The value of v[3] after changing X: " << v[3] << endl;									//These values should be identical, right? -- No. Stated above
	cout << "The value of P after changing X: " << *p << endl;										//This value didn't change, this is further prove both variables have only the same origin but are independent now!
}

void copy_function()
{
	int v1[10] = { 0,1,2,3,4,5,6,7,8,9 };															//Small sidenode: When using intellisense on these arrays. VS also shows the memory address. Cool.
	int v2[10];																						//v1 will be copied into v2.

	for (int i = 0; i != 10; ++i)																	//for more precise understanding I used int. The book uses "auto I", which is an int, too ;)
		v2[i] = v1[i];																				//Also note: You can also use i<=10 instead of i != 10. This depends on your coding-style. I like != so does the book. 
																									//But I understand why some people like the idea of being safe in case 10 is broken and the I never gets that value ;)
	//You can add further code here, like outputing to console.
}

void outputArray()
{
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };
	
	//C# has a own loop for this called foreach.
	//for (auto x : v)																				//Again: The book uses AUTO, which may be more typesafe but for keepint stuff simple I use int x.
	//	cout << x << endl;
	for (int x : v)
		cout << x << endl;

	for (int x : {10, 11, 12, 13, 16, 88, 4})														//It is reather logical, you CAN also put these values into the statement itself, but it wouldn't be very dynamic...
		cout << x << endl;
}

void incrementArray()
{
	int v[] = { 0,1,2,3,4,5,6,7,8,9 };

	//& is the operator for referencing. I like this very much! References are not pointers. 
	//They differ in their dynamic use. Pointers can be changed to be different objects.
	for (int& x : v)																				//Again book uses auto. Here I think this may be rather good styling as it is open for other types of input.
	{
		cout << "Old: " << x << endl;
		x++;
		cout << "New: " << x << endl;
	}
}

void PointerPractice()
{
	//Create a pointer. There currently is no ref so use nullpointer. 
	//This works with EVERY type of pointer.
	float* ip = nullptr;
	for (int i = 0; i != 5; i++)
	{
		float IntForPointer = i * 3.14;
		ip = &IntForPointer;
	}

	//This should create an error. -- It does: Auf das verworfene Objekt kann nicht zugegriffen werden.
	//cout << *ip << endl;

	//Always set the pointer to nullptr when it is no longer valid ;) This causes an error too, but
	//doesn't fuck up your security.
	ip = nullptr;
	//cout << *ip << endl;
}

int count_x(char* p, char x)
{
	//Check if p is even valid!
	if (p == nullptr) return 0;

	//Performance, I generally prefer to declare my variables at the very top. I will change this 
	//behaviour so the init checks are up first.
	int count = 0;

	//No, the counting variable does not need to be initialized here :)
	//This loop cuts away the first char every run. This works by moving the starting memory 
	//address! This is awsome!!!
	for (; *p != 0; p++)
	{
		if (*p == x)
			count++;
	}
	return count;
}

int main()
{
	//Stitched together ;)
	char v[] = { "Ich habe einen Beispielsatz erstellt!"};
	Pointerfun();
	copy_function();
	outputArray();
	incrementArray();
	PointerPractice();
	cout << count_x(v, 'e') << endl;																//Exptected: 7

    return 0;
}

