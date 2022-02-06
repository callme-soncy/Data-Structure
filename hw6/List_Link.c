/*#include "List_Link.h"

void printall(List*pList) {
	int n = 0, data = 0, ret = 0, flag = 0;
	
	printf("The current status of List : ");
	do {
		ret = traverseList(pList, n++, &data);
		
		if (ret)
		{
			if (flag ==1)
				printf(", ");
			printf("%d", data); 
			flag = 1;
		}
	} while (ret);
	printf("\n");
}

int main(void)
{
	int input; //choose
	List* pList = createList();
	ListNode* pLoc = NULL;
	ListNode* pPre = NULL;

	while (1) {
		int element = 0; //element
		printf("\nIn (0), Search (1), Out (2), Exit (3) : ");
		scanf("%d", &input);
		switch (input) {
		case 0:
			printf("In : ");
			scanf("%d", &element);
			addNodeList(pList, element);

			while (getchar() != '\n');
			printall(pList);
			break;
		case 1:
			printf("Search : ");
			scanf("%d", &element);
			if (_searchList(pList, &pPre, &pLoc, element)) {
				printf("My List has %d.\n", element);
			}
			else
				printf("My List does not have %d.\n", element);
			printall(pList);
			break;
		case 2:
			printf("Out : ");
			scanf("%d", &element);
			if ((_searchList(pList, &pPre, &pLoc, element))) {
				printf("%d was removed\n", element);
				_deleteList(pList, pPre, pLoc);
			}
			else 
				printf("My List does not have %d.\n", element);
			printall(pList);
			break;
		case 3:
			return 0;
		default:
			printf("choose number of 0~3\n");
			break;
		}
	}
	destroyList(pList);
}
*/