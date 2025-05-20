//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>

// Defines a node in the grid
typedef struct Node {
    int x;
    int y;
    int g;  // Distance from the start node
    int h;  // Heuristic distance to the end node
    int f;  // Total cost (g + h)
    struct Node *parent;
} Node;

// Defines a grid of nodes
typedef struct Grid {
    int width;
    int height;
    Node **nodes;
} Grid;

// Creates a new node
Node *new_node(int x, int y) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = INT_MAX;
    node->h = INT_MAX;
    node->f = INT_MAX;
    node->parent = NULL;
    return node;
}

// Creates a new grid
Grid *new_grid(int width, int height) {
    Grid *grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = malloc(sizeof(Node *) * width * height);
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid->nodes[i * height + j] = new_node(i, j);
        }
    }
    return grid;
}

// Frees the memory allocated for a grid
void free_grid(Grid *grid) {
    for (int i = 0; i < grid->width; i++) {
        for (int j = 0; j < grid->height; j++) {
            free(grid->nodes[i * grid->height + j]);
        }
    }
    free(grid->nodes);
    free(grid);
}

// Checks if a node is valid (i.e. within the grid and not an obstacle)
bool is_valid_node(Grid *grid, Node *node) {
    return node->x >= 0 && node->x < grid->width && node->y >= 0 && node->y < grid->height;
}

// Gets the neighbors of a node
Node **get_neighbors(Grid *grid, Node *node) {
    Node **neighbors = malloc(sizeof(Node *) * 8);
    int num_neighbors = 0;

    // Check the eight neighbors of the node
    for (int dx = -1; dx <= 1; dx++) {
        for (int dy = -1; dy <= 1; dy++) {
            if (dx == 0 && dy == 0) {
                continue;
            }
            int x = node->x + dx;
            int y = node->y + dy;
            Node *neighbor = grid->nodes[x * grid->height + y];
            if (is_valid_node(grid, neighbor)) {
                neighbors[num_neighbors++] = neighbor;
            }
        }
    }

    return neighbors;
}

// Calculates the heuristic distance between two nodes
int heuristic(Node *node1, Node *node2) {
    int dx = abs(node2->x - node1->x);
    int dy = abs(node2->y - node1->y);
    return dx + dy;
}

// Compares two nodes based on their total cost (f)
int compare_nodes(const void *a, const void *b) {
    Node *node1 = *(Node **)a;
    Node *node2 = *(Node **)b;
    return node1->f - node2->f;
}

// Finds the path from the start node to the end node using the A* algorithm
Node *a_star(Grid *grid, Node *start, Node *end) {
    // Initialize the open and closed lists
    Node **open_list = malloc(sizeof(Node *) * grid->width * grid->height);
    int open_list_size = 0;
    Node **closed_list = malloc(sizeof(Node *) * grid->width * grid->height);
    int closed_list_size = 0;

    // Add the start node to the open list
    open_list[open_list_size++] = start;

    // While the open list is not empty
    while (open_list_size > 0) {
        // Sort the open list by f-value
        qsort(open_list, open_list_size, sizeof(Node *), compare_nodes);

        // Get the node with the lowest f-value
        Node *current = open_list[0];

        // If the current node is the end node, return the path
        if (current == end) {
            return current;
        }

        // Move the current node from the open list to the closed list
        open_list_size--;
        closed_list[closed_list_size++] = current;

        // Get the neighbors of the current node
        Node **neighbors = get_neighbors(grid, current);

        // For each neighbor of the current node
        for (int i = 0; i < 8; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is not valid or is already in the closed list, continue
            if (!is_valid_node(grid, neighbor) || neighbor == current) {
                continue;
            }

            // Calculate the g-value of the neighbor
            int g = current->g + 1;

            // If the neighbor is already in the open list and the new g-value is lower, update the neighbor's g-value and parent
            for (int j = 0; j < open_list_size; j++) {
                if (open_list[j] == neighbor && g < open_list[j]->g) {
                    open_list[j]->g = g;
                    open_list[j]->parent = current;
                    break;
                }
            }

            // If the neighbor is not in the open list, add it to the open list
            if (neighbor->g == INT_MAX) {
                neighbor->g = g;
                neighbor->h = heuristic(neighbor, end);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;
                open_list[open_list_size++] = neighbor;
            }
        }

        // Free the memory allocated for the neighbors
        free(neighbors);
    }

    // If the end node was not found, return NULL
    return NULL;
}

// Prints the path from the start node to the end node
void print_path(Node *node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d, %d)\n", node->x, node->y);
}

// Main function
int main() {
    // Create a grid
    Grid *grid = new_grid(10, 10);

    // Set the start and end nodes
    Node *start = grid->nodes[0];
    Node *end = grid->nodes[99];

    // Find the path from the start node to the end node
    Node *path = a_star(grid, start, end);

    // Print the path
    if (path) {
        printf("Path:\n");
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    // Free the memory allocated for the grid
    free_grid(grid);

    return 0;
}