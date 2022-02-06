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
//위까지 linked list 요소들

int hash(int key) {
	return key % 10;
} //10으로 나눈 값을 기준으로 linked list 로 연결하겠음

void createGraph(graphType* g) {
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->adjList_H[v] = NULL;
	}
} //hash용 그래프 생성
void AddEdge(graphType* g, int u, int v) { //u : 입력값을 10으로 나눈 나머지, v : 입력값
	graphNode* node;
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node; //노드의 vertex 값에 입력값 넣고 linkedlist에 연결
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
int Findkey(graphType* g, int key) { //입력값이 있는지 찾는 함수
	graphNode* p = NULL; //포인터
	p = g->adjList_H[hash(key)]; //포인터가 linkedlist[입력값을 10으로 나눈 나머지] 로 감
	int state = 0; //찾는 값을 찾았는지 여부, 1이면 찾음, 0이면 찾지 못함
	while (p) { //p가 null이 아닌 동안
		if (p->vertex == key) { //p의 vertex값과 찾는 값이 일치할 경우
			state = 1; break; //찾은 상태임을 저장
		}
		p = p->link;//다음 link로 옮겨가며 검색
	}
	if(state == 1) printf("%d is found !", key);//찾은 경우
	else printf("%d is not found !", key);//찾지 못한 경우
	return 1;
}