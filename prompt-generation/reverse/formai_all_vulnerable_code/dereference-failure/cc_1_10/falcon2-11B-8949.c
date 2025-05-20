//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: excited
#include <stdio.h>
#include <stdlib.h>

// Define Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define Linked List structure
struct List {
    struct Node* head;
    struct Node* tail;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to create a new Linked List
struct List* createList() {
    struct List* list = (struct List*)malloc(sizeof(struct List));
    list->head = NULL;
    list->tail = NULL;
    return list;
}

// Function to insert an element at the beginning of the Linked List
void insertAtBeginning(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = list->head;
    list->head = newNode;
    list->tail = newNode;
}

// Function to insert an element at the end of the Linked List
void insertAtEnd(struct List* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        struct Node* current = list->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
        list->tail = newNode;
    }
}

// Function to delete an element from the Linked List
void deleteNode(struct List* list, int data) {
    struct Node* current = list->head;
    struct Node* prev = NULL;

    while (current!= NULL) {
        if (current->data == data) {
            if (prev == NULL) {
                list->head = current->next;
                free(current);
                return;
            } else {
                prev->next = current->next;
                free(current);
                return;
            }
        }
        prev = current;
        current = current->next;
    }
}

// Function to search an element in the Linked List
int search(struct List* list, int data) {
    struct Node* current = list->head;

    while (current!= NULL) {
        if (current->data == data) {
            return 1;
        }
        current = current->next;
    }

    return 0;
}

// Function to print the Linked List
void printList(struct List* list) {
    struct Node* current = list->head;

    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to free the memory allocated for the Linked List
void freeList(struct List* list) {
    struct Node* current = list->head;

    while (current!= NULL) {
        struct Node* temp = current->next;
        free(current);
        current = temp;
    }

    free(list);
}

// Main function
int main() {
    struct List* list = createList();

    // Insert elements at the beginning
    insertAtBeginning(list, 10);
    insertAtBeginning(list, 20);
    insertAtBeginning(list, 30);

    // Insert elements at the end
    insertAtEnd(list, 40);
    insertAtEnd(list, 50);

    // Search for an element
    if (search(list, 30) == 1) {
        printf("Element found\n");
    } else {
        printf("Element not found\n");
    }

    // Delete an element
    deleteNode(list, 30);

    // Print the Linked List
    printList(list);

    // Free the memory allocated for the Linked List
    freeList(list);

    return 0;
}