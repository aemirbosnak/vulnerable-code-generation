//MISTRAL-7B DATASET v1.0 Category: Graph representation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 100

// Structure for creating a node in the graph
typedef struct Node {
    int data;
    int visited;
    struct Node* next;
} Node;

// Function to create a new node in the graph
Node* newNode(int data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->visited = 0;
    new_node->next = NULL;
    return new_node;
}

// Function to add an edge in the graph
void addEdge(Node** graph, int src, int dest) {
    Node* new_node = newNode(dest);
    Node* temp = *graph;

    // Traverse through the list to find the position to insert the new node
    while (temp && temp->data != src) {
        temp = temp->next;
    }

    // Insert the new node at the position found in the previous step
    new_node->next = temp->next;
    temp->next = new_node;
}

// Function to print the graph in a 2D representation
void printGraph(Node** graph, int V) {
    int i;

    // Traverse through the graph and print the edges
    for (i = 0; i < V; i++) {
        Node* temp = *graph;
        printf("\n%d :-->", i);

        // Traverse through the list and print the edges
        while (temp != NULL) {
            printf("%d, ", temp->data);
            temp = temp->next;
        }
    }
}

// Driver code
int main() {
    int V = 5;
    Node** graph = (Node**) calloc(sizeof(Node*), V);

    // Add edges in the graph
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 3);
    addEdge(graph, 3, 4);

    // Print the graph in a 2D representation
    printGraph(graph, V);

    // Free the memory allocated to the graph
    for (int i = 0; i < V; i++) {
        Node* temp = graph[i];
        while (temp != NULL) {
            Node* next = temp->next;
            free(temp);
            temp = next;
        }
    }
    free(graph);

    return 0;
}