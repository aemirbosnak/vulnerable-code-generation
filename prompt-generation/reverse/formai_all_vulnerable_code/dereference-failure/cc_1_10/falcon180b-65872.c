//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Define the structure of a node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of a linked list
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Create a new node with the given data
Node* createNode(int data) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->data = data;
    node->next = NULL;
    return node;
}

// Create a new linked list
LinkedList* createLinkedList() {
    LinkedList* list = (LinkedList*)malloc(sizeof(LinkedList));
    list->head = NULL;
    list->size = 0;
    return list;
}

// Add a node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* node = createNode(data);
    if (list->head == NULL) {
        list->head = node;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = node;
    }
    list->size++;
}

// Print the linked list
void printList(LinkedList* list) {
    printf("Linked List:\n");
    Node* temp = list->head;
    int i = 0;
    while (temp!= NULL) {
        printf("Node %d: %d\n", i++, temp->data);
        temp = temp->next;
    }
}

// Main function
int main() {
    LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    addNode(list, 4);
    addNode(list, 5);
    printList(list);
    return 0;
}