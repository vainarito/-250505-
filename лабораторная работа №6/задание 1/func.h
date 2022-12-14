#pragma once       
#include <stdio.h>             
#include <stdlib.h>			   
#include <Windows.h>           

int checkInputInt();
void mainMenu();
int menu();
int* inputArray(int);
int inputValueOfArray();
int* allocateMemory(int*, int);
void showArray(int*, int, int);

double bubbleSort(int*, int, double);
double mergeSort(int*, int, double);
double badMergeSort(int*, int, double);
void freee(int*, int*, int*);
