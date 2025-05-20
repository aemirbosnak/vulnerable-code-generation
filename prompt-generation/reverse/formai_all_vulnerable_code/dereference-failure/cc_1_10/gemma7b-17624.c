//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
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

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 0);
    insert(&head, 2, 0);
    insert(&head, 3, 0);
    insert(&head, 4, 0);
    insert(&head, 5, 0);
    insert(&head, 6, 0);
    insert(&head, 7, 0);
    insert(&head, 8, 0);
    insert(&head, 9, 0);

    // Find the route from (0, 0) to (5, 5)
    Node* current = head;
    while (current) {
        if (current->x == 5 && current->y == 5) {
            printf("Route found!\n");
            break;
        } else {
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No route found.\n");
    }

    return 0;
}