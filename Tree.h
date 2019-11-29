#pragma once
#include "Node.h"
#include <string>
#include<fstream>
using namespace std;

class Tree
{
private:
	Node* root;


public:
	Tree();
	Tree(char, int);
	~Tree();

	void archive(std::string);
	Node* zeroless_and_sorted(int*, int*);
	Tree* combineWith(Tree*);

	Node* get_root();

	//int* get_number_of_symbols();
	//void set_number_of_symbols(int);
};
