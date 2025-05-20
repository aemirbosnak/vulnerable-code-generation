//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

// Graph representation using adjacency list
struct node {
    int data;
    struct node *next;
};

struct graph {
    int num_vertices;
    struct node **adj_lists;
};

// Create a new graph with the given number of vertices
struct graph *create_graph(int num_vertices) {
    struct graph *graph = (struct graph *)malloc(sizeof(struct graph));
    graph->num_vertices = num_vertices;
    graph->adj_lists = (struct node **)malloc(num_vertices * sizeof(struct node *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_lists[i] = NULL;
    }
    return graph;
}

// Add an edge between two vertices
void add_edge(struct graph *graph, int src, int dest) {
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->data = dest;
    new_node->next = graph->adj_lists[src];
    graph->adj_lists[src] = new_node;
}

// Print the adjacency list representation of the graph
void print_graph(struct graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        struct node *temp = graph->adj_lists[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Depth-first search
void dfs(struct graph *graph, int start, int *visited) {
    visited[start] = 1;
    printf("%d ", start);

    struct node *temp = graph->adj_lists[start];
    while (temp) {
        if (!visited[temp->data]) {
            dfs(graph, temp->data, visited);
        }
        temp = temp->next;
    }
}

// Breadth-first search
void bfs(struct graph *graph, int start, int *visited) {
    int queue[graph->num_vertices], front = 0, rear = 0;

    visited[start] = 1;
    queue[rear++] = start;

    while (front != rear) {
        int current = queue[front++];

        printf("%d ", current);

        struct node *temp = graph->adj_lists[current];
        while (temp) {
            if (!visited[temp->data]) {
                visited[temp->data] = 1;
                queue[rear++] = temp->data;
            }
            temp = temp->next;
        }
    }
}

int main() {
    // Create a graph with 5 vertices
    struct graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    // Print the adjacency list representation of the graph
    print_graph(graph);

    // Perform depth-first search starting from vertex 0
    int visited[graph->num_vertices];
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = 0;
    }
    dfs(graph, 0, visited);
    printf("\n");

    // Perform breadth-first search starting from vertex 0
    for (int i = 0; i < graph->num_vertices; i++) {
        visited[i] = 0;
    }
    bfs(graph, 0, visited);
    printf("\n");

    return 0;
}