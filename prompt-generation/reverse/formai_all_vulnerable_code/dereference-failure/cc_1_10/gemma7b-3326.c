//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void createMaze(Node** head, int x, int y) {
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

void findRoute(Node* head, int targetX, int targetY) {
    Node* current = head;
    while (current) {
        if (current->x == targetX && current->y == targetY) {
            printf("Path found!\n");
            return;
        } else if (current->x > targetX || current->y > targetY) {
            return;
        } else {
            current = current->next;
        }
    }

    printf("No path found.\n");
}

int main() {
    Node* head = NULL;
    createMaze(&head, 5, 5);
    createMaze(&head, 3, 3);
    createMaze(&head, 7, 4);
    createMaze(&head, 2, 2);

    findRoute(head, 4, 4);

    return 0;
}