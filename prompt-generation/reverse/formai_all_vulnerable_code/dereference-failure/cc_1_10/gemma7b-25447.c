//Gemma-7B DATASET v1.0 Category: Sorting ; Style: secure
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void sortList(Node* head) {
    Node* current = head;
    Node* previous = NULL;

    while (current) {
        Node* minNode = current;
        Node* minPrevious = previous;

        for (Node* traverse = current->next; traverse; traverse) {
            if (traverse->data < minNode->data) {
                minNode = traverse;
                minPrevious = previous;
            }
        }

        if (minPrevious) {
            minPrevious->next = minNode->next;
            minNode->next = current;
            current = minNode;
        } else {
            current = current->next;
        }
    }

    head = current;
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 4);
    insertAtTail(head, 2);
    insertAtTail(head, 8);
    insertAtTail(head, 6);
    insertAtTail(head, 3);

    sortList(head);

    while (head) {
        printf("%d ", head->data);
        head = head->next;
    }

    return 0;
}