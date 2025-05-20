//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insert(Node** head, int x, int y) {
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

void findDistance(Node* head, int x, int y) {
    while (head) {
        int dx = abs(head->x - x);
        int dy = abs(head->y - y);
        int distance = dx + dy;

        if (distance < MAX) {
            printf("Node at (%d, %d) is at a distance of %d.\n", head->x, head->y, distance);
        }
        head = head->next;
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 10, 20);
    insert(&head, 20, 30);
    insert(&head, 30, 40);
    insert(&head, 40, 50);

    findDistance(head, 25, 45);

    return 0;
}