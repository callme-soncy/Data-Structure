#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef char Element;

typedef struct tTreeNode {
	Element data;
	struct tTreeNode* left, * right;
} TreeNode;
#include "Tree_Queue.h"

TreeNode* CreateTree(TreeNode* left, Element item, TreeNode* right)
{
	TreeNode* pNewNode = (TreeNode*)malloc(sizeof(TreeNode));
	if (pNewNode == NULL)
		return NULL;
	pNewNode->data=item; // assuming Element is char
	pNewNode->left = left;
	pNewNode->right = right;
	return pNewNode;
}
void Preorder(TreeNode* root)
{
	if (root == NULL)
		return;
	printf("%c", root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(TreeNode* root)
{
	if (root == NULL)
		return;
	Inorder(root->left);
	printf("%c", root->data);
	Inorder(root->right);
}
void Postorder(TreeNode* root)
{
	if (root == NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%c", root->data);
}
void DestroyTree(TreeNode* root)
{
	if (root == NULL)
		return;
	if (root->left)
		DestroyTree(root->left);
	if (root->right)
		DestroyTree(root->right);
	free(root);
}
TreeNode* CopyTree(TreeNode* root)
{
	if (root == NULL)
		return NULL;
	return CreateTree(CopyTree(root->left), root->data,
		CopyTree(root->right));
}
void LevelOrder(TreeNode* root) {
	Queue* queue = NULL;
	if (root == NULL)
		return;
	queue = CreateQueue(10);
	while (root) {
		printf("%c", root->data);
		if (root->left)
			Enqueue(queue, root->left);
		if (root->right)
			Enqueue(queue, root->right);
		if (!IsEmptyQueue(queue))
			root = Dequeue(queue);
		else
			root = NULL;
	}
	DestroyQueue(queue);
}