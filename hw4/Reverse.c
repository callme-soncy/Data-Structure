/*#define _CRT_SECURE_NO_WARNIGS
typedef int Element;
#include "Stack_Link.h"


int main(void)
{
	int done = false;
	Stack* pStack = CreateStack(1000);

	while (!done) {
		int element = 0;
		int retVal = 0;
		printf("Enter a number : <Ctrl+d> to stop: ");
		retVal = scanf("%d", &element);
		if (retVal != 1) //int of EOF is -1
			break;
		Push(pStack, element);
	}
	printf("The List of numbers reversed:\n");
	while (!IsEmptyStack(pStack)) // IsEmpty 작성해야함
		printf("%d\n", Pop(pStack));

	DestroyStack(pStack);
	pStack = NULL;
	return 0;
}
*/