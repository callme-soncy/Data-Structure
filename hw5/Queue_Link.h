
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define Q_SIZE 20
#define _CRT_SECURE_NO_WARNINGS

typedef char Element;
typedef struct tQueueNode {
	Element data[Q_SIZE];
	struct tQueueNode* next;
}QueueNode;
typedef struct {
	int count;
	QueueNode* front, * rear;
}Queue;

Queue* CreateQueue(int size)
{
	//size is not used
	Queue* pNewQueue = (Queue*)malloc(sizeof(Queue));
	if (pNewQueue == NULL)
		return NULL;
	pNewQueue->count = 0;
	pNewQueue->front = pNewQueue->rear = NULL;
	return pNewQueue;
}
bool IsEmptyQueue(Queue* pQueue)
{
	if (pQueue->count == 0)
		return 1;
	else return 0;
}

void Enqueue(Queue* pQueue, Element item[])
{
	QueueNode* pNewNode = (QueueNode*)malloc(sizeof(QueueNode));
	if (pNewNode == NULL)
		return;
	strcpy(pNewNode->data, item);
	pNewNode->next = NULL;

	if (pQueue->count <= 0)
	{
		pQueue->front = pQueue->rear = pNewNode;
	}
	else
	{
		pQueue->rear->next = pNewNode;
		pQueue->rear = pNewNode;
	}
	pQueue->count++;
}
void Dequeue(Queue* pQueue)
{
	QueueNode* pFront = NULL;
	Element item[Q_SIZE];

	pFront = pQueue->front;
	strcpy(item, pFront->data);

	if (pQueue->count == 1) {
		pQueue->front = pQueue->rear = NULL;
	}
	else {
		pQueue->front = pFront->next;
	}
	free(pFront);
	pQueue->count--;
	printf("Customer dequeued : %s\n", item);
}
void DestroyQueue(Queue* pQueue)
{
	QueueNode* pCur = NULL, * pNext = NULL;
	for (pCur = pQueue->front; pCur != NULL; pCur = pNext) {
		pNext = pCur->next;
		free(pCur);
	}
	pQueue->count = 0;
	pQueue->front = pQueue->rear = NULL;
	free(pQueue);
}
void printLQ(Queue* pQueue)
{
	int flag = 0, i = 1;
	QueueNode* temp = pQueue->front;
	printf("The current status of Queue : (");
	while (temp) {
		if (flag == 1) printf(", ");
		printf("%s%d", temp->data,i++);
		temp = temp->next;
		flag = 1;
	}
	printf(")\n\n");
}