#include "Header.h"        
#include <stdio.h>             
#include <stdlib.h>			   
#include <Windows.h>           

void mainMenu()
{
	while (1)
	{
		switch (menu())
		{
		case 1:
			system("cls");
			theFirstTask();
			break;
		case 2:
			system("cls");
			theSecondTask();
			break;
		case 3:
			system("cls");
			return;
		default:
			printf("Неправильный вариант\n");
			break;
		}
	}
}
void theFirstTask()
{
	char* string = NULL;
	char* (*function)(char*) = NULL;
	function = removeExtraSpaces;
	string = allocateMemory(string);
	string = getstr(string);
	string = function(string);
	printf("Строка без лишних пробелов: %s", string);
	free(string);
}
void theSecondTask()
{
	int a, b;
	char* (*function)(char*, char*, int, int) = NULL;
	function = insertStrings;

	printf("Введите число a: ");
	a = checkInputInt();
	printf("Введите число b: ");
	b = checkInputInt();
	char* s = NULL, * s0 = NULL;
	s = allocateMemory(s);
	s0 = allocateMemory(s0);
	s = getstr(s);
	s0 = getstr(s0);
	if (b > str_len(s) || a > str_len(s0))
	{
		printf("Число b больше длины S или число а больше длины s0");
		return;
	}
	system("cls");
	printf("Искомые данные\n");
	printf("a = %d, b = %d\n", a, b);
	printf("S: %s\n", s);
	printf("S0: %s\n", s0);

	s0 = function(s, s0, a, b);

	printf("Итоговая строка: %s", s0);

	free(s);
	free(s0);
}
char* getstr(char* st)
{
	if (!st)
		return NULL;
	//если мы получаем пустой указатель то мы выходим из фуе=нкции иначе программа завершит работу 
	int flag = 1;//флаг нужен для проверки строки на пустоту
	do
	{
		printf("Введите строку: ");
		int i = 0;
		rewind(stdin); //чистка клавиатурного буфера
		while ((*(st + i++) = (char)getchar()) != '\n');
		//считываем в строку символы по одному пока очередной символ не будет ентер
		st[--i] = '\0';
		//ставим конец строки 
		i = 0;
		while (st[i] != '\0' && st[i] == ' ')
			i++;
		//проверка чтобы строка не была пустой
		if (st[i] != '\0')
			flag = 0;
	} while (st[0] == '\0' || flag);//если строка пустая то пускаем всё по кругу
	return st;
}
int str_len(char* st)//длина функци своя
{
	int n = 0;
	for (; st[n] != '\0'; n++);//бесконечный цикл пока символ не будет концом строки 
	return n;
}
char* removeExtraSpaces(char* st)
{
	if (!st) return NULL;

	int lengthOfString = str_len(st), index = 0;
	// считается кол-во пробелов в начале строки
	while (st[index] == ' ' && index < lengthOfString)
		index++;
	//удаляю их
	if (index)
	{
		for (int i = 0; i < lengthOfString - index; i++)
			st[i] = st[i + index];
		st[lengthOfString - index] = '\0';
	}

	//здесь смотрим если у меня два пробела подряд то я смотрю сколько еще там пробелов и потом убираю их путем смещения строки вперед
	index = 0;
	lengthOfString = str_len(st);

	for (int i = 0; i < lengthOfString - 1; i++)
	{
		if (st[i] == ' ' && st[i + 1] == ' ')
		{
			index = i;
			int j = index;
			while (st[j] == ' ' && j < lengthOfString)
				j++;

			index = j - i - 1;

			for (int ij = i + 1; ij < lengthOfString - index; ij++)
				st[ij] = st[ij + index];

			st[lengthOfString - index] = '\0';
			lengthOfString -= index;
		}
	}
	if (st[lengthOfString - 1] == ' ')
		st[lengthOfString - 1] = '\0';

	return st;
}
char* insertStrings(char* s, char* s0, int a, int b)
{
	if (!s || !s0) return NULL;

	char* string=NULL;
	//if (!(string = (char*)calloc(80, sizeof(char))))
	//{
	//	printf("Память под строку не выделилась");
	//	return 1;
	//}
	string = allocateMemory(string);
	string[str_len(s0) + b + 1] = '\0';

	for (int i = 0; i < a; i++)
		string[i] = s0[i];

	for (int i = a; i < a + b; i++)
		string[i] = s[i - a];

	int j = a + b;
	for (int i = a; i < str_len(s0); i++)
	{
		string[j] = s0[i];
		j++;
	}

	return string;
}
char* allocateMemory(char* string)
{
	if (!(string = (char*)calloc(80, sizeof(char))))
	{
		printf("Память под строку не выделилась");
		return 1;
	}

	return string;
}
int checkInputInt()
{
	int value;

	while (!scanf_s("%d", &value)|| getchar()!='\n'|| value<1)
	{
		printf("Некорректный ввод\n");
		rewind(stdin);
	}

	return value;
}
int menu()
{
	printf("\nМеню");
	printf("\n1. Дана строка. Удалить из нее все лишние пробелы. Между словами оставить только по одному пробелу");
	printf("\n2. Даны два числа a, b и строки S, S0. Вставить b символов строки S в строку S0 начиная с a-го индекса");
	printf("\n3. Выход");
	printf("\nВведите вариант: ");
	return checkInputInt();
}