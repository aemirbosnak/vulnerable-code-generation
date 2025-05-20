//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    *head = NULL;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
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

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Route found!\n");
            return;
        } else if (current->x != targetX || current->y != targetY) {
            current = current->next;
        } else {
            printf("Current: (%d, %d)\n", current->x, current->y);
            current = current->next;
        }
    }
    printf("No route found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head, 2, 2);
    return 0;
}