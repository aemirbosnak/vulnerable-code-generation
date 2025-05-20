//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->next = newNode);
        *head = newNode;
    }
}

void findRoute(Node* head, int target) {
    if (head == NULL) {
        return;
    }

    if (head->data == target) {
        printf("Target found!\n");
        return;
    }

    findRoute(head->next, target);

    if (head->next != NULL) {
        printf("Visiting node: %d\n", head->data);
    }
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 1);
    insertAtTail(&head, 2);
    insertAtTail(&head, 3);
    insertAtTail(&head, 4);
    insertAtTail(&head, 5);
    insertAtTail(&head, 6);
    insertAtTail(&head, 7);
    insertAtTail(&head, 8);
    insertAtTail(&head, 9);
    insertAtTail(&head, 10);

    findRoute(head, 6);

    return 0;
}