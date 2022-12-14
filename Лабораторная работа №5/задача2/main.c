#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include "Hader.h"
int main() {
    srand(time(NULL));
    int lines, m = 1, katiy;
    int** array=NULL;
    int* massiv = NULL;
    katiy = enter_k();
    lines = size();
    deleteK(lines, katiy, array, massiv);
    return 0;
}
