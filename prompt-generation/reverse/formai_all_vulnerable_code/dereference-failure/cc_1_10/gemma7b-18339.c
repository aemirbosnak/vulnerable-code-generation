//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: complex
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
    char previousCharacter = '\0';
    int count = 1;

    while (current) {
        if (previousCharacter == current->data) {
            count++;
        } else {
            if (previousCharacter) {
                printf("%c%d ", previousCharacter, count);
            }
            previousCharacter = current->data;
            count = 1;
        }

        current = current->next;
    }

    if (previousCharacter) {
        printf("%c%d ", previousCharacter, count);
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

    return 0;
}