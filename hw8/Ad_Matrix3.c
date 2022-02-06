#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>




#define Rnd(a,b) (rand()%(b+1-a))+a  //[a,b] 수

#include "Ad_Matrix3.h"

int visit[NumofBusstop] = { 0 };
int start, end;
int n, m;
int flag = 0;
int count(int arr[]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < NumofBusstop; i++) {
        if (arr[i] != 0)
            j++;
    }
    return j;
}

int choose(int distance[], int n, int found[], int v) {
    //printf("hi");
    int j = 0;
    int k = 0;
    int dist = 10000;


    for (j = 0; j < n - 1; j++) {
        if (dist > distance[j] && found[j] == FALSE) {
            dist = distance[j];
            k = j;
        }
        //printf("dist : %d ", dist);
    }

    return k;
}

void dijkstra(graphType* g, char ch)
{

    int v = ch - 65;
    int N = NumofBusstop;
    int i, u, w;
    int found[NumofBusstop] = { 0 };
    int distance[NumofBusstop] = { 0 };
    printf("Shortest path from %c : \n", ch);
    //printf("\n N : %d", N);
    for (i = 0; i < N; i++) {
        found[i] = FALSE;
        distance[i] = g->adjMatrix[v][i];
    }

    distance[v] = 0;
    //for (int x = 0; x < N; x++)
      //  printf("%d ", distance[x]);

    for (i = 0; i < N; i++) {
        printf("\n");
        if (distance[i] != 0) {
            u = choose(distance, N, found, v);
            //printf("\n shortest way vertex : %d\n", u);
            found[u] = TRUE;
            for (w = 0; w < N; w++) {
                if (!found[w] && distance[u] + g->adjMatrix[u][w] < distance[w])
                    distance[w] = distance[u] + g->adjMatrix[u][w];

            }
            for (int m = 0; m < N; m++) {
                if (distance[m] != 0)
                    printf("%c %c : %d \n", v + 65, 'A' + m, distance[m]);

            }
        }

    }
    printf("\n");
    for (int m = 0; m < N; m++) {
        if (distance[m] != 0)
            printf("%c %c : %d \n", v + 65, 'A' + m, distance[m]);

    }

}
int countedge(int T[][NumofBusstop]) {
    int i = 0;
    int j = 0;
    for (i = 0; i < NumofBusstop; i++) {
        if (T[0][i] != 0)
            j++;
    }
    return j;
}

/*void spanningtree(graphType* g, char ch)
{
    printf("Minimum spanning tree : \n");

    int u = 0;
    int v = 0;
    int m = 0;
    int l = 0;
    int n = count(arr);
    int T[2][MAX_VERTEX] = { 0 };
    int TV[MAX_VERTEX] = { 0 };
    int min = 1000;
    int origin = 0;
    TV[ch - 65] = 1;
    while (countedge(T) < n - 1) {
        min = 1000;
        origin = min;

        for (u = 0; u < n; u++) {
            if (TV[u] == 1) {
                for (v = 0; v < n; v++) {
                    if (TV[v] != 1) {
                        if (min > g->adjMatrix[u][v] && g->adjMatrix[u][v] != 0) {
                            min = g->adjMatrix[u][v];
                            m = u;
                            l = v;
                        }
                    }
                }
            }
        }
        if (origin != min) {
            TV[m] = 1;
            TV[l] = 1;
            printf("%c %c (%d)\n", m + 65, l + 65, min);
        }
        if (min == 1000)
            break;

        //T[m][l] = min;
    }
    //if (countedge(T) < n - 1)
      //  printf("No spanning tree\n");

}*/



int main()
{
    int ch = 0; // the starting point
    int ch1 = 0;
    graphType* G1;
    G1 = (graphType*)malloc(sizeof(graphType));
    createGraph(G1);

   
    //중구
    ch = 1;
    FILE* f = fopen("중구버스.txt", "r");
    if (f == NULL) {
        printf("파일열기 실패");
    }
    for (int i = 0; i < 중구수; i++) {
        fscanf(f, "%d", &ch1);
       // fseek(f, 3, SEEK_CUR);
        printf(" \nch : %d, ch1 : %d\n", ch, ch1);
        AddEdge1(G1, ch, ch1);
    }
    fclose(f);

    printgraph(G1);
    printf("\n");
    //spanningtree(G1, ch); printf("\n");
    //printmatrix(G1);

    dijkstra(G1, ch);


    return 0;
}