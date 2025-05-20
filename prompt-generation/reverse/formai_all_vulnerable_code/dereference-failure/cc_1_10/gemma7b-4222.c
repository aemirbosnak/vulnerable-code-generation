//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
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
    char previousData = '\0';

    while (current) {
        if (previousData == current->data) {
            count++;
        } else {
            if (previous) {
                previous->next = insertAtTail(previous->next, count);
            }

            previousData = current->data;
            count = 1;
        }

        current = current->next;
    }

    if (previous) {
        previous->next = insertAtTail(previous->next, count);
    }
}

int main() {
    struct Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'c');

    compress(head);

    struct Node* iterator = head;
    while (iterator) {
        printf("%c ", iterator->data);
        iterator = iterator->next;
    }

    return 0;
}