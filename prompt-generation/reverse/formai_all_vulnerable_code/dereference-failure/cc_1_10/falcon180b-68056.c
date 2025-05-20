//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data[MAX_SIZE];
    struct node* next;
} Node;

Node* createNode(char* data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(1);
    }
    strcpy(newNode->data, data);
    newNode->next = NULL;
    return newNode;
}

// Function to add element in the linked list
void addElement(Node** head, char* data) {
    Node* newNode = createNode(data);
    Node* temp = *head;
    if (*head == NULL) {
        newNode->next = NULL;
        *head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
    return;
}

// Function to search element in the linked list
Node* searchElement(Node* head, char* data) {
    Node* current = head;
    while (current!= NULL) {
        if (strcmp(current->data, data) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

// Function to print the linked list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    Node* head = NULL;

    // Adding elements to the linked list
    addElement(&head, "The");
    addElement(&head, "Adventure");
    addElement(&head, "of");
    addElement(&head, "the");
    addElement(&head, "Speckled");
    addElement(&head, "Band");

    // Searching for an element in the linked list
    Node* result = searchElement(head, "Speckled");
    if (result!= NULL) {
        printf("Element found at position %d\n", (int)(result - head + 1));
    } else {
        printf("Element not found\n");
    }

    // Printing the linked list
    printf("Linked List: ");
    printList(head);

    return 0;
}