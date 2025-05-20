//FormAI DATASET v1.0 Category: Data structures visualization ; Style: curious
#include <stdio.h>
#include <stdlib.h>

// Define a new datatype called Node to represent a node in our data structure
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a new datatype called LinkedList to represent our data structure
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Function to add a new node to the end of the linked list
void addNode(LinkedList* list, int data) {
    // Create a new node to hold the data
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    // "Attach" the new node to the end of the list
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* currentNode = list->head;
        while (currentNode->next != NULL) {
            currentNode = currentNode->next;
        }
        currentNode->next = newNode;
    }
}

// Function to print the current state of the linked list
void printList(LinkedList* list) {
    Node* currentNode = list->head;
    printf("Current state of linked list: ");
    while (currentNode != NULL) {
        printf("%d ", currentNode->data);
        currentNode = currentNode->next;
    }
    printf("\n");
}

int main() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;

    // Add some nodes to the list
    addNode(list, 5);
    printList(list);

    addNode(list, 10);
    printList(list);

    addNode(list, 15);
    printList(list);

    addNode(list, 20);
    printList(list);

    // Free memory allocated for list nodes
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* temp = currentNode;
        currentNode = currentNode->next;
        free(temp);
    }

    free(list);

    return 0;
}