#include "Node.h"



Node::Node() : sum(0), symbol(0)
{
	next_left = nullptr;
	next_right = nullptr;

}

Node::Node(char symbol, int sum) : sum(sum), symbol(symbol)
{
	next_left = nullptr;
	next_right = nullptr;
}


Node& Node::operator= (const Node& other) 
{
	if (this != &other) {
		this->sum = other.sum;
		this->symbol = other.symbol;
		this->next_left = nullptr;
		this->next_right = nullptr;
	}

	return *this;
}


Node::~Node()
{
}
