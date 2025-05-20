//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Structure for a node in the grid
typedef struct Node
{
    int x, y; // Position of the node on the grid
    int g; // Cost from the starting node to the current node
    int h; // Heuristic cost from the current node to the target node
    int f; // Total estimated cost of the node (f = g + h)
    struct Node* parent; // Parent node of the current node in the optimal path
    bool is_obstacle; // Whether this node is an obstacle or not
} Node;

// Structure for the grid
typedef struct Grid
{
    int width; // Width of the grid
    int height; // Height of the grid
    Node*** nodes; // 2D array of nodes representing the grid
} Grid;

// Function to create a new node
Node* new_node(int x, int y, bool is_obstacle)
{
    Node* node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g = 0;
    node->h = 0;
    node->f = 0;
    node->parent = NULL;
    node->is_obstacle = is_obstacle;

    return node;
}

// Function to create a new grid
Grid* new_grid(int width, int height)
{
    Grid* grid = malloc(sizeof(Grid));
    grid->width = width;
    grid->height = height;
    grid->nodes = calloc(width, sizeof(Node**));

    for (int x = 0; x < width; x++) {
        grid->nodes[x] = calloc(height, sizeof(Node*));
        for (int y = 0; y < height; y++) {
            grid->nodes[x][y] = new_node(x, y, false);
        }
    }

    return grid;
}

// Function to destroy a node
void destroy_node(Node* node)
{
    free(node);
}

// Function to destroy a grid
void destroy_grid(Grid* grid)
{
    for (int x = 0; x < grid->width; x++) {
        for (int y = 0; y < grid->height; y++) {
            destroy_node(grid->nodes[x][y]);
        }
        free(grid->nodes[x]);
    }
    free(grid->nodes);
    free(grid);
}

// Function to set a node as an obstacle
void set_obstacle(Node* node)
{
    node->is_obstacle = true;
}

// Function to get the Manhattan distance between two nodes
int manhattan_distance(Node* node1, Node* node2)
{
    return abs(node1->x - node2->x) + abs(node1->y - node2->y);
}

// Function to check if a node is valid (i.e., within the grid and not an obstacle)
bool is_valid_node(Grid* grid, int x, int y)
{
    if (x < 0 || x >= grid->width || y < 0 || y >= grid->height) {
        return false; // Node is out of bounds
    }
    if (grid->nodes[x][y]->is_obstacle) {
        return false; // Node is an obstacle
    }
    return true; // Node is valid
}

// Function to get the best node from a set of nodes (i.e., the one with the lowest f score)
Node* get_best_node(Node** nodes, int size)
{
    int best_index = 0;
    for (int i = 1; i < size; i++) {
        if (nodes[i]->f < nodes[best_index]->f) {
            best_index = i;
        }
    }
    return nodes[best_index];
}

// Function to get the neighbors of a node
Node** get_neighbors(Grid* grid, Node* node)
{
    Node** neighbors = calloc(8, sizeof(Node*));

    int x = node->x;
    int y = node->y;
    int i = 0;

    if (is_valid_node(grid, x-1, y-1)) {
        neighbors[i++] = grid->nodes[x-1][y-1];
    }
    if (is_valid_node(grid, x, y-1)) {
        neighbors[i++] = grid->nodes[x][y-1];
    }
    if (is_valid_node(grid, x+1, y-1)) {
        neighbors[i++] = grid->nodes[x+1][y-1];
    }
    if (is_valid_node(grid, x-1, y)) {
        neighbors[i++] = grid->nodes[x-1][y];
    }
    if (is_valid_node(grid, x+1, y)) {
        neighbors[i++] = grid->nodes[x+1][y];
    }
    if (is_valid_node(grid, x-1, y+1)) {
        neighbors[i++] = grid->nodes[x-1][y+1];
    }
    if (is_valid_node(grid, x, y+1)) {
        neighbors[i++] = grid->nodes[x][y+1];
    }
    if (is_valid_node(grid, x+1, y+1)) {
        neighbors[i++] = grid->nodes[x+1][y+1];
    }

    return neighbors;
}

// Function to free an array of nodes returned by get_neighbors
void free_neighbors(Node** neighbors)
{
    free(neighbors);
}

// Function to get the optimal path from the start node to the target node using the A* algorithm
Node** find_path(Grid* grid, Node* start, Node* target)
{
    Node* open_set[grid->width * grid->height];
    Node* closed_set[grid->width * grid->height];
    int open_set_size = 1;
    int closed_set_size = 0;

    open_set[0] = start;

    while (open_set_size > 0) {
        Node* current = get_best_node(open_set, open_set_size);

        if (current == target) {
            // Reconstruct the path from the target node to the start node
            Node* node = target;
            int path_length = 0;
            while (node != start) {
                path_length++;
                node = node->parent;
            }

            Node** path = calloc(path_length+1, sizeof(Node*));
            node = target;
            int i = path_length;
            while (node != start) {
                path[i] = node;
                i--;
                node = node->parent;
            }
            path[0] = start;

            return path;
        }

        // Move current node from open set to closed set
        for (int i = 0; i < open_set_size; i++) {
            if (open_set[i] == current) {
                for (int j = i; j < open_set_size-1; j++) {
                    open_set[j] = open_set[j+1];
                }
                open_set_size--;
                break;
            }
        }
        closed_set[closed_set_size++] = current;

        // Get the neighbors of the current node
        Node** neighbors = get_neighbors(grid, current);
        for (int i = 0; i < 8; i++) {
            Node* neighbor = neighbors[i];
            if (neighbor == NULL) {
                continue;
            }

            // Check if the neighbor is already in the closed set
            bool in_closed_set = false;
            for (int j = 0; j < closed_set_size; j++) {
                if (closed_set[j] == neighbor) {
                    in_closed_set = true;
                    break;
                }
            }
            if (in_closed_set) {
                continue;
            }

            // Calculate the tentative g score
            int tentative_g = current->g + manhattan_distance(current, neighbor);

            // Check if the neighbor is already in the open set
            bool in_open_set = false;
            for (int j = 0; j < open_set_size; j++) {
                if (open_set[j] == neighbor) {
                    in_open_set = true;
                    break;
                }
            }

            // Add the neighbor to the open set if it's not already in it
            if (!in_open_set) {
                open_set[open_set_size++] = neighbor;
            } else if (tentative_g >= neighbor->g) {
                continue;
            }

            // Update the neighbor's g, h, and f scores
            neighbor->parent = current;
            neighbor->g = tentative_g;
            neighbor->h = manhattan_distance(neighbor, target);
            neighbor->f = neighbor->g + neighbor->h;
        }

        free_neighbors(neighbors);
    }

    // No path was found
    return NULL;
}

// Function to print the grid
void print_grid(Grid* grid)
{
    for (int y = 0; y < grid->height; y++) {
        for (int x = 0; x < grid->width; x++) {
            if (grid->nodes[x][y]->is_obstacle) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }
}

int main()
{
    Grid* grid = new_grid(10, 10);
    set_obstacle(grid->nodes[4][4]);
    set_obstacle(grid->nodes[4][5]);
    set_obstacle(grid->nodes[5][4]);
    set_obstacle(grid->nodes[5][5]);
    print_grid(grid);

    Node* start = grid->nodes[2][2];
    Node* target = grid->nodes[7][7];
    Node** path = find_path(grid, start, target);

    if (path == NULL) {
        printf("No path was found\n");
    } else {
        for (int i = 0; path[i] != NULL; i++) {
            printf("(%d, %d) ", path[i]->x, path[i]->y);
        }
        printf("\n");
        free(path);
    }

    destroy_grid(grid);

    return 0;
}