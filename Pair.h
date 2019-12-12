#pragma once
#include<string>
using namespace std;
class Pair
{
	char ch;
	string str;

public:
	Pair();
	Pair(char, string);

	void set_ch(char);
	void add_ch_to_str(char);
	char get_ch();
	string get_str();

};
