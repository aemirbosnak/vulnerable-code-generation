//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->next = NULL;
    return node;
}

void insertNode(Node* node, Node* newNode) {
    if (node == NULL) {
        node = newNode;
    } else {
        node->next = newNode;
        node = newNode;
    }
}

int main() {

    Node* head = createNode(0, 0);
    insertNode(head, createNode(1, 1));
    insertNode(head, createNode(2, 2));
    insertNode(head, createNode(3, 3));

    // Find the route to (3, 3) from (0, 0)
    Node* current = head;
    while (current) {
        if (current->x == 3 && current->y == 3) {
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