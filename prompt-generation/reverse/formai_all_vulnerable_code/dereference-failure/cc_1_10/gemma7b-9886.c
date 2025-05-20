//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

typedef struct Node {
    int x;
    int y;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int x, int y) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->x = x;
    newNode->y = y;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void findClosestPair(Node* head, int target) {
    int minDistance = MAX;
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        int distance = abs(target - current->x) + abs(target - current->y);

        if (distance < minDistance) {
            minDistance = distance;
            previous = current;
        }
        current = current->next;
    }

    if (previous) {
        printf("Closest pair: (%d, %d) and (%d, %d)\n", previous->x, previous->y, current->x, current->y);
    } else {
        printf("No pair found.\n");
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1, 2);
    insertAtTail(&head, 3, 4);
    insertAtTail(&head, 5, 6);
    insertAtTail(&head, 7, 8);

    findClosestPair(head, 6);

    return 0;
}