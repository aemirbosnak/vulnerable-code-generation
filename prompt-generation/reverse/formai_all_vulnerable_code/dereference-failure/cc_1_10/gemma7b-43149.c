//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = NULL;
    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            if (*head == NULL) {
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }
}

void findRoute(Node* head, int x, int y) {
    if (head == NULL) {
        return;
    }
    if (head->x == x && head->y == y) {
        printf("Found the route!\n");
        return;
    }
    findRoute(head->next, x, y);
    if (head->next != NULL) {
        findRoute(head->next->next, x, y);
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head, 2, 2);
    return 0;
}