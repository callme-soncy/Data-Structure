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

typedef struct graphNode {
	int vertex;
	struct graphNode* link;
}graphNode;

typedef struct graphType {
	graphNode* adjList_H[MAX_VERTEX];
	int visited[MAX_VERTEX];
	int visited1[MAX_VERTEX];
}graphType;

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
		v = pop(); //0
		w = g->adjList_H[v];//adjlist[0]주소
		while (w) {
			if (!g->visited[w->vertex]) {// visited 안햇으면
				if (isEmpty()) push(v); //비어잇으니까 push
				push(w->vertex);
				g->visited[w->vertex] = TRUE;
				printf(" %c", w->vertex + 65);////////////
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
	//printf("old data : %d", old->data);
	int item;
	if (QisEmpty(LQ)) {
		 return 0;
	}
	else {
		//printf("im here");
		item = old->data;

		//printf("item = %d", item);

		LQ->front = LQ->front->link;
		//printf("%d", LQ->front);
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
	//if (Q->front == NULL)
	//	printf(" front is NULL \n");
	g->visited1[v] = TRUE;
	printf(" %c", v + 65);
	enQueue(Q, v);
	while (!QisEmpty(Q)) {
		//printf("1\n");
		//printf("old data : %d", Q->front->data);
		v = deQueue(Q);
		//printf("2\n");
		for(w = g->adjList_H[v]; w; w=w->link)
			if (!g->visited1[w->vertex]) {
				g->visited1[w->vertex] = TRUE;
				printf(" %c", (w->vertex) + 65);
				enQueue(Q, w->vertex);
			}
	}
}
void createGraph(graphType* g) {
	int v;
	for (v = 0; v < MAX_VERTEX; v++) {
		g->visited[v] = FALSE;
		g->visited1[v] = FALSE;
		g->adjList_H[v] = NULL;
	}
}
void InsertVertex(graphType* g, int v) {
	arr[v] = 1;
}
void DeleteVertex(graphType* g, int v) {
	arr[v] = 0;//정점개수 감소
}
void AddEdge(graphType* g, int u, int v) {
	graphNode* node;
	node = (graphNode*)malloc(sizeof(graphNode));
	node->vertex = v;
	node->link = g->adjList_H[u];
	g->adjList_H[u] = node;
}
void DeleteEdge(graphType* g, int u, int v) {
	graphNode* p = NULL;
	graphNode* q= NULL;
	p = g->adjList_H[u];
	while ((p->vertex) != v) {
		q = p; //p 한단계전 포인터
		p = p->link; //지우려는애
	}
	if (p == NULL)
	{
		(q->link) = NULL;
		free(p);
		return;
	}
	else {
		(q->link) = (p->link);
		p->link = NULL;
		free(p);
		return;
	}
}
void printgraph(graphType* g) {
	int i;
	graphNode* p = NULL;
	printf("\nThe graph is :\n");
	for (i = 0; i < MAX_VERTEX; i++) {
		if (arr[i] != 0) {
			printf("%c : ", i + 65);
			p = g->adjList_H[i];
			while (p) {
				printf("%c ", p->vertex + 65);
				p = p->link;
			}
		}printf("\n");
	}
}
