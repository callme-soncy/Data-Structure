#define MAX_VERTEX 10
int arr[MAX_VERTEX] = { 0 };
#define FALSE 0
#define TRUE 1
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
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX]; // stack
	int visited1[MAX_VERTEX];//queue
	int adjMatrix[MAX_VERTEX][MAX_VERTEX];
}graphType;

void createGraph(graphType* g) {
	int i, j;
	for (i = 0; i < MAX_VERTEX; i++) {
		for (j = 0; j < MAX_VERTEX; j++)
			g->adjMatrix[i][j] = 0;
	}
}
typedef int element;
typedef struct stackNode {
	int data;
	struct stackNode* link;
}stackNode;
stackNode* top;
int isEmpty() {
	if (top == NULL) return 1;
	else return 0;
}
void push(int item) {
	stackNode* temp = (stackNode*)malloc(sizeof(stackNode));
	temp->data = item;
	temp->link = top;
	top = temp;
}
int pop() {
	int item;
	stackNode* temp = top;
	if (isEmpty()) {
		printf("\n stack is empty!\n");
		return 0;
	}
	else {
		item = temp->data;
		top = temp->link;
		free(temp);
		return item;
	}
}
void DFS(graphType* g, int v) {
	graphNode* w;
	top = NULL;
	push(v);
	g->visited[v] = TRUE;
	printf("%c", v + 65);

	while (!isEmpty()) {
		v = pop(); 
		w = g->adjList_H[v];
		while (w) {
			if (!g->visited[w->vertex]) {
				if (isEmpty()) push(v); 
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);
				v = w->vertex;
				w = g->adjList_H[v];
			}
			else w = w->link;
		}
	}
}
typedef struct QNode {
	int data;
	struct QNode* link;
}QNode;
typedef struct {
	QNode* front, * rear;
}LQueueType;

LQueueType* createLinkedQueue() {
	LQueueType* LQ;
	LQ = (LQueueType*)malloc(sizeof(LQueueType));
	LQ->front = NULL;
	LQ->rear = NULL;
	return LQ;
}
int QisEmpty(LQueueType* LQ) {
	if (LQ->front == NULL) {
		//printf("empty!");
		return 1;
	}
	else return 0;
}
void enQueue(LQueueType* LQ, int item) {
	QNode* newNode = (QNode*)malloc(sizeof(QNode));
	newNode->data = item;
	newNode->link = NULL;
	if (LQ->front == NULL) {
		LQ->front = newNode;
		LQ->rear = newNode;
	}
	else {
		LQ->rear->link = newNode;
		LQ->rear = newNode;
	}
}
int deQueue(LQueueType* LQ) {
	QNode* old = LQ->front;
	int item;
	if (QisEmpty(LQ)) {
		return 0;
	}
	else {
		item = old->data;
		LQ->front = LQ->front->link;
		if (LQ->front == NULL)
			LQ->rear = NULL;
		free(old);
		return item;
	}
}
void BFS(graphType* g, int v) {
	graphNode* w;
	LQueueType* Q;
	Q = createLinkedQueue();
	g->visited1[v] = TRUE;
	printf(" %c", v + 65);
	enQueue(Q, v);
	while (!QisEmpty(Q)) {
		v = deQueue(Q);
		for (w = g->adjList_H[v]; w; w = w->link)
			if (!g->visited1[w->vertex]) {
				g->visited1[w->vertex] = TRUE;
				printf(" %c", (w->vertex) + 65);
				enQueue(Q, w->vertex);
			}
	}
}
void InsertVertex(graphType* g, int v) {
	arr[v] = 1;
}
void DeleteVertex(graphType* g, int v) {
	arr[v] = 0;//정점개수 감소
}
int AddEdge(graphType* g, int u, int v) { //간선 u-v
	if (arr[v] == 0) {
		printf("\n 그래프에 없는 정점입니다! ");
		return 0;
	}
	for(int i = 0; i < MAX_VERTEX; i++) {
		if (g->adjMatrix[u][i] == 3)
		{
			g->adjMatrix[u][v] = 4;
			return 0;
		}
	}
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (g->adjMatrix[u][i] == 2) {
			g->adjMatrix[u][v] = 3;
			return 0;
		}
	}
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (g->adjMatrix[u][i] == 1) {
			g->adjMatrix[u][v] = 2;
			return 0;
		}
	}
	g->adjMatrix[u][v] = 1;
	return 0;
	
}
void DeleteEdge(graphType* g, int u, int v) {
	g->adjMatrix[u][v] = 0;
}
void printgraph(graphType* g) {
	printf("\nThe graph is : \n");
	for (int i = 0; i < MAX_VERTEX; i++) {
		if (arr[i] != 0) {
			printf("%c : ", numtoalpha(i));
			for (int j = 0; j < MAX_VERTEX; j++) {
				if (g->adjMatrix[i][j] == 1)
					printf("%c ", numtoalpha(j));
			}
			for (int j = 0; j < MAX_VERTEX; j++) {
				if (g->adjMatrix[i][j] == 2)
					printf("%c ", numtoalpha(j));
			}
			for (int j = 0; j < MAX_VERTEX; j++) {
				if (g->adjMatrix[i][j] == 3)
					printf("%c ", numtoalpha(j));
			}
			for (int j = 0; j < MAX_VERTEX; j++) {
				if (g->adjMatrix[i][j] == 4)
					printf("%c ", numtoalpha(j));
			}
			printf("\n");
		}
	}
}
void createGraph1(graphType* g) {
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;
		g->visited1[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}
void InsertVertex1(graphType* g, int v) {
	arr[v] = 1;
}
void DeleteVertex1(graphType* g, int v) {
	arr[v] = 0;//정점개수 감소
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