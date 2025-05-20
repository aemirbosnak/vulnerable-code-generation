//Gemma-7B DATASET v1.0 Category: Searching algorithm ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

int search(Node* head, char data) {
    while (head) {
        if (head->data == data) {
            return 1;
        } else {
            head = head->next;
        }
    }

    return 0;
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');

    if (search(head, 'c') == 1) {
        printf("Data found.\n");
    } else {
        printf("Data not found.\n");
    }

    return 0;
}