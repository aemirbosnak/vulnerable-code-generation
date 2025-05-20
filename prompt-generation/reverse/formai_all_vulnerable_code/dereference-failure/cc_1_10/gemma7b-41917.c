//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void Insert(Node** head, int x, int y) {
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

void FindRoute(Node* head, int x, int y) {
    if (head == NULL) {
        return;
    }

    if (head->x == x && head->y == y) {
        printf("Path found!\n");
        return;
    }

    FindRoute(head->next, x, y);

    if (head->x - x == 1) {
        printf("Move right\n");
    } else if (head->x - x == -1) {
        printf("Move left\n");
    } else if (head->y - y == 1) {
        printf("Move down\n");
    } else if (head->y - y == -1) {
        printf("Move up\n");
    }
}

int main() {
    Node* head = NULL;

    Insert(&head, 0, 0);
    Insert(&head, 1, 0);
    Insert(&head, 2, 0);
    Insert(&head, 2, 1);
    Insert(&head, 2, 2);
    Insert(&head, 1, 2);

    FindRoute(head, 0, 2);

    return 0;
}