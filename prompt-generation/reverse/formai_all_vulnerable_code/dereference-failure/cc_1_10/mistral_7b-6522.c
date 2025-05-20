//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 50

typedef struct Node {
    char data[MAX_LEN];
    struct Node *next;
} Node;

Node* createNode(char str[]) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->data, str);
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(Node** head, char str[]) {
    Node* newNode = createNode(str);
    newNode->next = *head;
    *head = newNode;
}

void insertAtEnd(Node** head, char str[]) {
    Node* newNode = createNode(str);

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* last = *head;
    while (last->next != NULL)
        last = last->next;

    last->next = newNode;
}

void deleteNode(Node** head, char str[]) {
    Node *current = *head, *previous = NULL;

    while (current != NULL && strcmp(current->data, str) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL)
        return;

    if (previous == NULL)
        *head = current->next;
    else
        previous->next = current->next;

    free(current);
}

void displayList(Node* node) {
    if (node != NULL) {
        printf("%s -> ", node->data);
        displayList(node->next);
    }
}

int main() {
    Node* head = NULL;

    insertAtBeginning(&head, "Apple");
    insertAtEnd(&head, "Banana");
    insertAtBeginning(&head, "Mango");
    insertAtEnd(&head, "Orange");

    printf("Linked List: ");
    displayList(head);
    printf("\n");

    deleteNode(&head, "Mango");
    printf("After deleting 'Mango': ");
    displayList(head);
    printf("\n");

    return 0;
}