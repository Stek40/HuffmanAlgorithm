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

void Tree::symbolsCounter(std::string text)
{
	std::ifstream f(text);

	char ch;
	while (f >> ch) {
		set_number_of_symbols((int)ch);
	}
	cout << get_number_of_symbols()[(int)'a'] << endl << get_number_of_symbols()[(int)'c'] << endl;

}

int * Tree::get_number_of_symbols()
{
	return number_of_symbols;
}

void Tree::set_number_of_symbols(int i)
{
	get_number_of_symbols()[i]++;
}
