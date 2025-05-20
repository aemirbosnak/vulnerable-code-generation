//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: configurable
#include <stdio.h>
#include <stdlib.h>

// Structure to represent a node in the graph
struct Node {
    int data;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to insert a new node at the beginning of the linked list
struct Node* insertNode(struct Node* head, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = head;
    return newNode;
}

// Function to print the graph
void printGraph(struct Node* head) {
    while (head!= NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

// Function to find the length of the linked list
int getLength(struct Node* head) {
    int count = 0;
    while (head!= NULL) {
        head = head->next;
        count++;
    }
    return count;
}

int main() {
    struct Node* head = NULL;

    // Insert nodes in the graph
    head = insertNode(head, 1);
    head = insertNode(head, 2);
    head = insertNode(head, 3);
    head = insertNode(head, 4);

    // Print the graph
    printf("Graph: ");
    printGraph(head);
    printf("Length of the graph: %d\n", getLength(head));

    return 0;
}