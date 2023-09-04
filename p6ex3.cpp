#include <iostream>
#include <vector>

int inputValue();
void calculationBinomial(std::size_t, std::size_t, std::size_t, std::vector<long long>&, std::vector<long long>&);
void fillLevelBinomial(std::size_t, std::vector<long long>&, std::vector<long long>&);

int main()
{
	std::vector<long long> vec;
	std::vector<long long> vec_new;
	std::cout << "Enter the exponent (from 0 to 66): ";
	int exponent{inputValue()};

	vec.push_back(1);
	calculationBinomial(0, 1, static_cast<std::size_t>(exponent), vec, vec_new);

	for(const auto &elem : vec)
		std::cout << elem << " ";

	std::cout << "\n";

	return 0;
}

int inputValue()
{
	int value{};
	while(true)
	{
		std::cin >> value;

		if ( std::cin.fail() || value < 0 || value > 66 )
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

void calculationBinomial(std::size_t start_vec, std::size_t index, std::size_t end_vec, std::vector<long long>& vec, std::vector<long long>& vec_new)
{
	if(start_vec < end_vec)
	{
		vec_new = vec;
		fillLevelBinomial(index, vec, vec_new);
		vec = vec_new;
		vec.push_back(1);
		++start_vec;
		calculationBinomial(start_vec, index, end_vec, vec, vec_new);
	}
}

void fillLevelBinomial(std::size_t index, std::vector<long long>& vec, std::vector<long long>& vec_new)
{
	if(index < vec.size())
	{
		vec_new[index] += vec[index - 1];
		++index;
		fillLevelBinomial(index, vec, vec_new);
	}
}