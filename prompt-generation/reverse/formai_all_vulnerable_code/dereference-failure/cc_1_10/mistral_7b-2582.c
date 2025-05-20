//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

#define VEXNUM 10

typedef struct {
    int data;
    int *adj;
} VertexType;

typedef struct {
    VertexType vexs[VEXNUM];
    int vexnum, edgenum;
} MysticGraph;

void CreateMysticGraph(MysticGraph *graph) {
    int i, j;

    graph->vexnum = VEXNUM;
    graph->edgenum = 0;

    for (i = 0; i < VEXNUM; i++) {
        graph->vexs[i].data = i;
        graph->vexs[i].adj = (int *)malloc(VEXNUM * sizeof(int));

        // Self-loop
        graph->vexs[i].adj[i] = 1;

        for (j = 0; j < VEXNUM; j++) {
            if (i != j) {
                // Exactly one edge between any two distinct vertices
                graph->vexs[i].adj[j] = 1;
                graph->vexs[j].adj[i] = 0; // Directed graph
                graph->edgenum++;
            }
        }
    }
}

void PrintMysticGraph(MysticGraph graph) {
    int i, j;

    printf("MysticGraph:\n");
    printf("Vertex\tAdjacencyList\n");

    for (i = 0; i < graph.vexnum; i++) {
        printf("%d\t", graph.vexs[i].data);
        for (j = 0; j < graph.vexnum; j++) {
            printf("%d ", graph.vexs[i].adj[j]);
        }
        printf("\n");
    }
}

int main() {
    MysticGraph mysticGraph;

    CreateMysticGraph(&mysticGraph);
    PrintMysticGraph(mysticGraph);

    return 0;
}