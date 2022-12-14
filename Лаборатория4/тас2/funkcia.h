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
			for (int j = 0; j <m; j++) {
				massiv[i][j] = (rand() % 200);
			}
		}
	}
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
}
void vivod_matrici(int massiv[100][100], int n, int m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <m; j++) {
			printf("%4d",massiv[i][j]);
		}
		printf("\n");
		printf("\v");
	}
}
void izmenenie_znaka(int massiv[100][100], int n, int m) {
	printf(" Изменённая матрица:\n");
	printf("\n");
		for (int i = 0; i < n; ++i) //проверка эллементов массива на отрицатнльный знак массива на знак 
		{                                //и последущая замена знаков 
		 for (int j = 0; j < m; ++j)
			{
			 if (massiv[i][j] < 0) {
					             for (int i = 0; i < n; ++i)
					            {
						         for (int j = 0; j < m; ++j)
					        	{
							     massiv[i][j] = -massiv[i][j];
						         printf("%4d",massiv[i][j]);
					         	}
						         printf("\n");
						         printf("\v");
					            }
								 printf(" ОНО РАБОТАЕТ! ОНО ЖИВОЕ!");
								 printf("\n");
			                     exit (0);
				                }
			                    }
		                        }
}
void izmenenie_znaka_net(int massiv[100][100], int n, int m) {
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			printf("%4d",massiv[i][j]);
		}
		printf("\n");
		printf("\v");
	}
	printf(" В матрице не встречаются отрицательные эллементы, значит элементы матрицы не поменяют свои знаки!\n");
}