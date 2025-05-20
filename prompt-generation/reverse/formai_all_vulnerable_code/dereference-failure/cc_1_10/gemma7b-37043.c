//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: complex
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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

int findRoute(Node* head, int x, int y) {
    while (head) {
        if (head->x == x && head->y == y) {
            return 1;
        } else if (head->x == x && head->y != y) {
            return 0;
        } else if (head->x != x && head->y == y) {
            return 0;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(&head, 1, 1);
    insertNode(&head, 2, 2);
    insertNode(&head, 3, 3);
    insertNode(&head, 4, 4);

    if (findRoute(head, 2, 2) == 1) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }

    return 0;
}