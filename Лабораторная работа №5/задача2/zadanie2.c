#include<time.h>
#include"Hader.h"
#include <stdio.h>
#include <stdlib.h>
int size() {
    int number_of_lines;
    printf(" Ведите количество строк:");
    while (!scanf_s("%d", &number_of_lines) || getchar() != '\n' || number_of_lines > 100 || number_of_lines < -100) {
        printf(" Ошибка!\n");
        printf(" Ведите количество строк:");
        rewind(stdin);
    }
    printf("\n");
    return number_of_lines;
}
int enter_k() {
    int repeating_element_s;
    printf(" Введите элемент k-тую строку, которая будет удаляться:");
    while (!scanf_s("%d", &repeating_element_s) || getchar() != '\n' || repeating_element_s > 100 || repeating_element_s < -100) {
        printf(" Ошибка!\n");
        printf(" Введите элемент k-тую строку, которая будет удаляться:");
        rewind(stdin);
    }
    printf("\n");
    return repeating_element_s;
}
void arrayOutput(int** array, int lines, int* Number_of_elements_per_line) {
    for (int i = 0; i < lines; i++) {
        for (int j = 0; j < Number_of_elements_per_line[i]; j++) {
            printf("%5d", array[i][j]);
        }
        printf("\n");
    }
}
void deletingArr(int** array, int lines) {
    for (int i = 0; i < lines; ++i) {
        free(array[i]);
    }
    free(array);
}
void deleteK(int lines, int katiy, int** array, int* massiv) {
    array = (int**)malloc(lines * sizeof(int*));
    massiv = (int*)malloc(lines * sizeof(int)); // массив кол-ва элеменов в строках массива array2
    int size = 1;
    for (int i = 0; i < lines; i++) // Ввод элементов массива
    {
        massiv[i] = size;
        array[i] = (int*)malloc(massiv[i] * sizeof(int));
        for (int j = 0; j < massiv[i]; j++) {
            size++;
            massiv[i] = size;
            array[i] = (int*)realloc(array[i], (massiv[i]) * sizeof(int));
            printf(" a[%d][%d]= ", i + 1, j + 1);
            while (!scanf_s("%d", &array[i][j]) || getchar() != '\n') {
                printf(" Ошибка!\n");
                printf(" a[%d][%d]= ", i + 1, j + 1);
                rewind(stdin);
            }
            if (array[i][j] == -100) {
                massiv[i] = size - 2;
                size = 1;
                break;
            }
        }
    }
    printf("______________________________________________\n Получилась матрица:\n\v");
    arrayOutput(array, lines, massiv);
    int l = 0;
    for (int i = 0; i < lines; i++) {
        array[l] = (int*)realloc(array[l], massiv[i] * sizeof(int));
        massiv[l] = massiv[i];
        for (int j = 0; j < massiv[i]; j++) {
            if ((i + 1) % katiy != 0)
            {
                array[l][j] = array[i][j];
            }
        }
        if ((i + 1) % katiy != 0)
            l++;
    }
    lines = lines - l+1;
    array = (int**)realloc(array, lines * sizeof(int*));
    printf("______________________________________________\n Получилась матрица:\n\v");
    for (int i = 0; i < lines; i++) // Вывод элементов массива
    {
        for (int j = 0; j < massiv[i]; j++)
        {
            printf("%5d ", array[i][j]);
        }
        printf("\n");
    }
    deletingArr(array, lines);
}