#include <fstream>
#include <string>
#include <iostream>
void range_based_for_file_array()
{
	std::ifstream a[]
	{ std::ifstream(__FILE__)
	, std::ifstream(__FILE__)
	};
	//参照にする
	for (auto& file : a) {
		std::string s;
		if (std::getline(file, s))
			std::cout << s << '\n';
	}
}
