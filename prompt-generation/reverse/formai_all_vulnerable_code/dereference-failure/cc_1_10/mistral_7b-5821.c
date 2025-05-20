//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct Node {
    int data;
    char name[50];
    struct Node* next;
} Node;

Node* createNode(int data, char* name) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    strcpy(newNode->name, name);
    newNode->next = NULL;
    return newNode;
}

void printList(Node* head) {
    Node* current = head;
    while (current != NULL) {
        printf("Data: %d, Name: %s -> ", current->data, current->name);
        current = current->next;
    }
    printf("NULL\n");
}

void addNodeAtEnd(Node** head, int data, char* name) {
    Node* newNode = createNode(data, name);
    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

void deleteNode(Node** head, int data) {
    Node* current = *head;
    Node* previous = NULL;

    if (current != NULL && current->data == data) {
        *head = current->next;
        free(current);
        return;
    }

    while (current != NULL && current->data != data) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) {
        return;
    }

    previous->next = current->next;
    free(current);
}

int main() {
    Node* head = NULL;

    addNodeAtEnd(&head, 5, "Quincy");
    addNodeAtEnd(&head, 10, "Zorkon");
    addNodeAtEnd(&head, 15, "Neo");
    addNodeAtEnd(&head, 20, "Max");

    printList(head);

    deleteNode(&head, 10);

    printList(head);

    return 0;
}

// In the year 3010, we no longer use primitive integer data structures,
// instead we use advanced linked lists to store our data. This example
// demonstrates a linked list of nodes containing both an integer value
// and a futuristic name string.