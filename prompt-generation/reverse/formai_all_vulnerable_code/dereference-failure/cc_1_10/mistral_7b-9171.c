//MISTRAL-7B DATASET v1.0 Category: Graph Coloring Problem ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 100
#define MAX_COLOR 10

typedef struct Edge {
    int from, to;
} Edge;

typedef struct Graph {
    int vertices;
    int color[MAX_VERTICES];
    Edge *adjacencies;
} Graph;

Graph createGraph(int vertices) {
    Graph g;
    g.vertices = vertices;
    g.adjacencies = (Edge *)calloc(vertices * vertices, sizeof(Edge));
    return g;
}

void addEdge(Graph *g, int from, int to) {
    g->adjacencies[from * g->vertices + to].from = from;
    g->adjacencies[from * g->vertices + to].to = to;
    g->adjacencies[to * g->vertices + from].from = to;
    g->adjacencies[to * g->vertices + from].to = from;
}

int canColorVertex(Graph *g, int vertex, int color) {
    for (int i = 0; i < g->vertices; i++) {
        if (g->adjacencies[vertex * g->vertices + i].from == vertex && g->color[i] == color) {
            return 0;
        }
    }
    return 1;
}

int graphColoring(Graph *g, int m) {
    for (int i = 0; i < g->vertices; i++) {
        for (int j = 0; j < m; j++) {
            if (canColorVertex(g, i, j)) {
                g->color[i] = j;
                if (i + 1 == g->vertices || !graphColoring(g, m)) {
                    g->color[i] = -1;
                    break;
                }
            }
        }
        if (g->color[i] == -1) {
            return -1;
        }
    }
    return 1;
}

void printGraphColoring(Graph g) {
    printf("Graph Coloring Solution for %d vertices:\n", g.vertices);
    for (int i = 0; i < g.vertices; i++) {
        printf("Vertex %d: Color %d\n", i, g.color[i]);
    }
}

int main() {
    int n, m;
    printf("Enter the number of vertices: ");
    scanf("%d", &n);
    Graph g = createGraph(n);

    printf("Enter the number of colors: ");
    scanf("%d", &m);

    printf("Enter the number of edges and their endpoints:\n");
    int edges;
    scanf("%d", &edges);

    for (int i = 0; i < edges; i++) {
        int from, to;
        scanf("%d %d", &from, &to);
        addEdge(&g, from, to);
    }

    int result = graphColoring(&g, m);

    if (result == -1) {
        printf("Sherlock Holmes: It seems impossible to color the graph with %d colors.\n", m);
    } else {
        printGraphColoring(g);
    }

    free(g.adjacencies);
    return 0;
}