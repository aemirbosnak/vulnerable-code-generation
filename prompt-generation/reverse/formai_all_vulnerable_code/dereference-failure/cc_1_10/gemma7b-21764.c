//Gemma-7B DATASET v1.0 Category: Linked list operations ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data)
{
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void paranoidDelete(Node* head)
{
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        previous = current;
        current = current->next;

        if (previous && current && previous->data == current->data) {
            free(previous);
            previous = NULL;
        }
    }

    head = current;
}

int main()
{
    Node* head = NULL;

    insertAtTail(head, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    paranoidDelete(head);

    head = NULL;

    return 0;
}