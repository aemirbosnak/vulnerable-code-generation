//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node {
    char data[10];
    struct Node* next;
} Node;

Node* createNode(const char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

Node* addNodeAtBeginning(Node** head, const char* data) {
    Node* newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void displayList(const Node* node) {
    while (node != NULL) {
        printf("%s -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void destroyList(Node** head) {
    Node* current = *head;
    while (current != NULL) {
        Node* next = current->next;
        free(current);
        current = next;
    }
    *head = NULL;
}

int main() {
    Node* head = NULL;

    addNodeAtBeginning(&head, "Apple");
    addNodeAtBeginning(&head, "Banana");
    addNodeAtBeginning(&head, "Cherry");

    displayList(head);

    destroyList(&head);

    return 0;
}