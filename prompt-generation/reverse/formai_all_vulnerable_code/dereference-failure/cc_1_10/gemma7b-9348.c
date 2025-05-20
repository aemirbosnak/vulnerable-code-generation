//Gemma-7B DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

#define MAX 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void sort(Node** head) {
    Node* current = *head;
    Node* previous = NULL;

    while (current) {
        Node* next = current->next;

        if (previous && current->data < previous->data) {
            int temp = current->data;
            current->data = previous->data;
            previous->data = temp;
        }

        previous = current;
        current = next;
    }

    *head = previous;
}

int main() {
    Node* head = NULL;
    insert(&head, 4);
    insert(&head, 2);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 3);

    sort(&head);

    printf("Sorted list:");
    while (head) {
        printf(" %d", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}