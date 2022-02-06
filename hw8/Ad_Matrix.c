/*
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#include "Ad_Matrix.h"
int main()
{
    char ch;
    char ch1;
    char ch2;
    char file[10];
    int line = 0;
    char c;

    graphType* G1;
    G1 = (graphType*)malloc(sizeof(graphType));
    createGraph(G1);
    graphType* G2;
    G2 = (graphType*)malloc(sizeof(graphType));
    createGraph1(G2);
    

    printf("File name of a graph : ");
    scanf("%s", file);
    FILE* f = fopen(file, "r");
    while ((c = fgetc(f)) != EOF)
        if (c == '\n') line++;
    fclose(f);
    FILE* fp = fopen(file, "r");
    if (fp == NULL) {
        printf("파일열기 실패");
    }

    fscanf(fp, "%c", &ch);
    InsertVertex(G1, alphatonum(ch));

    for (int i = 0; i < line; i++) {
        fseek(fp, 2, SEEK_CUR);
        fscanf(fp, "%c %c", &ch1, &ch2);
        InsertVertex(G1, alphatonum(ch1));
        InsertVertex(G1, alphatonum(ch2));
        AddEdge(G1, alphatonum(ch1), alphatonum(ch2));
    }
    fclose(fp);

    printgraph(G1);
    printf("\n");
   
    FILE* fp1 = fopen(file, "r");
    if (fp1 == NULL) {
        printf("파일열기 실패");
    }
    fscanf(fp1, "%c", &ch);
    InsertVertex1(G2, alphatonum(ch));
    for (int i = 0; i < line; i++) {
        fseek(fp1, 2, SEEK_CUR);
        fscanf(fp1, "%c %c", &ch1, &ch2);
        InsertVertex1(G2, alphatonum(ch1));
        InsertVertex1(G2, alphatonum(ch2));
        AddEdge1(G2, alphatonum(ch1), alphatonum(ch2));
    }
    printf("Depth First Traversal : ");
    DFS(G2, ch - 65);
    printf("\nBreath First Traversal : ");
    BFS(G2, ch - 65);
    printf("\n");
    return 0;
}
*/