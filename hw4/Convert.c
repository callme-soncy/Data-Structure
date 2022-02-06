/*#define _CRT_SECURE_NO_WARNIGS
typedef int Element;
#include "Stack_Link.h"

int main(void)
{
	Stack* pStack = CreateStack(1000);
	printf("Enter an integer: ");
	int element; // 입력수
	int remain; //나머지
	scanf("%d", &element);
	int a; //몫
	a = element / 2;
	remain = element % 2;
	Push(pStack, remain);
	do {
		remain = a % 2;
		a = a / 2;
		Push(pStack, remain);
	} while (a != 0);
	printf("The binary number of %d: ", element);
	while (!IsEmptyStack(pStack))
		printf("%d", Pop(pStack));
	return 0;
	DestroyStack(pStack);
}
*/