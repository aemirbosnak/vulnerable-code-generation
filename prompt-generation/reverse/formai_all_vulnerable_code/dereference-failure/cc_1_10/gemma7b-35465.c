//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 10

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertAtTail(Node** head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        (*head)->next = newNode;
        *head = newNode;
    }
}

void printList(Node* head) {
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;
    insertAtTail(&head, 'a');
    insertAtTail(&head, 'b');
    insertAtTail(&head, 'c');
    insertAtTail(&head, 'd');

    printList(head);

    // Find the route from a to d
    Node* current = head;
    while (current && current->data != 'd') {
        current = current->next;
    }

    // Print the route
    Node* previous = NULL;
    current = head;
    while (current && current->data != 'd') {
        if (previous) {
            printf("%c ", previous->data);
        }
        previous = current;
        current = current->next;
    }

    printf("%c\n", previous->data);

    return 0;
}