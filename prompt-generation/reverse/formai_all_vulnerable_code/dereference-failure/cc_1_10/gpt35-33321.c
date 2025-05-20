//FormAI DATASET v1.0 Category: Graph representation ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAX_VERTICES 10

// Vertex Structure
typedef struct _vertex {
    int data;
    pthread_mutex_t lock;
} Vertex;

// Graph Structure
typedef struct _graph {
    int n_vertices;
    Vertex* vertices[MAX_VERTICES];
    int edges[MAX_VERTICES][MAX_VERTICES];
    pthread_mutex_t lock;
} Graph;

// Function to create a new vertex
Vertex* create_vertex(int data) {
    Vertex* vertex = (Vertex*)malloc(sizeof(Vertex));
    vertex->data = data;
    pthread_mutex_init(&vertex->lock, NULL);
    return vertex;
}

// Function to create a new graph with n vertices
Graph* create_graph(int n) {
    Graph* graph = (Graph*)malloc(sizeof(Graph));
    graph->n_vertices = n;
    for (int i = 0; i < n; i++) {
        graph->vertices[i] = create_vertex(i);
        for (int j = 0; j < n; j++) {
            graph->edges[i][j] = 0;
        }
    }
    pthread_mutex_init(&graph->lock, NULL);
    return graph;
}

// Function to add an edge between vertices v1 and v2
void add_edge(Graph* graph, int v1, int v2) {
    pthread_mutex_lock(&graph->lock);
    graph->edges[v1][v2] = 1;
    graph->edges[v2][v1] = 1;
    pthread_mutex_unlock(&graph->lock);
}

// Function to remove an edge between vertices v1 and v2
void remove_edge(Graph* graph, int v1, int v2) {
    pthread_mutex_lock(&graph->lock);
    graph->edges[v1][v2] = 0;
    graph->edges[v2][v1] = 0;
    pthread_mutex_unlock(&graph->lock);
}

// Function to print the graph
void print_graph(Graph* graph) {
    pthread_mutex_lock(&graph->lock);
    printf("Graph:\n");
    for (int i = 0; i < graph->n_vertices; i++) {
        printf("%d -> ", i);
        for (int j = 0; j < graph->n_vertices; j++) {
            if (graph->edges[i][j] == 1) {
                printf("%d ", j);
            }
        }
        printf("\n");
    }
    pthread_mutex_unlock(&graph->lock);
}

// Main function
int main() {
    Graph* graph = create_graph(5);
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 2, 3);
    add_edge(graph, 3, 4);
    print_graph(graph);
    remove_edge(graph, 1, 2);
    remove_edge(graph, 0, 2);
    print_graph(graph);
    return 0;
}