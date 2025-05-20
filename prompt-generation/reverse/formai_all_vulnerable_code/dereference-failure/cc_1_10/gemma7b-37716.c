//Gemma-7B DATASET v1.0 Category: Pathfinding algorithms ; Style: synchronous
#include <stdlib.h>
#include <stdio.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

int main() {
    Node** graph = (Node**)malloc(MAX_SIZE * sizeof(Node*));
    for (int i = 0; i < MAX_SIZE; i++) {
        graph[i] = NULL;
    }

    graph[0] = (Node*)malloc(sizeof(Node));
    graph[0]->x = 0;
    graph[0]->y = 0;
    graph[0]->next = NULL;

    graph[1] = (Node*)malloc(sizeof(Node));
    graph[1]->x = 1;
    graph[1]->y = 0;
    graph[1]->next = NULL;

    graph[2] = (Node*)malloc(sizeof(Node));
    graph[2]->x = 2;
    graph[2]->y = 0;
    graph[2]->next = NULL;

    graph[3] = (Node*)malloc(sizeof(Node));
    graph[3]->x = 0;
    graph[3]->y = 1;
    graph[3]->next = NULL;

    graph[4] = (Node*)malloc(sizeof(Node));
    graph[4]->x = 1;
    graph[4]->y = 1;
    graph[4]->next = NULL;

    graph[5] = (Node*)malloc(sizeof(Node));
    graph[5]->x = 2;
    graph[5]->y = 1;
    graph[5]->next = NULL;

    graph[6] = (Node*)malloc(sizeof(Node));
    graph[6]->x = 0;
    graph[6]->y = 2;
    graph[6]->next = NULL;

    graph[7] = (Node*)malloc(sizeof(Node));
    graph[7]->x = 1;
    graph[7]->y = 2;
    graph[7]->next = NULL;

    graph[8] = (Node*)malloc(sizeof(Node));
    graph[8]->x = 2;
    graph[8]->y = 2;
    graph[8]->next = NULL;

    // Start from node 0 and find path to node 8
    Node* current = graph[0];
    Node* target = graph[8];

    while (current) {
        if (current->x == target->x && current->y == target->y) {
            printf("Path found!\n");
            break;
        } else if (current->next) {
            current = current->next;
        } else {
            printf("No path found.\n");
            break;
        }
    }

    return 0;
}