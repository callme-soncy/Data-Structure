#include "List_Array.h"

void printall(int* pList) {
	int n = 0, data = 0, ret = 0, flag = 0;

	printf("The current status of List : ");
	do {
		ret = traverseList(pList, n++, &data);
		if (ret)
		{
			if (flag == 1)
				printf(", ");
			printf("%d", data);
			flag = 1;
		}
	} while (n != size);
	printf("\n");
}

int main(void)
{
	int input; //choose
	int* pList = createList(); //문자열 포인터 선언, 100칸 만듦
	int* pLoc = NULL;
	int count = 0; //배열 수 저장용

	while (1) {
		int element = 0; //to insert
		printf("\nIn (0), Search (1), Out (2), Exit (3) : ");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("In : ");
			scanf("%d", &element);
			addNodeList(pList, element);
			printall(pList);
			break;
		case 1:
			printf("Search : ");
			scanf("%d", &element);
			if (_searchList(pList, &pLoc, element)) {
				printf("My List has %d.\n", element);
			}
			else
				printf("My List does not have %d.\n", element);
			printall(pList);
			break;
		case 2:
			printf("out : ");
			scanf("%d", &element);
			if ((_searchList(pList, &pLoc, element))) {
				printf("%d was removed\n", element);
				_deleteList(pList, pLoc);
			}
			else
				printf("my list does not have %d.\n", element);
			printall(pList);
			break;
		case 3:
			break;
		default:
			printf("choose number of 0~3\n");
			break;
		}
	}
	destroyList(pList);
}
