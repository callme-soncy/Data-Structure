/*
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#include <math.h>
#include<ctype.h>

typedef struct {
	Element *stack;
	int size;
	int top;
}Stack;

Stack* CreateStack(int size)
{
	Stack* pStack = (Stack*)malloc(sizeof(Stack));
	if (pStack == NULL)
		return NULL;
	(pStack->stack) = (Element*)malloc(size * sizeof(Element));
	if (pStack->stack == NULL) {
		free(pStack);
		return NULL;
	}
	pStack -> size = size;
	pStack -> top = -1;

	return pStack;
}

void Push(Stack* pStack, Element item)
{
	if (pStack -> top == pStack -> size - 1)
		return;  // check if stack is full
	(pStack -> stack[++pStack -> top]) = item;
}
Element Pop(Stack* pStack)
{
	if (pStack -> top < 0) // check if stack is empty
		return 0;
	return pStack -> stack[pStack -> top--];
}
Element Top(Stack* pStack)
{
	if (pStack -> top < 0) // empty
		return 0;
	return pStack -> stack[pStack->top];
}
void DestroyStack(Stack* pStack)
{
	if (pStack -> size > 0)
		free(pStack -> stack);
	free(pStack);
}
bool IsFullStack(Stack *pStack)
{
	if (pStack->top == pStack->size - 1) return 1;  // check if stack is full
	else return 0;
}
bool IsEmptyStack(Stack* pStack)
{
	if (pStack -> top < 0) return 1; //empty
	else return 0;
}
int CountStackItem(Stack* pStack)
{
	return pStack -> size;
}
void ClearStack(Stack* pStack)
{
	while (!IsEmptyStack(pStack)) 
		Pop(pStack);
}
*/