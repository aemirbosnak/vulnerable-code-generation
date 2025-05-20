//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void insertAtTail(struct Node* head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        struct Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
}

struct Node* search(struct Node* head, int data) {
    struct Node* temp = head;
    while (temp && temp->data != data) {
        temp = temp->next;
    }

    return temp;
}

int main() {
    struct Node* head = NULL;
    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);

    struct Node* result = search(head, 30);

    if (result) {
        printf("The data is: %d\n", result->data);
    } else {
        printf("The data is not found.\n");
    }

    return 0;
}