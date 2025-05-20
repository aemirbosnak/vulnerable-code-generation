//Gemma-7B DATASET v1.0 Category: Network Topology Mapper ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <netdb.h>
#include <unistd.h>

#define MAX_CONNECTIONS 10

typedef struct Node {
    char name[256];
    int connections[MAX_CONNECTIONS];
    struct Node* next;
} Node;

int main() {
    Node* head = NULL;
    Node* newNode = NULL;

    // Create a new node
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, "Alice");
    newNode->connections[0] = 1;
    newNode->connections[1] = 3;
    newNode->next = NULL;

    // Add the new node to the head of the list
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    // Create another new node
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, "Bob");
    newNode->connections[0] = 2;
    newNode->connections[1] = 4;
    newNode->next = NULL;

    // Add the new node to the head of the list
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    // Create a third new node
    newNode = (Node*)malloc(sizeof(Node));
    strcpy(newNode->name, "Charlie");
    newNode->connections[0] = 3;
    newNode->connections[1] = 5;
    newNode->next = NULL;

    // Add the new node to the head of the list
    if (head == NULL) {
        head = newNode;
    } else {
        newNode->next = head;
        head = newNode;
    }

    // Print the topology of the network
    for (Node* current = head; current; current = current->next) {
        printf("%s is connected to:", current->name);
        for (int i = 0; i < current->connections[0]; i++) {
            printf(" %s", current->connections[i + 1]);
        }
        printf("\n");
    }

    return 0;
}