//Gemma-7B DATASET v1.0 Category: Sorting ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

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

void sort(Node** head) {
    // Bubble sort algorithm
    for (int i = 0; i < MAX_SIZE - 1; i++) {
        for (int j = 0; j < MAX_SIZE - i - 1; j++) {
            Node* current = *head;
            Node* next = current->next;

            if (current->data > next->data) {
                int temp = current->data;
                current->data = next->data;
                next->data = temp;
            }
        }
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 4);
    insert(&head, 3);
    insert(&head, 8);
    insert(&head, 6);
    insert(&head, 2);
    insert(&head, 9);

    sort(&head);

    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}