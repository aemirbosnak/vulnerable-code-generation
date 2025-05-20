//GEMINI-pro DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int data;
    struct node *next;
} node_t;

typedef struct graph {
    int num_vertices;
    int num_edges;
    node_t **adj_list;
} graph_t;

graph_t *create_graph(int num_vertices) {
    graph_t *graph = malloc(sizeof(graph_t));
    graph->num_vertices = num_vertices;
    graph->num_edges = 0;
    graph->adj_list = malloc(sizeof(node_t *) * num_vertices);
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }
    return graph;
}

void add_edge(graph_t *graph, int src, int dst) {
    node_t *new_node = malloc(sizeof(node_t));
    new_node->data = dst;
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
    graph->num_edges++;
}

void print_graph(graph_t *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        node_t *curr = graph->adj_list[i];
        printf("%d:", i);
        while (curr != NULL) {
            printf(" %d", curr->data);
            curr = curr->next;
        }
        printf("\n");
    }
}

void dfs(graph_t *graph, int start, bool *visited) {
    visited[start] = true;
    printf("%d ", start);
    node_t *curr = graph->adj_list[start];
    while (curr != NULL) {
        if (!visited[curr->data]) {
            dfs(graph, curr->data, visited);
        }
        curr = curr->next;
    }
}

void bfs(graph_t *graph, int start, bool *visited) {
    int *queue = malloc(sizeof(int) * graph->num_vertices);
    int front = 0;
    int rear = 0;
    visited[start] = true;
    queue[rear++] = start;
    while (front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        node_t *node = graph->adj_list[curr];
        while (node != NULL) {
            if (!visited[node->data]) {
                visited[node->data] = true;
                queue[rear++] = node->data;
            }
            node = node->next;
        }
    }
}

int main() {
    graph_t *graph = create_graph(6);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);
    add_edge(graph, 2, 5);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    print_graph(graph);
    bool *visited = malloc(sizeof(bool) * graph->num_vertices);
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = false;
    }
    printf("DFS: ");
    dfs(graph, 0, visited);
    printf("\n");
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = false;
    }
    printf("BFS: ");
    bfs(graph, 0, visited);
    printf("\n");
    return 0;
}