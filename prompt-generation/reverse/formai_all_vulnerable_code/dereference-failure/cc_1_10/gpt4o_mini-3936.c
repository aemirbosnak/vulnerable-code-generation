//GPT-4o-mini DATASET v1.0 Category: Linked list operations ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (!newNode) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void append(Node** head, int newData) {
    Node* newNode = createNode(newData);
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    Node* last = *head;
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
}

void insertAtBeginning(Node** head, int newData) {
    Node* newNode = createNode(newData);
    newNode->next = *head;
    *head = newNode;
}

void insertAfter(Node* prevNode, int newData) {
    if (prevNode == NULL) {
        fprintf(stderr, "Previous node cannot be NULL\n");
        return;
    }
    Node* newNode = createNode(newData);
    newNode->next = prevNode->next;
    prevNode->next = newNode;
}

void deleteNode(Node** head, int key) {
    Node* temp = *head, *prev = NULL;
    
    if (temp != NULL && temp->data == key) {
        *head = temp->next; 
        free(temp); 
        return;
    }
    
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }
    
    if (temp == NULL) {
        fprintf(stderr, "Key not found\n");
        return;
    }
    
    prev->next = temp->next;
    free(temp);
}

void printList(Node* node) {
    while (node != NULL) {
        printf("%d -> ", node->data);
        node = node->next;
    }
    printf("NULL\n");
}

void freeList(Node* node) {
    Node* temp;
    while (node != NULL) {
        temp = node;
        node = node->next;
        free(temp);
    }
}

int main() {
    Node* head = NULL;

    append(&head, 10);
    append(&head, 20);
    append(&head, 30);
    printf("Initial list: ");
    printList(head);

    insertAtBeginning(&head, 5);
    printf("After inserting 5 at the beginning: ");
    printList(head);

    insertAfter(head->next, 15);
    printf("After inserting 15 after the second node: ");
    printList(head);

    deleteNode(&head, 20);
    printf("After deleting 20: ");
    printList(head);

    deleteNode(&head, 5);
    printf("After deleting 5: ");
    printList(head);

    deleteNode(&head, 100); // Trying to delete a non-existent node

    freeList(head);
    head = NULL;
    return 0;
}