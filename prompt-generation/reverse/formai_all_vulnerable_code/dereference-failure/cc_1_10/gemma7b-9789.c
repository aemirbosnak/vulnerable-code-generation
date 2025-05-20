//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* insert(Node* head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void findPath(Node* head, int targetX, int targetY) {
    printf("Path found:\n");

    while (head) {
        if (head->x == targetX && head->y == targetY) {
            printf("(%d, %d) ", head->x, head->y);
            head = head->next;
            continue;
        }

        printf("(%d, %d) ", head->x, head->y);
        head = head->next;
    }

    printf("\n");
}

int main() {
    Node* head = insert(NULL, 0, 0);
    insert(head, 1, 0);
    insert(head, 2, 0);
    insert(head, 3, 0);
    insert(head, 4, 0);
    insert(head, 5, 0);

    insert(head, 0, 1);
    insert(head, 1, 1);
    insert(head, 2, 1);
    insert(head, 3, 1);
    insert(head, 4, 1);
    insert(head, 5, 1);

    insert(head, 0, 2);
    insert(head, 1, 2);
    insert(head, 2, 2);
    insert(head, 3, 2);
    insert(head, 4, 2);
    insert(head, 5, 2);

    findPath(head, 4, 2);

    return 0;
}