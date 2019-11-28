#pragma once
struct node
{
	int sum;
	char symbol;
	node* next_left;
	node* next_right;
	node();
	node(int, char);
	~node();
};

