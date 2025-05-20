//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

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
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);
    insert(&head, 4, 4);

    // Find the shortest route from (0, 0) to (4, 4)
    int x, y, dx, dy;
    x = 0;
    y = 0;
    dx = 4;
    dy = 4;

    // Traverse the maze
    while (x != dx || y != dy) {
        // Move in the direction of the goal
        if (x < dx) {
            x++;
        } else if (x > dx) {
            x--;
        }
        if (y < dy) {
            y++;
        } else if (y > dy) {
            y--;
        }

        // Insert the current position into the list
        insert(&head, x, y);

        // Check if the goal has been reached
        if (x == dx && y == dy) {
            printf("The goal has been reached!");
            break;
        }
    }

    return 0;
}