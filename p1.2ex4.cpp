#include <iostream>
#include <iomanip>
#include <random>
////////////////////////////////////////////////////////////////
int generateValue()
{
	std::random_device rd;
	std::mt19937 rnd(rd());
	std::uniform_int_distribution<int> distrib(-100, 100);
	return distrib(rnd);
}
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
int enteringQuantity()
{
	int value{};
	while(true)
	{
		value = inputValue();
		if(value > 0)
			break;

		std::cout << "The quantity must be greater than zero. Try again: ";
	}

	return value;
}
//////////////////////////////////////////////////////////////////
void printArr(int **arr, int N, int M)
{
	for(int i{}; i < N; ++i)
	{
		for(int j{}; j < M; ++j)
		{
			std::cout << std::setw(5) << arr[i][j] << " ";
		}
		std::cout << "\n";
	}
}
///////////////////////////////////////////////////////////////////
int main()
{
	int N, M;
	std::cout << "Enter the dimension of the matrix.\n";

	//ввод количества строк
	std::cout << "Number of rows N = ";
	N = enteringQuantity();

	//ввод количества колонок
	std::cout << "Number of columns M = ";
	M = enteringQuantity();

	//создание и заполнение динамического массива
	int **arr = new int* [N];
	for(int i{}; i < N; ++i)
	{
		arr[i] = new int[M];
		for(int j{}; j < M; ++j)
		{
			arr[i][j] = generateValue();
		}
	}

	//вывод сформированного массива на экран
	std::cout << "\nThe original matrix:\n";
	printArr(arr, N, M);

	//определение максимального индекса
	//главной диагонали не квадратной матрицы
	int NM;
	if(N > M)
		NM = M;
	else
		NM = N;

	//сортировка элементов главной диагонали матрицы по убыванию
	for(int i{}; i < NM - 1; ++i)
	{
		for(int j{i + 1}; j < NM; ++j)
		{
			if(arr[i][i] < arr[j][j])
			{
				int temp = arr[i][i];
				arr[i][i] = arr[j][j];
				arr[j][j] = temp;
			}
		}
	}

	//вывод отсортированной матрицы по главной диагонали на экран
	std::cout << "\nThe sorted matrix:\n";
	printArr(arr, N, M);

	std::cout << "\n";

	//очистка динамической памяти
	for(int i{}; i < N; ++i)
	{
		delete [] arr[i];
	}
	delete [] arr;

	return 0;
}