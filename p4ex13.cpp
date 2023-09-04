#include <iostream>
#include <string>

int main()
{
	std::string A{"123456789"};
	std::string B{"67"};
	std::string C{"-sixty-seven-"};
	
	std::size_t index = A.find(B);
	if(index != std::string::npos)
	{
		A.replace(index, 2, C);
	}
	
	std::cout << A << "\n";
	
	return 0;
}