//FormAI DATASET v1.0 Category: Graph representation ; Style: surprised
#include <stdio.h>
#include <stdlib.h>

struct Edge {
    int src, dest;
};

struct Graph {
    int V, E;

    struct Edge* edge;
};

// function to create a graph with V vertices and E edges
struct Graph* createGraph(int V, int E) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = V;
    graph->E = E;

    graph->edge = (struct Edge*)malloc(graph->E * sizeof(struct Edge));

    // now the surprising part comes in!
    printf("Are you ready to see something amazing? Let's create a Graph!\n");

    for(int i = 0; i < E; i++) {
        printf("Enter source vertex and destination vertex for edge %d:", i+1);
        scanf("%d %d", &(graph->edge[i].src), &(graph->edge[i].dest));

        // and here it is, the most surprising part of the program!
        printf("\n");

        // add some drama and suspense

        printf("Oh my gosh! We just added edge [%d, %d] to the graph!\n", graph->edge[i].src, graph->edge[i].dest);
        printf("Did you see that? We're creating a GRAPH!!\n");
        printf("This is so unexpected and exciting!!\n");
        printf("Whew, I need to take a moment to catch my breath.\n\n");
    }

    printf("Alright, we've created a Graph with %d vertices and %d edges. \n", V, E);
    printf("Hope you had as much fun as I did creating this amazing Graph!!!\n");

    return graph;
}

int main() {
    printf("Hello world! Today we're going to create a graph in C. How cool is that?!\n");

    int V, E;

    printf("Enter the number of vertices: ");
    scanf("%d", &V);

    printf("Enter the number of edges: ");
    scanf("%d", &E);

    struct Graph* graph = createGraph(V, E);
 
    return 0;
}