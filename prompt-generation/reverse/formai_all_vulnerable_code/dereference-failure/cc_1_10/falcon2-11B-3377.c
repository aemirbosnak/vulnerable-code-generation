//Falcon2-11B DATASET v1.0 Category: Graph representation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Node structure for graph
struct node {
    int data;
    struct node* next;
};

// Function to add a node to the graph
void addNode(struct node** head, int data) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->data = data;
    newNode->next = NULL;
    struct node* temp = *head;
    while (temp->next!= NULL) {
        temp = temp->next;
    }
    temp->next = newNode;
}

// Function to print the graph
void printGraph(struct node* head) {
    struct node* temp = head;
    while (temp!= NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct node* head = NULL;

    // Add nodes to the graph
    addNode(&head, 1);
    addNode(&head, 2);
    addNode(&head, 3);
    addNode(&head, 4);
    addNode(&head, 5);
    addNode(&head, 6);
    addNode(&head, 7);
    addNode(&head, 8);
    addNode(&head, 9);
    addNode(&head, 10);

    // Print the graph
    printf("Graph representation:\n");
    printGraph(head);

    return 0;
}