//FormAI DATASET v1.0 Category: Classical Circuit Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Node structure for the circuit
typedef struct Node {
    int id;
    bool value;
    struct Node* next;
} Node;

// Helper function to initialize a new node
Node* createNode(int id, bool value) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->id = id;
    node->value = value;
    node->next = NULL;
    return node;
}

// Add a node to the end of the linked list
void addNode(Node** head, Node* node) {
    Node* current = *head;
    if (current == NULL) {
        *head = node;
    } else {
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = node;
    }
}

// Delete a node from the linked list
void deleteNode(Node** head, int id) {
    Node* current = *head;
    if (current == NULL) return;

    // If the head node matches the target ID
    if (current->id == id) {
        *head = current->next;
        free(current);
        return;
    }

    // Search through the linked list
    while (current->next != NULL) {
        if (current->next->id == id) {
            Node* temp = current->next;
            current->next = temp->next;
            free(temp);
            return;
        }
        current = current->next;
    }
}

// Get the value of a node in the linked list
bool getNodeValue(Node* head, int id) {
    Node* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current->value;
        }
        current = current->next;
    }
    return false;
}

int main() {
    Node* circuit = NULL;

    // Create some nodes for the circuit
    Node* node1 = createNode(1, false);
    Node* node2 = createNode(2, false);
    Node* node3 = createNode(3, false);

    // Add the nodes to the circuit
    addNode(&circuit, node1);
    addNode(&circuit, node2);
    addNode(&circuit, node3);

    // Set the initial toggle state
    bool toggle = false;

    // Run the simulation for 10 ticks
    for (int i = 0; i < 10; i++) {
        printf("Tick %d: ", i+1);

        // Update the node values based on their inputs
        node1->value = toggle;
        node2->value = getNodeValue(circuit, 1);
        node3->value = getNodeValue(circuit, 2);

        // Print out the node values
        printf("%d %d %d\n", node1->value, node2->value, node3->value);

        // Toggle the state for the next tick
        toggle = !toggle;

        // Manually delete node 3 halfway through the simulation
        if (i == 4) {
            deleteNode(&circuit, 3);
        }
    }

    // Free the memory used by the nodes
    free(node1);
    free(node2);

    // Print out the final state of the circuit (should only have nodes 1 and 2)
    printf("Final State: %d %d\n", getNodeValue(circuit, 1), getNodeValue(circuit, 2));

    return 0;
}