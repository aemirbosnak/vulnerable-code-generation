//FormAI DATASET v1.0 Category: Graph representation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

/*
 * This program creates a graph representation using an adjacency list.
 * It takes user input to create edges between nodes, and then it prints
 * out the graph in adjacency list form.
 */

// Define maximum number of vertices
#define MAX_VERTICES 10

// Create node struct to hold vertex value and pointer to next node
struct node {
    int vertex;
    struct node* next;
};

// Create graph struct to hold array of vertices and pointer to adjacency lists
struct graph {
    int num_vertices;
    bool directed;
    struct node* adjLists[MAX_VERTICES];
};

// Function to create new node in adjacency list
struct node* createNode(int v) {
    struct node* newNode = malloc(sizeof(struct node));
    newNode->vertex = v;
    newNode->next = NULL;
    return newNode;
}

// Function to add edge to a graph
void addEdge(struct graph* g, int src, int dest) {
    // Check if vertices are within range
    if (src >= g->num_vertices || dest >= g->num_vertices) {
        printf("Invalid input. Please enter values within 0 and %d.\n", g->num_vertices-1);
        return;
    }
    // Add edge from src to dest
    struct node* newNode = createNode(dest);
    newNode->next = g->adjLists[src];
    g->adjLists[src] = newNode;
    // If graph is undirected, add edge from dest to src as well
    if (!g->directed) {
        newNode = createNode(src);
        newNode->next = g->adjLists[dest];
        g->adjLists[dest] = newNode;
    }
    printf("Edge from %d to %d added.\n", src, dest);
}

// Function to print adjacency list for a graph
void printGraph(struct graph* g) {
    printf("\n---GRAPH---\n");
    for (int i = 0; i < g->num_vertices; i++) {
        struct node* curr = g->adjLists[i];
        printf("Vertex %d: ", i);
        while (curr != NULL) {
            printf("%d -> ", curr->vertex);
            curr = curr->next;
        }
        printf("NULL\n");
    }
    printf("------------\n");
}

int main() {
    // Initialize graph with 5 vertices
    struct graph* g = malloc(sizeof(struct graph));
    g->num_vertices = 5;
    g->directed = true;
    // Initialize adjacency lists for each vertex
    for (int i = 0; i < g->num_vertices; i++) {
        g->adjLists[i] = NULL;
    }
    // Prompt user to add edges to graph
    int src, dest;
    printf("Welcome to the Graph Creator!\n");
    printf("Enter edges in the format 'src dest', or enter '-1 -1' to stop:\n");
    scanf("%d %d", &src, &dest);
    while (src != -1 && dest != -1) {
        addEdge(g, src, dest);
        scanf("%d %d", &src, &dest);
    }
    // Print final adjacency list
    printGraph(g);
    return 0;
}