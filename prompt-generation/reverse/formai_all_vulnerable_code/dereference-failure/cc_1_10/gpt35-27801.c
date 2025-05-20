//FormAI DATASET v1.0 Category: Data structures visualization ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Define a struct for the node in our linked list
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define a struct for the linked list
typedef struct LinkedList {
    Node* head;
} LinkedList;

// Create a new linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    return list;
}

// Add a new node to the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = list->head;
    list->head = newNode;
}

// Print the linked list to console
void printLinkedList(LinkedList* list) {
    Node* currentNode = list->head;
    
    while (currentNode != NULL) {
        printf("%d -> ", currentNode->data);
        currentNode = currentNode->next;
    }
    
    printf("NULL\n");
}

int main() {
    // Create a new linked list
    LinkedList* list = createLinkedList();
    
    // Add some nodes to the list
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    
    // Print the list to console
    printLinkedList(list);
    
    // Free up memory used by linked list and nodes
    Node* currentNode = list->head;
    while (currentNode != NULL) {
        Node* nextNode = currentNode->next;
        free(currentNode);
        currentNode = nextNode;
    }
    free(list);
    
    return 0;
}