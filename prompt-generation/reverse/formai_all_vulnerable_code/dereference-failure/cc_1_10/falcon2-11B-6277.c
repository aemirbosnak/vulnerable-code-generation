//Falcon2-11B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define INF 99999

struct Node {
    int x;
    int y;
    int g;
    int h;
    int f;
};

struct Edge {
    int weight;
    int g;
    int h;
};

struct Graph {
    int numVertices;
    struct Node **vertices;
};

bool isValid(int x, int y) {
    // Check if the position is within the boundaries of the grid
    return x >= 0 && x < 10 && y >= 0 && y < 10;
}

void initializeGraph(struct Graph *graph, int numVertices) {
    // Initialize the graph with empty vertices
    graph->numVertices = numVertices;
    graph->vertices = malloc(numVertices * sizeof(struct Node*));
    for (int i = 0; i < numVertices; i++) {
        graph->vertices[i] = malloc(sizeof(struct Node));
        graph->vertices[i]->x = -1;
        graph->vertices[i]->y = -1;
        graph->vertices[i]->g = INF;
        graph->vertices[i]->h = INF;
        graph->vertices[i]->f = INF;
    }
}

void addEdge(struct Graph *graph, int start, int end, int weight) {
    // Add an edge between two vertices
    struct Edge edge = {weight, 0, 0};
    graph->vertices[start]->h = graph->vertices[end]->h = edge.h;
    graph->vertices[start]->g = graph->vertices[end]->g = graph->vertices[start]->g + edge.weight;
    graph->vertices[end]->f = graph->vertices[start]->f = graph->vertices[end]->f + edge.weight;
}

void printGraph(struct Graph *graph) {
    // Print the graph in a happy style
    printf(">-----\n");
    for (int i = 0; i < graph->numVertices; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < graph->numVertices; j++) {
            if (graph->vertices[i]->f == INF) {
                printf(" ");
            } else if (j == graph->vertices[i]->f) {
                printf("* ");
            } else {
                printf(" ");
            }
        }
        printf(">-----\n");
    }
}

int main() {
    struct Graph graph;
    initializeGraph(&graph, 10);
    addEdge(&graph, 0, 3, 4);
    addEdge(&graph, 0, 1, 2);
    addEdge(&graph, 3, 4, 1);
    addEdge(&graph, 4, 2, 1);
    printGraph(&graph);
    return 0;
}