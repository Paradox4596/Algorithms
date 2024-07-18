#include <iostream>

void PrintArray(int input[], int size);
void Swap(int& value1, int& value2);
void SequentialSort(int input[], int size); // 순차정렬
void SelectionSort(int input[], int size); // 선택정렬
void BubbleSort(int input[], int size); // 거품정렬
void InsertionSort(int input[], int size); // 삽입정렬
void MergeSort(int input[], int start, int end, int temp[]); // 합병(병합)정렬
void Merge(int input[], int start, int half, int end, int temp[]);

int main()
{
	const int size = 5;
	int array[size]{ 8,7,2,3,1 };

	// SORT ALGORITHM
	/*SequentialSort(array, size);*/

	// Divide And Conquer
	MergeSort(array, 0, size - 1, tempArray);

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
			Swap(input[i], input[minIndex]); // 가장 작은 값으 배열 인덱스 저장
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

void MergeSort(int input[], int start, int end, int temp[])
{
	if (start >= end)
	{
		return;
	}

	int half = (start + end) / 2;

	MergeSort(input, start, half, temp);
	MergeSort(input, half +1, end, temp);
	Merge(input, start, half, end, temp);
}

void Merge(int input[], int start, int half, int end, int temp[])
{
	int i = start;
	int j = half + 1;
	int tempIndex = 0;

	// 왼쪽 블럭과 오른쪽 블럭을 정렬 합병
	while (i<=half && j <= end)
	{
		if (input[i] < input[j])
		{
			temp[tempIndex++] = input[i++];
		}
		else
		{
			temp[tempIndex++] = input[j++];
		}
	}
	
	// 남은 인덱스들을 병합
	// 왼쪽 or 오른쪽 블럭이 남아있을 경우 대비해서 각각 병합
	while (i <= half)
	{
		temp[tempIndex++] = input[i++];
	}
	
	while (j <= end)
	{
		temp[tempIndex++] = input[j++];
	}
}
