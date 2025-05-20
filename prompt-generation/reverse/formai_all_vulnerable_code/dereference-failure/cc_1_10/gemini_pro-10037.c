//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Check if the coordinates are valid and within the grid
#define IS_VALID(x, y, grid) ((x >= 0 && x < grid->width) && (y >= 0 && y < grid->height))

// The grid structure represents the environment in which the A* algorithm operates
typedef struct {
    int width;
    int height;
    int** values;
} Grid;

// The node structure represents a cell in the grid and stores its coordinates, cost, and heuristic value
typedef struct {
    int x;
    int y;
    int g_cost;
    int h_cost;
    int f_cost;
    struct Node* parent;
} Node;

// Initialize the grid with the given width and height
Grid* create_grid(int width, int height) {
    Grid* grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->values = malloc(sizeof(int*) * height);
    for (int i = 0; i < height; i++) {
        grid->values[i] = malloc(sizeof(int) * width);
    }
    return grid;
}

// Free the memory allocated for the grid
void free_grid(Grid* grid) {
    for (int i = 0; i < grid->height; i++) {
        free(grid->values[i]);
    }
    free(grid->values);
    free(grid);
}

// Initialize a node with the given coordinates, cost, and heuristic value
Node* create_node(int x, int y, int g_cost, int h_cost) {
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g_cost = g_cost;
    node->h_cost = h_cost;
    node->f_cost = g_cost + h_cost;
    node->parent = NULL;
    return node;
}

// Free the memory allocated for the node
void free_node(Node* node) {
    free(node);
}

// Calculate the heuristic value using the Manhattan distance
int calculate_heuristic(Node* node, Node* goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Compare two nodes based on their f_cost values
int compare_nodes(const void* a, const void* b) {
    Node* node1 = (Node*)a;
    Node* node2 = (Node*)b;
    return node1->f_cost - node2->f_cost;
}

// Find the path from the start node to the goal node
Node* find_path(Grid* grid, Node* start, Node* goal) {
    // Create a priority queue to store the nodes to be explored
    Node** open_list = malloc(sizeof(Node*) * grid->width * grid->height);
    int open_list_size = 0;

    // Create a closed list to store the nodes that have been explored
    Node** closed_list = malloc(sizeof(Node*) * grid->width * grid->height);
    int closed_list_size = 0;

    // Add the start node to the open list
    open_list[open_list_size++] = start;

    // While the open list is not empty
    while (open_list_size > 0) {
        // Sort the open list based on the f_cost values
        qsort(open_list, open_list_size, sizeof(Node*), compare_nodes);

        // Get the node with the lowest f_cost value
        Node* current = open_list[0];

        // Remove the node from the open list
        open_list_size--;
        for (int i = 0; i < open_list_size; i++) {
            open_list[i] = open_list[i + 1];
        }

        // Add the node to the closed list
        closed_list[closed_list_size++] = current;

        // If the current node is the goal node, return the path
        if (current->x == goal->x && current->y == goal->y) {
            return current;
        }

        // Get the neighbors of the current node
        Node* neighbors[4];
        neighbors[0] = create_node(current->x + 1, current->y, current->g_cost + grid->values[current->y][current->x + 1], calculate_heuristic(current, goal));
        neighbors[1] = create_node(current->x - 1, current->y, current->g_cost + grid->values[current->y][current->x - 1], calculate_heuristic(current, goal));
        neighbors[2] = create_node(current->x, current->y + 1, current->g_cost + grid->values[current->y + 1][current->x], calculate_heuristic(current, goal));
        neighbors[3] = create_node(current->x, current->y - 1, current->g_cost + grid->values[current->y - 1][current->x], calculate_heuristic(current, goal));

        // Loop through the neighbors
        for (int i = 0; i < 4; i++) {
            Node* neighbor = neighbors[i];

            // If the neighbor is valid and not in the closed list
            if (IS_VALID(neighbor->x, neighbor->y, grid) && !neighbor_in_list(neighbor, closed_list, closed_list_size)) {
                // Calculate the neighbor's g_cost and h_cost
                neighbor->g_cost = current->g_cost + grid->values[neighbor->y][neighbor->x];
                neighbor->h_cost = calculate_heuristic(neighbor, goal);

                // Calculate the neighbor's f_cost
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                // Set the neighbor's parent to the current node
                neighbor->parent = current;

                // Add the neighbor to the open list
                open_list[open_list_size++] = neighbor;
            }

            // Free the memory allocated for the neighbor
            free_node(neighbor);
        }
    }

    // Free the memory allocated for the open list and closed list
    free(open_list);
    free(closed_list);

    // Return NULL if the path was not found
    return NULL;
}

// Print the path from the start node to the goal node
void print_path(Node* node) {
    if (node == NULL) {
        printf("No path found.\n");
        return;
    }

    printf("Path:");
    while (node != NULL) {
        printf(" (%d, %d)", node->x, node->y);
        node = node->parent;
    }
    printf("\n");
}

// Check if a node is in a list
int neighbor_in_list(Node* node, Node** list, int list_size) {
    for (int i = 0; i < list_size; i++) {
        if (node->x == list[i]->x && node->y == list[i]->y) {
            return 1;
        }
    }
    return 0;
}

// Main function
int main() {
    // Create the grid
    Grid* grid = create_grid(10, 10);

    // Set the values of the grid
    for (int i = 0; i < grid->height; i++) {
        for (int j = 0; j < grid->width; j++) {
            grid->values[i][j] = rand() % 10;
        }
    }

    // Create the start and goal nodes
    Node* start = create_node(0, 0, 0, calculate_heuristic(start, create_node(9, 9, 0, 0)));
    Node* goal = create_node(9, 9, 0, 0);

    // Find the path from the start node to the goal node
    Node* path = find_path(grid, start, goal);

    // Print the path
    print_path(path);

    // Free the memory allocated for the path, start node, and goal node
    free_node(path);
    free_node(start);
    free_node(goal);

    // Free the memory allocated for the grid
    free_grid(grid);

    return 0;
}