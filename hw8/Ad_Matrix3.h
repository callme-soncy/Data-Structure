//#define MAX_VERTEX 10
//int arr[MAX_VERTEX] = { 0 };
#define FALSE 0
#define TRUE 1

#define INF 1000

#define NumofBusstop 80

#define 중구수 10//118
#define 서구수 10//186
#define 북구수 10//576
#define 동구수 10//581
#define 달서구수 10//557
#define 달성군수 10//161
#define 남구수 10//161
#define 수성구수 10//419

#define 자치구수 8

#define 중구 01
#define 서구 02
#define 북구 03
#define 동구 04
#define 달서구 05
#define 달성군 06
#define 남구 07
#define 수성구 08

int alphatonum(char c) {
	switch (c)
	{
	case 'A': return 0;
	case 'B': return 1;
	case 'C': return 2;
	case 'D': return 3;
	case 'E': return 4;
	case 'F': return 5;
	case 'G': return 6;
	case 'H': return 7;
	case 'I': return 8;
	case 'J': return 9;
	default: printf("error\n");
		return 0;
	}
}

char numtoalpha(int d) {
	switch (d)
	{
	case 0: return 'A';
	case 1: return 'B';
	case 2: return 'C';
	case 3: return 'D';
	case 4: return 'E';
	case 5: return 'F';
	case 6: return 'G';
	case 7: return 'H';
	case 8: return 'I';
	case 9: return 'J';
	default: printf("error\n");
		return 'Z';
	}
}
typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	//int n;
	graphNode* adjList_H[자치구수];
	int visited[NumofBusstop]; // stack
	int visited1[NumofBusstop];//queue
	int adjMatrix[NumofBusstop][NumofBusstop];
}graphType;

void createGraph(graphType* g) {
	int i, j;
	//g->n = 0;
	for (i = 0; i < NumofBusstop; i++) {
		for (j = 0; j < NumofBusstop; j++)
			g->adjMatrix[i][j] = 1000;
	}
}
typedef int element;
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;
stackNode* top;

void InsertVertex(graphType* g, int v) {
	//arr[v] = 1; //g->n++;
}
void DeleteVertex(graphType* g, int v) {
	//arr[v] = 0;//정점개수 감소
}
int AddEdge(graphType* g, int u, int v, int d) { //간선 u-v
	//(g->adjMatrix[u][v]) = d;
	//(g->adjMatrix[v][u]) = d;
	return 0;
	//printf("u : %d, v : %d  d : %d",u, v, g->adjMatrix[u][v]);
}
void DeleteEdge(graphType* g, int u, int v) {
	g->adjMatrix[u][v] = 0;
}
void printgraph(graphType* g) {
	printf("\nThe graph is : \n");
	for (int i = 0; i < NumofBusstop; i++) {
		if (1) {
			printf("%c : ", i + 65);

			for (int j = 0; j < NumofBusstop; j++) {
				if (g->adjMatrix[i][j] != 1000)
					printf("%c (%d) ", j + 65, g->adjMatrix[i][j]);
			}
			printf("\n");
		}
	}
}
void printmatrix(graphType* g)
{
	for (int i = 0; i < NumofBusstop; i++)
	{
		for (int j = 0; j < NumofBusstop; j++)
		{
			printf("%d ", g->adjMatrix[i][j]);
		}
		printf("\n");
	}
}

void createGraph1(graphType* g) {
	int v;
	for (v = 0; v < 자치구수; v++) {
		g->visited[v] = FALSE;
		g->visited1[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}
void InsertVertex1(graphType* g, int v) {
	//arr[v] = 1;
}
void DeleteVertex1(graphType* g, int v) {
	//arr[v] = 0;//정점개수 감소
}
void AddEdge1(graphType* g, int u, int v) {
	graphNode* node;
	graphNode* node1;
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = NULL;
	int c = 0;
	if (g->adjList_H[u] == NULL) {
		g->adjList_H[u] = node;
	}
	else {
		for (node1 = g->adjList_H[u]; (node1->link) != NULL; node1 = node1->link) {
			c++;
		}
		(node1->link) = node;
	}
}