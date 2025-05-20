//Gemma-7B DATASET v1.0 Category: Compression algorithms ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 1024

typedef struct Node {
    char data;
    struct Node* next;
} Node;

Node* insertAtTail(Node* head, char data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
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
            insertAtTail(previous, (count - 1) + 'a' - count);
            previous = current;
            count = 1;
        }
    }

    insertAtTail(previous, (count - 1) + 'a' - count);
}

int main() {
    Node* head = insertAtTail(NULL, 'a');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'a');
    insertAtTail(head, 'c');

    compress(head);

    Node* compressedHead = head;
    while (compressedHead) {
        printf("%c", compressedHead->data);
        compressedHead = compressedHead->next;
    }

    return 0;
}