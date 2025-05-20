//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int x, int y) {
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

void findDistance(Node* head, int x, int y) {
    Node* current = head;
    while (current) {
        int dx = abs(current->x - x);
        int dy = abs(current->y - y);
        int distance = dx + dy;

        if (distance < MAX) {
            printf("Node at (%d, %d) is at a distance of %d\n", current->x, current->y, distance);
        }
    }
}

int main() {
    Node* head = NULL;
    head = insertAtTail(head, 10, 20);
    head = insertAtTail(head, 20, 30);
    head = insertAtTail(head, 30, 40);

    findDistance(head, 15, 35);

    return 0;
}