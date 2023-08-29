#include <iostream>

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
	const int N{10};
	std::cout << "Enter an array of 10 elements: ";
	int arr[N];
	int newArr[N];
	int index{};
	
	for(int i{}; i < N; ++i)
	{
		arr[i] = inputValue();
		if(arr[i] == 0)
		{
			newArr[index] = arr[i];
			++index;
		}
	}
	
	for(int i{}; i < N; ++i)
	{
		if(arr[i])
		{
			newArr[index] = arr[i];
			++index;
		}
	}
	
	std::cout << "New array:\n";
	for(int i{}; i < N; ++i)
	{
		std::cout << newArr[i] << " ";
	}
	std::cout << "\n";
	
	return 0;
}