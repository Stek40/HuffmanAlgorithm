#pragma once
#include "Node.h"
#include <string>
#include<fstream>

class Tree
{
private:
	Node* root;
	int* number_of_symbols;

public:
	Tree();
	~Tree();

	void archive(std::string);

	Node* get_root();

	int* get_number_of_symbols();
	void set_number_of_symbols(int);
};
