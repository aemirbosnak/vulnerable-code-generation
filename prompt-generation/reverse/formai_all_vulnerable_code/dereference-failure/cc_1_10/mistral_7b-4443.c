//MISTRAL-7B DATASET v1.0 Category: Linked list operations ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct Node {
    char name[30];
    int happiness;
    struct Node *next;
} Node;

Node *head = NULL;

// Function to create a new node
Node *createNode(char *name, int happiness) {
    Node *newNode = (Node *)malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->happiness = happiness;
    newNode->next = NULL;
    return newNode;
}

// Function to add a new node at the end of the list
void addNode(Node *newNode) {
    if (head == NULL) {
        head = newNode;
    } else {
        Node *lastNode = head;
        while (lastNode->next != NULL) {
            lastNode = lastNode->next;
        }
        lastNode->next = newNode;
    }
}

// Function to print the list in a happy way
void printList() {
    Node *currentNode = head;
    printf("\n===\nHappy Linked List:\n===\n");
    while (currentNode != NULL) {
        printf("%s is %d units happy.\n", currentNode->name, currentNode->happiness);
        currentNode = currentNode->next;
    }
    printf("======================\n");
}

// Function to add happiness to a node
void addHappiness(Node *node, int units) {
    node->happiness += units;
}

// Function to remove a node from the list by name
Node *removeNode(char *name) {
    Node *currentNode = head;
    Node *previousNode = NULL;

    if (head == NULL) {
        return NULL;
    }

    if (strcmp(head->name, name) == 0) {
        head = head->next;
        free(currentNode);
        return head;
    }

    while (currentNode != NULL && strcmp(currentNode->name, name) != 0) {
        previousNode = currentNode;
        currentNode = currentNode->next;
    }

    if (currentNode == NULL) {
        return NULL;
    }

    previousNode->next = currentNode->next;
    free(currentNode);

    return previousNode;
}

int main() {
    // Create some initial nodes
    Node *john = createNode("John", 5);
    Node *jane = createNode("Jane", 7);
    Node *bob = createNode("Bob", 3);

    // Add nodes to the list
    addNode(john);
    addNode(jane);
    addNode(bob);

    // Print the list
    printList();

    // Add happiness to a node
    addHappiness(jane, 3);

    // Print the list again
    printList();

    // Remove a node from the list
    Node *bobNode = removeNode("Bob");

    // Print the list once more
    printList();

    return 0;
}