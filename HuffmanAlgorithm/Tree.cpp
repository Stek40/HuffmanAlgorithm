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

Tree::Tree(Node* node)
{
	Node* neww = node;
	root = neww;
}

Tree::~Tree()
{
	myDelete(this->root);
}

void Tree::myDelete(Node* nd)
{
	if (nd == nullptr)
	{
		return;
	}
	//myDelete(nd->next_left);
	//myDelete(nd->next_right);
	//delete nd;
	//nd = nullptr;
}

void Tree::unzip()
{
	//tree construction
	ifstream infile(this->file_name);
	string str_tree;
	getline(infile, str_tree);
	if (str_tree.at(str_tree.length() - 1) != ')')//if there is new line as a symbol in the tree
	{
		string str_tree2;
		getline(infile, str_tree2);
		str_tree += "\n" + str_tree2;
	}
	cout << "tree: " << str_tree << endl;
	treeConstrByString(str_tree);

	//text construction
	char ch;
	string zipped_numbers = "";
	std::getline(infile, zipped_numbers);
	string one_number = "";
	string zero_and_one = "";

	//end of string logic for the last number
	int lastSpaceIndex = zipped_numbers.length();
	while (true)
	{
		lastSpaceIndex--;
		if (zipped_numbers.at(lastSpaceIndex) == ' ')
		{
			break;
		}
	}
	for (int i = 0; i < zipped_numbers.length(); i++)
	{

		if (i == lastSpaceIndex)
		{
			//cout << "last number: " << one_number << endl;
			zero_and_one = zero_and_one + nZeroes(8 - (zipped_numbers.at((zipped_numbers.length() - 1)) - '0'), decTobin(strToNum(one_number)));
		}
		else if (zipped_numbers.at(i) == ' ')
		{
			//cout << "single number: " << one_number << endl;
			zero_and_one += decTobin(strToNum(one_number));
			one_number = "";
		}
		else
		{
			one_number += zipped_numbers.at(i);
		}
	}
	cout << "after transformation: " << zero_and_one << endl;


	ofstream outfile("unziped_" + this->file_name);
	Node* iterator = this->root;
	for (int i = 0; i < zero_and_one.length(); i++)
	{
		if (iterator->next_left == nullptr)
		{
			outfile << iterator->symbol;
			iterator = this->root;
		}
		if (zero_and_one.at(i) == '1')
		{
			iterator = iterator->next_left;
		}
		else
		{
			iterator = iterator->next_right;
		}
	}
	outfile << iterator->symbol;
}
string Tree::nZeroes(int n, string binstr)
{
	string result = "";
	for (int i = n; i < binstr.length(); i++)
	{
		result += binstr.at(i);
	}
	return result;
}
string Tree::decTobin(int n)
{
	string result = "";
	int length = 0;
	while (n != 0)
	{
		result = (n % 2 == 0 ? "0" : "1") + result;
		n /= 2;
		length++;
	}
	if (length != 8)
	{
		for (int i = 0; i < 8 - length; i++)
		{
			result = "0" + result;
		}
	}
	return result;
}

void Tree::treeConstrByString(string str_tree)
{
	myDelete(this->root);

	root = new Node();

	readTree(str_tree, 1, str_tree.length() - 2, this->root);//bez skobi go podavame
}
void Tree::readTree(string str_subtree, int first, int last, Node* new_root)
{
	int i = first;
	string number = "";
	while (str_subtree.at(i) >= '0' && str_subtree.at(i) <= '9' && str_subtree.at(i + 1) != ')')
	{
		number += str_subtree.at(i);
		i++;
	}
	new_root->sum = strToNum(number);
	if (str_subtree.at(i) != '(')// listo
	{
		new_root->symbol = str_subtree.at(i);
	}
	else
	{
		if (str_subtree.at(i + 1) == ')')// ( moje da e simvola, a ne nachalo na durvo
		{
			new_root->symbol = '(';
		}
		else
		{
			new_root->next_left = new Node();
			new_root->next_right = new Node();
			int close_bracket_index = closeBracket(str_subtree, i);
			readTree(str_subtree, i + 1, close_bracket_index - 1, new_root->next_left);
			readTree(str_subtree, close_bracket_index + 2, closeBracket(str_subtree, close_bracket_index + 1) - 1, new_root->next_right);
		}
	}
}
int Tree::closeBracket(string str, int i)//trqbva i da e purvata skoba (
{
	int open = 0, close = 0;
	while (1)
	{
		if (str.at(i) == '(') open++;
		if (str.at(i) == ')') close++;
		if (open == close) return i;
		i++;
	}
}
int Tree::strToNum(string number)
{
	int number_length = number.length();
	int result = 0;
	for (int i = number_length - 1; i >= 0; i--)
	{
		result += (number.at(i) - '0') * pow(10, number_length - 1 - i);
	}
	return result;
}

