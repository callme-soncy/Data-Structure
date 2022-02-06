#include "Queue_Array.h"

int main(void)
{
	int c; //choosing
	char input[20] = " ";
	Queue* pQ = CreateQueue(10);
	while (1)
	{
		printf("In (0),out (1),exit (2) : ");
		scanf("%d", &c); //c ют╥б

		switch (c)
		{
		case 0:
			printf("Customer : ");
			while (getchar() != '\n');
			fgets(input, sizeof(input), stdin);
			input[strlen(input) - 1] = '\0';
			Enqueue(pQ, input);
			printLQ(pQ);
			break;
		case 1:
			if (IsEmptyQueue(pQ))
				printf("Queue is empty ! \n\n");
			else {
				Dequeue(pQ);
				printLQ(pQ);
			}
			break;
		case 2:
			exit(1);
			break;
		default:
			printf("choose number from 1 to 3\n");
			break;
		}
	}
	DestroyQueue(pQ);
}