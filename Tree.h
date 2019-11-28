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
	vector<Node> zeroless_and_sorted(int*);

	Node* get_root();

	//int* get_number_of_symbols();
	//void set_number_of_symbols(int);
};
