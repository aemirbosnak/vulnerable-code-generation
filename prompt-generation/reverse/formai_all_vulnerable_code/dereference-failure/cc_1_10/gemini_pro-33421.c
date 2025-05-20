//GEMINI-pro DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the baggage queue
typedef struct Node {
    int id;
    struct Node *next;
} Node;

// Function to create a new node
Node* create_node(int id) {
    Node *new_node = (Node*) malloc(sizeof(Node));
    new_node->id = id;
    new_node->next = NULL;
    return new_node;
}

// Function to enqueue a node
void enqueue(Node **head, Node *new_node) {
    if (*head == NULL) {
        *head = new_node;
    } else {
        Node *current = *head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_node;
    }
}

// Function to dequeue a node
Node* dequeue(Node **head) {
    if (*head == NULL) {
        return NULL;
    } else {
        Node *temp = *head;
        *head = (*head)->next;
        return temp;
    }
}

// Function to simulate the baggage handling system
void baggage_handling(int num_bags, int num_handlers) {
    // Create the baggage queue
    Node *head = NULL;

    // Create the handlers
    int *handlers = (int*) malloc(sizeof(int) * num_handlers);
    for (int i = 0; i < num_handlers; i++) {
        handlers[i] = 0;
    }

    // Enqueue the bags
    for (int i = 0; i < num_bags; i++) {
        Node *new_node = create_node(i);
        enqueue(&head, new_node);
    }

    // Simulate the baggage handling
    while (head != NULL) {
        // Find the first available handler
        int handler_id = -1;
        for (int i = 0; i < num_handlers; i++) {
            if (handlers[i] == 0) {
                handler_id = i;
                break;
            }
        }

        // If there is no available handler, wait
        if (handler_id == -1) {
            continue;
        }

        // Assign the bag to the handler
        Node *bag = dequeue(&head);
        handlers[handler_id] = bag->id;

        // Simulate the handling time
        int handling_time = rand() % 10;
        sleep(handling_time);

        // Free the bag
        free(bag);

        // Mark the handler as available
        handlers[handler_id] = 0;
    }

    // Free the handlers
    free(handlers);

    printf("All bags have been handled.\n");
}

int main() {
    // Number of bags
    int num_bags = 100;

    // Number of handlers
    int num_handlers = 5;

    // Simulate the baggage handling system
    baggage_handling(num_bags, num_handlers);

    return 0;
}