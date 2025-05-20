//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

struct node {
    int data;
    struct node* next;
};

void insertAtTail(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

struct node* search(struct node* head, int data) {
    while (head) {
        if (head->data == data) {
            return head;
        } else if (head->next) {
            head = head->next;
        } else {
            return NULL;
        }
    }
}

int main() {
    struct node* head = NULL;
    insertAtTail(&head, 10);
    insertAtTail(&head, 20);
    insertAtTail(&head, 30);
    insertAtTail(&head, 40);
    insertAtTail(&head, 50);

    struct node* foundNode = search(head, 30);

    if (foundNode) {
        printf("Found node data: %d\n", foundNode->data);
    } else {
        printf("Node not found.\n");
    }

    return 0;
}