//Falcon-180B DATASET v1.0 Category: Memory management ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    void* data;
    size_t size;
    struct Node* next;
} Node;

Node* createNode(void* data, size_t size) {
    Node* node = malloc(sizeof(Node));
    if (node == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    node->data = data;
    node->size = size;
    node->next = NULL;
    return node;
}

void addNode(Node** head, void* data, size_t size) {
    Node* node = createNode(data, size);
    Node* temp = *head;
    if (*head == NULL) {
        *head = node;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = node;
}

void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("Data: %p, Size: %zu\n", temp->data, temp->size);
        temp = temp->next;
    }
}

void freeList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        free(temp->data);
        Node* next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node* head = NULL;
    addNode(&head, "Hello", 6);
    addNode(&head, "World", 5);
    printList(head);
    freeList(head);
    return 0;
}