//Gemma-7B DATASET v1.0 Category: Database Indexing System ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data[MAX_SIZE];
    struct Node* next;
} Node;

void insert(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data[0] = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
        *head = newNode;
    }
}

void search(Node* head, char data) {
    while (head) {
        if (head->data[0] == data) {
            printf("Data found: %c\n", data);
            return;
        } else {
            head = head->next;
        }
    }

    printf("Data not found: %c\n", data);
}

int main() {
    Node* head = NULL;

    insert(&head, 'a');
    insert(&head, 'b');
    insert(&head, 'c');
    insert(&head, 'd');
    insert(&head, 'e');

    search(head, 'c');
    search(head, 'f');

    return 0;
}