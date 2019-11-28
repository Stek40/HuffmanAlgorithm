#include "node.h"



node::node()
{
	next_left = nullptr;
	next_right = nullptr;

}

node::node(int sum, char symbol) : sum(sum), symbol(symbol)
{
	next_left = nullptr;
	next_right = nullptr;
}


node::~node()
{
}
