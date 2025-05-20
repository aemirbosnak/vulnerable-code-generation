//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* insertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

int search(struct Node* head, int target) {
    struct Node* current = head;

    while (current) {
        if (current->data == target) {
            return 1;
        } else if (current->data > target) {
            return 0;
        } else {
            current = current->next;
        }
    }

    return 0;
}

int main() {
    struct Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    if (search(head, 20) == 1) {
        printf("Target found!");
    } else {
        printf("Target not found!");
    }

    return 0;
}