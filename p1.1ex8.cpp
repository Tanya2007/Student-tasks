#include <iostream>
#include <iomanip>
#include <cmath>

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
	constexpr int N{10};
	int arr[N];
	
	double summ{};
	
	for(int i{}; i < N; ++i)
	{
		arr[i] = inputValue();
		summ += arr[i];
	}
	
	double arithmetic_mean = std::round(summ / N * 100) / 100;
	
	int above_average{};
	
	for(int i{}; i < N; ++i)
	{
		if(arr[i] > arithmetic_mean)
		{
			++above_average;
		}
	}
	
	std::cout << "The percentage of elements exceeding the arithmetic mean of all elements of the array: ";
	std::cout << std::fixed << std::setprecision(2) << above_average * 100 / N << " %\n";
	
	return 0;
}