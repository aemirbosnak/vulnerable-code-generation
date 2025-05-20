//Gemma-7B DATASET v1.0 Category: Database simulation ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void printList(Node* head) {
    Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');

    printList(head);

    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    printList(head);

    return 0;
}