#include<iostream>
#include "Tree.h"
#include <iostream>
using namespace std;


Tree::Tree()
{
	root = nullptr;
	number_of_symbols = new int[256]{};
}


Tree::~Tree()
{
	delete[] number_of_symbols;

}

void Tree::archive(std::string file_name)
{
	std::ifstream f(file_name);

	char ch;
	while (f.get(ch)) {
		set_number_of_symbols((int)ch);
	}
	cout << get_number_of_symbols()[(int)'a'] << endl 
		 << get_number_of_symbols()[(int)'c'] << endl
		 << get_number_of_symbols()[(int)' '] << endl;

	for (size_t i = 0; i < 256; i++)
	{

	}

}

int* Tree::get_number_of_symbols()
{
	return number_of_symbols;
}

void Tree::set_number_of_symbols(int i)
{
	get_number_of_symbols()[i]++;
}
