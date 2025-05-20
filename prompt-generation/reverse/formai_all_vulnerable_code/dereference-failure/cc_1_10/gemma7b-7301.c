//Gemma-7B DATASET v1.0 Category: Huffman Coding Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

struct Node* insertAtTail(struct Node* head, char data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    newNode->prev = head;

    if (head == NULL) {
        head = newNode;
    } else {
        head->prev = newNode;
        head = newNode;
    }

    return head;
}

void traverse(struct Node* head) {
    struct Node* current = head;

    while (current) {
        printf("%c ", current->data);
        current = current->next;
    }

    printf("\n");
}

int main() {
    struct Node* head = NULL;

    insertAtTail(head, 'a');
    insertAtTail(head, 'b');
    insertAtTail(head, 'c');
    insertAtTail(head, 'a');
    insertAtTail(head, 'b');

    traverse(head);

    return 0;
}