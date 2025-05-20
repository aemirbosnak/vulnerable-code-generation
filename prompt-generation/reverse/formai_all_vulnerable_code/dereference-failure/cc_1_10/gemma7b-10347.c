//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insertAtTail(Node* head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    head = newNode;
}

int search(Node* head, int target) {
    while (head) {
        if (head->data == target) {
            return 1;
        } else if (head->data < target) {
            head = head->next;
        } else {
            return 0;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    if (search(head, 40) == 1) {
        printf("Target found!\n");
    } else {
        printf("Target not found.\n");
    }

    return 0;
}