#include "Node.h"



Node::Node()
{
	next_left = nullptr;
	next_right = nullptr;

}

Node::Node(int sum, char symbol) : sum(sum), symbol(symbol)
{
	next_left = nullptr;
	next_right = nullptr;
}


Node::~Node()
{
}
