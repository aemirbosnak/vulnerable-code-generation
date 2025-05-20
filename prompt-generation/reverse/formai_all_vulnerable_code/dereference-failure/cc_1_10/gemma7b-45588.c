//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

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

void compress(Node* head) {
    Node* current = head;
    Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                previous->next = insertAtTail(previous->next, count);
            }

            previous = current;
            count = 1;
        }

        current = current->next;
    }

    if (previous) {
        previous->next = insertAtTail(previous->next, count);
    }

    head = head->next;
    free(head);
}

int main() {
    Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');

    compress(head);

    head = head->next;
    while (head) {
        printf("%c ", head->data);
        head = head->next;
    }

    printf("\n");

    return 0;
}