#include <iostream>
#include <random>

int inputValue();
int randomValue();
void sortArray(int *, int);

int main()
{
	std::cout << "Enter the size of array: ";
	int size_arr{inputValue()};
	int *const arr = new (std::nothrow) int[size_arr];
	
	if(!arr)
	{
		std::cout << "Could not allocate memory\n"; 
		return 0;
	}
	
	int *arr_temp = arr;
	
	for(int i{}; i < size_arr; ++i, ++arr_temp)
	{
		*arr_temp = randomValue();
		std::cout << *arr_temp << " ";
	}
	std::cout << "\n\n";
	
	sortArray(arr, size_arr);
	
	arr_temp = arr;
	
	for(int i{}; i < size_arr; ++i, ++arr_temp)
	{
		std::cout << *arr_temp << " ";
	}
	
	std::cout << "\n";
	
	delete [] arr;
	
	return 0;
}

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || value < 0)
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

int randomValue()
{
	std::random_device rd;
	std::mt19937 rnd(rd());
	std::uniform_int_distribution<int> distrib(0, 2);
	return distrib(rnd);
}

void sortArray(int *arr, int size_arr)
{
	for(int i{}; i < size_arr - 1; ++i)
	{
		for(int j{i + 1}; j < size_arr; ++j)
		{
			if(*(arr + i) > *(arr + j))
			{
				int temp = *(arr + i);
				*(arr + i) = *(arr + j);
				*(arr + j) = temp;
			}
		}
	}
}
