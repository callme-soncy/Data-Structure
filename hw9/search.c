#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include "list.h"
#define MAX 500
typedef int element;
int size = 0;
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
void binarySearch(element a[], int begin, int end, element key) {
	int middle;
	//j++;
	if (begin == end) {
		if (key == a[begin])printf("%d is found !\n\n", key);
		else printf("%d is not found ! \n\n", key);
		return;
	}
	middle = (begin + end) / 2;
	if (key == a[middle])printf("%d is found !\n\n", key);
	else if (key < a[middle] && (middle - 1 >= begin))
		binarySearch(a, begin, middle - 1, key);
	else if (key > a[middle] && (middle + 1 <= end))
		binarySearch(a, middle + 1, end, key);
	else printf("%d is not found ! \n\n", key);
}

int main() {
	element list[500] = { 0 };
	char name[20] = " ";
	int choose;
	int temp = 0;
	int i = 0;
	graphType* G1; //hash용 그래프 동적 할당
	G1 = (graphType*)malloc(sizeof(graphType));
	createGraph(G1);
	printf("Input file name : ");
	scanf("%s", name);
	ofp = fopen(name, "r");
	while (!feof(ofp)) {
		fscanf(ofp, "%d", &temp);
		AddEdge(G1, hash(temp), temp); //hash용 그래프 엣지
		list[i++] = temp;
	}
	size = i;
	printf("Target integer : ");
	scanf("%d", &temp);
	printf("\nChoose a searching method (Binary : 1, HEAP : 2) :");
	scanf("%d", &choose);

	switch (choose)
	{
	case 1:
		SelectionSort(list, size);
		binarySearch(list, 0, size - 1, temp);
		break;
	case 2:
		Findkey(G1, temp); //hashed search
		break;
	default:
		break;
	}
}