//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_VERTICES 10

typedef struct Node {
    int index;
    struct Node* next;
} Node;

void display_topology(Node* head) {
    Node* current = head;
    while (current) {
        printf("%d ", current->index);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* graph[MAX_VERTICES] = { NULL };
    for (int i = 0; i < MAX_VERTICES; i++) {
        graph[i] = NULL;
    }

    graph[0] = malloc(sizeof(Node));
    graph[0]->index = 0;
    graph[0]->next = NULL;

    graph[1] = malloc(sizeof(Node));
    graph[1]->index = 1;
    graph[1]->next = NULL;

    graph[2] = malloc(sizeof(Node));
    graph[2]->index = 2;
    graph[2]->next = NULL;

    graph[3] = malloc(sizeof(Node));
    graph[3]->index = 3;
    graph[3]->next = NULL;

    graph[4] = malloc(sizeof(Node));
    graph[4]->index = 4;
    graph[4]->next = NULL;

    graph[0]->next = graph[1];
    graph[1]->next = graph[2];
    graph[2]->next = graph[3];
    graph[3]->next = graph[4];

    display_topology(graph[0]);

    return 0;
}