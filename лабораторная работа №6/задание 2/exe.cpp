#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>
#include<string.h>
#include"Header.h"

//размеры  
void raz(int* x)
{
	while (!scanf_s("%d", x) || getchar() != '\n' || *x <= 0)
	{
		rewind(stdin);
		printf(" Ошибка вводимых данных:\n");
	}
}
// принт эрэй)
void printArray(int razmer, int* arr)
{
	for (int i = 0; i < razmer; i++)
		printf("%5d; ", arr[i]);
}
//доп к сортировке 
int* initArray(int x)
{
	int* arr = (int*)(malloc(x * sizeof(int)));
	return arr;
}
//выделение памяти
int** initMatrixNxM(int col, int row)
{
	int** arr = (int**)calloc(row, sizeof(int*));
	for (int i = 0; i < row; i++)
	{
		arr[i] = (int*)calloc(col, sizeof(int));
	}
	return arr;
}
//заполнение матрицы
int** pasteNxM(int** arr, int row, int col)
{
	srand(time(NULL));
	for (int i = 0; i < row; i++)
		for (int n = 0; n < col; n++)
			arr[i][n] = rand() % 200 - 100;
	return arr;
}
//вывод изначальной матрицы 
void printMatrix(int row, int col, int** arr)
{
	for (int i = 0; i < row; i++)
	{
		printf("\n");
		for (int n = 0; n < col; n++)
		{
			printf("%5d;\t", arr[i][n]);
		}
	}
	printf("\n");
}

//заполнение памяти массива сумм
int* arrayM2(int* sumResults, int col) {
	sumResults = (int*)calloc(col, sizeof(int));
	return sumResults;
}
//заполнение массив сумм
void arraySum(int* sumResults, int row, int col, int** arr) {
	int sum = 0;
	for (int i = 0; i < col; i++) {
		for (int j = 0; j < row; j++) {
			sum += arr[j][i];
		}
		sumResults[i] = sum;
		sum = 0;
	}
}
//вывод массива сумм
void output2(int* sumResults, int col) {
	printf("\n Суммы столбцов:\n");
	for (int i = 0; i < col; i++)
		printf("%5d", sumResults[i]);
}
//удаленеи массива сумм
void deleteArr(int* sumResults, int col) {
	int m = 0;
	for (int i = 0; i < col; i++) {
		if ((i + 1) % 2 != 0)
		{
			sumResults[m++] = sumResults[i + 1];
		}
	}
}
//новый размер сумм 
int newSize(int* sumResults, int col) {
	int newsize = 0;
	for (int i = 0; i < col; i++) {
		if ((i + 1) % 2 != 0)
		{
			newsize++;
		}
	}
	return newsize;
}
//сотритровка 
void sortArrQuick(int**& arr, int* sort, int row, int col)
{
	int** new_matrix = initMatrixNxM(row, col);
	for (int sort_pos = 0; sort_pos < col; sort_pos++)
	{
		for (int j = 0; j < row; j++)
		{
			if (sort_pos % 2 == 1)
			{
				new_matrix[j][sort_pos] = arr[j][sort[(int)sort_pos / 2]];
			}
			else
			{
				new_matrix[j][sort_pos] = arr[j][sort_pos];
			}
		}
	}
	arr = new_matrix;
}
//сортировка
void quickSort(int*& arr, int*& sort, int start, int end) {
	int i = start;
	int j = end;
	int tmp;
	int sort_tmp;
	int x = arr[(start + end) / 2];
	do
	{
		while (arr[i] > x)
			i++;
		while (arr[j] < x)
			j--;
		if (i <= j) {
			if (i < j) {

				tmp = arr[i];
				arr[i] = arr[j];
				arr[j] = tmp;

				sort_tmp = sort[i];
				sort[i] = sort[j];
				sort[j] = sort_tmp;
			}
			i++;
			j--;
		}
	} while (i <= j);

	if (i < end)
		quickSort(arr, sort, i, end);
	if (start < j)
		quickSort(arr, sort, start, j);
}
//сортировка
void quickSortMatrix(int**& arr, int row, int col)
{
	int* sort = initArray(col / 2);
	int* sumArr = initArray(col / 2);
	for (int i = 1; i < col; i++) {
		int sum = 0;
		for (int j = 0; j < row; j++)
		{
			sum += arr[j][i];
		}
		if (i % 2 == 1)
		{
			sumArr[i / 2] = sum;
			sort[i / 2] = i;

		}
	}

	quickSort(sumArr, sort, 0, (col - 1) / 2);
	sortArrQuick(arr, sort, row, col);
	free(sort);
}

