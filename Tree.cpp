#include<iostream>
#include "Tree.h"
#include <iostream>
#include <vector> 
#include <map> 
using namespace std;


Tree::Tree()
{
	root = nullptr;

}

Tree::Tree(char ch, int n)
{
	root = new Node(ch, n);
}

Tree::Tree(Node* node)
{
	root = node;
}


Tree::~Tree()
{
	

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
		<< number_of_symbols[(int)'\n'] << endl;
	int* n_of_diff_chars = new int[1];
	Node* nodes = zeroless_and_sorted(number_of_symbols, n_of_diff_chars);
	cout << number_of_symbols[(int)'a'] << endl
		<< number_of_symbols[(int)'c'] << endl
		<< number_of_symbols[(int)'b'] << endl
		<< number_of_symbols[(int)'\n'] << endl;
	cout << *n_of_diff_chars << "!!" << endl;
	for (int i = 0; i < 4; i++)
	{
		cout << nodes[i].symbol << " " << nodes[i].sum << endl;
	}

	vector<Tree> trees;

	for (int i = 0; i < *n_of_diff_chars; i++)
	{
		Tree t(&nodes[i]);
		trees.push_back(t);
	}

	// uniting trees into one big tree
	cout << "size of trees before uniting:" << trees.size()<<endl;
	while (trees.size() > 1)
	{
		Tree* min1;
		Tree* min2;
		int min2_position,
			min1_position;
		if (trees[0].root->sum > trees[1].root->sum)
		{
			min1 = &trees[0];
			min2 = &trees[1];
			min1_position = 0;
			min2_position = 1;
		}
		else 
		{
			min1 = &trees[1];
			min2 = &trees[0];
			min1_position = 1;
			min2_position = 0;
		}
		
		
		for (int i = 2; i < trees.size(); i++)
		{
			if (trees[i].root->sum < min1->root->sum)
			{
				min2 = min1;
				min2_position = min1_position;
				min1 = &trees[i];
				min1_position = i;
			}
			else
			{
				if (trees[i].root->sum < min2->root->sum)
				{
					min2 = &trees[i];
					min2_position = i;
				}
			}
		}
		min1->combineWith(min2);
		trees.erase(trees.begin() + min2_position);
	}

	cout << trees[0].root->sum;

	// obrazuvane na 0 i 1 posledovatelnosti za vs simvol

	map<char, string>* symbols_archive = new map<char, string>();
	symbols_archive->insert(pair<char, string>('a', "010"));
	

	int found_all = 0;
	
	//while (found_all != *n_of_diff_chars)
	{
		trees[0];
	}
}

void Tree::mappingSymbols(map<char, string>* symbols_archive, Node* node)
{

}

void Tree::combineWith(Tree* tree)
{
	Node* new_root = new Node(this->root->sum + tree->root->sum);
	new_root->next_left = this->root;
	new_root->next_right = tree->root;
	this->root = new_root;
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
