//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
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
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            *head = malloc(sizeof(Node));
            (*head)->x = i;
            (*head)->y = j;
            (*head)->next = NULL;
            head = &((*head)->next);
        }
    }
}

void findRoute(Node* head, int x, int y) {
    if (head == NULL) {
        return;
    }
    if (head->x == x && head->y == y) {
        printf("Path found!\n");
        return;
    }
    findRoute(head->next, x, y);
    if (head->x - 1 >= 0 && head->y == y) {
        printf("Move left\n");
        findRoute(head->next, head->x - 1, y);
    }
    if (head->x + 1 < MAX_SIZE && head->y == y) {
        printf("Move right\n");
        findRoute(head->next, head->x + 1, y);
    }
    if (head->x == x && head->y - 1 >= 0) {
        printf("Move down\n");
        findRoute(head->next, x, head->y - 1);
    }
    if (head->x == x && head->y + 1 < MAX_SIZE) {
        printf("Move up\n");
        findRoute(head->next, x, head->y + 1);
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head, 0, 0);
    return 0;
}