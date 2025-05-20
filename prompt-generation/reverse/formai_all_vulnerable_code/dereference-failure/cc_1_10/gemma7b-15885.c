//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTS 100

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void map_topology(Node* head) {
    int i, j, k;
    Node* current = head;
    printf("Mapping topology...\n");

    // Calculate the number of vertices
    int num_verts = 0;
    while (current) {
        num_verts++;
        current = current->next;
    }

    // Create a matrix of adjacency lists
    int** adjacency_list = (int**)malloc(num_verts * sizeof(int*));
    for (i = 0; i < num_verts; i++) {
        adjacency_list[i] = (int*)malloc(num_verts * sizeof(int));
        for (j = 0; j < num_verts; j++) {
            adjacency_list[i][j] = 0;
        }
    }

    // Populate the adjacency list
    current = head;
    while (current) {
        for (i = 0; i < num_verts; i++) {
            if (current->index == i) {
                for (j = 0; j < num_verts; j++) {
                    if (current->next && current->next->index == j) {
                        adjacency_list[i][j] = 1;
                    }
                }
            }
        }
        current = current->next;
    }

    // Print the adjacency list
    for (i = 0; i < num_verts; i++) {
        for (j = 0; j < num_verts; j++) {
            printf("%d ", adjacency_list[i][j]);
        }
        printf("\n");
    }

    // Free the memory
    for (i = 0; i < num_verts; i++) {
        free(adjacency_list[i]);
    }
    free(adjacency_list);
}

int main() {
    Node* head = (Node*)malloc(sizeof(Node));
    head->index = 0;
    head->next = (Node*)malloc(sizeof(Node));
    head->next->index = 1;
    head->next->next = (Node*)malloc(sizeof(Node));
    head->next->next->index = 2;

    map_topology(head);

    return 0;
}