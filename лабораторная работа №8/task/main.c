#include "Header.h"
#include <locale.h>
#include <stdlib.h>
#include <stdio.h>
#include <Windows.h>
#include <conio.h>

int main(int argc, char** argv)
{
    setlocale(LC_ALL, "ru");
    SetConsoleCP(1251);

    char** strings = inputStrings(argc, argv);
    printStrings(strings, "Искомые строки", argc);
    sortStrings(strings, 2, argc - 1);
    printStrings(strings, "Cтроки после сортировки", argc);
    free(strings);
    return 0;
}
void sortStrings(char** strings, int first, int last)
{
    int i = first, j = last, x = str_len(strings[(first + last) / 2]);
    char* swapString = NULL;
    do
    {
        while (str_len(strings[i]) < x) i++;
        while (str_len(strings[j]) > x) j--;

        if (i <= j)
        {
            if (str_len(strings[i]) > str_len(strings[j]))
            {
                swapString = strings[i];
                strings[i] = strings[j];
                strings[j] = swapString;
            }
            i++;
            j--;
        }
    } while (i <= j);

    if (i < last)
        sortStrings(strings, i, last);
    if (first < j)
        sortStrings(strings, first, j);

}
int str_len(char* st)
{
    int n = 0;
    for (; st[n] != '\0'; n++);
    return n;
}
char** inputStrings(int argc, char** argv)
{
    char** strings = NULL;

    if (!(strings = (char**)malloc(argc * sizeof(char*))))
    {
        printf("Память под строку не выделилась");
        return 1;
    }

    for (int i = 0; i < argc; i++)
    {
        if (!(strings[i] = (char*)malloc(50 * sizeof(char))))
        {
            printf("Память под строку не выделилась");
            return 1;
        }
        strings[i] = argv[i];
    }

    return strings;
}
void printStrings(char** strings, char* string, int n)
{
    printf("%s:\n", string);
    for (int i = 2; i < n; i++)
    {
        printf("%s\n", strings[i]);
    }
}
