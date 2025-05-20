//Gemma-7B DATASET v1.0 Category: Sorting ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->next = newNode;
    }
}

void sortByData(Node** head) {
    Node* current = *head;
    Node* sortedHead = NULL;

    while (current) {
        Node* next = current->next;
        current->next = sortedHead;
        sortedHead = current;
        current = next;
    }

    *head = sortedHead;
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'e');
    insertAtTail(&head, 'b');

    sortByData(&head);

    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");

    return 0;
}