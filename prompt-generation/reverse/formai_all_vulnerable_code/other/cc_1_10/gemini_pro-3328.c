//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

// Graph representation using adjacency list
typedef struct node {
    int data;
    struct node *next;
} node;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node **adj_list;
} graph;

// Create a new graph with n vertices
graph *create_graph(int n) {
    graph *g = malloc(sizeof(graph));
    assert(g != NULL);
    g->num_vertices = n;
    g->num_edges = 0;
    g->adj_list = malloc(n * sizeof(node *));
    assert(g->adj_list != NULL);
    for (int i = 0; i < n; i++) {
        g->adj_list[i] = NULL;
    }
    return g;
}

// Add an edge between vertices u and v
void add_edge(graph *g, int u, int v) {
    assert(u >= 0 && u < g->num_vertices);
    assert(v >= 0 && v < g->num_vertices);
    node *new_node = malloc(sizeof(node));
    assert(new_node != NULL);
    new_node->data = v;
    new_node->next = g->adj_list[u];
    g->adj_list[u] = new_node;
    g->num_edges++;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        printf("%d: ", i);
        node *curr = g->adj_list[i];
        while (curr != NULL) {
            printf("%d ", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Depth-first search
void dfs(graph *g, int start, int *visited) {
    visited[start] = 1;
    printf("%d ", start);
    node *curr = g->adj_list[start];
    while (curr != NULL) {
        if (!visited[curr->data]) {
            dfs(g, curr->data, visited);
        }
        curr = curr->next;
    }
}

// Breadth-first search
void bfs(graph *g, int start, int *visited) {
    int *queue = malloc(g->num_vertices * sizeof(int));
    assert(queue != NULL);
    int front = 0;
    int rear = 0;
    queue[rear++] = start;
    visited[start] = 1;
    while (front != rear) {
        int u = queue[front++];
        printf("%d ", u);
        node *curr = g->adj_list[u];
        while (curr != NULL) {
            if (!visited[curr->data]) {
                queue[rear++] = curr->data;
                visited[curr->data] = 1;
            }
            curr = curr->next;
        }
    }
    free(queue);
}

// Test the graph representation
int main() {
    graph *g = create_graph(5);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);
    print_graph(g);
    int *visited = malloc(g->num_vertices * sizeof(int));
    assert(visited != NULL);
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = 0;
    }
    dfs(g, 0, visited);
    printf("\n");
    for (int i = 0; i < g->num_vertices; i++) {
        visited[i] = 0;
    }
    bfs(g, 0, visited);
    printf("\n");
    return 0;
}