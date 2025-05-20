//Falcon-180B DATASET v1.0 Category: Linked list operations ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the structure of the node
typedef struct Node {
    int data;
    struct Node* next;
} Node;

// Define the structure of the linked list
typedef struct LinkedList {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
LinkedList* createLinkedList() {
    LinkedList* newList = (LinkedList*)malloc(sizeof(LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node to the end of the linked list
void addNode(LinkedList* list, int data) {
    Node* newNode = createNode(data);
    Node* temp = list->head;
    if (list->head == NULL) {
        list->head = newNode;
    }
    else {
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to remove a node from the linked list
bool removeNode(LinkedList* list, int data) {
    Node* temp = list->head;
    if (temp == NULL) {
        return false;
    }
    if (temp->data == data) {
        list->head = temp->next;
        free(temp);
        list->size--;
        return true;
    }
    while (temp->next!= NULL) {
        if (temp->next->data == data) {
            Node* nodeToRemove = temp->next;
            temp->next = temp->next->next;
            free(nodeToRemove);
            list->size--;
            return true;
        }
        temp = temp->next;
    }
    return false;
}

// Function to print the linked list
void printList(LinkedList* list) {
    Node* temp = list->head;
    printf("Linked List: ");
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function to test the linked list operations
int main() {
    LinkedList* myList = createLinkedList();
    addNode(myList, 10);
    addNode(myList, 20);
    addNode(myList, 30);
    printList(myList);
    removeNode(myList, 20);
    printList(myList);
    return 0;
}