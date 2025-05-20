//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: multiplayer
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
    *head = NULL;
    for (i = 0; i < MAX_SIZE; i++) {
        for (j = 0; j < MAX_SIZE; j++) {
            Node* newNode = malloc(sizeof(Node));
            newNode->x = i;
            newNode->y = j;
            newNode->next = NULL;
            if (*head == NULL) {
                *head = newNode;
            } else {
                (*head)->next = newNode;
                *head = newNode;
            }
        }
    }
}

void findRoute(Node* head) {
    int x, y;
    printf("Enter the starting point (x, y): ");
    scanf("%d %d", &x, &y);

    printf("Enter the end point (x, y): ");
    scanf("%d %d", &x, &y);

    // Search for the route
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            printf("Route found!\n");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("No route found.\n");
    }
}

int main() {
    Node* head = NULL;
    createMaze(&head);
    findRoute(head);

    return 0;
}