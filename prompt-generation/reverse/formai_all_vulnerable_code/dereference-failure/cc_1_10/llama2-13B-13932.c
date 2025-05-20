//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>

// Graph structure using arrays
typedef struct node {
    int data; // data stored in each node
    struct node* next; // pointer to next node in the graph
} Node;

// Function to create a graph
void createGraph(int* graph, int n) {
    int i, j, k;

    // Initialize graph with no edges
    for (i = 0; i < n; i++) {
        graph[i] = NULL;
    }

    // Add edges to the graph
    for (i = 0; i < n; i++) {
        for (j = i + 1; j < n; j++) {
            if (i != j) {
                // Create a new node and add it to the graph
                Node* newNode = (Node*) malloc(sizeof(Node));
                newNode->data = i * j;
                newNode->next = graph[i];
                graph[i] = newNode;
                graph[j] = newNode;
            }
        }
    }
}

// Function to traverse the graph
void traverse(Node* root) {
    while (root != NULL) {
        printf("%d -> ", root->data);
        root = root->next;
    }
    printf("\n");
}

int main() {
    int n = 5; // number of nodes in the graph
    int* graph = malloc(n * sizeof(Node*));

    // Create the graph
    createGraph(graph, n);

    // Traverse the graph
    traverse(graph[0]);

    return 0;
}