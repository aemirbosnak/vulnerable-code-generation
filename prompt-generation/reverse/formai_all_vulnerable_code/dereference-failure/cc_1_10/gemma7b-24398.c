//Gemma-7B DATASET v1.0 Category: Maze Route Finder ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insertAtTail(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = head;

    if (head == NULL) {
        head = newNode;
    } else {
        head->prev->next = newNode;
    }
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
    insertAtTail(head, 'd');
    insertAtTail(head, 'e');

    printList(head);

    // Find the route from a to d
    Node* current = head;
    while (current) {
        if (current->data == 'a') {
            current = current->next;
            while (current && current->data != 'd') {
                printf("%c ", current->data);
                current = current->next;
            }
            printf("%c ", current->data);
        }
    }

    return 0;
}