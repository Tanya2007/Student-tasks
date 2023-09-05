#include <iostream>
#include <string>
#include <utility>

template <typename T>
void percentageNumber (T *arr, int size)
{
	for(int i{}; i < size - 1; ++i)
	{
		for(int j{i + 1}; j < size; ++j)
		{
			if(arr[i] > arr[j])
			{
				T temp = std::move(arr[i]);
				arr[i] = std::move(arr[j]);
				arr[j] = std::move(temp);
			}
		}
	}
}

template <typename T>
void print(const T *arr, int size)
{
	for(int i{}; i < size; ++i)
	{
		std::cout << arr[i] << " ";
	}
	std::cout << "\n";
}

int main()
{
	int arr_int[]{1,5,-6,7,36,12};
	percentageNumber(arr_int, 6);
	print(arr_int, 6);
	
	double arr_double[]{4.0,-25,47.6,51.8,-100,33};
	percentageNumber(arr_double, 6);
	print(arr_double, 6);
	
	std::string arr_string[]{"hello", "anika", "xor"};
	percentageNumber(arr_string, 3);
	print(arr_string, 3);
	
	char arr_char[]{'h', 'a', 'x'};
	percentageNumber(arr_char, 3);
	print(arr_char, 3);
	
	return 0;
}