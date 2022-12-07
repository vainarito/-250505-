#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include"Header.h"

int main()
{
	int row, col = 0;
	int new_col = 0;
	int** array = NULL;
	printf(" Введите количество строк массива:\n");
	raz(&row);
	printf(" Введите количество столбцов массива:\n");
	raz(&col);
	array = init_matrix_NxM(col, row);
	system("CLS");
	paste_NxM(array, row, col);
	printf("\n Ваша матрица:\n");
	print_matrix(row, col, array);

	int* sum_results = NULL, * array3=NULL;
	sum_results = arrayM2(sum_results, col);
	arraysum(sum_results, row, col, array);
	output2(sum_results, col);
	
	quickSortMatrix(array, row, col);
	printf("\n\v Результат:\n");
	print_matrix(row, col, array);
	free(array, row, sum_results);
	return 0;

}




