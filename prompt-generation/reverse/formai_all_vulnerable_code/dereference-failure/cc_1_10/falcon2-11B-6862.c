//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    int data;
    struct Node* next;
};

struct Graph {
    int V;
    struct Node** adjList;
};

// Function to print the given graph
void printGraph(struct Graph* graph) {
    int i;
    for (i = 0; i < graph->V; i++) {
        printf("Vertex %d: ", i);
        struct Node* node = graph->adjList[i];
        while (node!= NULL) {
            printf("%d ", node->data);
            node = node->next;
        }
        printf("\n");
    }
}

int main() {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->V = 5;
    graph->adjList = (struct Node**)malloc(sizeof(struct Node*) * graph->V);

    // Create the adjacency list for the graph
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    node1->data = 1;
    node1->next = NULL;
    graph->adjList[0] = node1;

    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    node2->data = 2;
    node2->next = NULL;
    graph->adjList[1] = node2;

    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));
    node3->data = 3;
    node3->next = NULL;
    graph->adjList[2] = node3;

    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    node4->data = 4;
    node4->next = NULL;
    graph->adjList[3] = node4;

    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    node5->data = 5;
    node5->next = NULL;
    graph->adjList[4] = node5;

    // Print the graph
    printf("The given graph is:\n");
    printGraph(graph);

    // Free the memory allocated for the graph
    free(graph->adjList);
    free(graph);

    return 0;
}