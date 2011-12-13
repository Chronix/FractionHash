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

	std::cout << "Zlomky v tabulce:" << std::endl;
	hash.prvni();
	do
	{
		(*hash.aktual())();
		std::cout << std::endl;
	} while (hash.dalsi());

	std::cout << std::endl << "-------------" << std::endl << "Odstraneni zlomku ";
	z2();
	hash -= z2;

	std::cout << std::endl << "-------------" << std::endl << "Zlomky v tabulce:" << std::endl;

	hash.prvni();
	do
	{
		(*hash.aktual())();
		std::cout << std::endl;
	} while (hash.dalsi());

	std::cout << std::endl << std::endl << "Hledani zlomku ";
	z1();
	std::cout << " v tabulce:";

	Zlomek* zl = hash >> z1;

	if (zl != nullptr) std::cout << std::endl << "Zlomek byl nalezen.";

	std::cout << std::endl << std::endl << "Hledani zlomku ";
	z2();
	std::cout << " v tabulce:";
	zl = hash >> z2;
	
	if (zl == nullptr) std::cout << std::endl << "Zlomek nebyl nalezen." << std::endl << std::endl;

	system("pause");
	return 0;
}