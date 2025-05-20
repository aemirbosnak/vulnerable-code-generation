//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x, y;
    struct Node *next;
} Node;

void insertNode(Node *head, int x, int y) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        Node *temp = head;
        while (temp->next) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

int findRoute(Node *head, int x, int y) {
    Node *current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node *head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 4, 0);
    insertNode(head, 5, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 4, 1);
    insertNode(head, 5, 1);

    int result = findRoute(head, 2, 1);
    if (result) {
        printf("Route found!");
    } else {
        printf("No route found!");
    }

    return 0;
}