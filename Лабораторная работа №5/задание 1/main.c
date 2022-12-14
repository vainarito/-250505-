#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include"funkcia.h"
int main() {
	int massiv[100][100], sumAr[100][2], n, m;
	srand(time(NULL));
	printf("\n Надо ввести размер строк и столбцов матрицы!\n");
	m = vvodim_razmer_strok();
	n = vvodim_razmer_stolbikov();
	vagnaaj_shtuka(massiv, n, m);
	vivod_matrici(massiv, n, m);
	izmerenie_harakteristica(massiv,sumAr, n, m);
	characteristics(massiv, sumAr, n, m);
	return 0;
}
