//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <math.h>

// A-star pathfinding algorithm implementation.

// Node structure.
typedef struct node {
    int x, y; // Coordinates
    int f, g, h; // Costs
    struct node *parent; // Parent node
} node;

// Map structure.
typedef struct map {
    int width, height; // Dimensions
    int **cost; // Cost of each cell
    int **visited; // Whether each cell has been visited
} map;

// Compare function for qsort() to sort nodes by f-cost.
int compare_nodes(const void *a, const void *b) {
    const node *na = (const node *)a;
    const node *nb = (const node *)b;
    return na->f - nb->f;
}

// Check if a node is valid.
int is_valid_node(map *m, node *n) {
    return n->x >= 0 && n->x < m->width && n->y >= 0 && n->y < m->height && m->cost[n->y][n->x] != -1;
}

// Get the neighbors of a node.
node **get_neighbors(map *m, node *n) {
    node **neighbors = malloc(sizeof(node *) * 8);
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            node *neighbor = malloc(sizeof(node));
            neighbor->x = n->x + i;
            neighbor->y = n->y + j;
            if (is_valid_node(m, neighbor)) {
                neighbors[count++] = neighbor;
            }
        }
    }
    return neighbors;
}

// Calculate the heuristic cost of a node.
int heuristic_cost(node *n, node *end) {
    return abs(n->x - end->x) + abs(n->y - end->y);
}

// Initialize a node.
node *init_node(map *m, int x, int y) {
    node *n = malloc(sizeof(node));
    n->x = x;
    n->y = y;
    n->f = INT_MAX;
    n->g = INT_MAX;
    n->h = INT_MAX;
    n->parent = NULL;
    return n;
}

// A-star pathfinding algorithm.
node *a_star(map *m, node *start, node *end) {
    // Initialize the start node.
    start->f = 0;
    start->g = 0;
    start->h = 0;

    // Create the open set.
    node **open_set = malloc(sizeof(node *) * m->width * m->height);
    int open_set_length = 0;
    open_set[open_set_length++] = start;

    // Create the closed set.
    node **closed_set = malloc(sizeof(node *) * m->width * m->height);
    int closed_set_length = 0;

    // While the open set is not empty.
    while (open_set_length > 0) {
        // Sort the open set by f-cost.
        qsort(open_set, open_set_length, sizeof(node *), compare_nodes);

        // Get the node with the lowest f-cost.
        node *current = open_set[0];
        open_set[0] = open_set[open_set_length - 1];
        open_set_length--;

        // Add the current node to the closed set.
        closed_set[closed_set_length++] = current;

        // If the current node is the end node.
        if (current->x == end->x && current->y == end->y) {
            return current;
        }

        // Get the neighbors of the current node.
        node **neighbors = get_neighbors(m, current);

        // For each neighbor.
        for (int i = 0; i < 8; i++) {
            node *neighbor = neighbors[i];

            // If the neighbor is not valid.
            if (!is_valid_node(m, neighbor)) {
                continue;
            }

            // If the neighbor is in the closed set.
            int found = 0;
            for (int j = 0; j < closed_set_length; j++) {
                if (neighbor->x == closed_set[j]->x && neighbor->y == closed_set[j]->y) {
                    found = 1;
                    break;
                }
            }
            if (found) {
                continue;
            }

            // Calculate the g-cost of the neighbor.
            int g_cost = current->g + m->cost[neighbor->y][neighbor->x];

            // If the g-cost of the neighbor is lower than the current g-cost.
            if (g_cost < neighbor->g) {
                // Set the neighbor's parent to the current node.
                neighbor->parent = current;

                // Calculate the h-cost of the neighbor.
                neighbor->h = heuristic_cost(neighbor, end);

                // Calculate the f-cost of the neighbor.
                neighbor->f = neighbor->g + neighbor->h;

                // Add the neighbor to the open set.
                open_set[open_set_length++] = neighbor;
            }
        }
    }

    // No path found.
    return NULL;
}

// Print the path.
void print_path(node *n) {
    if (n->parent != NULL) {
        print_path(n->parent);
    }
    printf("(%d, %d)\n", n->x, n->y);
}

// Free the memory of a node.
void free_node(node *n) {
    free(n);
}

// Free the memory of a map.
void free_map(map *m) {
    for (int i = 0; i < m->height; i++) {
        free(m->cost[i]);
    }
    for (int i = 0; i < m->height; i++) {
        free(m->visited[i]);
    }
    free(m->cost);
    free(m->visited);
    free(m);
}

// Driver code.
int main() {
    // Create a map.
    map m;
    m.width = 10;
    m.height = 10;
    m.cost = malloc(sizeof(int *) * m.height);
    m.visited = malloc(sizeof(int *) * m.height);
    for (int i = 0; i < m.height; i++) {
        m.cost[i] = malloc(sizeof(int) * m.width);
        m.visited[i] = malloc(sizeof(int) * m.width);
    }
    for (int i = 0; i < m.height; i++) {
        for (int j = 0; j < m.width; j++) {
            m.cost[i][j] = 0;
            m.visited[i][j] = 0;
        }
    }
    m.cost[0][0] = -1;
    m.cost[0][9] = -1;
    m.cost[9][0] = -1;
    m.cost[9][9] = -1;

    // Create a start node.
    node *start = init_node(&m, 0, 0);

    // Create an end node.
    node *end = init_node(&m, 9, 9);

    // Find the path.
    node *path = a_star(&m, start, end);

    // Print the path.
    if (path != NULL) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    // Free the memory of the nodes.
    free_node(start);
    free_node(end);
    free_node(path);

    // Free the memory of the map.
    free_map(&m);

    return 0;
}