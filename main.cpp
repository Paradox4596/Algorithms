#include <iostream>

void PrintArray(int input[], int size);
void Swap(int& value1, int& value2);
void SequentialSort(int input[], int size); // 순차정렬
void SelectionSort(int input[], int size); // 선택정렬
void BubbleSort(int input[], int size); // 거품정렬
void InsertionSort(int input[], int size); // 삽입정렬

int main()
{
	const int size = 5;
	int array[size]{ 8,7,2,3,1 };

	// SORT ALGORITHM
	SequentialSort(array, size);

	PrintArray(array, size);
}

void PrintArray(int input[], int size)
{
	for (int i = 0; i < size; i++)
	{
		std::cout << input[i] << " ";
	}
}

void Swap(int& value1, int& value2)
{
	int temp = value1;
	value1 = temp; // ??
	value1 = value2;
	value2 = temp;
}

void SequentialSort(int input[], int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = i+1; j < size; j++)
		{
			if (input[i] > input[j])
			{
				Swap(input[i], input[j]);
			}
		}
	}
}

void SelectionSort(int input[], int size)
{
	for (int i = 0; i < size ; i++)
	{
		int minIndex = i;
		for (int j = i ; j < size; j++)
		{
			if (input[minIndex] > input[j])
			{
				minIndex = j;
			}
		}
		if (minIndex != i)
		{
			Swap(input[i], input[minIndex]);
		}
	}
}

void BubbleSort(int input[], int size)
{
	for (int phase = 0; phase < size-1; phase++)
	{
		for (int k = 0; k < size - phase - 1; k++)
		{
			if (input[k] > input[k+1])
			{
				Swap(input[k], input[k+1]);
			}
		}
	}
}

void InsertionSort(int input[], int size)
{
	for (int i = 1; i < size; i++)
	{
		int j = i; // i = 1 , j = 1
		int target = input[i]; // target =7

		while (--j >= 0 && target < input[j]) // j = 0, 7<8
		{
			input[j + 1] = input[j];
			input[j] = target;
		}
	}
}
