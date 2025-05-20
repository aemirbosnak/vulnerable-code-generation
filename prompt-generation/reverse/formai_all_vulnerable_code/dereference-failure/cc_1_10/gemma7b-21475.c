//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head, int n, int m) {
    *head = malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            ((*head)->next) = newNode;
            head = &newNode;
        }
    }
}

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Route found!\n");
            return;
        } else if (current->x < targetX && current->y < targetY) {
            current = current->next;
        } else if (current->x > targetX && current->y > targetY) {
            current = current->next;
        } else if (current->x < targetX && current->y > targetY) {
            current = current->next;
        } else {
            current = current->next;
        }
    }

    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head, 5, 5);
    findRoute(head, 2, 2);

    return 0;
}