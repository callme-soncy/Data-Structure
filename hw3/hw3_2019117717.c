#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct {
	char name[50]; // 성
	int age;	//나이
	int math;	//수학
	int eng;	//영어
	int history;//역사
}student;

void menu();
void sortmenu();
void sortmenusub(int a, student* stst, int n);
void bar();
void nodata() {
	printf("\nResult : There is no data to be sorted. Program terminates."); bar(); exit(0);
};
void negative() {
	printf("Result : The age cannot be a negative number. Program terminates."); bar(); exit(0);
}


int main()
{

	int n = 1;
	int numberstu = 0; //No에 표시
	int firsttime = 0; //프로그램이 계속 이어지는지 확인
	int sel;		//menu select
	int sortsel;	//sortmenu select
	char fname[100];	//name of file
	FILE* fp = NULL;

	student* stst = (student*)malloc(sizeof(student) * n);
	do {
		if (firsttime == 0)bar();
		firsttime = 1;

		menu();	//menu screen
		scanf("%d", &sel);	//sel 저장
		switch (sel) {
		case 1:
		{
			printf("File name : ");
			scanf("%s", fname);

			fp = fopen(fname, "r");

			char c;
			while ((c = fgetc(fp)) != EOF)
				if (c == '\n')n++;//몇줄인지파악
			stst = (student*)malloc(sizeof(student) * n);
			fclose(fp);
			fp = fopen(fname, "r");
			int once = 0;
			for (int i = 0; i < n; i++) {
				numberstu++;
				fscanf(fp, "%s %d %d %d %d", (stst + i)->name, &(stst + i)->age, &(stst + i)->math, &(stst + i)->eng, &(stst + i)->history);
				if ((stst + i)->age <= 0) {
					negative(); bar(); exit(0);
				}
				else if (((stst + i)->math) <= 0 || ((stst + i)->math) >= 100 || ((stst + i)->eng) <= 0 || ((stst + i)->eng) >= 100 || ((stst + i)->history) <= 0 || ((stst + i)->history) >= 100)
					printf("점수오류가 있습니다\n");
				if (once == 0) {
					printf("NO\tName\tAge\tMath\tEnglish\tHistory\n");
				}once++;
				printf("%d\t%s\t%d\t%d\t%d\t%d\n", numberstu, (stst + i)->name, (stst + i)->age, (stst + i)->math, (stst + i)->eng, (stst + i)->history);
			}
		}
		break;
		case 2:
		{
			if (fp == NULL) nodata();
			else
			{
				sortmenu();
				scanf("%d", &sortsel);
				sortmenusub(sortsel, stst, n);
			}
		}
		break;
		case 3:
		{
			bar(); fclose(fp);
			exit(0);
		}
		break;
		default:
			printf("***1~3 사이의 숫자를 입력하시오***");
		}
	} while (sel >= 1 && sel <= 3);

}

void menu() {
	printf("\n1) Insert\n2) Sort\n3) Quit\nSelect a menu : ");
}
void sortmenu() {
	printf("1) Name\n2) Age\n3) Math\n4) English\n5) History\nChoose the field to sort by : ");
}
void bar() {
	printf("\n============================");
}
void sortmenusub(int a, student* stst, int n) {
	int numberstu = 0;
	student tmp; //임시저장
	int i, j; //버블솔트용


	do {
		switch (a)
		{
		case 1:
		{
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if (strcmp((stst[i].name), (stst[j].name))>0)
					{
						tmp = (stst[j]);
						(stst[j]) = (stst[i]);
						(stst[i]) = tmp;
					}
				}
			}
			printf("NO\tName\tAge\tMath\tEnglish\tHistory\n");
			for (i = 0; i < n; i++) {
				numberstu++;
				printf("%d\t%s\t%d\t%d\t%d\t%d\n", numberstu, stst[i].name, stst[i].age, stst[i].math, stst[i].eng, stst[i].history);
			}
		}
		break;
		case 2:
		{
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if ((stst[i].age) >= (stst[j].age))
					{
						tmp = (stst[j]);
						(stst[j]) = (stst[i]);
						(stst[i]) = tmp;
					}
				}
			}
			printf("NO\tAge\tName\tMath\tEnglish\tHistory\n");
			for (i = 0; i < n; i++) {
				numberstu++;
				printf("%d\t%d\t%s\t%d\t%d\t%d\n", numberstu, stst[i].age, stst[i].name, stst[i].math, stst[i].eng, stst[i].history);
			}
		}
		break;
		case 3:
		{
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if ((stst[i].math) > (stst[j].math))
					{
						tmp = (stst[j]);
						(stst[j]) = (stst[i]);
						(stst[i]) = tmp;
					}
				}
			}
			printf("NO\tMath\tName\tAge\tEnglish\tHistory\n");
			for (i = 0; i < n; i++) {
				numberstu++;
				printf("%d\t%d\t%s\t%d\t%d\t%d\n", numberstu, stst[i].math, stst[i].name, stst[i].age, stst[i].eng, stst[i].history);
			}
		}
		break;
		case 4:
		{
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if ((stst[i].eng) > (stst[j].eng))
					{
						tmp = (stst[j]);
						(stst[j]) = (stst[i]);
						(stst[i]) = tmp;
					}
				}
			}
			printf("NO\tEnglish\tName\tAge\tMath\tHistory\n");
			for (i = 0; i < n; i++) {
				numberstu++;
				printf("%d\t%d\t%s\t%d\t%d\t%d\n", numberstu, stst[i].eng, stst[i].name, stst[i].age, stst[i].math, stst[i].history);
			}
		}
		break;
		case 5:
		{
			for (i = 0; i < n - 1; i++)
			{
				for (j = i + 1; j < n; j++)
				{
					if ((stst[i].history) >= (stst[j].history))
					{
						tmp = (stst[j]);
						(stst[j]) = (stst[i]);
						(stst[i]) = tmp;
					}
				}
			}
			printf("NO\tHistory\tName\tAge\tMath\tEnglish\n");
			for (i = 0; i < n; i++) {
				numberstu++;
				printf("%d\t%d\t%s\t%d\t%d\t%d\n", numberstu, stst[i].history, stst[i].name, stst[i].age, stst[i].math, stst[i].eng);
			}
		}
		break;
		default:
			printf("***1~5 사이의 숫자를 입력하시오***");
			break;
		}
	} while (a < 1 || a>5);
}