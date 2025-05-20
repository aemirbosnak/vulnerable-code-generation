//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
    if (head == NULL) {
        head = newNode;
    } else {
        Node* current = head;
        while (current->next) {
            current = current->next;
        }
        current->next = newNode;
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 2, 2);

    // Find the route from (0, 0) to (2, 2)
    Node* current = head;
    while (current) {
        if (current->x == 2 && current->y == 2) {
            printf("Route found!\n");
            break;
        }
        current = current->next;
    }

    if (current == NULL) {
        printf("No route found.\n");
    }

    return 0;
}