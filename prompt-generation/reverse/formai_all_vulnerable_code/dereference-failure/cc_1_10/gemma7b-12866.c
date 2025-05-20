//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: safe
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createMaze(Node* head) {
    head = (Node*)malloc(MAX * sizeof(Node));
    head->data = 0;
    head->next = NULL;

    for (int i = 1; i < MAX; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        head->next = newNode;
        head = newNode;
    }
}

void findRoute(Node* head) {
    int visited[MAX] = {0};
    visited[0] = 1;

    Node* current = head;
    while (current) {
        if (visited[current->data] == 0) {
            visited[current->data] = 1;

            if (current->data == MAX - 1) {
                printf("Route found!\n");
                return;
            }

            findRoute(current->next);
        }
        current = current->next;
    }

    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(head);
    findRoute(head);

    return 0;
}