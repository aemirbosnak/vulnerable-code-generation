//FormAI DATASET v1.0 Category: Data structures visualization ; Style: complex
#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
} Node;

// Initialize the list
void initList(Node** head) {
    *head = NULL;
}

// Insert a new node at the beginning of the list
void insertAtBeginning(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}

// Insert a new node after a given node in the list
void insertAfter(Node* prev, int data) {
    if (prev == NULL) {
        printf("Previous node cannot be null");
        return;
    }
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = prev->next;
    prev->next = newNode;
}

// Insert a new node at the end of the list
void insertAtEnd(Node** head, int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    Node* last = *head;
    newNode->data = data;
    newNode->next = NULL;
    if (*head == NULL) {
        *head = newNode;
        return;
    }
    while (last->next != NULL) {
        last = last->next;
    }
    last->next = newNode;
    return;
}

// Delete a node from the list given its key
void deleteNodeByKey(Node** head, int key) {
    Node* temp = *head, *prev;
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
        printf("Node with key %d not found in list", key);
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Delete a node from the list given its position
void deleteNodeByIndex(Node** head, int index) {
    Node* temp = *head, *prev;
    if (index == 0) {
        *head = temp->next;
        free(temp);
        return;
    }
    for (int i = 0; temp != NULL && i < index; i++) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Index out of bounds");
        return;
    }
    prev->next = temp->next;
    free(temp);
}

// Print the list
void printList(Node* head) {
    printf("[ ");
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("]\n");
}

int main() {
    Node* head;
    initList(&head);
    insertAtEnd(&head, 5);
    insertAtBeginning(&head, 3);
    insertAfter(head->next, 4);
    printf("Initial List: ");
    printList(head);
    deleteNodeByIndex(&head, 2);
    deleteNodeByKey(&head, 3);
    printf("List after deletion: ");
    printList(head);
    return 0;
}