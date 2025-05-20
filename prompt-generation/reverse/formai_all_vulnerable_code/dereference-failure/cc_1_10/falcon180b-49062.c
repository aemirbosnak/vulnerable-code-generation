//Falcon-180B DATASET v1.0 Category: Database simulation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

// Node structure for the linked list
typedef struct node {
    char name[MAX_SIZE];
    int age;
    struct node* next;
} Node;

// Function to create a new node
Node* createNode(char* name, int age) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->age = age;
    newNode->next = NULL;
    return newNode;
}

// Function to add a node to the end of the list
void addNode(Node* head, char* name, int age) {
    Node* newNode = createNode(name, age);
    Node* temp = head;
    if (head == NULL) {
        head = newNode;
        return;
    }
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to delete a node by name
void deleteNode(Node* head, char* name) {
    Node* temp = head;
    Node* prev = NULL;
    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        prev = temp;
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Node not found\n");
        return;
    }
    if (prev == NULL) {
        head = temp->next;
    } else {
        prev->next = temp->next;
    }
    free(temp);
}

// Function to search for a node by name
Node* searchNode(Node* head, char* name) {
    Node* temp = head;
    while (temp!= NULL && strcmp(temp->name, name)!= 0) {
        temp = temp->next;
    }
    return temp;
}

// Function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp!= NULL) {
        printf("%s %d\n", temp->name, temp->age);
        temp = temp->next;
    }
}

int main() {
    Node* head = NULL;

    // Add some nodes
    addNode(head, "John", 25);
    addNode(head, "Jane", 30);
    addNode(head, "Bob", 20);

    // Print the list
    printList(head);

    // Delete a node
    deleteNode(head, "Bob");

    // Print the list again
    printList(head);

    return 0;
}