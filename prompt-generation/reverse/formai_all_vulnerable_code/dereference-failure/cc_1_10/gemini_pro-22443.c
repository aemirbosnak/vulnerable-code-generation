//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: multi-threaded
#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>

// Grid dimensions
#define WIDTH 10
#define HEIGHT 10

// Node struct
typedef struct node {
    int x;
    int y;
    int g;
    int h;
    struct node *parent;
} node;

// Global variables
node *start;
node *end;
node **grid;
pthread_mutex_t mutex;

// Function to calculate the heuristic cost
int heuristic(node *a, node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Function to find the neighbors of a node
node **get_neighbors(node *n) {
    node **neighbors = malloc(4 * sizeof(node));
    int count = 0;

    // Check if the node is on the left edge
    if (n->x > 0) {
        neighbors[count++] = &grid[n->y][n->x - 1];
    }

    // Check if the node is on the right edge
    if (n->x < WIDTH - 1) {
        neighbors[count++] = &grid[n->y][n->x + 1];
    }

    // Check if the node is on the top edge
    if (n->y > 0) {
        neighbors[count++] = &grid[n->y - 1][n->x];
    }

    // Check if the node is on the bottom edge
    if (n->y < HEIGHT - 1) {
        neighbors[count++] = &grid[n->y + 1][n->x];
    }

    return neighbors;
}

// Function to compare two nodes based on their f-score
int compare_nodes(const void *a, const void *b) {
    node *n1 = (node *)a;
    node *n2 = (node *)b;

    return n1->g + n1->h - n2->g - n2->h;
}

// Function to find the path from the start to the end node
node *find_path(node *start, node *end) {
    // Initialize the open and closed lists
    node **open = malloc(WIDTH * HEIGHT * sizeof(node));
    node **closed = malloc(WIDTH * HEIGHT * sizeof(node));
    int open_count = 0;
    int closed_count = 0;

    // Add the start node to the open list
    open[open_count++] = start;

    // While the open list is not empty
    while (open_count > 0) {
        // Sort the open list by f-score
        qsort(open, open_count, sizeof(node *), compare_nodes);

        // Get the node with the lowest f-score
        node *current = open[0];

        // If the current node is the end node, return the path
        if (current == end) {
            return current;
        }

        // Move the current node from the open list to the closed list
        open_count--;
        closed[closed_count++] = current;

        // Get the neighbors of the current node
        node **neighbors = get_neighbors(current);

        // For each neighbor
        for (int i = 0; i < 4; i++) {
            node *neighbor = neighbors[i];

            // If the neighbor is not in the closed list
            if (!neighbor || neighbor->x < 0 || neighbor->y < 0 || neighbor->x >= WIDTH || neighbor->y >= HEIGHT) {
                continue;
            }

            // Calculate the g-score of the neighbor
            int g = current->g + 1;

            // If the neighbor is not in the open list or the new g-score is lower than the old g-score
            if (!neighbor->g || g < neighbor->g) {
                // Set the neighbor's parent to the current node
                neighbor->parent = current;

                // Set the neighbor's g-score
                neighbor->g = g;

                // Calculate the neighbor's h-score
                neighbor->h = heuristic(neighbor, end);

                // If the neighbor is not in the open list
                if (!neighbor->g) {
                    // Add the neighbor to the open list
                    open[open_count++] = neighbor;
                }
            }
        }

        // Free the neighbors
        free(neighbors);
    }

    // If the open list is empty, there is no path from the start to the end node
    return NULL;
}

// Function to print the path from the start to the end node
void print_path(node *node) {
    if (node->parent) {
        print_path(node->parent);
    }

    printf("(%d, %d)\n", node->x, node->y);
}

// Function to run the pathfinding algorithm in a multi-threaded style
void *pathfinding_thread(void *arg) {
    int **map = (int **)arg;

    // Initialize the grid
    grid = malloc(HEIGHT * sizeof(node *));
    for (int i = 0; i < HEIGHT; i++) {
        grid[i] = malloc(WIDTH * sizeof(node));
    }

    // Initialize the start and end nodes
    start = &grid[0][0];
    end = &grid[HEIGHT - 1][WIDTH - 1];

    // Set the g-score of the start node to 0
    start->g = 0;

    // Calculate the h-score of the start and end nodes
    start->h = heuristic(start, end);
    end->h = 0;

    // Find the path from the start to the end node
    node *path = find_path(start, end);

    // Print the path
    if (path) {
        print_path(path);
    } else {
        printf("No path found.\n");
    }

    return NULL;
}

int main() {
    // Create a mutex
    pthread_mutex_init(&mutex, NULL);

    // Create a thread pool
    pthread_t threads[4];

    // Create the map
    int **map = malloc(HEIGHT * sizeof(int *));
    for (int i = 0; i < HEIGHT; i++) {
        map[i] = malloc(WIDTH * sizeof(int));
    }

    // Initialize the map
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            map[i][j] = 0;
        }
    }

    // Create the threads
    for (int i = 0; i < 4; i++) {
        pthread_create(&threads[i], NULL, pathfinding_thread, (void *)map);
    }

    // Join the threads
    for (int i = 0; i < 4; i++) {
        pthread_join(threads[i], NULL);
    }

    // Destroy the mutex
    pthread_mutex_destroy(&mutex);

    return 0;
}