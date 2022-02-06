#include "Binary_Tree.h"
#include<math.h>
int main(void)
{
	char st[30];
	int line = 0; //�迭����
	int c = 0; //��� �����ұ�

	printf("Input a string : ");
	scanf("%[^\n]s", st);

	line = strlen(st);
	TreeNode** address = (TreeNode**)malloc(30 * sizeof(TreeNode*)); //�ּ������ ���
	TreeNode* a = CreateTree(NULL, st[c], NULL);
	address[c] = a;//1���ּ� ������

	c++; //c�� 1�� �ȴ� 

	for (int i = 1; c < line; i++) //i�� level
	{
		while (c + 1 < pow(2, i + 1) && c < line)
		{
			
			address[c] = CreateTree(NULL, st[c], NULL);
			if ((c + 1) % 2 == 0) //�ذ��� c�� ¦��
				address[(c-1) / 2]->left = address[c];
			else//c�� Ȧ��
				address[(c-1) / 2]->right = address[c];

			c++; //c = 2������ �ߴ�

		}
	}

	printf("\nPre-order : ");
	Preorder(a);
	printf("\n\nIn-order : ");
	Inorder(a);
	printf("\n\nPost-order : ");
	Postorder(a);
	printf("\n\nBreadth First : ");
	LevelOrder(a);

	DestroyTree(a);
	
	free(address);
	return 0;
}