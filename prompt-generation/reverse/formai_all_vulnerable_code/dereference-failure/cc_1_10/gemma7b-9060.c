//Gemma-7B DATASET v1.0 Category: Database querying ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insert(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void traverse(Node* head) {
    if (head) {
        printf("%c ", head->data);
        traverse(head->next);
    }
}

int search(Node* head, char data) {
    if (head) {
        if (head->data == data) {
            return 1;
        } else {
            return search(head->next, data);
        }
    } else {
        return 0;
    }
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    traverse(head);
    printf("\n");

    if (search(head, 'c') == 1) {
        printf("Character c found.\n");
    } else {
        printf("Character c not found.\n");
    }

    return 0;
}