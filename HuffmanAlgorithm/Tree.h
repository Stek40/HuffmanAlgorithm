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
	string file_name;


public:
	Tree();
	Tree(char, int);
	Tree(Node*);
	~Tree();
	void myDelete(Node*);

	void zip();
	Node* zeroless_and_sorted(int*, int*);
	void combineWith(Tree*);
	int treedepth();
	void mappingSymbols(Pair**);
	void symbolsTreeSearch(Pair**, Node*, string, int*);
	string map(Pair**, char, int);
	string treeToString();
	string treeToStringRecursion(string, Node*, Node*);

	string numToStr(int);
	int strToNum(string);
	string binToDec(string);
	string decTobin(int);
	string nZeroes(int, string);

	Node* get_root();
	void set_root(Node*);
	string get_file_name();
	void set_file_name(string);

	void unzip();
	void treeConstrByString(string);
	void readTree(string, int, int, Node*);
	int closeBracket(string, int);
};