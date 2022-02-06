/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
typedef int Element;

typedef struct tListNode {
	Element data;
	struct tListNode* next;
}ListNode;

typedef struct {
	int count;
	ListNode* pos;
	ListNode* head; 
}List;

List* createList()
{
	List* pNewList = (List*)malloc(sizeof(List));
	if (pNewList == NULL)
		return NULL;
	pNewList->count = 0;
	pNewList->head = NULL;
	pNewList->pos = NULL;
	return pNewList;
}

void _insertList(List* pList, ListNode* pPre, Element data)
{
	ListNode* pNewNode = (ListNode*)malloc(sizeof(ListNode));
	pNewNode->data = data;
	if (pPre == NULL) {
		pNewNode->next = pList->head;
		pList->head = pNewNode;
	}
	else {
		pNewNode->next = pPre->next;
		pPre->next = pNewNode;
	}
	pList->count++;
}
bool _searchList(List* pList, ListNode** ppPre, ListNode** ppLoc, Element data)
{
	for (*ppPre = NULL, *ppLoc = pList->head; *ppLoc != NULL;
		*ppPre = *ppLoc, *ppLoc = (*ppLoc)->next) {
		if ((*ppLoc)->data == data) // data was found
			return true;
		else if ((*ppLoc)->data > data)
			break;
	}
	return false;
}

void addNodeList(List* pList, Element data) //searchlist 써서 하는...
{
	ListNode* pPre = NULL, * pLoc = NULL;
	bool found = _searchList(pList, &pPre, &pLoc, data);
	if (!found)
		_insertList(pList, pPre, data);
}
void _deleteList(List* pList, ListNode* pPre, ListNode* pLoc)
{
	if (pPre == NULL)
	{
		pList->head = pLoc->next; //pLoc : 지우려는애, pPre는 그 앞에 애
	}
	else {
		pPre->next = pLoc->next;
	}
		
	free(pLoc);
	pList->count--;
}
bool traverseList(List* pList, int fromWhere, Element* pDataOut)
{
	if (fromWhere == 0 || pList->pos == NULL){
		pList->pos = pList->head;
	}
	else {
	pList->pos = pList->pos->next;
	}
	if (pList->pos != NULL) {
	*pDataOut = pList->pos->data;
	return true;
	}
	else {
	*pDataOut = 0;
	return false;
	}
}
void destroyList(List* pList)
{
	ListNode* pDel = NULL, * pNext = NULL;
	for (pDel = pList->head; pDel != NULL; pDel = pNext) {
		pNext = pDel->next;
		free(pDel);
	}
	free(pList);
}
*/