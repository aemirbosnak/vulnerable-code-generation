//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x, y;
    struct Node* next;
} Node;

void insertNode(Node** head, int x, int y) {
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

void findClosestNode(Node* head, int x, int y) {
    int minDistance = MAX;
    Node* closestNode = NULL;

    while (head) {
        int dx = abs(head->x - x);
        int dy = abs(head->y - y);
        int distance = dx + dy;

        if (distance < minDistance) {
            minDistance = distance;
            closestNode = head;
        }
        head = head->next;
    }

    printf("The closest node to (%d, %d) is (%d, %d) with a distance of %d.\n", x, y, closestNode->x, closestNode->y, minDistance);
}

int main() {
    Node* head = NULL;

    insertNode(&head, 10, 20);
    insertNode(&head, 20, 30);
    insertNode(&head, 30, 40);
    insertNode(&head, 40, 50);

    findClosestNode(head, 25, 45);

    return 0;
}