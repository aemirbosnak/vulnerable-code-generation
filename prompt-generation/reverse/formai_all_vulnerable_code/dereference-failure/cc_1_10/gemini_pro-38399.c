//GEMINI-pro DATASET v1.0 Category: Graph representation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
typedef struct Node {
    int data;
    struct Node *next;
} Node;

// Structure to represent a graph
typedef struct Graph {
    int num_vertices;
    struct Node **adj_list;
} Graph;

// Function to create a new graph
Graph *create_graph(int num_vertices) {
    Graph *graph = (Graph *)malloc(sizeof(Graph));
    graph->num_vertices = num_vertices;

    // Create an adjacency list for the graph
    graph->adj_list = (Node **)malloc(num_vertices * sizeof(Node *));
    for (int i = 0; i < num_vertices; i++) {
        graph->adj_list[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void add_edge(Graph *graph, int src, int dest) {
    // Create a new node for the source vertex
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = dest;
    new_node->next = NULL;

    // Add the new node to the adjacency list for the source vertex
    new_node->next = graph->adj_list[src];
    graph->adj_list[src] = new_node;
}

// Function to print the graph
void print_graph(Graph *graph) {
    for (int i = 0; i < graph->num_vertices; i++) {
        Node *temp = graph->adj_list[i];
        printf("Vertex %d: ", i);
        while (temp) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

// Function to perform a depth-first search on the graph
void dfs(Graph *graph, int start) {
    // Create a stack to store the vertices to be visited
    Node *stack = NULL;

    // Push the start vertex onto the stack
    Node *new_node = (Node *)malloc(sizeof(Node));
    new_node->data = start;
    new_node->next = NULL;
    stack = new_node;

    // While the stack is not empty
    while (stack) {
        // Pop the top vertex from the stack
        int current = stack->data;
        stack = stack->next;

        // Print the current vertex
        printf("%d ", current);

        // Push the unvisited neighbors of the current vertex onto the stack
        Node *temp = graph->adj_list[current];
        while (temp) {
            if (!is_visited(temp->data, stack)) {
                Node *new_node = (Node *)malloc(sizeof(Node));
                new_node->data = temp->data;
                new_node->next = NULL;
                new_node->next = stack;
                stack = new_node;
            }
            temp = temp->next;
        }
    }
}

// Function to check if a vertex has been visited
int is_visited(int vertex, Node *stack) {
    while (stack) {
        if (stack->data == vertex) {
            return 1;
        }
        stack = stack->next;
    }
    return 0;
}

// Main function
int main() {
    // Create a graph with 5 vertices
    Graph *graph = create_graph(5);

    // Add edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 1, 2);
    add_edge(graph, 1, 3);
    add_edge(graph, 2, 4);

    // Print the graph
    print_graph(graph);

    // Perform a depth-first search on the graph
    dfs(graph, 0);

    return 0;
}