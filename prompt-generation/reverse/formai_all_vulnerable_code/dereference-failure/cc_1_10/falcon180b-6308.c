//Falcon-180B DATASET v1.0 Category: Searching algorithm ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1000

// Node structure for linked list
typedef struct node {
    char data;
    struct node* next;
} Node;

// Linked list structure
typedef struct {
    Node* head;
    int size;
} LinkedList;

// Function to create a new node
Node* createNode(char data) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    if (newNode == NULL) {
        printf("Memory error\n");
        exit(0);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(LinkedList* list, char data) {
    Node* newNode = createNode(data);
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        Node* temp = list->head;
        while (temp->next!= NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
    }
    list->size++;
}

// Function to search for a node in the list
Node* searchNode(LinkedList* list, char data) {
    Node* temp = list->head;
    while (temp!= NULL) {
        if (temp->data == data) {
            return temp;
        }
        temp = temp->next;
    }
    return NULL;
}

// Function to print the list
void printList(LinkedList* list) {
    Node* temp = list->head;
    while (temp!= NULL) {
        printf("%c -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

// Main function
int main() {
    LinkedList list;
    list.head = NULL;
    list.size = 0;

    addNode(&list, 'a');
    addNode(&list, 'b');
    addNode(&list, 'c');

    printf("List after adding nodes:\n");
    printList(&list);

    Node* searchResult = searchNode(&list, 'b');
    if (searchResult!= NULL) {
        printf("Node found: %c\n", searchResult->data);
    } else {
        printf("Node not found\n");
    }

    return 0;
}