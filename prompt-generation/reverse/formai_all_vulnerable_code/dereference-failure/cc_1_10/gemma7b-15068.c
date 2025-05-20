//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void createMaze(Node** head) {
    *head = (Node*)malloc(sizeof(Node));
    (*head)->x = 0;
    (*head)->y = 0;
    (*head)->next = NULL;

    for (int i = 0; i < MAX_SIZE; i++) {
        for (int j = 0; j < MAX_SIZE; j++) {
            Node* newNode = (Node*)malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;

            ((*head)->next) = newNode;
            head = &newNode;
        }
    }
}

void findRoute(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return;
    }

    if (head->x == targetX && head->y == targetY) {
        printf("Path found!\n");
        return;
    }

    findRoute(head->next, targetX, targetY);

    if (head->x - targetX > 0) {
        printf("Moving right\n");
    } else if (head->x - targetX < 0) {
        printf("Moving left\n");
    }

    if (head->y - targetY > 0) {
        printf("Moving up\n");
    } else if (head->y - targetY < 0) {
        printf("Moving down\n");
    }

    findRoute(head->next, targetX, targetY);
}

int main() {
    Node* head = NULL;
    createMaze(&head);

    findRoute(head, 5, 5);

    return 0;
}