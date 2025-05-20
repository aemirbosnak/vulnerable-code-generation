//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

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
        (*head)->next = newNode;
    }
}

void GreedyMerge(Node** head1, Node** head2) {
    Node** head3 = (Node**)malloc(sizeof(Node));
    *head3 = NULL;

    Node* current1 = *head1;
    Node* current2 = *head2;

    while (current1 && current2) {
        if (current1->data < current2->data) {
            insertAtTail(head3, current1->data);
            current1 = current1->next;
        } else {
            insertAtTail(head3, current2->data);
            current2 = current2->next;
        }
    }

    insertAtTail(head3, current1 ? current1->data : current2->data);

    *head1 = *head2 = *head3 = NULL;
}

int main() {
    Node* head1 = NULL;
    insertAtTail(&head1, 4);
    insertAtTail(&head1, 2);
    insertAtTail(&head1, 8);

    Node* head2 = NULL;
    insertAtTail(&head2, 6);
    insertAtTail(&head2, 3);
    insertAtTail(&head2, 1);

    GreedyMerge(&head1, &head2);

    Node* current = head1;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    return 0;
}