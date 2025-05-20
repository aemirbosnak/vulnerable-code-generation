//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: curious
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void createMaze(Node* head) {
    head = (Node*)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;

    for (int i = 1; i < MAX_SIZE; i++) {
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->data = i;
        newNode->next = NULL;
        head->next = newNode;
        head = newNode;
    }
}

void findRoute(Node* head) {
    int visited = 0;
    Node* current = head;

    while (!visited) {
        if (current->data == MAX_SIZE - 1) {
            visited = 1;
            printf("The route is found!\n");
        } else {
            current->next = (Node*)malloc(sizeof(Node));
            current->next->data = current->data + 1;
            current->next->next = NULL;
            current = current->next;
        }
    }

    if (!visited) {
        printf("No route found.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(head);
    findRoute(head);

    return 0;
}