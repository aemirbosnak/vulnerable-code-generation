//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

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

void findMazeRoute(Node* head) {
    int x, y, dx, dy;
    x = head->x;
    y = head->y;
    dx = 1;
    dy = 0;

    while (x) {
        printf("(%d, %d) -> ", x, y);
        x += dx;
        y += dy;
        insertNode(head, x, y);
    }

    printf("(%d, %d)\n", x, y);
}

int main() {
    Node* head = NULL;
    insertNode(head, 0, 0);
    insertNode(head, 1, 0);
    insertNode(head, 2, 0);
    insertNode(head, 2, 1);
    insertNode(head, 3, 1);
    insertNode(head, 3, 2);
    insertNode(head, 4, 2);
    insertNode(head, 4, 3);

    findMazeRoute(head);

    return 0;
}