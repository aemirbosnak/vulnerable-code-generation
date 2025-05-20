//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTS 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void mapNetworkTopology(Node* head) {
    int i, j, count = 0;
    Node* curr = head;
    Node* prev = NULL;

    printf("Network Topology Mapping:\n");

    // Calculate the number of vertices
    while (curr) {
        count++;
        prev = curr;
        curr = curr->next;
    }

    // Print the number of vertices
    printf("Number of vertices: %d\n", count);

    // Print the adjacency list
    prev = head;
    while (prev) {
        printf("Vertex %d: ", prev->index);
        curr = prev->next;
        while (curr) {
            printf("%d ", curr->index);
            curr = curr->next;
        }
        printf("\n");
    }
}

int main() {
    Node* head = NULL;
    head = malloc(sizeof(Node));
    head->index = 0;
    head->next = malloc(sizeof(Node));
    head->next->index = 1;
    head->next->next = malloc(sizeof(Node));
    head->next->next->index = 2;
    head->next->next->next = NULL;

    mapNetworkTopology(head);

    return 0;
}