void Tree::zip()
{
	ifstream length(this->file_name);
	string orig_text = "";
	char ch2;
	int orig_file_size = 0;
	while (length.get(ch2))
	{
		orig_file_size++;
	} orig_file_size *= 8;

	ifstream f(this->file_name);
	int* number_of_symbols = new int[256]{}; // chestotna tablica
	char ch;

	// reading file
	while (f.get(ch)) {
		number_of_symbols[(int)ch]++;
	}
	int* n_of_diff_chars = new int[1];
	Node* nodes = zeroless_and_sorted(number_of_symbols, n_of_diff_chars);
	cout << "different symbols: " << *n_of_diff_chars << endl;

	vector<Tree> trees;

	for (int i = 0; i < *n_of_diff_chars; i++) // n trees with a single Node
	{
		Tree* t = new Tree(nodes[i].symbol, nodes[i].sum);
		trees.push_back(*t);
	}

	// uniting trees into one big tree
	while (trees.size() > 1)
	{
		Tree* min1;
		Tree* min2;                  // min1->sum < min2->sum
		int min1_position,
			min2_position;
		if (trees[0].root->sum > trees[1].root->sum)
		{
			min1 = &trees[1];
			min2 = &trees[0];
			min1_position = 1;
			min2_position = 0;
		}
		else
		{
			min1 = &trees[1];
			min2 = &trees[0];
			min1_position = 1;
			min2_position = 0;
		}

		for (int i = 2; i < (int)trees.size(); i++)
		{
			if (trees[i].root->sum < min1->root->sum)
			{
				min2 = min1;
				min2_position = min1_position;
				min1 = &trees[i];
				min1_position = i;
			}
			else if (trees[i].root->sum < min2->root->sum)
			{
				min2 = &trees[i];
				min2_position = i;
			}
			else
			{
				if (trees[i].root->sum == min1->root->sum && trees[i].treedepth() > min1->treedepth())
				{
					min2 = min1;
					min2_position = min1_position;
					min1 = &trees[i];
					min1_position = i;
				}
				else
				{
					if (trees[i].root->sum == min2->root->sum && trees[i].treedepth() > min2->treedepth())
					{
						min2 = &trees[i];
						min2_position = i;
					}
				}
			}
		}
		min1->combineWith(min2);
		trees.erase(trees.begin() + min2_position);
	}

	this->set_root(trees[0].root);

	Pair** pairs = new Pair * [*n_of_diff_chars];
	mappingSymbols(pairs); // creating pairs(map) of... example: 'a' -> 01001

	for (int i = 0; i < *n_of_diff_chars; i++)
	{
		cout << pairs[i]->get_ch() << " " << pairs[i]->get_str() << "; ";
	}
	cout << endl;

	// saving to archive
	ifstream infile(this->file_name);
	ofstream outfile("zip_" + this->file_name);
	char symb;

	outfile << treeToString() + "\n";

	string str01 = "";
	while (infile.get(symb))
	{
		str01 += map(pairs, symb, *n_of_diff_chars);//map_name(symb)
	}
	int compressed_size = str01.length();

	outfile << binToDec(str01);

	infile.close();
	outfile.close();
	double compression = ((double)compressed_size / orig_file_size) * 100;
	cout << "\nCOMPRESSION: " << compression << "%\n\n";
}

string Tree::binToDec(string str01)
{
	cout << "0&1: " << str01 << "\n ";
	string result = "";
	int decNumbers = str01.length() / 8;
	int last_number_length = str01.length() % 8;
	int decNumber = 0;
	for (int i = 0; i < decNumbers; i++)
	{
		for (int j = 0; j < 8; j++)
		{
			decNumber += (str01.at(i * 8 + j) - '0') * (int)pow(2, 8 - j - 1);
		}
		cout << decNumber << " ";
		result += numToStr(decNumber) + " ";
		decNumber = 0;
	}
	for (int i = 0; i < last_number_length; i++)
	{
		decNumber += (str01.at(decNumbers * 8 + i) - '0') * (int)pow(2, last_number_length - i - 1);
	}

	cout << decNumber << "\n ";
	result += numToStr(decNumber);

	result = result + " " + (char)(last_number_length + '0');

	return result;
}

string Tree::treeToString()
{
	return treeToStringRecursion("", this->get_root(), nullptr);
}
string Tree::treeToStringRecursion(string string_tree, Node* dis, Node* super)
{

	if (dis->next_left == nullptr)
	{
		return string_tree + "(" + numToStr(dis->sum) + dis->symbol + ")";
	}
	else
	{
		return string_tree + "(" + numToStr(dis->sum) + treeToStringRecursion(string_tree, dis->next_left, dis)
			+ treeToStringRecursion(string_tree, dis->next_right, dis) + ")";
	}
}
string Tree::numToStr(int n)
{
	int len = 0;
	int ncopy = n;
	do
	{
		ncopy /= 10;
		len++;
	} while (ncopy != 0);

	string result = "";
	for (int i = len - 1; i >= 0; i--)
	{
		result += (char)((int)'0' + n / (int)pow(10, i));
		n -= n / (int)pow(10, i) * (int)pow(10, i);
	}
	return result;
}

string Tree::map(Pair** pairs, char symbol, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (pairs[i]->get_ch() == symbol)
			return pairs[i]->get_str();
	}
}

void Tree::mappingSymbols(Pair** pairs)
{
	int* pairsCurrentSize = new int();
	*pairsCurrentSize = 0;
	symbolsTreeSearch(pairs, this->get_root(), "", pairsCurrentSize);
}
void Tree::symbolsTreeSearch(Pair** pairs, Node* node, string str01, int* pairsCurrentSize)
{
	if (node->next_left == nullptr)//listo
	{
		pairs[*pairsCurrentSize] = new Pair(node->symbol, str01);
		(*pairsCurrentSize)++;
		return;
	}
	symbolsTreeSearch(pairs, node->next_left, str01 + "1", pairsCurrentSize);
	symbolsTreeSearch(pairs, node->next_right, str01 + "0", pairsCurrentSize);
}

void Tree::combineWith(Tree* tree)
{
	Node* new_root = new Node(this->root->sum + tree->root->sum);
	new_root->next_left = this->root;
	new_root->next_right = tree->root;
	this->root = new_root;
}

int Tree::treedepth()
{
	int depth = 0;
	Node* iter = this->root;
	while (iter != nullptr)
	{
		iter = iter->next_left;
		depth++;
	}
	return depth;
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

string Tree::get_file_name()
{
	return this->file_name;
}

void Tree::set_root(Node* root)
{
	this->root = root;
}

void Tree::set_file_name(string new_file_name)
{
	this->file_name = new_file_name;
}