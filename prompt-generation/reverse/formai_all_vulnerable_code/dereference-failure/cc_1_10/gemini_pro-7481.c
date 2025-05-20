//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_SIZE 100

// Node struct representing a point in the grid
typedef struct Node {
    int x;
    int y;
    int cost;
    struct Node *parent;
} Node;

// Grid struct representing the grid world
typedef struct Grid {
    int size;
    int **grid;
} Grid;

// Function to create a new grid
Grid *create_grid(int size) {
    Grid *grid = (Grid *)malloc(sizeof(Grid));
    grid->size = size;

    grid->grid = (int **)malloc(size * sizeof(int *));
    for (int i = 0; i < size; i++) {
        grid->grid[i] = (int *)malloc(size * sizeof(int));
    }

    return grid;
}

// Function to delete a grid
void delete_grid(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        free(grid->grid[i]);
    }
    free(grid->grid);
    free(grid);
}

// Function to print a grid
void print_grid(Grid *grid) {
    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            printf("%d ", grid->grid[i][j]);
        }
        printf("\n");
    }
}

// Function to initialize a grid with values from a file
void initialize_grid(Grid *grid, char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(1);
    }

    for (int i = 0; i < grid->size; i++) {
        for (int j = 0; j < grid->size; j++) {
            fscanf(fp, "%d ", &grid->grid[i][j]);
        }
    }

    fclose(fp);
}

// Function to find the neighbors of a given node
Node **get_neighbors(Grid *grid, Node *node) {
    int x = node->x;
    int y = node->y;

    Node **neighbors = (Node **)malloc(4 * sizeof(Node *));

    // Check if the node is on the left edge of the grid
    if (x > 0) {
        neighbors[0] = (Node *)malloc(sizeof(Node));
        neighbors[0]->x = x - 1;
        neighbors[0]->y = y;
        neighbors[0]->cost = grid->grid[x - 1][y];
        neighbors[0]->parent = node;
    }

    // Check if the node is on the right edge of the grid
    if (x < grid->size - 1) {
        neighbors[1] = (Node *)malloc(sizeof(Node));
        neighbors[1]->x = x + 1;
        neighbors[1]->y = y;
        neighbors[1]->cost = grid->grid[x + 1][y];
        neighbors[1]->parent = node;
    }

    // Check if the node is on the top edge of the grid
    if (y > 0) {
        neighbors[2] = (Node *)malloc(sizeof(Node));
        neighbors[2]->x = x;
        neighbors[2]->y = y - 1;
        neighbors[2]->cost = grid->grid[x][y - 1];
        neighbors[2]->parent = node;
    }

    // Check if the node is on the bottom edge of the grid
    if (y < grid->size - 1) {
        neighbors[3] = (Node *)malloc(sizeof(Node));
        neighbors[3]->x = x;
        neighbors[3]->y = y + 1;
        neighbors[3]->cost = grid->grid[x][y + 1];
        neighbors[3]->parent = node;
    }

    return neighbors;
}

// Function to compare two nodes based on their cost
int compare_nodes(const void *a, const void *b) {
    Node *node1 = (Node *)a;
    Node *node2 = (Node *)b;

    return node1->cost - node2->cost;
}

// Function to find the shortest path from the start node to the end node using A* algorithm
Node *a_star(Grid *grid, Node *start, Node *end) {
    // Create a priority queue to store the nodes
    Node **queue = (Node **)malloc(MAX_SIZE * sizeof(Node *));
    int queue_size = 0;

    // Create a closed set to store the visited nodes
    Node **closed_set = (Node **)malloc(MAX_SIZE * sizeof(Node *));
    int closed_set_size = 0;

    // Set the start node as the first node in the queue
    queue[queue_size++] = start;

    // While the queue is not empty
    while (queue_size > 0) {
        // Sort the queue based on the cost of the nodes
        qsort(queue, queue_size, sizeof(Node *), compare_nodes);

        // Get the node with the lowest cost from the queue
        Node *current = queue[0];

        // If the current node is the end node, return the end node
        if (current->x == end->x && current->y == end->y) {
            return current;
        }

        // Remove the current node from the queue
        queue_size--;
        for (int i = 0; i < queue_size; i++) {
            queue[i] = queue[i + 1];
        }

        // Add the current node to the closed set
        closed_set[closed_set_size++] = current;

        // Get the neighbors of the current node
        Node **neighbors = get_neighbors(grid, current);

        // For each neighbor of the current node
        for (int i = 0; i < 4; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is not in the closed set
            if (!neighbor) {
                continue;
            }

            // Calculate the new cost of the neighbor
            int new_cost = current->cost + neighbor->cost;

            // If the new cost is less than the previous cost of the neighbor
            if (new_cost < neighbor->cost) {
                // Update the cost of the neighbor
                neighbor->cost = new_cost;

                // Set the parent of the neighbor to the current node
                neighbor->parent = current;

                // If the neighbor is not in the queue, add it to the queue
                if (queue_size == MAX_SIZE) {
                    printf("Error: Queue is full\n");
                    exit(1);
                }
                queue[queue_size++] = neighbor;
            }
        }
    }

    // If the queue is empty, return NULL
    return NULL;
}

// Function to print the shortest path
void print_path(Node *node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d, %d) ", node->x, node->y);
}

// Main function
int main() {
    // Create a grid
    Grid *grid = create_grid(8);

    // Initialize the grid with values from a file
    initialize_grid(grid, "grid.txt");

    // Print the grid
    print_grid(grid);

    // Create a start node
    Node *start = (Node *)malloc(sizeof(Node));
    start->x = 0;
    start->y = 0;
    start->cost = 0;
    start->parent = NULL;

    // Create an end node
    Node *end = (Node *)malloc(sizeof(Node));
    end->x = 7;
    end->y = 7;
    end->cost = 0;
    end->parent = NULL;

    // Find the shortest path from the start node to the end node using A* algorithm
    Node *path = a_star(grid, start, end);

    // Print the shortest path
    print_path(path);

    // Delete the grid
    delete_grid(grid);

    // Delete the start node
    free(start);

    // Delete the end node
    free(end);

    // Delete the path
    free(path);

    return 0;
}