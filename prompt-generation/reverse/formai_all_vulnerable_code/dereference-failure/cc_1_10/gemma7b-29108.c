//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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
        newNode->next = head;
        head = newNode;
    }
}

int findRoute(Node* head, int targetX, int targetY) {
    if (head == NULL) {
        return 0;
    }

    if (head->x == targetX && head->y == targetY) {
        return 1;
    }

    int route = findRoute(head->next, targetX, targetY);

    if (route) {
        return route;
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 2, 2);
    insertNode(head, 3, 2);

    int targetX = 3;
    int targetY = 2;

    int route = findRoute(head, targetX, targetY);

    if (route) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }

    return 0;
}