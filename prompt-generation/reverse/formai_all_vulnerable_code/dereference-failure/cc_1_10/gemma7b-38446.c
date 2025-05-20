//Gemma-7B DATASET v1.0 Category: Geometric algorithms ; Style: authentic
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

void findCircle(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        if (previous && current->x == previous->x && current->y == previous->y) {
            printf("Circle found!\n");
            return;
        }

        previous = current;
        current = current->next;
    }

    printf("No circle found.\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1, 2);
    insertAtTail(&head, 3, 4);
    insertAtTail(&head, 5, 6);
    insertAtTail(&head, 7, 8);
    insertAtTail(&head, 9, 10);

    findCircle(head);

    return 0;
}