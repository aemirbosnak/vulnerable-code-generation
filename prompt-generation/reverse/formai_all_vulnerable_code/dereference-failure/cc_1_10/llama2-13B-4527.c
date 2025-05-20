//LLAMA2-13B DATASET v1.0 Category: Networking ; Style: genius
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define N 10000

// Define a struct to represent a node in the network
struct Node {
    int id;
    int weight;
    struct Node* next;
};

// Define a function to create a node with a random weight
struct Node* createNode(void) {
    struct Node* node = malloc(sizeof(struct Node));
    node->id = rand() % N;
    node->weight = rand() % 100;
    node->next = NULL;
    return node;
}

// Define a function to add a node to the network
void addNode(struct Node** head_ref, int id) {
    struct Node* new_node = createNode();
    new_node->id = id;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

// Define a function to traverse the network and print the weights
void printWeights(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->weight);
        head = head->next;
    }
    printf("\n");
}

// Define the main function
int main(void) {
    struct Node* head = NULL;
    int i;

    // Create N nodes with random weights
    for (i = 0; i < N; i++) {
        addNode(&head, i);
    }

    // Traverse the network and print the weights
    printWeights(head);

    return 0;
}