#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#define MAX 500
typedef int element;
int size;
int i = 0;
element sorted[MAX];
FILE* ofp;

void SelectionSort(int a[], int size) {
	int i, j, min;
	element temp;
	for (i = 0; i < size - 1; i++) {
		min = i;
		for (j = i + 1; j < size; j++) {
			if (a[j] < a[min]) min = j;
		}
		temp = a[i];
		a[i] = a[min];
		a[min] = temp;
	}
}
int partition(element a[], int begin, int end) {
	int pivot, L, R;
	element temp;
	L = begin;
	R = end;
	pivot = (int)((begin + end) / 2.0);
	while (L < R) {
		while ((a[L] < a[pivot]) && (L < R)) L++;
		while ((a[R] >= a[pivot]) && (L < R)) R--;
		if (L < R) {
			temp = a[L];
			a[L] = a[R];
			a[R] = temp;
			if (L == pivot)
				pivot = R;
		}
	}
	temp = a[pivot];
	a[pivot] = a[R];
	a[R] = temp;
	return R;	
}
void quickSort(element a[], int begin, int end) {
	int p;
	if (begin < end) {
		p = partition(a, begin, end);
		quickSort(a, begin, p - 1);
		quickSort(a, p + 1, end);
	}
}
void bubbleSort(element a[], int size) {
	int i, j;
	element temp;
	for (i = size - 1; i > 0; i--) {
		for (j = 0; j < i; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void insertionSort(int a[], int size) {
	int i, j, temp;
	for (i = 1; i < size; i++) {
		temp = a[i];
		j = i;
		while ((j > 0) && (a[j - 1] > temp)) {
			a[j] = a[j - 1];
			j = j - 1;
		}
		a[j] = temp;
	}
}
void merge(element a[], int m, int middle, int n) {
	int i, j, k, t;
	i = m;
	j = middle + 1;
	k = m;

	while (i <= middle && j <= n) {
		if (a[i] <= a[j]) {
			sorted[k] = a[i];
			i++;
		}
		else {
			sorted[k] = a[j];
			j++;
		}
		k++;
	}
	if (i > middle) for (t = j; t <= n; t++, k++) sorted[k] = a[t];
	else 
		for (t = i; t <= middle; t++, k++)sorted[k] = a[t];

	for (t = m; t <= n; t++) a[t] = sorted[t];
}
void mergeSort(element a[], int m, int n) {
	int middle;
	if (m < n) {
		middle = (m + n) / 2;
		mergeSort(a, m, middle);
		mergeSort(a, middle + 1, n);
		merge(a, m, middle, n);
	}
}
int main() {
	element list[500] = {0};
	char name[20] = " ";
	int choose;
	size = 0;
	int i = 0;
	int temp;
	printf("Input file name : ");
	scanf("%s", name);
	ofp = fopen(name, "r");
	while(!feof(ofp)) {
		fscanf(ofp, "%d", &temp);
		list[i++] = temp;
	}
	size = i;
	//printf("size : %d\n\n", size);
	printf("\nChoose a sortind method to use (Selection : 0, Insertion : 1, Bubble : 2, Quick : 3, Merge : 4 ) : ");
	scanf("%d", &choose);
	switch (choose)
	{
	case 0:
		SelectionSort(list, size);
		break;
	case 1:
		insertionSort(list, size);
		break;
	case 2:
		bubbleSort(list, size);
		break;
	case 3:
		quickSort(list, 0, size - 1);
		break;
	case 4:
		mergeSort(list, 0, size - 1);
		break;
	default:
		break;
	}
	printf("\nThe numbers sorted : ");
	for (int t = 0; t < size; t++) {
		if (t == 0)
			printf("%d", list[t]);
		else
			printf(", %d", list[t]);
	}
	fclose(ofp);
	getchar();
}