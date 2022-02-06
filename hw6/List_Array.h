#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <malloc.h>
#include <string.h>


typedef int Element;
int size = 0;

int* createList()
{
	int* pNewarray = (int*)malloc(sizeof(int)*(10));
	if (pNewarray == NULL)
		return NULL;
	*pNewarray = 1000;
	return pNewarray;
}

void _insertList(int* pList, int* pLoc, Element data)
{
	int* pPre = NULL;

	size++;

	for (pPre = pList + size; pPre != pLoc; pPre--) {
		*(pPre) = *(pPre-1);
	}
	*pLoc = data;
}
bool _searchList(int* pList, int** ppLoc, Element data)
{
	for (*ppLoc = pList; *ppLoc != NULL; *ppLoc = *ppLoc+1) {
		if (**ppLoc== data) // data was found
			return true;
		else if (**ppLoc > data)
			break;
	}
	return false;
}

void addNodeList(int* pList, Element data) //searchlist 써서 하는...
{
	int* pLoc = NULL;

	bool found = _searchList(pList, &pLoc, data);
	if (!found)
		_insertList(pList, pLoc, data);
}

void _deleteList(int* pList, int* pLoc)
{
	int* pPre = NULL;
	for (pPre = pLoc; pPre != pLoc + size - 1; pPre++) {
		*pPre = *(pPre+1);
	}
	size--;
}

bool traverseList(int* pList, int fromWhere, int* pDataOut)
{
	int* pos = pList + fromWhere; //fromwhere는 0부터 시작
	if (*pos != 1000) {
		*pDataOut = *pos;
		return true;
	}
	else { //문자열 끝 만나면
	*pDataOut = 0; 
	return false;
	}
}
void destroyList(int* pList)
{
	free(pList);
}
