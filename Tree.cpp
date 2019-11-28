#include<iostream>
#include "Tree.h"
#include <iostream>
#include <vector>
using namespace std;


Tree::Tree()
{
	root = nullptr;
	
}

Tree::Tree(char ch, int n)
{
	root = new Node(ch, n);
}


Tree::~Tree()
{
	//delete[] number_of_symbols;

}

void Tree::archive(std::string file_name)
{
	std::ifstream f(file_name);
	int* number_of_symbols = new int[256]{};
	char ch;
	while (f.get(ch)) {
		number_of_symbols[(int)ch]++;
	}
	cout << number_of_symbols[(int)'a'] << endl
		<< number_of_symbols[(int)'c'] << endl
		<< number_of_symbols[(int)' '] << endl;

	vector<Node> nodes = zeroless_and_sorted(number_of_symbols);

	vector<Tree> trees;

	for (size_t i = 0; i < 256; i++)
	{
		if (number_of_symbols[i] != 0) {
			Tree t((char)i, number_of_symbols[i]);
			trees.push_back(t);
		}
	}

}

vector<Node> Tree::zeroless_and_sorted(int* arr)
{
	vector<Node> result_arr;
	for (size_t i = 0; i < 256; i++)
	{
		if (arr[i] != 0)
		{
			Node nd((char)i, arr[i]);
			result_arr.push_back(nd);
		}
	}
	for (size_t i = 0; i < result_arr.size; i++)
	{

	}
}
	/*
int* Tree::get_number_of_symbols()
{
	return number_of_symbols;
}

void Tree::set_number_of_symbols(int i)
{
	get_number_of_symbols()[i]++;
}*/
