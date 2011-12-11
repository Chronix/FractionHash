#include "HashZlomky.h"
#include <iostream>

int main(int argc, char** argv)
{
	HashZlomky<5> hash;
	~hash;
	Zlomek z1(1,2);
	Zlomek z2(2,3);
	Zlomek z3(7,4);

	hash << z1;
	hash << z2;
	hash += z3;

	hash.prvni();
	do
	{
		(*hash.aktual())();
	} while (hash.dalsi());

	hash -= z2;

	std::cout << "-----" << std::endl;

	hash.prvni();
	do
	{
		(*hash.aktual())();
	} while (hash.dalsi());
	
	return 0;
}