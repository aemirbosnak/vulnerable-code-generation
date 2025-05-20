//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
    Node* newNode = malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findRoute(Node* head) {
    int x = 0;
    int y = 0;

    while (head) {
        if (head->x == x && head->y == y) {
            printf("Found you! (%d, %d)\n", head->x, head->y);
            return;
        }

        x++;
        if (x == MAX_SIZE) {
            y++;
            x = 0;
        }

        head = head->next;
    }

    printf("No route found.\n");
}

int main() {
    Node* head = NULL;

    insertNode(&head, 0, 0);
    insertNode(&head, 1, 0);
    insertNode(&head, 2, 0);
    insertNode(&head, 3, 0);
    insertNode(&head, 3, 1);
    insertNode(&head, 3, 2);
    insertNode(&head, 2, 2);
    insertNode(&head, 1, 2);

    findRoute(head);

    return 0;
}