//Gemma-7B DATASET v1.0 Category: Memory management ; Style: Claude Shannon
#include <stdlib.h>
#include <stdio.h>

#define BLOCK_SIZE 16

struct Node {
    struct Node* next;
    void* data;
};

typedef struct Node Node;

Node* createNode() {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->next = NULL;
    newNode->data = NULL;

    return newNode;
}

void insertAtTail(Node* head, void* data) {
    Node* newNode = createNode();
    newNode->data = data;

    if (head == NULL) {
        head = newNode;
    } else {
        head->next = newNode;
    }
}

void traverse(Node* head) {
    Node* current = head;
    while (current) {
        printf("%p ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    Node* head = NULL;

    insertAtTail(head, (void*)10);
    insertAtTail(head, (void*)20);
    insertAtTail(head, (void*)30);
    insertAtTail(head, (void*)40);
    insertAtTail(head, (void*)50);

    traverse(head);

    return 0;
}