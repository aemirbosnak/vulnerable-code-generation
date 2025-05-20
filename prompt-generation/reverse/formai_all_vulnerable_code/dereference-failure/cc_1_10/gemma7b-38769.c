//Gemma-7B DATASET v1.0 Category: Graph representation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define a node structure for the graph
typedef struct Node {
    char name[20];
    struct Node* next;
    struct Node* prev;
    int visited;
} Node;

// Create a graph
void createGraph(Node** head) {
    *head = NULL;
}

// Add a node to the graph
void addNode(Node** head, char* name) {
    Node* newNode = malloc(sizeof(Node));
    strcpy(newNode->name, name);
    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->visited = 0;

    if (*head == NULL) {
        *head = newNode;
    } else {
        (*head)->prev = newNode;
        *head = newNode;
    }
}

// Traverse the graph
void traverseGraph(Node* head) {
    while (head) {
        printf("%s ", head->name);
        head->visited = 1;
        if (head->next) {
            head = head->next;
        } else {
            head = head->prev;
        }
    }
}

int main() {
    Node* head = NULL;
    createGraph(&head);
    addNode(head, "A");
    addNode(head, "B");
    addNode(head, "C");
    addNode(head, "D");
    traverseGraph(head);

    return 0;
}