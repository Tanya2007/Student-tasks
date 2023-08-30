#include <iostream>
#include <fstream>

int main()
{
	std::ifstream fin("p2ex4_Matrix.txt");
	int N, M;
	
	fin >> N >> M;
	int **arr = new int* [N];
	for(int i = 0; i < N; ++i)
	{
		arr[i] = new int [M];
		for (int j = 0; j < M; ++j)
		{
			fin >> arr[i][j];
		}
	}
	fin.close();
	
	for (int j = 0; j < M; ++j)
	{
		for (int i = 0; i < N - 1; ++i)
		{
			for (int k = i + 1; k < N; ++k)
			{
				if(arr[i][j] < arr[k][j])
				{
					int temp = arr[k][j];
					arr[k][j] = arr[i][j];
					arr[i][j] = temp;
				}
			}
		}
	}
	
	std::ofstream fout("p2ex4_Matrix_Sort.txt");
	fout << N  << "\t" << M << "\n";
	for(int i = 0; i < N; ++i)
	{
		for (int j = 0; j < M; ++j)
		{
			fout << arr[i][j] << "\t";
		}
		fout << "\n";
	}
	
	for(int i = 0; i < N; ++i)
	{
		delete [] arr[i];
	}
	delete [] arr;
	
	return 0;
}