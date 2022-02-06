#define MAX_VERTEX 10
int arr[MAX_VERTEX] = { 0 };
#define FALSE 0
#define TRUE 1

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	graphNode* adjList_H[MAX_VERTEX];
}graphType;

typedef int element;
//������ linked list ��ҵ�

int hash(int key) {
	return key % 10;
} //10���� ���� ���� �������� linked list �� �����ϰ���

void createGraph(graphType* g) {
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
	}
} //hash�� �׷��� ����
void AddEdge(graphType* g, int u, int v) { //u : �Է°��� 10���� ���� ������, v : �Է°�
	graphNode* node;
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node; //����� vertex ���� �Է°� �ְ� linkedlist�� ����
}
/*
void printgraph(graphType* g) {
	int i;
	graphNode* p = NULL;
	printf("\nThe graph is :\n");
	for (i = 0; i < 10; i++) {
		if (1) {
			printf("%d : ", i);
			p = g->adjList_H[i];
			while (p) {
				printf("%c ", p->vertex);
				p = p->link;
			}
		}printf("\n");
	}
}
*/
int Findkey(graphType* g, int key) { //�Է°��� �ִ��� ã�� �Լ�
	graphNode* p = NULL; //������
	p = g->adjList_H[hash(key)]; //�����Ͱ� linkedlist[�Է°��� 10���� ���� ������] �� ��
	int state = 0; //ã�� ���� ã�Ҵ��� ����, 1�̸� ã��, 0�̸� ã�� ����
	while (p) { //p�� null�� �ƴ� ����
		if (p->vertex == key) { //p�� vertex���� ã�� ���� ��ġ�� ���
			state = 1; break; //ã�� �������� ����
		}
		p = p->link;//���� link�� �Űܰ��� �˻�
	}
	if(state == 1) printf("%d is found !", key);//ã�� ���
	else printf("%d is not found !", key);//ã�� ���� ���
	return 1;
}