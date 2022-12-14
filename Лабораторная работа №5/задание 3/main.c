#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
int main()
{
    int** a;  // указатель на указатель на строку элементов
    int i, j, n, m, k;
    printf("Введите количество строк: ");
    scanf("%d", &n);
    printf("Введите количество столбцов: ");
    scanf("%d", &m);
    printf("Введите катый: ");
    scanf("%d", &k);
    // Выделение памяти под указатели на строки
    a = (int**)malloc(n * sizeof(int*));
    // Ввод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        // Выделение памяти под хранение строк
        a[i] = (int*)malloc(m * sizeof(int));
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("a[%d][%d] = ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    // Вывод элементов массива
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }
    int h = 0;
    for (i = 0; i < n; i++) {
        for (j = 0; j < m; j++) {
            if ((i + 1) % k != 0) {
                a[h++][j] = a[i][j];

            }
        }
    }
    for (i = 0; i < n; i++)  // цикл по строкам
    {
        for (j = 0; j < m; j++)  // цикл по столбцам
        {
            printf("%5d ", a[i][j]); // 5 знакомест под элемент массива
        }
        printf("\n");
    }

    return 0;
}
