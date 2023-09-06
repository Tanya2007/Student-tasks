#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

template <typename T>
std::vector<T>& partHalf(const std::vector<T> &vec, std::vector<T> &vec_part)
{
	std::size_t size_vec_part = vec.size() / 2;
	vec_part.resize(size_vec_part);
	std::copy(vec.begin(), vec.begin() + static_cast<int>(size_vec_part), vec_part.begin());
	
	return vec_part;
}

template <typename T>
std::vector<T>& partThird(const std::vector<T> &vec, std::vector<T> &vec_third)
{
	std::size_t size_vec_third = vec.size() / 3;
	vec_third.resize(size_vec_third);
	std::copy(vec.begin() + static_cast<int>(size_vec_third), vec.begin() + static_cast<int>(size_vec_third * 2), vec_third.begin());
	
	return vec_third;
}

template <typename T>
std::vector<T>& concat(std::vector<T> &vec, const std::vector<T> &vec_con)
{
	int size_vec = static_cast<int>(vec.size());
	vec.resize(vec_con.size() + vec.size());
	std::copy(vec_con.begin(), vec_con.end(), vec.begin() + size_vec);
	
	return vec;
}

int main()
{
	//получение половины вектора
	std::vector<std::string> vec{"Hello","Tanya","OK","single","love", "like", "bye", "come", "true"};
	std::vector<std::string> vec_part;
	
	partHalf(vec, vec_part);
	
	for(const auto &elem : vec_part)
		std::cout << elem << " ";
		
	std::cout << "\n";
		
	//получение средней трети вектора
	std::vector<std::string> vec_third;
	
	partThird(vec, vec_third);
	
	for(const auto &elem : vec_third)
		std::cout << elem << " ";
		
	std::cout << "\n";
	
	//сцепление двух векторов
	concat(vec_third, std::vector<std::string>{"Hello","Tanya"});
	for(const auto &elem : vec_third)
		std::cout << elem << " ";
		
	std::cout << "\n";
	
	return 0;
}