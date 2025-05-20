//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 100

typedef struct {
    int data;
    int visited;
} vertex;

typedef struct {
    int vertices;
    vertex vertex_list[MAX_VERTICES];
    int adj_matrix[MAX_VERTICES][MAX_VERTICES];
} graph;

graph* create_graph(int vertices) {
    graph* g = (graph*)malloc(sizeof(graph));
    g->vertices = vertices;
    for (int i = 0; i < vertices; i++) {
        g->vertex_list[i].data = i;
        g->vertex_list[i].visited = 0;
        for (int j = 0; j < vertices; j++) {
            g->adj_matrix[i][j] = 0;
        }
    }
    return g;
}

void add_edge(graph* g, int from, int to, int weight) {
    g->adj_matrix[from][to] = weight;
}

void print_graph(graph* g) {
    for (int i = 0; i < g->vertices; i++) {
        printf("%d: ", g->vertex_list[i].data);
        for (int j = 0; j < g->vertices; j++) {
            if (g->adj_matrix[i][j] > 0) {
                printf("%d(%d), ", j, g->adj_matrix[i][j]);
            }
        }
        printf("\n");
    }
}

void dfs(graph* g, int start) {
    g->vertex_list[start].visited = 1;
    printf("%d ", start);
    for (int i = 0; i < g->vertices; i++) {
        if (g->adj_matrix[start][i] > 0 && g->vertex_list[i].visited == 0) {
            dfs(g, i);
        }
    }
}

void bfs(graph* g, int start) {
    int queue[MAX_VERTICES];
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    g->vertex_list[start].visited = 1;
    while (front != rear) {
        int current = queue[front++];
        printf("%d ", current);
        for (int i = 0; i < g->vertices; i++) {
            if (g->adj_matrix[current][i] > 0 && g->vertex_list[i].visited == 0) {
                queue[rear++] = i;
                g->vertex_list[i].visited = 1;
            }
        }
    }
}

int main() {
    graph* g = create_graph(6);
    add_edge(g, 0, 1, 1);
    add_edge(g, 0, 2, 1);
    add_edge(g, 1, 2, 1);
    add_edge(g, 1, 3, 1);
    add_edge(g, 2, 4, 1);
    add_edge(g, 3, 4, 1);
    add_edge(g, 4, 5, 1);
    add_edge(g, 5, 0, 1);
    print_graph(g);
    printf("\nDFS: ");
    dfs(g, 0);
    printf("\nBFS: ");
    bfs(g, 0);
    printf("\n");
    return 0;
}