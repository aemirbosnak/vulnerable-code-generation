//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define structure for a node
struct Node {
    int data;
    struct Node* next;
};

// Define structure for a linked list
struct LinkedList {
    struct Node* head;
    int size;
};

// Function to create a new node with given data
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create an empty linked list
struct LinkedList* createLinkedList() {
    struct LinkedList* newList = (struct LinkedList*)malloc(sizeof(struct LinkedList));
    newList->head = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node at the end of the list
void addNode(struct LinkedList* list, int data) {
    struct Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        struct Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to remove a node with given data from the list
void removeNode(struct LinkedList* list, int data) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if (list->head->data == data) {
        struct Node* temp = list->head;
        list->head = list->head->next;
        free(temp);
        list->size--;
        return;
    }
    struct Node* temp = list->head;
    while (temp->next!= NULL && temp->next->data!= data) {
        temp = temp->next;
    }
    if (temp->next == NULL) {
        printf("Node not found.\n");
    } else {
        struct Node* nodeToRemove = temp->next;
        temp->next = temp->next->next;
        free(nodeToRemove);
        list->size--;
    }
}

// Function to display the contents of the list
void displayList(struct LinkedList* list) {
    if (list->head == NULL) {
        printf("List is empty.\n");
        return;
    }
    printf("List: ");
    struct Node* temp = list->head;
    while (temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Main function
int main() {
    struct LinkedList* list = createLinkedList();
    addNode(list, 1);
    addNode(list, 2);
    addNode(list, 3);
    displayList(list);
    removeNode(list, 2);
    displayList(list);
    return 0;
}