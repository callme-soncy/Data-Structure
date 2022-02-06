#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define COUNT 20


int main()
{
	int i, j, k = 0;
	int temp = 0;
	int num[20];
	int plus[20];
	int twenty = 0; //input is 20
	int ascend = 0; // ascending = 0

	twenty = 0;
	printf("Input : \n-");
	scanf("%d, %d, %d, %d, %d, %d, %d, %d, %d, %d\n%d, %d, %d, %d, %d, %d, %d, %d, %d, %d", &num[0], &num[1], &num[2], &num[3], &num[4], &num[5], &num[6], &num[7], &num[8], &num[9], &num[10], &num[11], &num[12], &num[13], &num[14], &num[15], &num[16], &num[17], &num[18], &num[19]);

	for (i = 0; i < 20; i++) {
		if (num[i] < -1000 || num[i] > 1000) twenty = 1;
	}
	for (i = 0; i < 9; i++) {
		if (num[i] > num[i + 1]) ascend++;
	}
	for (i = 10; i < 19; i++) {
		if (num[i] > num[i + 1]) ascend++;
	}

	if (twenty == 1) {
		printf("You should input 20 numbers in total");
		exit(0);
	}
	else if (ascend != 0) {
		printf("The input numbers are not in ascending order\n");
		exit(0);
	}
	else {
		for (k = 0; k < COUNT - 1; k++)
		{
			for (j = 0; j < COUNT - 1 - k; j++)
			{
				if (num[j] > num[j + 1])
				{
					temp = num[j];
					num[j] = num[j + 1];
					num[j + 1] = temp;
				}
			}
		} //오름차순

		j = 0;
		plus[0] = num[0];
		for (i = 1; i < 20; i++)
		{
			if (plus[j] < num[i])
			{
				j++;
				plus[j] = num[i];
			}
		} //중복제거

		printf("Output : \n-");

		for (i = 0; i < j + 1; i++) {
			if (i == j)
				printf("%d", plus[j]);
			else
				printf("%d, ", plus[i]);
		}
		return 0;
	}
}

