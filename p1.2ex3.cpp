#include <iostream>
#include <iomanip>

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail())
		{
			std::cin.clear();
			std::cin.ignore(32767,'\n');
		}
		else
		{
			std::cin.ignore(32767, '\n');
			return value;
		}

		std::cout << "\nInvalid input, try again: ";
	}
}

int main()
{
	constexpr int N{5};	
	int arr[N][N];			//первое N - строки, второе N - столбцы
	
	for(int i{}; i < N; ++i)
	{
		for(int j{}; j < N; ++j)
		{
			arr[i][j] = inputValue();
		}
	}
	
	std::cout << "The original matrix:\n";
	for(int i{}; i < N; ++i)
	{
		for(int j{}; j < N; ++j)
		{
			std::cout << std::setw(5) << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
	
	for(int j{}; j < N; j += 2)
	{
		if(arr[0][j] < arr[N - 1][j])
		{
			std::cout << "\nColumn # " << j + 1 << ", where the first element is smaller than the last:\n";
			for(int i{}; i < N; ++i)
			{
				std::cout << arr[i][j] << " ";
			}
		}
	}
	
	std::cout << "\n";
	
	return 0;
}