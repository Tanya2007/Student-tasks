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
	int arr[10];
	
	for(int i{}; i < 10; ++i)
	{
		arr[i] = inputValue();
	}
	
	int temp;
	for(int i{}; i < 3; ++i)
	{
		for(int j{i + 1}; j < 4; ++j)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	for(int i{6}; i < 9; ++i)
	{
		for(int j{i + 1}; j < 10; ++j)
		{
			if(arr[i] < arr[j])
			{
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	
	for(int i{}; i < 10; ++i)
	{
		std::cout << arr[i] << " ";
	}
	
	std::cout << "\n";
	
	return 0;
}