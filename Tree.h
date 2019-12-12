#pragma once
#include "Node.h"
#include <string>
#include<fstream>
#include "Pair.h"
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
	void mappingSymbols(Pair**);
	void symbolsTreeSearch(Pair**, Node*, string, int*);
	string mapped(Pair**, char, int);
	string treeToString();
	string treeToStringRecursion(string, Node*, Node*);
	string numToStr(int);

	Node* get_root();
	void set_root(Node*);
};
