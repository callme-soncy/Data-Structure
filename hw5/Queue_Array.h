
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <stdbool.h>
#define Q_SIZE 20
#define _CRT_DEFINE_NO_WARNINGS

typedef char Element;

typedef struct {
	Element* queue[Q_SIZE];
	int size;
	int front, rear;
}Queue;

Queue* CreateQueue(int size)
{
	Queue* pQueue = (Queue*)malloc(sizeof(Queue));
	if (pQueue == NULL)
		return NULL;
	for (int i = 0; i < size; i++)
	{
		pQueue->queue[i] = (Element*)malloc(Q_SIZE * sizeof(Element));
	}

	pQueue->size = size;
	pQueue->front = pQueue->rear = 0;
	return pQueue;
}
bool IsFullQueue(Queue* q)
{
	if ((q->rear + 1) % q->size == q->front)
		return 1;
	else return 0;
}
bool IsEmptyQueue(Queue* q)
{
	if (q->front == q->rear)
		return 1;
	else return 0;
}
void Enqueue(Queue* q, Element item[Q_SIZE])
{
	if (IsFullQueue(q))
	{
		printf("Queue is Full !");
	}
	else {
		q->rear = (q->rear + 1) % q->size;
		strcpy(q->queue[q->rear], item);
	}
}
void Dequeue(Queue* q)
{
	Element item[Q_SIZE];
	if (IsEmptyQueue(q))
	{
		printf("Queue is empty !");
	}
	else {
		q->front = (q->front + 1) % q->size;
		strcpy(item, q->queue[q->front]);
		printf("Customer dequeued : %s\n", item);
	}
}
void DestroyQueue(Queue* q)
{
	for (int i = 0; i < q->size ; i++) {
		free(q->queue[i]);
	}
	q->size = 0;
	q->front = q->rear = 0;
	free(q);
}
void printLQ(Queue* q) {
	int flag = 0;
	int i = 1;
	int temp = q->front;
	printf("The current status of Queue : (");
	while (temp < (q->rear)) {
		if (flag == 1) printf(", ");

		
		printf("%s%d", q->queue[temp + 1], i++);
		temp++;
		flag = 1;
	}
	printf(")\n\n");
}
