//Gemma-7B DATASET v1.0 Category: Memory Game ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10

typedef struct Node {
    int data;
    struct Node* next;
} Node;

void initialize(Node** head) {
    *head = NULL;
}

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

void search(Node* head, int data) {
    while (head) {
        if (head->data == data) {
            printf("Data found!\n");
            return;
        } else if (head->next) {
            head = head->next;
        } else {
            printf("Data not found.\n");
            return;
        }
    }
}

int main() {
    Node* head = NULL;
    initialize(&head);

    insert(head, 10);
    insert(head, 20);
    insert(head, 30);
    insert(head, 40);
    insert(head, 50);

    search(head, 30);

    return 0;
}