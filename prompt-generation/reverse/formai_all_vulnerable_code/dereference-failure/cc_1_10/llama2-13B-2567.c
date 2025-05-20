//LLAMA2-13B DATASET v1.0 Category: Recursive ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Structure to represent a node in the maze
typedef struct node {
    int x;
    int y;
    int next_x;
    int next_y;
} node_t;

// Function to generate a random maze
node_t* generate_maze(int width, int height) {
    // Create the starting node
    node_t* start = malloc(sizeof(node_t));
    start->x = 0;
    start->y = 0;
    start->next_x = 1;
    start->next_y = 1;

    // Create the rest of the nodes in the maze
    int i, j;
    for (i = 1; i < width; i++) {
        for (j = 1; j < height; j++) {
            // Create a new node and set its coordinates randomly
            int x = (i * (rand() % 2)) - 1;
            int y = (j * (rand() % 2)) - 1;
            node_t* new_node = malloc(sizeof(node_t));
            new_node->x = x;
            new_node->y = y;
            new_node->next_x = (x == 0) ? width - 1 : i - 1;
            new_node->next_y = (y == 0) ? height - 1 : j - 1;

            // Add the new node to the maze
            start->next_x = new_node->next_x;
            start->next_y = new_node->next_y;
            start = new_node;
        }
    }

    return start;
}

// Function to traverse the maze recursively
void traverse(node_t* current) {
    // Print the current node
    printf("Current node: (%d, %d)\n", current->x, current->y);

    // If the current node has no next node, return
    if (current->next_x == -1 && current->next_y == -1) {
        return;
    }

    // Traverse the next node recursively
    traverse(current->next_x == -1 ? current->next_y : current->next_x);

    // Traverse the next node recursively
    traverse(current->next_y == -1 ? current->next_x : current->next_y);
}

int main() {
    // Generate the maze
    node_t* maze = generate_maze(10, 10);

    // Traverse the maze recursively
    traverse(maze);

    return 0;
}