#pragma once
struct Node
{
	int sum;
	char symbol;
	Node* next_left;
	Node* next_right;
	Node();
	Node(char, int);
	Node(int);
	Node& operator= (const Node& other);
	~Node();
};
