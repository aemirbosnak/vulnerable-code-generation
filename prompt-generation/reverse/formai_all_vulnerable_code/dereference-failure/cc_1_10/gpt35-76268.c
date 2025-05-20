//FormAI DATASET v1.0 Category: Airport Baggage Handling Simulation ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

#define MAX_BAGGAGE 100 // Maximum number of bags that can be carried by the conveyor belt.

// Struct representing a single baggage item
typedef struct {
    int id; // id of the bag
    char color[20]; // color of the bag
} Baggage;

// Linked list node for holding the baggages at a particular node location in the conveyor belt
typedef struct BaggageNode {
    Baggage data; // the baggage item
    struct BaggageNode *next; // pointer to the next baggage node in the conveyor belt
} BaggageNode;

// struct representing a single conveyor belt node location
typedef struct {
    int id; // unique id of the node location in the conveyor belt
    int capacity; // maximum number of baggage items that can be held at this particular node location
    BaggageNode *head; // the head of the linked list of baggages at this node location
} ConveyorNode;

// Array of all the nodes in the conveyor belt
ConveyorNode conveyor_belt[10];

void print_baggage(Baggage b) {
    printf("Baggage ID: %d | Color: %s\n", b.id, b.color);
}

void add_baggage(int node_id, Baggage b) {
    // Check if this node location has reached capacity already
    if(!conveyor_belt[node_id].head || conveyor_belt[node_id].capacity > 0) {

        // Create a new node for the baggage
        BaggageNode *new_node = (BaggageNode *) malloc(sizeof(BaggageNode));
        new_node->data = b;
        new_node->next = NULL;

        // Append the new node to the list at this node location
        if(!conveyor_belt[node_id].head) {
            conveyor_belt[node_id].head = new_node;
        } else {
            BaggageNode *curr_node = conveyor_belt[node_id].head;
            while(curr_node->next) {
                curr_node = curr_node->next;
            }
            curr_node->next = new_node;
        }

        conveyor_belt[node_id].capacity--;
    } else {
        printf("Node %d at capacity!\n", node_id);
    }
}

void remove_baggage(int node_id, int baggage_id) {
    // Check if there are any baggages at this node location
    if(!conveyor_belt[node_id].head) {
        printf("Node %d has no baggages!\n", node_id);
    } else {
        BaggageNode *curr_node = conveyor_belt[node_id].head;
        BaggageNode *prev_node = NULL;

        // Traverse the linked list of baggages at this location
        while(curr_node) {
            if(curr_node->data.id == baggage_id) {
                // Found the baggage item to be removed
                printf("Removal Request for Baggage %d from Node %d\n", baggage_id, node_id);
                print_baggage(curr_node->data);

                // Remove the baggage
                if(!prev_node) {
                    // The head node of the linked list was the node to be removed
                    conveyor_belt[node_id].head = curr_node->next;
                } else {
                    prev_node->next = curr_node->next;
                }
                free(curr_node);
                conveyor_belt[node_id].capacity++;
                printf("Removal of baggage %d from Node %d complete.\n", baggage_id, node_id);
                return;
            }
            prev_node = curr_node;
            curr_node = curr_node->next;
        }

        printf("Baggage %d not found at Node %d!\n", baggage_id, node_id);
    }
}

int main() {
    int node_id, baggage_id;
    Baggage b;

    // Initialize the conveyor belt nodes and their capacities
    for(int i=0; i<10; i++) {
        conveyor_belt[i].id = i;
        conveyor_belt[i].capacity = (i+1)*2;
        conveyor_belt[i].head = NULL;
    }

    // Add some sample baggages to the conveyor belt
    b.id = 1;
    sprintf(b.color, "Brown");
    add_baggage(0, b);

    b.id = 2;
    sprintf(b.color, "Black");
    add_baggage(1, b);

    b.id = 3;
    sprintf(b.color, "Red");
    add_baggage(0, b);

    b.id = 4;
    sprintf(b.color, "Yellow");
    add_baggage(2, b);

    // Remove a baggage from the conveyor belt
    node_id = 0;
    baggage_id = 1;
    remove_baggage(node_id, baggage_id);

    // Add a new baggage to the conveyor belt
    b.id = 5;
    sprintf(b.color, "Blue");
    add_baggage(1, b);

    return 0;
}