//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <stdbool.h>

// Node structure represents a cell in the grid
typedef struct Node {
    int x;
    int y;
    int f_cost;
    int g_cost;
    int h_cost;
    struct Node* parent;
} Node;

// Grid structure represents the 2D grid
typedef struct Grid {
    int width;
    int height;
    Node** nodes;
} Grid;

// Function to create a new node
Node* create_node(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f_cost = INT_MAX;
    node->g_cost = INT_MAX;
    node->h_cost = INT_MAX;
    node->parent = NULL;
    return node;
}

// Function to create a new grid
Grid* create_grid(int width, int height) {
    Grid* grid = (Grid*)malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = (Node**)malloc(sizeof(Node*) * height);
    for (int i = 0; i < height; i++) {
        grid->nodes[i] = (Node*)malloc(sizeof(Node) * width);
        for (int j = 0; j < width; j++) {
            grid->nodes[i][j] = *create_node(j, i);
        }
    }
    return grid;
}

// Function to set the obstacle in the grid
void set_obstacle(Grid* grid, int x, int y) {
    grid->nodes[y][x].f_cost = INT_MAX;
}

// Function to calculate the heuristic cost
int calculate_heuristic_cost(Node* start, Node* end) {
    return abs(end->x - start->x) + abs(end->y - start->y);
}

// Function to calculate the g-cost
int calculate_g_cost(Node* start, Node* current) {
    return abs(current->x - start->x) + abs(current->y - start->y);
}

// Function to calculate the f-cost
int calculate_f_cost(Node* node) {
    return node->g_cost + node->h_cost;
}

// Function to compare two nodes
int compare_nodes(Node* a, Node* b) {
    return a->f_cost - b->f_cost;
}

// Function to find the neighbors of a node
Node** find_neighbors(Grid* grid, Node* node) {
    Node** neighbors = (Node**)malloc(sizeof(Node*) * 4);
    int index = 0;
    if (node->x > 0) {
        neighbors[index++] = &grid->nodes[node->y][node->x - 1];
    }
    if (node->x < grid->width - 1) {
        neighbors[index++] = &grid->nodes[node->y][node->x + 1];
    }
    if (node->y > 0) {
        neighbors[index++] = &grid->nodes[node->y - 1][node->x];
    }
    if (node->y < grid->height - 1) {
        neighbors[index++] = &grid->nodes[node->y + 1][node->x];
    }
    return neighbors;
}

// Function to implement the A* algorithm
Node* a_star(Grid* grid, Node* start, Node* end) {
    // Create an open and closed list
    Node** open_list = (Node**)malloc(sizeof(Node*) * grid->width * grid->height);
    Node** closed_list = (Node**)malloc(sizeof(Node*) * grid->width * grid->height);
    int open_list_size = 0;
    int closed_list_size = 0;

    // Add the start node to the open list
    open_list[open_list_size++] = start;

    // While the open list is not empty
    while (open_list_size > 0) {
        // Find the node with the lowest f-cost
        Node* current = open_list[0];
        for (int i = 1; i < open_list_size; i++) {
            if (compare_nodes(open_list[i], current) < 0) {
                current = open_list[i];
            }
        }

        // Remove the node from the open list
        open_list_size--;
        for (int i = 0; i < open_list_size; i++) {
            if (open_list[i] == current) {
                open_list[i] = open_list[open_list_size];
                break;
            }
        }

        // Add the node to the closed list
        closed_list[closed_list_size++] = current;

        // If the current node is the end node, return the path
        if (current == end) {
            return current;
        }

        // Find the neighbors of the current node
        Node** neighbors = find_neighbors(grid, current);

        // For each neighbor of the current node
        for (int i = 0; i < 4; i++) {
            Node* neighbor = neighbors[i];

            // If the neighbor is not in the closed list and is not an obstacle
            if (!neighbor || neighbor->f_cost == INT_MAX) {
                continue;
            }

            // Calculate the new g-cost for the neighbor
            int new_g_cost = calculate_g_cost(start, neighbor);

            // If the new g-cost is less than the previous g-cost
            if (new_g_cost < neighbor->g_cost) {
                // Update the neighbor's g-cost and parent
                neighbor->g_cost = new_g_cost;
                neighbor->parent = current;

                // Calculate the neighbor's h-cost and f-cost
                neighbor->h_cost = calculate_heuristic_cost(neighbor, end);
                neighbor->f_cost = calculate_f_cost(neighbor);

                // Add the neighbor to the open list
                open_list[open_list_size++] = neighbor;
            }
        }
    }

    // If the end node was not found, return NULL
    return NULL;
}

// Function to print the path
void print_path(Node* node) {
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d, %d)\n", node->x, node->y);
}

int main() {
    // Create a grid
    Grid* grid = create_grid(10, 10);

    // Set obstacles in the grid
    set_obstacle(grid, 2, 2);
    set_obstacle(grid, 3, 3);
    set_obstacle(grid, 4, 4);

    // Create the start and end nodes
    Node* start = &grid->nodes[0][0];
    Node* end = &grid->nodes[9][9];

    // Run the A* algorithm
    Node* path = a_star(grid, start, end);

    // Print the path
    if (path) {
        print_path(path);
    } else {
        printf("No path found\n");
    }

    return 0;
}