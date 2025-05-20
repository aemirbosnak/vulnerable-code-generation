//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    int i, j;
    Node* newNode;

    *head = NULL;

    for (i = 0; i < MAX; i++) {
        for (j = 0; j < MAX; j++) {
            newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            if (*head == NULL) {
                *head = newNode;
            } else {
                ((*head)->next = newNode)->next = NULL;
                head = &((*head)->next);
            }
        }
    }
}

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x > targetX || current->y > targetY) {
            return;
        } else {
            current = current->next;
        }
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head, 5, 5);

    return 0;
}