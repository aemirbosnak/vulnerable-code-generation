//FormAI DATASET v1.0 Category: Remote control Vehicle Simulation ; Style: decentralized
// Decentralized Remote Control Vehicle Simulation

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Node Structure
struct node {
    int id;
    int x;
    int y;
    struct node *next;
};
typedef struct node node;

// Initialization of Nodes
void initialize_nodes(node **head, int num_nodes) {
    for (int i = 0; i < num_nodes; i++) {
        node *new_node = malloc(sizeof(node));
        new_node->id = i + 1;

        // Random Positioning of Nodes
        new_node->x = rand() % 101;
        new_node->y = rand() % 101;
        new_node->next = NULL;

        if (*head == NULL) {
            *head = new_node;
        } else {
            node *curr = *head;
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = new_node;
        }
    }
}

// Displaying the Coordinates of Nodes
void display_nodes(node *head) {
    printf("ID\tX\tY\n");
    printf("--------------------------------\n");
    while (head != NULL) {
        printf("%d\t%d\t%d\n", head->id, head->x, head->y);
        head = head->next;
    }
}

int main() {
    srand(time(NULL));

    printf("Welcome to Decentralized Remote Control Vehicle Simulation\n");
    printf("Initializing Nodes...\n");
    node *head = NULL;
    int num_nodes = 5;
    initialize_nodes(&head, num_nodes);

    printf("Nodes Initialized!\n");
    display_nodes(head);

    printf("\nSimulating Vehicle Movement...\n");
    while (1) {
        int node_id, new_x, new_y;
        printf("Enter Node ID: ");
        scanf("%d", &node_id);
        printf("Enter New X Value: ");
        scanf("%d", &new_x);
        printf("Enter New Y Value: ");
        scanf("%d", &new_y);

        // Finding the Node with Given ID and Updating its Coordinates
        node *curr = head;
        while (curr != NULL) {
            if (curr->id == node_id) {
                curr->x = new_x;
                curr->y = new_y;
                break;
            }
            curr = curr->next;
        }

        printf("Updated Nodes:\n");
        display_nodes(head);
    }

    return 0;
}