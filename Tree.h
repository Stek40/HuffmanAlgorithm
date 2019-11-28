#pragma once
#include "node.h"
#include <string>
#include<fstream>

class Tree
{
private:
	node* root;
	int* number_of_symbols;

public:
	Tree();
	~Tree();

	void archive(std::string);

	node* get_root();

	int* get_number_of_symbols();
	void set_number_of_symbols(int);
};
