#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>

int main()
{
	std::ifstream ftext("p2ex7.cpp");
	std::string str;
	std::vector<std::string> vec_str;
	while(std::getline(ftext, str))
	{
		vec_str.push_back(str);
	}
	
	std::reverse(vec_str.begin(), vec_str.end());
	
	for(const auto &elem : vec_str)
	{
		std::cout << elem << "\n";
	}
	
	return 0;
}