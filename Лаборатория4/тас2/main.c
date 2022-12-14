#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"funkcia.h"
int main() {
	int massiv[100][100], n, m;
	srand(time(NULL));
	printf("\n Надо ввести размер строк и столбцов матрицы!\n");
	m = vvodim_razmer_strok();
	n = vvodim_razmer_stolbikov();
	printf("\n");
	vagnaaj_shtuka(massiv, n, m);
	printf("\n У тебя получиласть вот такая матрица:\n");
	printf("\n");
	vivod_matrici(massiv, n, m);
	printf("\n");
	izmenenie_znaka(massiv, n, m);
	izmenenie_znaka_net(massiv, n, m);
	printf("\n");
	printf(" ОНО РАБОТАЕТ! ОНО ЖИВОЕ!");
	printf("\n");
	return 0;
}	
