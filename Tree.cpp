#include<iostream>
#include "Tree.h"
#include <iostream>
#include <vector> 
#include <algorithm>
#include <functional>
#include <array>
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
		<< number_of_symbols[(int)'b'] << endl
		<< number_of_symbols[(int)' '] << endl;
	int* n_of_diff_chars = new int[1];
	Node* nodes = zeroless_and_sorted(number_of_symbols, n_of_diff_chars);
	cout << *n_of_diff_chars << "!!" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << nodes[i].symbol << " " << nodes[i].sum << endl;
	}

	vector<Tree> trees;

	for (int i = 0; i < *n_of_diff_chars; i++)
	{
		Tree t((char)i, number_of_symbols[i]);
		trees.push_back(t);
	}

	// uniting trees into one big tree

	
	
}

Tree* Tree::combineWith(Tree* tree)
{
	Node* new_root = new Node('null', this->get_root.sum + tree->get_root.sum);
	// unite 2 trees and return it
}

Node* Tree::zeroless_and_sorted(int* arr, int* n_of_diff_chars)
{
	Node* node_arr = new Node[256];
	int size = 0;
	for (size_t i = 0; i < 256; i++)
	{
		if (arr[i] != 0)
		{
			Node* nd = new Node((char)i, arr[i]);
			node_arr[size++] = *nd;
		}
	}
	*n_of_diff_chars = size;
	Node* result_arr = new Node[size];
	for (int i = 0; i < size; i++)
	{
		result_arr[i] = node_arr[i];
	}
	delete[] node_arr;
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (result_arr[j].sum < result_arr[j + 1].sum)
			{
				int temp = result_arr[j].sum;
				char temp_ch = result_arr[j].symbol;
				result_arr[j].sum = result_arr[j + 1].sum;
				result_arr[j + 1].sum = temp;
				result_arr[j].symbol = result_arr[j + 1].symbol;
				result_arr[j + 1].symbol = temp_ch;
			}
		}
	}
	return result_arr;
}

Node* Tree::get_root()
{
	return root;
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
