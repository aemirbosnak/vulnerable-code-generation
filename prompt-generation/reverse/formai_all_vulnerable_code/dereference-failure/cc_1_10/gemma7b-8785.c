//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

struct Node* insert(struct Node* head, char data) {
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
                insert(head, previous->data);
                insert(head, count - 1);
            }

            previous = current;
            count = 1;
        }

        current = current->next;
    }

    if (previous) {
        insert(head, previous->data);
        insert(head, count - 1);
    }
}

int main() {
    struct Node* head = NULL;
    head = insert(head, 'a');
    head = insert(head, 'a');
    head = insert(head, 'b');
    head = insert(head, 'b');
    head = insert(head, 'c');

    compress(head);

    struct Node* current = head;
    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    return 0;
}