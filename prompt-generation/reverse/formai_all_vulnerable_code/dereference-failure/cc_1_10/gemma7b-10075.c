//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 5

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

void findRoute(Node* head, int target) {
    printf("Route found:\n");

    while (head) {
        if (head->data == target) {
            printf("Target found: %d\n", head->data);
            return;
        } else if (head->data < target) {
            printf("Current node: %d, moving to next node...\n", head->data);
            head = head->next;
        } else {
            printf("Current node: %d, moving to previous node...\n", head->data);
            head = head->next;
        }
    }

    printf("Target not found.\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 1);
    insertAtTail(head, 2);
    insertAtTail(head, 3);
    insertAtTail(head, 4);
    insertAtTail(head, 5);

    findRoute(head, 4);

    return 0;
}