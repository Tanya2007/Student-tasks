#include <iostream>

int inputValue();
double* memoryAllocation (int);
void fillingData(double*, int);
void printArray(double*, int);
void deleteMemory(double*);

int main()
{
	double *arr;
	std::cout << "Enter the size of the array: ";
	int size_arr{inputValue()};
	
	arr = memoryAllocation(size_arr);
	fillingData(arr, size_arr);
	printArray(arr, size_arr);
	deleteMemory(arr);
	
	return 0;
}

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || value <= 0)
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

double* memoryAllocation (int size_arr)
{
	std::cout << "\nMemory Allocation\n";
	return new double[size_arr];
}

void fillingData(double *arr, int size_arr)
{
	std::cout << "\nFilling in data\n";
	for(int i = 0; i < size_arr; ++i, ++arr)
	{
		std::cin >> *arr;
	}
}

void printArray(double *arr, int size_arr)
{
	std::cout << "\nPrint array:\n";
	for(int i = 0; i < size_arr; ++i, ++arr)
	{
		std::cout << *arr << " ";
	}
	std::cout << "\n";
}

void deleteMemory(double *arr)
{
	std::cout << "\nFreeing dynamic memory\n";
	delete [] arr;
}