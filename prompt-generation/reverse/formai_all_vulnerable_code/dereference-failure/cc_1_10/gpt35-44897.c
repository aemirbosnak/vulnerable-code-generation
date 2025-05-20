//FormAI DATASET v1.0 Category: Graph representation ; Style: cheerful
// Hello! Welcome to my happy C Graph representation example program!
// In this program, we'll create a graph using an adjacency list and
// display it using a cheerful ASCII art representation!

#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 20

// Define our node for the adjacency list
typedef struct node {
    int vertex;
    struct node* next;
} Node;

// Define our graph and adjacency list
typedef struct graph {
    int num_vertices;
    Node* adjacency_list[MAX_VERTICES];
} Graph;

// Helper function for adding edges to the adjacency list
void add_edge(Graph* graph, int src, int dest) {
    // Create a new node for the destination vertex
    Node* new_node = malloc(sizeof(Node));
    new_node->vertex = dest;
    new_node->next = NULL;

    // Insert the node at the beginning of the adjacency list for the source vertex
    new_node->next = graph->adjacency_list[src];
    graph->adjacency_list[src] = new_node;

    // Since this is an undirected graph, we need to add an edge in the other direction as well
    // Comment out this block if you want a directed graph instead
    new_node = malloc(sizeof(Node));
    new_node->vertex = src;
    new_node->next = NULL;

    // Insert the node at the beginning of the adjacency list for the destination vertex
    new_node->next = graph->adjacency_list[dest];
    graph->adjacency_list[dest] = new_node;
}

// Function to display our graph using some cheerful ASCII art
void display_graph(Graph* graph) {
    printf("   *    \n");
    printf("  / \\   \n");
    printf(" *---*  \n");
    printf("/ \\ / \\ \n");

    // Iterate through each vertex and its adjacency list
    for (int i = 0; i < graph->num_vertices; i++) {
        // Print the vertex number
        printf("%2d ", i);

        // Print all of the vertices connected to the current vertex
        Node* curr_node = graph->adjacency_list[i];
        while (curr_node != NULL) {
            printf("--> %2d", curr_node->vertex);
            curr_node = curr_node->next;
        }

        // Print a newline character at the end of each line
        printf("\n");
    }
}

// Main function to create and display our graph
int main() {
    // Create a new graph
    Graph* graph = malloc(sizeof(Graph));
    graph->num_vertices = 7;

    // Initialize each adjacency list to NULL
    for (int i = 0; i < graph->num_vertices; i++) {
        graph->adjacency_list[i] = NULL;
    }

    // Add the edges to the graph
    add_edge(graph, 0, 1);
    add_edge(graph, 0, 2);
    add_edge(graph, 0, 3);
    add_edge(graph, 1, 2);
    add_edge(graph, 3, 4);
    add_edge(graph, 4, 5);
    add_edge(graph, 5, 6);

    // Display the graph with some cheerful ASCII art!
    printf("Here is your happy graph:\n");
    display_graph(graph);

    // Free memory and exit program with happiness
    free(graph);
    printf("Goodbye and have a happy day!\n");
    return 0;
}