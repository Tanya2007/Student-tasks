#include <iostream>
#include <float.h>
///////////////////////////////////////////////////////////////////
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
//////////////////////////////////////////////////////////////
int main()
{
	const int N{10};
	std::cout << "Enter the array\n";
	int arr[N];
	int largest_odd{INT_MIN};
	int index{};
	
	for (int i{}; i < N; ++i)
	{
		arr[i] = inputValue();
		if((arr[i] % 2) && (arr[i] > largest_odd))
		{
			largest_odd = arr[i];
			index = i;
		}
	}
	
	std::cout << "The largest odd: " << largest_odd << "\n";

	int arr_new[N];
	for (int i{}; i < index; ++i)
	{
		arr_new[i] = arr[i];
	}
	
	for (int i{index}; i < N - 1; ++i)
	{
		arr_new[i] = arr[i + 1];
	}
	
	arr_new[N - 1] = arr[index];
	
	for (int i{}; i < N; ++i)
	{
		std::cout << arr_new[i] << " ";
	}
	std::cout << "\n";

	return 0;
}