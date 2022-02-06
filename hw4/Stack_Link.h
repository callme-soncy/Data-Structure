#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>
#include<ctype.h>
#define _CRT_SECURE_NO_WARNIGS

typedef char Element;

typedef struct tStackNode {
	Element data[10];
	struct tStackNode* next;
}StackNode;

typedef struct {
	int count;
	StackNode* top;
}Stack;

Stack* CreateStack(int size)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	pStack->count = 0;
	pStack->top = NULL;
	return pStack;
}

void Push(Stack* pStack, Element item[])
{
	StackNode* pNewNode = (StackNode*)malloc(sizeof(StackNode));
	if (pNewNode == NULL)
		return; //full
	
	strcpy(pNewNode->data,item); //수정할 부분 data[count] = character 로 변환해서 입력

	pNewNode->next = pStack->top;
	pStack->top = pNewNode;
	pStack->count++;
}
Element Pop(Stack* pStack)
{
	if (pStack->top == NULL)
		return 0; //empty
	else {
		Element item[10];
		strcpy(item, pStack->top->data);
		
		StackNode* pOldTop = pStack->top;
		pStack->top = pOldTop->next;
		free(pOldTop);
		pStack->count--;
		return item[10];
	}
}
Element Top(Stack* pStack)  //+++++++++++
{
	if (pStack->top < 0) // empty
		return 0;
	return pStack->top->data[10];
}
Element IsEmptyStack(Stack* pStack)
{
	if (pStack->top == NULL)
		return 1; //empty
	else return 0;
}
int CountStackItem(Stack* pStack)
{
	return pStack->count;
}
void ClearStack(Stack* pStack)
{
	while (!IsEmptyStack(pStack))
		Pop(pStack);
}
void DestroyStack(Stack* pStack)
{
	while (!IsEmptyStack(pStack))
		Pop(pStack);
	free(pStack);
}
void printStack(Stack* pStack)
{
	StackNode* temp = pStack->top;
	int tempcount = pStack->count;
	printf("STACK Stat : ");
	while (tempcount > 0) {
		printf("%s ", pStack->top->data);
		temp = temp->next;
		tempcount--;
	}
	printf("(%d)", pStack-> count);
}