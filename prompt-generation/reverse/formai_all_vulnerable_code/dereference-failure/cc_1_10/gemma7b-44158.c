//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_BUFFER_SIZE 4096

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insert_at_tail(Node* head, char data) {
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
    char previousCharacter = '\0';
    int count = 1;
    Node* current = head;

    while (current) {
        if (previousCharacter == current->data) {
            count++;
        } else {
            printf("%c%d ", previousCharacter, count);
            previousCharacter = current->data;
            count = 1;
        }

        current = current->next;
    }

    printf("%c%d ", previousCharacter, count);
}

int main() {
    Node* head = insert_at_tail(NULL, 'a');
    insert_at_tail(head, 'a');
    insert_at_tail(head, 'b');
    insert_at_tail(head, 'b');
    insert_at_tail(head, 'c');
    insert_at_tail(head, 'c');

    compress(head);

    return 0;
}