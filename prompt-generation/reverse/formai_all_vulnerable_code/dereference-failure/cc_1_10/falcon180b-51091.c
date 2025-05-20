//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of a linked list
typedef struct list {
    Node* head;
    Node* tail;
    int size;
} List;

// Function to create a new node
Node* createNode(int data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a new linked list
List* createList() {
    List* newList = (List*) malloc(sizeof(List));
    newList->head = NULL;
    newList->tail = NULL;
    newList->size = 0;
    return newList;
}

// Function to add a node to the end of a linked list
void addNode(List* list, int data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
        list->tail = newNode;
    } else {
        list->tail->next = newNode;
        list->tail = newNode;
    }
    list->size++;
}

// Function to search for a node in a linked list
Node* searchList(List* list, int data) {
    Node* currNode = list->head;
    while (currNode!= NULL) {
        if (currNode->data == data) {
            return currNode;
        }
        currNode = currNode->next;
    }
    return NULL;
}

// Function to display the contents of a linked list
void displayList(List* list) {
    printf("List: ");
    Node* currNode = list->head;
    while (currNode!= NULL) {
        printf("%d ", currNode->data);
        currNode = currNode->next;
    }
    printf("\n");
}

int main() {
    // Create a new linked list
    List* myList = createList();

    // Add some nodes to the list
    addNode(myList, 5);
    addNode(myList, 10);
    addNode(myList, 15);

    // Display the contents of the list
    displayList(myList);

    // Search for a node in the list
    Node* foundNode = searchList(myList, 10);
    if (foundNode!= NULL) {
        printf("Node found with data %d\n", foundNode->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}