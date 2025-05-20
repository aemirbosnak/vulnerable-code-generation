//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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
    insert(&head, 2, 1);
    insert(&head, 2, 2);
    insert(&head, 1, 2);

    // Find the route from (0, 0) to (2, 2)
    int x = 0, y = 0, target_x = 2, target_y = 2;

    // Traverse the maze
    while (x != target_x || y != target_y) {
        int dx = abs(x - target_x);
        int dy = abs(y - target_y);

        if (dx > dy) {
            y++;
        } else {
            x++;
        }

        insert(&head, x, y);
    }

    // Print the route
    Node* current = head;
    while (current) {
        printf("(%d, %d) ", current->x, current->y);
        current = current->next;
    }

    return 0;
}