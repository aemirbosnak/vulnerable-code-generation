//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insert(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node* temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insert(head, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 2, 1);
    insert(head, 2, 2);
    insert(head, 1, 2);

    // Find the route from (0, 0) to (2, 2)
    Node* current = head;
    while (current) {
        if (current->x == 2 && current->y == 2) {
            printf("Path found!\n");
            break;
        } else if (current->x == 0 && current->y == 0) {
            printf("Starting point reached.\n");
        } else {
            printf("Current position: (%d, %d)\n", current->x, current->y);
            current = current->next;
        }
    }

    if (current == NULL) {
        printf("No path found.\n");
    }

    return 0;
}