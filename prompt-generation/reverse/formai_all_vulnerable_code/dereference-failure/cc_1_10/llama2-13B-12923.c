//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a node in the graph
struct Node {
    int label; // node label
    struct Node* next; // next node in the graph
    struct Node* prev; // previous node in the graph
};

// Define a function to create a new node
struct Node* newNode(int label) {
    struct Node* node = malloc(sizeof(struct Node));
    node->label = label;
    node->next = NULL;
    node->prev = NULL;
    return node;
}

// Define a function to add a node to the graph
void addNode(struct Node** graph, int label) {
    struct Node* node = newNode(label);
    if (graph == NULL) {
        printf("Error: graph cannot be NULL\n");
        return;
    }
    if (*graph == NULL) {
        (*graph) = node;
    } else {
        (*graph)->next = node;
        node->prev = (*graph);
        (*graph) = node;
    }
}

// Define a function to traverse the graph
void traverse(struct Node* graph) {
    if (graph == NULL) {
        printf("Error: graph cannot be NULL\n");
        return;
    }
    printf("Traversing graph...\n");
    while (graph != NULL) {
        printf("%d ", graph->label);
        graph = graph->next;
    }
    printf("\n");
}

int main() {
    struct Node* graph = NULL;
    srand(time(NULL));
    for (int i = 0; i < 10; i++) {
        int label = rand() % 10;
        addNode(&graph, label);
    }
    traverse(graph);
    return 0;
}