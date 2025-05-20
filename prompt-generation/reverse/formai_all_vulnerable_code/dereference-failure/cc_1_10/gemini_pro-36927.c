//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define MAX_X 100
#define MAX_Y 100

// Node structure
typedef struct node {
    int x, y;
    int g_score;
    int f_score;
    struct node *parent;
} node;

// Grid structure
typedef struct grid {
    node **nodes;
} grid;

// Initialize the grid
grid *create_grid(int x_size, int y_size) {
    grid *g = malloc(sizeof(grid));
    g->nodes = malloc(sizeof(node *) * x_size);
    for (int i = 0; i < x_size; i++) {
        g->nodes[i] = malloc(sizeof(node) * y_size);
    }

    for (int i = 0; i < x_size; i++) {
        for (int j = 0; j < y_size; j++) {
            g->nodes[i][j].x = i;
            g->nodes[i][j].y = j;
            g->nodes[i][j].g_score = INT_MAX;
            g->nodes[i][j].f_score = INT_MAX;
            g->nodes[i][j].parent = NULL;
        }
    }

    return g;
}

// Free the grid
void free_grid(grid *g, int x_size, int y_size) {
    for (int i = 0; i < x_size; i++) {
        free(g->nodes[i]);
    }
    free(g->nodes);
    free(g);
}

// Set obstacle
void set_obstacle(grid *g, int x, int y) {
    g->nodes[x][y].g_score = INT_MAX;
    g->nodes[x][y].f_score = INT_MAX;
}

// Calculate manhattan distance
int manhattan_distance(node *a, node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Compare two nodes based on f_score
int compare_nodes(const void *a, const void *b) {
    node *node1 = (node *)a;
    node *node2 = (node *)b;

    return node1->f_score - node2->f_score;
}

// Get neighbors of a node
node **get_neighbors(grid *g, node *n, int x_size, int y_size) {
    int num_neighbors = 0;

    // Check if the node has any neighbors
    if (n->x > 0) num_neighbors++;
    if (n->x < x_size - 1) num_neighbors++;
    if (n->y > 0) num_neighbors++;
    if (n->y < y_size - 1) num_neighbors++;

    // Allocate memory for the neighbors
    node **neighbors = malloc(sizeof(node *) * num_neighbors);

    // Add the neighbors to the array
    int i = 0;
    if (n->x > 0) neighbors[i++] = &g->nodes[n->x - 1][n->y];
    if (n->x < x_size - 1) neighbors[i++] = &g->nodes[n->x + 1][n->y];
    if (n->y > 0) neighbors[i++] = &g->nodes[n->x][n->y - 1];
    if (n->y < y_size - 1) neighbors[i++] = &g->nodes[n->x][n->y + 1];

    return neighbors;
}

// Find the path from the start node to the goal node
node *a_star(grid *g, node *start, node *goal, int x_size, int y_size) {
    // Initialize open and closed lists
    node **open_list = malloc(sizeof(node *) * x_size * y_size);
    node **closed_list = malloc(sizeof(node *) * x_size * y_size);
    int open_list_size = 0;
    int closed_list_size = 0;

    // Add the start node to the open list
    open_list[open_list_size++] = start;

    // While the open list is not empty
    while (open_list_size > 0) {
        // Get the node with the lowest f_score from the open list
        node *current = open_list[0];
        for (int i = 1; i < open_list_size; i++) {
            if (open_list[i]->f_score < current->f_score) {
                current = open_list[i];
            }
        }

        // If the current node is the goal node, return the current node
        if (current == goal) {
            return current;
        }

        // Move the current node from the open list to the closed list
        open_list[current - start] = open_list[open_list_size - 1];
        open_list_size--;
        closed_list[closed_list_size++] = current;

        // Get the neighbors of the current node
        node **neighbors = get_neighbors(g, current, x_size, y_size);
        int num_neighbors = closed_list_size;

        // For each neighbor
        for (int i = 0; i < num_neighbors; i++) {
            node *neighbor = neighbors[i];

            // If the neighbor is on the closed list, continue
            if (neighbor->g_score == INT_MAX) {
                continue;
            }

            // Calculate the g_score for the neighbor
            int g_score = current->g_score + 1;

            // If the g_score is lower than the neighbor's g_score, update the neighbor's g_score and f_score
            if (g_score < neighbor->g_score) {
                neighbor->g_score = g_score;
                neighbor->f_score = g_score + manhattan_distance(neighbor, goal);
                neighbor->parent = current;

                // Add the neighbor to the open list if it is not already on the list
                int found = 0;
                for (int j = 0; j < open_list_size; j++) {
                    if (open_list[j] == neighbor) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    open_list[open_list_size++] = neighbor;
                }
            }
        }

        // Free the neighbors
        free(neighbors);
    }

    // No path found
    return NULL;
}

// Print the path from the start node to the goal node
void print_path(node *start, node *goal) {
    if (goal == NULL) {
        printf("No path found\n");
        return;
    }

    node *current = goal;
    while (current != start) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }

    printf("(%d, %d)\n", start->x, start->y);
}

int main() {
    // Create a grid
    grid *g = create_grid(MAX_X, MAX_Y);

    // Set obstacles
    set_obstacle(g, 0, 0);
    set_obstacle(g, 10, 10);
    set_obstacle(g, 20, 20);

    // Find the path from the start node to the goal node
    node *start = &g->nodes[0][0];
    node *goal = &g->nodes[99][99];
    node *path = a_star(g, start, goal, MAX_X, MAX_Y);

    // Print the path
    print_path(start, path);

    // Free the grid
    free_grid(g, MAX_X, MAX_Y);

    return 0;
}