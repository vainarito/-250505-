void vagnaaj_shtuka(int massiv[100][100], int n, int m) {
	int tuutuuu;
	printf(" Если хотите ввести значения через клавиатуру - нажмите 1!\n Если хотите ввести значения случайным образом - нажмите на любое другое число!\n");
	printf("\n");
	printf(" Вводимое число:");
	while (!scanf_s("%d", &tuutuuu) || getchar() != '\n') {
		printf(" Вводимое число:");
		rewind(stdin);
	}
	if (tuutuuu == 1) { //ввод элеметов массива в ручную
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				printf(" %d.%d элемент матрицы = ", i + 1, j + 1);
				while (!scanf_s("%d", &massiv[i][j]) || getchar() != '\n') {
					printf(" %d.%d элемент матрицы = ", i + 1, j + 1);
					rewind(stdin);
				}
			}
		}
	}
	else {
		// ввод элементов рандомно 
		srand(time(NULL));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				massiv[i][j] = (rand() % 200) - 100;
			}
		}
	}
	printf("___________________________________________________________________________________________\n\v");
	printf("\n У тебя получиласть вот такая матрица:\n");
	printf("\n");
}
int vvodim_razmer_strok() {
	int stroki;
	//ввод с клавиатуры количества столбцов и строк в массиве
	printf(" Введите размер строки: ");
	while (!scanf_s("%d", &stroki) || stroki > 100 || stroki <= 0 || getchar() != '\n') {
		printf(" Введите размер строки:");
		rewind(stdin);
	}
	return stroki;
}
int vvodim_razmer_stolbikov() {
	int stolbiki;
	//ввод с клавиатуры количества столбцов и строк в массиве
	printf(" Введите размер столбца: ");
	while (!scanf_s("%d", &stolbiki) || stolbiki > 100 || stolbiki <= 0 || getchar() != '\n') {
		printf(" Введите размер столбца: ");
		rewind(stdin);
	}
	return stolbiki;
	printf("\n");
}
void vivod_matrici(int massiv[100][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			printf("%4d", massiv[i][j]);
		}
		printf("\n");
		printf("\v");
	}
	printf("___________________________________________________________________________________________\n\v\v");
}
void izmerenie_harakteristica(int massiv[100][100], int sumAr[100][2], int n, int m) {
	int summ = 0, flag = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (massiv[i][j] < 0 && massiv[i][j] % 2 == 0) {
				summ += massiv[i][j];
			}
		}
		printf(" Характеристика сторки %d = %d\n\v", i + 1, summ);
		sumAr[i][0] = summ;
		sumAr[i][1] = i;
		summ = 0;
	}
	printf("___________________________________________________________________________________________\n\v\v");
}
void characteristics(int massiv[100][100], int sumAr[100][2], int n, int m) {
	int flag = 0;
	printf(" Изменённая матрица, строки которой были отсортированы по убыванию характеоистик этих сток:\n\v");
	for (int t = 0; t < n; t++)
	{
		for (int j = 0; j < n; j++)
		{
			if (sumAr[j][0] < sumAr[j + 1][0])
			{
				flag = sumAr[j][0];
				sumAr[j][0] = sumAr[j + 1][0];
				sumAr[j + 1][0] = flag;

				flag = sumAr[j][1];
				sumAr[j][1] = sumAr[j + 1][1];
				sumAr[j + 1][1] = flag;
				for (int i = 0; i < n; i++)
				{
					flag = massiv[j][i];
					massiv[j][i] = massiv[j + 1][i];
					massiv[j + 1][i] = flag;
				}
			}

		}
	}
	for (int i = 0; i < n; i++) {

		for (int j = 0; j < m; j++) {
			printf("%4d", massiv[i][j]);
		}
		printf("\n");
		printf("\v");
	}
	printf("\n");
	printf(" ОНО РАБОТАЕТ! ОНО ЖИВОЕ!");
	printf("\n");
}