//Falcon2-11B DATASET v1.0 Category: Graph Coloring Problem ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

#define MAX_NODES 6
#define MAX_EDGES 7

typedef struct {
    int v;
    int w;
} Edge;

typedef struct {
    int color;
    bool visited;
    int count;
} Node;

typedef struct {
    Node* nodes;
    Edge* edges;
} Graph;

void initializeGraph(Graph* graph) {
    graph->nodes = (Node*)malloc(sizeof(Node) * MAX_NODES);
    graph->edges = (Edge*)malloc(sizeof(Edge) * MAX_EDGES);

    // Initialize nodes
    for (int i = 0; i < MAX_NODES; i++) {
        graph->nodes[i].color = -1;
        graph->nodes[i].visited = false;
        graph->nodes[i].count = 0;
    }

    // Initialize edges
    for (int i = 0; i < MAX_EDGES; i++) {
        graph->edges[i].v = i % MAX_NODES;
        graph->edges[i].w = (i + 1) % MAX_NODES;
    }
}

void printGraph(Graph* graph) {
    printf("Nodes:\n");
    for (int i = 0; i < MAX_NODES; i++) {
        if (graph->nodes[i].visited) {
            printf("Node %d (color: %d, count: %d)\n", i, graph->nodes[i].color, graph->nodes[i].count);
        }
    }
    printf("Edges:\n");
    for (int i = 0; i < MAX_EDGES; i++) {
        printf("%d -> %d\n", graph->edges[i].v, graph->edges[i].w);
    }
}

int minimumColoring(Graph* graph) {
    int colorCount = 0;

    // DFS to color nodes
    for (int i = 0; i < MAX_NODES; i++) {
        if (!graph->nodes[i].visited) {
            colorCount = dfsColor(graph, i, colorCount);
        }
    }

    return colorCount;
}

int dfsColor(Graph* graph, int node, int colorCount) {
    graph->nodes[node].color = colorCount % MAX_NODES;
    colorCount++;

    for (int i = 0; i < MAX_NODES; i++) {
        if (graph->edges[i].v == node &&!graph->nodes[i].visited) {
            graph->nodes[i].visited = true;
            graph->nodes[i].count++;

            if (graph->nodes[i].color!= -1) {
                graph->nodes[i].color = -1;
                dfsColor(graph, i, colorCount);
            }
        }
    }

    return colorCount;
}

int main() {
    Graph graph;
    initializeGraph(&graph);

    printf("Minimum number of colors: %d\n", minimumColoring(&graph));
    printGraph(&graph);

    free(graph.nodes);
    free(graph.edges);

    return 0;
}