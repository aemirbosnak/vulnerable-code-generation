//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

Node* createNode(int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;
    return newNode;
}

void insertNode(Node* head, int x, int y) {
    Node* newNode = createNode(x, y);
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

int findPath(Node* head, int x, int y) {
    Node* current = head;
    while (current) {
        if (current->x == x && current->y == y) {
            return 1;
        }
        current = current->next;
    }
    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 0, 1);
    insertNode(head, 1, 1);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 0, 2);
    insertNode(head, 1, 2);
    insertNode(head, 2, 2);
    insertNode(head, 3, 2);

    if (findPath(head, 2, 2) == 1) {
        printf("Path found!");
    } else {
        printf("Path not found!");
    }

    return 0;
}