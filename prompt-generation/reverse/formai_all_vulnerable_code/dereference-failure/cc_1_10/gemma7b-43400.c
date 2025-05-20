//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x, y;
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

void findClosest(Node* head, int x, int y) {
    Node* current = head;
    int minDistance = MAX;
    while (current) {
        int dx = abs(current->x - x);
        int dy = abs(current->y - y);
        int distance = dx + dy;

        if (distance < minDistance) {
            minDistance = distance;
        }

        current = current->next;
    }

    printf("The closest node is at (%d, %d) with a distance of %d\n", current->x, current->y, minDistance);
}

int main() {
    Node* head = NULL;

    insert(head, 10, 10);
    insert(head, 20, 20);
    insert(head, 30, 30);
    insert(head, 40, 40);

    findClosest(head, 25, 25);

    return 0;
}