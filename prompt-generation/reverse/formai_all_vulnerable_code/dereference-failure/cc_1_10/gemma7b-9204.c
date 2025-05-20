//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define MAX 1000

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, int data) {
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

void greedyAlgorithm(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int total = 0;

    while (current) {
        int data = current->data;
        current = current->next;

        if (previous && data > previous->data) {
            total += data - previous->data;
        }

        previous = current;
    }

    printf("Total greed: %d\n", total);
}

int main() {
    Node* head = insertAtTail(NULL, 10);
    insertAtTail(head, 20);
    insertAtTail(head, 30);
    insertAtTail(head, 40);
    insertAtTail(head, 50);

    greedyAlgorithm(head);

    return 0;
}