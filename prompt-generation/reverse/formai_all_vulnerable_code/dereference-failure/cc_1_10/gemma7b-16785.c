//Gemma-7B DATASET v1.0 Category: Greedy Algorithms ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>

#define MAX 100

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void insert(Node** head, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void greedy(Node** head) {
    Node* current = *head;
    Node* previous = NULL;
    int sum = 0;

    while (current) {
        int currentData = current->data;
        if (previous && currentData > previous->data) {
            sum += currentData - previous->data;
        }
        previous = current;
        current = current->next;
    }

    printf("Total sum: %d\n", sum);
}

int main() {
    Node* head = NULL;
    insert(&head, 10);
    insert(&head, 20);
    insert(&head, 30);
    insert(&head, 40);
    insert(&head, 50);

    greedy(&head);

    return 0;
}