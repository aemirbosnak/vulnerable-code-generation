//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }

    return head;
}

void compress(struct Node* head) {
    struct Node* current = head;
    struct Node* previous = NULL;
    int count = 1;

    while (current) {
        if (previous && current->data == previous->data) {
            count++;
        } else {
            if (previous) {
                insertAtTail(head, previous->data)  -> data = count;
            }
            previous = current;
            count = 1;
        }
        current = current->next;
    }

    if (previous) {
        insertAtTail(head, previous->data)  -> data = count;
    }

    return;
}

int main() {
    struct Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'c');

    compress(head);

    struct Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}