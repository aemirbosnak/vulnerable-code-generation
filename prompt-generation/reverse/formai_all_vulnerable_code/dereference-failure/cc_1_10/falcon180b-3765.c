//Falcon-180B DATASET v1.0 Category: Data structures visualization ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the maximum size of the data structure
#define MAX_SIZE 100

// Define the structure of a node
typedef struct node {
    int data;
    struct node* next;
} Node;

// Define the structure of the data structure
typedef struct {
    Node* head;
    int size;
} DataStructure;

// Initialize the data structure with an empty list
void init(DataStructure* ds) {
    ds->head = NULL;
    ds->size = 0;
}

// Add a new node to the end of the list
void addNode(DataStructure* ds, int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->next = NULL;

    if (ds->head == NULL) {
        ds->head = newNode;
    } else {
        Node* current = ds->head;
        while (current->next!= NULL) {
            current = current->next;
        }
        current->next = newNode;
    }

    ds->size++;
}

// Remove a node from the list
void removeNode(DataStructure* ds, int data) {
    if (ds->head == NULL) {
        printf("List is empty\n");
        return;
    }

    if (ds->head->data == data) {
        Node* temp = ds->head;
        ds->head = ds->head->next;
        free(temp);
        ds->size--;
        return;
    }

    Node* current = ds->head;
    while (current->next!= NULL && current->next->data!= data) {
        current = current->next;
    }

    if (current->next == NULL) {
        printf("Node not found\n");
    } else {
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
        ds->size--;
    }
}

// Print the contents of the list
void printList(DataStructure* ds) {
    if (ds->head == NULL) {
        printf("List is empty\n");
        return;
    }

    Node* current = ds->head;
    while (current!= NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

// Main function
int main() {
    DataStructure ds;
    init(&ds);

    addNode(&ds, 10);
    addNode(&ds, 20);
    addNode(&ds, 30);
    addNode(&ds, 40);

    printList(&ds);

    removeNode(&ds, 20);

    printList(&ds);

    return 0;
}