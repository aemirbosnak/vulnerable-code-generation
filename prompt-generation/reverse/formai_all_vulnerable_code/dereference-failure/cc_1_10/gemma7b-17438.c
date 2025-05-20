//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: brave
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int x;
    int y;
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
        newNode->next = head;
        head = newNode;
    }
}

void findMazeRoute(Node* head) {
    Node* current = head;
    while (current) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->next;
    }
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 3, 0);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);
    insertNode(head, 3, 3);

    findMazeRoute(head);

    return 0;
}