//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* InsertAtTail(struct Node* head, int data) {
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

struct Node* DeleteFromTail(struct Node* head) {
    struct Node* prev = NULL;
    struct Node* current = head;

    while (current->next) {
        prev = current;
        current = current->next;
    }

    if (prev) {
        prev->next = NULL;
    } else {
        head = NULL;
    }

    return head;
}

int main() {
    struct Node* head = NULL;

    InsertAtTail(head, 10);
    InsertAtTail(head, 20);
    InsertAtTail(head, 30);
    InsertAtTail(head, 40);

    head = DeleteFromTail(head);
    head = DeleteFromTail(head);

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}