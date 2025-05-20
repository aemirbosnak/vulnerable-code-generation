//Gemma-7B DATASET v1.0 Category: Data mining ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX 1000

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

int main() {
    Node* head = NULL;
    insert(&head, 1);
    insert(&head, 2);
    insert(&head, 3);
    insert(&head, 4);
    insert(&head, 5);

    Node* current = head;
    while (current) {
        printf("%d ", current->data);
        current = current->next;
    }

    printf("\n");

    int sum = 0;
    current = head;
    while (current) {
        sum += current->data;
        current = current->next;
    }

    printf("The sum of the data in the linked list is: %d\n", sum);

    return 0;
}