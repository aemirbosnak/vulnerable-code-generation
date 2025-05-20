//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: thoughtful
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
            Node* newNode = malloc(sizeof(Node));
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

int findRoute(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return 0;
    }

    if (head->x == targetX && head->y == targetY) {
        return 1;
    }

    findRoute(head->next, targetX, targetY);

    if (findRoute(head->next, targetX, targetY) == 1) {
        return 1;
    }

    return 0;
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    int targetX = 5;
    int targetY = 5;

    if (findRoute(head, targetX, targetY) == 1) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }

    return 0;
}