//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the LinkedList structure
struct LinkedList {
    struct Node* head;
    int size;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node at the beginning of the linked list
void push(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->size++;
}

// Function to add a node at the end of the linked list
void append(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
    list->size++;
}

// Function to delete a node from the linked list
void deleteNode(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    struct Node* previous = NULL;
    if (list->head!= NULL) {
        while (current->data!= data && current->next!= NULL) {
            previous = current;
            current = current->next;
        }
        if (current->next == NULL) {
            previous->next = NULL;
            free(current);
            list->size--;
        } else {
            previous->next = current->next;
            free(current);
            list->size--;
        }
    }
}

// Function to print the linked list
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%d -> ", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    struct LinkedList* list = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    list->head = NULL;
    list->size = 0;

    // Create and print an empty linked list
    push(list, 1);
    push(list, 2);
    push(list, 3);
    printf("Linked list before deleting node 2: ");
    printList(list);

    // Delete node 2
    deleteNode(list, 2);

    // Create and print a linked list after deleting node 2
    push(list, 1);
    push(list, 2);
    push(list, 3);
    printf("Linked list after deleting node 2: ");
    printList(list);

    return 0;
}