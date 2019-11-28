#pragma once
struct Node
{
	int sum;
	char symbol;
	Node* next_left;
	Node* next_right;
	Node();
	Node(int, char);
	~Node();
};
