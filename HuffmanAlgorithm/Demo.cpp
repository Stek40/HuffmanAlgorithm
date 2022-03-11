#include<iostream>
#include <fstream>
#include <thread>
#include <chrono>

#include "Tree.h"
#include "Utils.h"

using namespace std;

void printInstructions() {
	cout << "> 'c <filename>' for compress\n> 'd <filename>' for decompress\n> 'x' for exit\n";
}

void commandController() {
	string input;

	while (true)
	{
		bool has_invalid_input = false;
		cout << "\n>";
		getline(cin, input);

		if (input == "x")
		{
			cout << "exiting...\n";
			this_thread::sleep_for(chrono::seconds(1));
			return;
		}
		if (input.size() >= 3 && input.at(1) == ' ')
		{

			string file_name = input.substr(2, input.length() - 1);
            cout << file_name;
			ifstream f(file_name);
			if (Utils::isEmptyFile(f))
			{
				has_invalid_input = true;
			}
			else if (input.at(0) == 'c')
			{
				Tree t1;
				t1.set_file_name(file_name);
				t1.zip();
			}
			else if (input.at(0) == 'd')
			{
				Tree t1;
				t1.set_file_name(file_name);
				t1.unzip();
			}
			else
			{
				has_invalid_input = true;
			}
		} 
		else
		{
			has_invalid_input = true;
		}

		if(has_invalid_input) 
		{
			cout << "\nThe input is invalid!\n\n";
			printInstructions();
		}
	}

}

int main() {

//    ofstream outfile("unziped_");
//
//    outfile << 'a';

	printInstructions();
	commandController();

	//Tree tree;
	//tree.zip("text.txt");
	//tree.unzip("zip_text.txt");

	system("pause");
	return 0;
}
