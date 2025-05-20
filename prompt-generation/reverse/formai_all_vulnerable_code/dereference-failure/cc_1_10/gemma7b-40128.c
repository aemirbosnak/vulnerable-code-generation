//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: shape shifting
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAX 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        ((*head)->prev)->next = newNode;
        newNode->prev = (*head)->prev;
    }
}

void traverse(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    traverse(head);

    insert(&head, 'f');
    insert(&head, 'g');

    traverse(head);

    return 0;
}