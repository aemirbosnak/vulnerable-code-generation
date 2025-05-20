//LLAMA2-13B DATASET v1.0 Category: Graph representation ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Define a struct to represent a node in the graph
struct Node {
    char name[20];    // Name of the node
    int weight;      // Weight of the edge connecting to the next node
    struct Node *next; // Pointer to the next node in the list
};

// Define a function to create a new node
struct Node* newNode(char name[20], int weight) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    strcpy(node->name, name);
    node->weight = weight;
    node->next = NULL;
    return node;
}

// Define a function to add a node to the graph
void addNode(struct Node** head_ref, char name[20], int weight) {
    struct Node* new_node = newNode(name, weight);
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Define a function to print the graph
void printGraph(struct Node* head) {
    if (head == NULL) {
        printf("The graph is empty.\n");
        return;
    }

    printf("The graph contains the following nodes:\n");
    struct Node* current = head;
    while (current != NULL) {
        printf("%s (weight: %d)\n", current->name, current->weight);
        current = current->next;
    }
}

// Define a function to traverse the graph
void traverse(struct Node* head) {
    if (head == NULL) {
        return;
    }

    struct Node* current = head;
    while (current != NULL) {
        printf("%s (weight: %d)\n", current->name, current->weight);
        current = current->next;
    }
}

int main() {
    struct Node* head = NULL;

    // Add some nodes to the graph
    addNode(&head, "Alice", 10);
    addNode(&head, "Bob", 20);
    addNode(&head, "Charlie", 30);
    addNode(&head, "David", 40);
    addNode(&head, "Eve", 50);

    // Print the graph
    printGraph(head);

    // Traverse the graph
    traverse(head);

    return 0;
}