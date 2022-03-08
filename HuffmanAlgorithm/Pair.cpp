#include "Pair.h"

Pair::Pair() {}
Pair::Pair(char ch, string str) : ch(ch), str(str) {}

void Pair::add_ch_to_str(char bit)
{
	this->str = str + bit;
}

char Pair::get_ch()
{
	return this->ch;
}

string Pair::get_str()
{
	return this->str;
}