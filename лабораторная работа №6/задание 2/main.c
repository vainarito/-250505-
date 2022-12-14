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
	array = initMatrixNxM(col, row);
	system("CLS");
	pasteNxM(array, row, col);
	printf("\n Ваша матрица:\n");
	printMatrix(row, col, array);

	int* sumResults = NULL; //* array3=NULL;
	sumResults = arrayM2(sumResults, col);
	arraySum(sumResults, row, col, array);
	output2(sumResults, col);
	
	quickSortMatrix(array, row, col);
	printf("\n\v Результат:\n");
	printMatrix(row, col, array);
	return 0;

}




