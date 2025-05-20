//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: satisfied
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

int findRoute(Node* head, int target) {
    while (head) {
        if (head->data == target) {
            return 1;
        } else if (head->data < target) {
            head = head->next;
        }
    }

    return 0;
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

    if (findRoute(head, 5) == 1) {
        printf("Route found!\n");
    } else {
        printf("No route found.\n");
    }

    return 0;
}