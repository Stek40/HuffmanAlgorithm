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
	Tree(Node*);
	~Tree();

	void archive(std::string);
	Node* zeroless_and_sorted(int*, int*);
	void combineWith(Tree*);
	void mappingSymbols(map<char, string>&, Node*);

	Node* get_root();
};
