//Gemma-7B DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int distance(int x1, int y1, int x2, int y2) {
    return abs(x2 - x1) + abs(y2 - y1);
}

int main() {
    Node* head = NULL;
    insertNode(&head, 0, 0);
    insertNode(&head, 1, 1);
    insertNode(&head, 2, 2);
    insertNode(&head, 3, 3);

    int targetX = 2;
    int targetY = 2;

    Node* current = head;
    while (current) {
        if (distance(current->x, current->y, targetX, targetY) <= 3) {
            printf("Found target at (%d, %d)\n", current->x, current->y);
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("Target not found\n");
    }

    return 0;
}