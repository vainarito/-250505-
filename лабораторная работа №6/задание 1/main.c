#include "func.h"    
#include <stdio.h>             
#include <stdlib.h>	
//#include <math.h>
#include <Windows.h>     
#include <time.h>

int main()
{

	mainMenu();
	return 1;
}
void mainMenu()
{
	int* array = NULL;
	int* arrayBubble = NULL;
	int flagOfArray = 0;
	int valueOfArray = 0;
	double bubbleTime = 0;
	double mergeTime = 0;
	double bedmergeTime = 0;
	while (1)
	{
		switch (menu())
		{
		case 1:
			system("cls");
			free(array);
			valueOfArray = inputValueOfArray();
			array = inputArray(valueOfArray);
			arrayBubble = allocateMemory(arrayBubble, valueOfArray);
			for (int i = 0; i <= valueOfArray; i++) {
				arrayBubble[i] = array[i];
			}
			flagOfArray = 1;
			break;
		case 2:
			system("cls");
			if (flagOfArray)
			{
				showArray(array, valueOfArray, 1);
				printf("\nВремя сортировки слиянием — %f", mergeSort(array, valueOfArray, mergeTime));
			}
			else
				printf("Введите массив\n");
			break;
		case 3:
			system("cls");
			if (flagOfArray)
			{
				//showArray(array, valueOfArray, 1);
				mergeTime = mergeSort(array, valueOfArray, mergeTime);
				printf("\nВремя сортировки слиянием — %f", mergeTime);
				bubbleTime = bubbleSort(arrayBubble, valueOfArray, bubbleTime);
				printf("\nВремя сортировки пузырьком — %f", bubbleTime);
				if (mergeTime != bubbleTime)
				{
					if (mergeTime < bubbleTime)
						printf("\nСортировка слияния быстрее на %f", bubbleTime - mergeTime);
					else
						printf("\nСортировка пузырька быстрее на %f", mergeTime - bubbleTime);
				}
				else
					printf("\nСортировки работают одинаково по времени");
			}
			else
				printf("Введите массив\n");
			break;
		case 4:
			system("cls");
			if (flagOfArray)
			{
				showArray(array, valueOfArray, 1);
				printf("\nХудшее время слиянием — %f", badMergeSort(array, valueOfArray, bedmergeTime));
			}
			else
				printf("Введите массив\n");
			break;
		case 5:
			system("cls");
			free(array);
			return;
		default:
			printf("Неправильный вариант\n");
			break;
		}
	}
}

