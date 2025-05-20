//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *next;
} Node;

Node* createNode(int data) {
    Node *newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(EXIT_FAILURE);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtHead(Node **head, int data) {
    Node *newNode = createNode(data);
    newNode->next = *head;
    *head = newNode;
}

void displayList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void deleteNode(Node **head, int key) {
    Node *temp = *head, *prev;

    if (temp != NULL && temp->data == key) {
        *head = temp->next;
        free(temp);
        return;
    }

    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) return;

    prev->next = temp->next;
    free(temp);
}

void reverseList(Node **head) {
    Node *prev = NULL, *current = *head, *next;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    *head = prev;
}

void freeList(Node **head) {
    Node *temp = *head;
    while (*head != NULL) {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
}

int main() {
    Node *head = NULL;

    // Create and insert 5 integers
    for (int i = 0; i < 5; i++)
        insertAtHead(&head, i + 1);

    // Display the list
    printf("Original list: ");
    displayList(head);

    // Delete the first occurrence of integer 3
    deleteNode(&head, 3);

    // Display the list after deletion
    printf("List after deleting 3: ");
    displayList(head);

    // Reverse the linked list
    reverseList(&head);

    // Display the reversed list
    printf("Reversed list: ");
    displayList(head);

    // Delete the linked list
    freeList(&head);

    return 0;
}