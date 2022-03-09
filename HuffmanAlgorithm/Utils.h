#pragma once
#include<string>
using namespace std;

class Utils {

public:
	static string decToBin(int);
	static bool isEmptyFile(ifstream &f);


private:

	Utils() {}

};
