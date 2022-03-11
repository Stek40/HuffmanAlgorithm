#include "Utils.h"
#include <fstream>
using namespace std;

bool Utils::isEmptyFile(ifstream &f)
{
	return f.peek() == std::ifstream::traits_type::eof();
}


string Utils::decToBin(int dec) {
	string result;
	int length = 0;
	while (dec != 0)
	{
		result += (dec % 2 == 0 ? "0" : "1");
		dec /= 2;
		length++;
	}
	if (length != 8)
	{
		for (int i = 0; i < 8 - length; i++)
		{
			result += "0";
		}
	}
	return result;
}