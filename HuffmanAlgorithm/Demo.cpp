#include<iostream>
#include <fstream>
#include <thread>
#include <chrono>
#include "Tree.h"

using namespace std;


int main() {

	cout << "> 'c <filename>' for compress\n> 'd <filename>' for decompress\n> 'x' for exit\n";
	string input = "";

	while (1)
	{
		cout << "\n>";
		getline(cin, input);
		if (input.at(0) == 'x')
		{
			cout << "exiting...\n";
			this_thread::sleep_for(chrono::seconds(1));
			return 0;
		}
		if (input.at(0) == 'c')
		{
			string file_name = input.substr(2, input.length() - 1);
			Tree t1;
			t1.set_file_name(file_name);
			t1.zip();
		}
		if (input.at(0) == 'd')
		{
			string file_name = input.substr(2, input.length() - 1);
			Tree t1;
			t1.set_file_name(file_name);
			t1.unzip();
		}
	}


	//Tree tree;
	//tree.zip("text.txt");
	//tree.unzip("zip_text.txt");
	//tree.zip("BIG.txt");
	//tree.unzip("zip_BIG.txt");
	//Tree tree2;
	//tree2.zip("textche.txt");
	//tree2.unzip("zip_textche.txt");




	system("pause");

	return 0;
}