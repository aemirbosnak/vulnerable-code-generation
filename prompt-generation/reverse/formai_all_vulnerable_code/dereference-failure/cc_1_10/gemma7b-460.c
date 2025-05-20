//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 10

typedef struct Node {
    int num;
    struct Node* next;
} Node;

void mapTopology(Node* head) {
    int i, j, count = 0;
    Node* current = head;
    printf("The topology of the C network is as follows:\n");

    // Count the number of vertices in the network
    while (current) {
        count++;
        current = current->next;
    }

    // Print the number of vertices
    printf("Number of vertices: %d\n", count);

    // Create a matrix to represent the network topology
    int** graph = (int**)malloc(count * sizeof(int*));
    for (i = 0; i < count; i++) {
        graph[i] = (int*)malloc(count * sizeof(int));
        for (j = 0; j < count; j++) {
            graph[i][j] = 0;
        }
    }

    // Populate the matrix with the connections between vertices
    current = head;
    while (current) {
        graph[current->num][current->next->num] = 1;
        current = current->next;
    }

    // Print the adjacency matrix
    for (i = 0; i < count; i++) {
        for (j = 0; j < count; j++) {
            printf("%d ", graph[i][j]);
        }
        printf("\n");
    }

    // Free the memory allocated for the matrix
    for (i = 0; i < count; i++) {
        free(graph[i]);
    }
    free(graph);
}

int main() {
    // Create a sample network topology
    Node* head = (Node*)malloc(sizeof(Node));
    head->num = 1;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->num = 2;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->num = 3;
    head->next->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->next->num = 4;

    mapTopology(head);

    return 0;
}