int* allocateMemory(int* array, int n)
{
	if (!(array = (int*)calloc(n, sizeof(int))))
	{
		printf("Память под массив не выделилась");
		return NULL;
	}

	return array;
}
void showArray(int* array, int valueOfArray, int flag)
{
	if (!array)
	{
		printf("Массив пуст\n");
		return;
	}

	if (flag)
		printf("\nИсходный массив:\n");
	else
		printf("\nОтсортированный массив:\n");

	for (int i = 0; i < valueOfArray; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");

}
int* inputArray(int valueOfArray)
{
	int* array = NULL;
	array = allocateMemory(array, valueOfArray);
	srand(time(NULL));
	for (int i = 0; i < valueOfArray; i++)
	{
		array[i] = rand() % 200 - 100;
	}
	return array;
}
int inputValueOfArray()
{
	printf("Введите количество элементов массива: ");
	return checkInputInt();
}
int checkInputInt()
{
	int value;

	while (!scanf_s("%d", &value))
	{
		printf("Некорректный ввод\n");
		rewind(stdin);
	}

	return value;
}
int menu()
{
	printf("\nМеню");
	printf("\n1. Ввести массив чисел");
	printf("\n2. Измерить время сортировки слиянием");
	printf("\n3. Сравнить время сортировки с сортировкой методом пузырьком");
	printf("\n4. Измерить худшее время");
	printf("\n5. Выход");
	printf("\nВведите вариант: ");
	return checkInputInt();
}
double bubbleSort(int* desiredArray, int n, double time)
{
	int* array = NULL, * arrayIndex = NULL;
	int valueOfIndex = 0;
	array = allocateMemory(array, n);
	for (int i = 0; i < n; i++)
	{
		array[i] = desiredArray[i];
		if (abs(array[i]) % 2 == 1)
			valueOfIndex++;
	}

	arrayIndex = allocateMemory(arrayIndex, valueOfIndex);
	valueOfIndex = 0;
	for (int i = 0; i < n; i++)
		if (abs(array[i]) % 2 == 1)
		{
			arrayIndex[valueOfIndex] = i;
			valueOfIndex++;
		}

	clock_t time_start = clock();
	int i, j, swap;
	for (i = 0; i < valueOfIndex - 1; ++i)
		for (j = valueOfIndex - 1; j > i; --j)
		{
			if (array[arrayIndex[j - 1]] > array[arrayIndex[j]])
			{
				swap = array[arrayIndex[j - 1]];
				array[arrayIndex[j - 1]] = array[arrayIndex[j]];
				array[arrayIndex[j]] = swap;
			}
		}
	clock_t time_end = clock() - time_start;
	time = (double)time_end / CLOCKS_PER_SEC;
	showArray(array, n, 0);

	freee(array, arrayIndex, 0);
	return time;
}
double mergeSort(int* desiredArray, int n, double time)
{
	int* array = NULL, * arrayIndex = NULL;
	int valueOfIndex = 0;
	array = allocateMemory(array, n);
	for (int i = 0; i < n; i++)
	{
		array[i] = desiredArray[i];
		if (abs(array[i]) % 2 == 1)
			valueOfIndex++;
	}

	arrayIndex = allocateMemory(arrayIndex, valueOfIndex);
	valueOfIndex = 0;
	for (int i = 0; i < n; i++)
		if (abs(array[i]) % 2 == 1)
		{
			arrayIndex[valueOfIndex] = i;
			valueOfIndex++;
		}

	clock_t time_start = clock();

	int step = 1;  // шаг разбиения последовательности
	int* temp = (int*)malloc(valueOfIndex * sizeof(int)); // дополнительный массив
	while (step < valueOfIndex)  // пока шаг меньше длины массива
	{
		int index = 0;    // индекс результирующего массива
		int l = 0;      // левая граница участка
		int m = l + step;  // середина участка
		int r = l + step * 2;  // правая граница участка
		do
		{
			m = m < valueOfIndex ? m : valueOfIndex;  // сортируемый участок не выходит за границы последовательности
			r = r < valueOfIndex ? r : valueOfIndex;
			int i1 = l, i2 = m; // индексы сравниваемых элементов
			for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
			{
				if (array[arrayIndex[i1]] < array[arrayIndex[i2]]) { temp[index++] = array[arrayIndex[i1++]]; } // заполняем участок результирующей последовательности
				else { temp[index++] = array[arrayIndex[i2++]]; }
			}
			// Или i1 < m или i2 < r - только один из операторов while может выполниться
			while (i1 < m) temp[index++] = array[arrayIndex[i1++]]; // заносим оставшиеся элементы сортируемых участков
			while (i2 < r) temp[index++] = array[arrayIndex[i2++]]; // в результирующий массив
			l += step * 2; // перемещаемся на следующий сортируемый участок
			m += step * 2;
			r += step * 2;
		} while (l < valueOfIndex); // пока левая граница сортируемого участка - в пределах последоватльности
		for (int i = 0; i < valueOfIndex; i++) // переносим сформированный массив обратно в a
			array[arrayIndex[i]] = temp[i];
		step *= 2; // увеличиваем в 2 раза шаг разбиения

	}


	clock_t time_end = clock() - time_start;
	time = (double)time_end / CLOCKS_PER_SEC;
	showArray(array, n, 0);
	freee(array, arrayIndex, temp);
	return time;
}
double badMergeSort(int* desiredArray, int n, double time)
{
	int* array = NULL, * arrayIndex = NULL;
	int valueOfIndex = 0;
	array = allocateMemory(array, n);
	clock_t time_start = clock();
	mergeSort(desiredArray,n, time);

	int step = 1;  // шаг разбиения последовательности
	int* temp = (int*)malloc(valueOfIndex * sizeof(int)); // дополнительный массив
	while (step < valueOfIndex)  // пока шаг меньше длины массива
	{
		int index = 0;    // индекс результирующего массива
		int l = 0;      // левая граница участка
		int m = l + step;  // середина участка
		int r = l + step * 2;  // правая граница участка
		do
		{
			m = m < valueOfIndex ? m : valueOfIndex;  // сортируемый участок не выходит за границы последовательности
			r = r < valueOfIndex ? r : valueOfIndex;
			int i1 = l, i2 = m; // индексы сравниваемых элементов
			for (; i1 < m && i2 < r; ) // пока i1 не дошёл до середины и i2 не дошёл до конца
			{
				if (array[arrayIndex[i1]] < array[arrayIndex[i2]]) { temp[index++] = array[arrayIndex[i1++]]; } // заполняем участок результирующей последовательности
				else { temp[index++] = array[arrayIndex[i2++]]; }
			}
			// Или i1 < m или i2 < r - только один из операторов while может выполниться
			while (i1 < m) temp[index++] = array[arrayIndex[i1++]]; // заносим оставшиеся элементы сортируемых участков
			while (i2 < r) temp[index++] = array[arrayIndex[i2++]]; // в результирующий массив
			l += step * 2; // перемещаемся на следующий сортируемый участок
			m += step * 2;
			r += step * 2;
		} while (l < valueOfIndex); // пока левая граница сортируемого участка - в пределах последоватльности
		for (int i = 0; i < valueOfIndex; i++) // переносим сформированный массив обратно в a
			array[arrayIndex[i]] = temp[i];
		step *= 2; // увеличиваем в 2 раза шаг разбиения

	}

	clock_t time_end = clock() - time_start;
	time = (double)time_end / CLOCKS_PER_SEC;
	//showArray(array, n, 0);
	freee(array, 0 ,0);
	return time;
}
void freee(int* arr1, int* arr2, int* arr3) {
	free(arr1);
	free(arr2);
	free(arr3);
}

