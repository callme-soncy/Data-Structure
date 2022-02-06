#include "Binary_Tree.h"
#include<math.h>
int main(void)
{
	char st[30];
	int line = 0; //배열길이
	int c = 0; //어디를 저장할까

	printf("Input a string : ");
	scanf("%[^\n]s", st);

	line = strlen(st);
	TreeNode** address = (TreeNode**)malloc(30 * sizeof(TreeNode*)); //주소저장용 어레이
	TreeNode* a = CreateTree(NULL, st[c], NULL);
	address[c] = a;//1번주소 저장함

	c++; //c는 1이 된다 

	for (int i = 1; c < line; i++) //i는 level
	{
		while (c + 1 < pow(2, i + 1) && c < line)
		{
			
			address[c] = CreateTree(NULL, st[c], NULL);
			if ((c + 1) % 2 == 0) //해결한 c가 짝수
				address[(c-1) / 2]->left = address[c];
			else//c가 홀수
				address[(c-1) / 2]->right = address[c];

			c++; //c = 2번까지 했다

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