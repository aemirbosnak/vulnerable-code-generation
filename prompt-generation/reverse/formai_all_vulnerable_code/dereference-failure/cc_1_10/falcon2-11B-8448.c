//Falcon2-11B DATASET v1.0 Category: Linked list operations ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

// Define the Node structure
struct Node {
    int data;
    struct Node* next;
};

// Define the LinkedList structure
struct LinkedList {
    struct Node* head;
};

// Function to create a new Node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new Node to the LinkedList
void addNode(struct LinkedList* list, int data) {
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
}

// Function to print the LinkedList
void printList(struct LinkedList* list) {
    struct Node* current = list->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Function to remove a Node from the LinkedList
void removeNode(struct LinkedList* list, int data) {
    struct Node* current = list->head;
    struct Node* previous = NULL;
    while (current!= NULL && current->data!= data) {
        previous = current;
        current = current->next;
    }
    if (current!= NULL) {
        if (previous == NULL) {
            list->head = current->next;
        } else {
            previous->next = current->next;
        }
        free(current);
    }
}

// Function to reverse the LinkedList
void reverseList(struct LinkedList* list) {
    struct Node* current = list->head;
    struct Node* previous = NULL;
    struct Node* nextNode = NULL;
    while (current!= NULL) {
        nextNode = current->next;
        current->next = previous;
        previous = current;
        current = nextNode;
    }
    list->head = previous;
}

int main() {
    struct LinkedList* list = (struct LinkedList*) malloc(sizeof(struct LinkedList));
    list->head = NULL;
    
    // Add some nodes to the LinkedList
    addNode(list, 5);
    addNode(list, 10);
    addNode(list, 15);
    
    // Print the LinkedList
    printf("Original LinkedList: ");
    printList(list);
    
    // Remove a Node from the LinkedList
    removeNode(list, 10);
    
    // Print the updated LinkedList
    printf("Updated LinkedList: ");
    printList(list);
    
    // Reverse the LinkedList
    reverseList(list);
    
    // Print the reversed LinkedList
    printf("Reversed LinkedList: ");
    printList(list);
    
    return 0;
}