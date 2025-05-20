//FormAI DATASET v1.0 Category: Graph representation ; Style: thoughtful
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define MAX 100 // maximum size of the graph

struct Edge {
    int src, dest, weight;
};

struct Graph {
    int V, E; // V is the number of vertices, E is the number of edges
    struct Edge* edge; // edge array to store edges
};

struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;
    graph->edge = (struct Edge*) malloc(sizeof(struct Edge) * E);
    return graph;
}

void printGraph(struct Graph* graph) {
    printf("Graph representation using adjacency matrix:\n");
    for(int i = 0; i < graph->V; i++) {
        for(int j = 0; j < graph->V; j++) {
            int found = 0;
            for(int k = 0; k < graph->E; k++) {
                if(graph->edge[k].src == i && graph->edge[k].dest == j) {
                    printf("%d ", graph->edge[k].weight);
                    found = 1;
                    break;
                }
            }
            if(!found) {
                printf("0 ");
            }
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL)); // seed the random number generator
    
    int V = 6; // number of vertices
    int E = 10; // number of edges

    struct Graph* graph = createGraph(V, E);
    
    // generate random edges with random weights
    for(int i = 0; i < E; i++) {
        graph->edge[i].src = rand() % V;
        graph->edge[i].dest = rand() % V;
        graph->edge[i].weight = rand() % 10 + 1;
    }
    
    // print the generated graph
    printGraph(graph);
    
    return 0;
}