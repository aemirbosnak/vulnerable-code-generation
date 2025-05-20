//FormAI DATASET v1.0 Category: Network Topology Mapper ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Declaring variables and structures
struct Node {
    int id;
    int x, y;
    struct Node *next;
};

int map_width = 20, map_height = 20;
struct Node *head = NULL;

// Function to add a new node to the linked list
void add_node(int id, int x, int y) {
    struct Node *new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->id = id;
    new_node->x = x;
    new_node->y = y;
    new_node->next = head;
    head = new_node;
}

// Function to generate random coordinates for the nodes
int rand_coordinate() {
    return rand() % (map_width - 2) + 1;
}

// Main function to create the network topology mapper
int main() {
    int num_nodes = 5;
    srand(time(NULL)); // Seeding the random function

    printf("Generating network topology mapper...\n");

    // Adding nodes to the map
    for (int i = 1; i <= num_nodes; i++) {
        int x = rand_coordinate();
        int y = rand_coordinate();
        add_node(i, x, y);
    }

    // Printing the nodes and their coordinates
    printf("Node ID \t X-Coordinate \t Y-Coordinate\n");
    printf("===============================================\n");
    struct Node *current_node = head;
    while (current_node != NULL) {
        printf("%d \t\t %d \t\t %d\n", current_node->id, current_node->x, current_node->y);
        current_node = current_node->next;
    }
    printf("\n");

    // Printing the connections between nodes
    printf("Connections between nodes:\n");
    printf("===========================\n");
    current_node = head;
    while (current_node != NULL) {
        struct Node *other_node = current_node->next;
        while (other_node != NULL) {
            // Medieval style: connection types are based on noble houses
            const char* houses[] = {"Stark", "Lannister", "Targaryen", "Baratheon", "Tyrell"};
            int connection_type = rand() % 5;
            printf("%d (%s) - %d (%s)\n", current_node->id, houses[connection_type], other_node->id, houses[connection_type]);
            other_node = other_node->next;
        }
        current_node = current_node->next;
    }

    printf("\n");
    printf("Mapping complete. Go forth and conquer the network!\n");

    return 0;
}