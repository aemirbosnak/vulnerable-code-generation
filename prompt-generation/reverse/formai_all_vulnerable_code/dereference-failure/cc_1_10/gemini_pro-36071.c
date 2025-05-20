//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: optimized
// Optimized C Graph representation and traversal example

#include <stdlib.h>
#include <stdio.h>

// Node structure
typedef struct node {
    int data;
    struct node *next;
} node;

// Graph structure
typedef struct graph {
    int num_vertices;
    node **adj_list;
} graph;

// Create a new graph
graph *create_graph(int num_vertices) {
    graph *g = (graph *) malloc(sizeof(graph));
    g->num_vertices = num_vertices;
    g->adj_list = (node **) malloc(num_vertices * sizeof(node *));
    for (int i = 0; i < num_vertices; i++) {
        g->adj_list[i] = NULL;
    }
    return g;
}

// Add an edge between two vertices
void add_edge(graph *g, int src, int dest) {
    node *new_node = (node *) malloc(sizeof(node));
    new_node->data = dest;
    new_node->next = g->adj_list[src];
    g->adj_list[src] = new_node;
}

// Print the graph
void print_graph(graph *g) {
    for (int i = 0; i < g->num_vertices; i++) {
        node *temp = g->adj_list[i];
        printf("Vertex %d: ", i);
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth-first search
void dfs(graph *g, int v, int *visited) {
    visited[v] = 1;
    printf("%d ", v);
    node *temp = g->adj_list[v];
    while (temp != NULL) {
        if (!visited[temp->data]) {
            dfs(g, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Breadth-first search
void bfs(graph *g, int v, int *visited) {
    int queue[g->num_vertices];
    int front = 0, rear = 0;
    visited[v] = 1;
    queue[rear++] = v;
    while (front != rear) {
        int curr = queue[front++];
        printf("%d ", curr);
        node *temp = g->adj_list[curr];
        while (temp != NULL) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

// Driver code
int main() {
    int num_vertices = 5;
    graph *g = create_graph(num_vertices);
    add_edge(g, 0, 1);
    add_edge(g, 0, 2);
    add_edge(g, 1, 2);
    add_edge(g, 1, 3);
    add_edge(g, 2, 4);

    print_graph(g);

    printf("Depth-first search: ");
    int visited[num_vertices];
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }
    dfs(g, 0, visited);
    printf("\n");

    printf("Breadth-first search: ");
    for (int i = 0; i < num_vertices; i++) {
        visited[i] = 0;
    }
    bfs(g, 0, visited);
    printf("\n");

    return 0;
}