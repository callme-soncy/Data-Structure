#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
char firstname[50];
int i;

int main()
{
	struct {
		char name[50]; // 이름
		int age;
		char sex;
		char* namep; // 성을 가리키는 포인터
	}student;

	while(1){
		printf("\n\n\nProvide your personal information:");
		printf("\n\n? Name : ");
		fgets(student.name, sizeof(student.name), stdin);
		student.name[strlen(student.name) - 1] = '\0';
		if (strcmp(student.name, "stop") == 0)
			exit(1);
		for (i = 0; student.name[i] != ' '; i++)
		{
			firstname[i] = student.name[i];
		}
		firstname[i] = '\0';

		student.namep = strchr(student.name, ' ') + 1;

		printf("\n\n? Age : ");
		scanf("%d%*c", &student.age);
		printf("\n\n? Sex (M/F) : ");
		scanf("%c%*c", &student.sex);

		printf("\n\n\nYour name is %s %s, your age is %d, your sex is %c.\n", student.namep, firstname, student.age, student.sex);
	} 

	return 0;
}



