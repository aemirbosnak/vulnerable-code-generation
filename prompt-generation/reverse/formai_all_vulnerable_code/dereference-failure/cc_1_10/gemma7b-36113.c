//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
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

int main() {
    Node* head = NULL;
    insert(&head, 0, 0);
    insert(&head, 1, 1);
    insert(&head, 2, 2);
    insert(&head, 3, 3);

    int x, y;
    scanf("Enter the starting position (x, y): ", &x);
    scanf("Enter the ending position (x, y): ", &y);

    // Find the route
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("The route: ");
            while (current) {
                printf("(%d, %d) ", current->x, current->y);
                current = current->next;
            }
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("No route found.");
    }

    return 0;
}