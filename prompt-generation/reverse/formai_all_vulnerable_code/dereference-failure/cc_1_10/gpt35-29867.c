//FormAI DATASET v1.0 Category: Graph representation ; Style: sophisticated
#include<stdio.h>
#include<stdlib.h>

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E;
    struct Edge* edge;
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*)malloc(E * sizeof(struct Edge));
    return graph;
}

void printGraph(struct Graph* graph) {
    printf("\nGraph Representation:\n");
    for (int i = 0; i < graph->E; i++) {
        printf("Edge %d : Source - %d, Destination - %d, Weight - %d \n", i+1, graph->edge[i].src, graph->edge[i].dest, graph->edge[i].weight);
    }
}

int main() {
    int V = 5, E = 7;
    struct Graph* graph = createGraph(V, E);
    
    //inserting edges
    graph->edge[0].src = 0;
    graph->edge[0].dest = 1;
    graph->edge[0].weight = 1;

    graph->edge[1].src = 0;
    graph->edge[1].dest = 2;
    graph->edge[1].weight = 6;

    graph->edge[2].src = 1;
    graph->edge[2].dest = 2;
    graph->edge[2].weight = 3;

    graph->edge[3].src = 1;
    graph->edge[3].dest = 3;
    graph->edge[3].weight = 7;

    graph->edge[4].src = 1;
    graph->edge[4].dest = 4;
    graph->edge[4].weight = 5;

    graph->edge[5].src = 2;
    graph->edge[5].dest = 4;
    graph->edge[5].weight = 4;

    graph->edge[6].src = 3;
    graph->edge[6].dest = 4;
    graph->edge[6].weight = 2;

    printGraph(graph);
    return 0;
}