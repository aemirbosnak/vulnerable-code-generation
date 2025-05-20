//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define WIDTH 10
#define HEIGHT 10

// Node struct
typedef struct Node {
    int x;
    int y;
    struct Node *parent;
    int g_score;
    int f_score;
} Node;

// Grid struct
typedef struct Grid {
    Node **nodes;
} Grid;

// Create a new grid
Grid *create_grid() {
    Grid *grid = malloc(sizeof(Grid));
    grid->nodes = malloc(sizeof(Node *) * HEIGHT);
    for (int i = 0; i < HEIGHT; i++) {
        grid->nodes[i] = malloc(sizeof(Node) * WIDTH);
    }
    return grid;
}

// Free the grid
void free_grid(Grid *grid) {
    for (int i = 0; i < HEIGHT; i++) {
        free(grid->nodes[i]);
    }
    free(grid->nodes);
    free(grid);
}

// Set a node as a wall
void set_wall(Grid *grid, int x, int y) {
    grid->nodes[y][x].x = -1;
    grid->nodes[y][x].y = -1;
}

// Check if a node is a wall
int is_wall(Grid *grid, int x, int y) {
    return grid->nodes[y][x].x == -1 && grid->nodes[y][x].y == -1;
}

// Get the neighbors of a node
Node **get_neighbors(Grid *grid, Node *node) {
    Node **neighbors = malloc(sizeof(Node *) * 8);
    int index = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;
            if (node->x + i < 0 || node->x + i >= WIDTH) continue;
            if (node->y + j < 0 || node->y + j >= HEIGHT) continue;
            if (is_wall(grid, node->x + i, node->y + j)) continue;
            neighbors[index++] = &grid->nodes[node->y + j][node->x + i];
        }
    }
    return neighbors;
}

// Calculate the heuristic cost of a node
int heuristic_cost(Node *node, Node *goal) {
    return abs(node->x - goal->x) + abs(node->y - goal->y);
}

// Find the path from the start to the goal
Node *find_path(Grid *grid, Node *start, Node *goal) {
    // Initialize the open and closed sets
    Node **open_set = malloc(sizeof(Node *) * WIDTH * HEIGHT);
    Node **closed_set = malloc(sizeof(Node *) * WIDTH * HEIGHT);
    int open_set_size = 0;
    int closed_set_size = 0;

    // Add the start node to the open set
    open_set[open_set_size++] = start;

    // While the open set is not empty
    while (open_set_size > 0) {
        // Find the node with the lowest f_score
        Node *current = open_set[0];
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f_score < current->f_score) {
                current = open_set[i];
            }
        }

        // If the current node is the goal, return the path
        if (current == goal) {
            return current;
        }

        // Move the current node from the open set to the closed set
        open_set[current - start] = open_set[open_set_size - 1];
        open_set_size--;
        closed_set[closed_set_size++] = current;

        // Get the neighbors of the current node
        Node **neighbors = get_neighbors(grid, current);

        // For each neighbor
        for (int i = 0; i < 8; i++) {
            Node *neighbor = neighbors[i];

            // If the neighbor is a wall or is in the closed set, continue
            if (is_wall(grid, neighbor->x, neighbor->y) || neighbor - start < 0 || neighbor - start >= open_set_size) continue;

            // Calculate the g_score of the neighbor
            int g_score = current->g_score + 1;

            // If the neighbor is in the open set and the new g_score is lower, update the g_score and parent
            if (neighbor - start >= 0 && neighbor - start < open_set_size && g_score < neighbor->g_score) {
                neighbor->g_score = g_score;
                neighbor->parent = current;
            }

            // If the neighbor is not in the open set, add it to the open set
            if (neighbor - start < 0 || neighbor - start >= open_set_size) {
                neighbor->g_score = g_score;
                neighbor->parent = current;
                open_set[open_set_size++] = neighbor;
            }

            // Calculate the f_score of the neighbor
            neighbor->f_score = neighbor->g_score + heuristic_cost(neighbor, goal);
        }

        // Free the neighbors
        free(neighbors);
    }

    // No path found
    return NULL;
}

// Print the grid
void print_grid(Grid *grid) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (grid->nodes[i][j].x == -1 && grid->nodes[i][j].y == -1) {
                printf("#");
            } else if (grid->nodes[i][j].parent == NULL) {
                printf(".");
            } else {
                printf("*");
            }
        }
        printf("\n");
    }
}

// Main function
int main() {
    srand(time(NULL));

    // Create a grid
    Grid *grid = create_grid();

    // Set some walls
    for (int i = 0; i < WIDTH; i++) {
        set_wall(grid, i, 0);
        set_wall(grid, i, HEIGHT - 1);
    }
    for (int i = 0; i < HEIGHT; i++) {
        set_wall(grid, 0, i);
        set_wall(grid, WIDTH - 1, i);
    }

    // Generate a random start and goal
    Node *start = &grid->nodes[rand() % HEIGHT][rand() % WIDTH];
    Node *goal = &grid->nodes[rand() % HEIGHT][rand() % WIDTH];

    // Find the path
    Node *path = find_path(grid, start, goal);

    // Print the grid
    print_grid(grid);

    // Print the path
    if (path != NULL) {
        printf("Path found!\n");
        while (path != NULL) {
            printf("(%d, %d)\n", path->x, path->y);
            path = path->parent;
        }
    } else {
        printf("No path found.\n");
    }

    // Free the grid
    free_grid(grid);

    return 0;
}