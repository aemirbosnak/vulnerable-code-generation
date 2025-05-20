//GPT-4o-mini DATASET v1.0 Category: Pathfinding algorithms ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <string.h>

#define GRID_SIZE 10
#define OPEN 'O'
#define BLOCKED 'X'
#define START 'S'
#define GOAL 'G'
#define PATH '*'

// Structure to represent a grid cell
typedef struct {
    int x, y;
    int g_cost; // Cost from start to this node
    int h_cost; // Heuristic cost to goal
    int f_cost; // Total cost (g + h)
    struct Node *parent; // Pointer to the parent node
} Node;

// The grid setup
char grid[GRID_SIZE][GRID_SIZE] = {
    {OPEN, OPEN, OPEN, BLOCKED, OPEN, OPEN, OPEN, OPEN, BLOCKED, OPEN},
    {BLOCKED, BLOCKED, OPEN, BLOCKED, OPEN, BLOCKED, BLOCKED, OPEN, BLOCKED, OPEN},
    {OPEN, OPEN, OPEN, OPEN, OPEN, BLOCKED, OPEN, OPEN, OPEN, OPEN},
    {OPEN, BLOCKED, BLOCKED, BLOCKED, OPEN, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN},
    {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, BLOCKED, OPEN, OPEN},
    {BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN, BLOCKED},
    {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN},
    {OPEN, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, OPEN, BLOCKED, BLOCKED},
    {OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, OPEN, GOAL, BLOCKED, OPEN},
    {BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED, BLOCKED}
};

// Function to create a node
Node* create_node(int x, int y, Node* parent) {
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->x = x;
    new_node->y = y;
    new_node->parent = parent;
    return new_node;
}

// Heuristic function (Manhattan distance)
int heuristic(Node* a, Node* b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Print the grid with the path
void print_grid() {
    for (int i = 0; i < GRID_SIZE; i++) {
        for (int j = 0; j < GRID_SIZE; j++) {
            printf("%c ", grid[i][j]);
        }
        printf("\n");
    }
}

// A* Pathfinding Algorithm
bool a_star(Node* start, Node* goal) {
    Node* open_set[GRID_SIZE * GRID_SIZE];
    int open_set_size = 0;

    open_set[open_set_size++] = start;

    while (open_set_size > 0) {
        // Find the node with the lowest f_cost
        int lowest_index = 0;
        for (int i = 1; i < open_set_size; i++) {
            if (open_set[i]->f_cost < open_set[lowest_index]->f_cost) {
                lowest_index = i;
            }
        }

        Node* current = open_set[lowest_index];

        // Check if we reached the goal
        if (current->x == goal->x && current->y == goal->y) {
            Node* path_node = current;
            while (path_node) {
                grid[path_node->x][path_node->y] = PATH;
                path_node = path_node->parent;
            }
            return true; // Path found!
        }

        // Remove current from open set
        open_set[lowest_index] = open_set[--open_set_size];

        // Check adjacent nodes (4 directions)
        const int dx[] = {1, 0, -1, 0};
        const int dy[] = {0, 1, 0, -1};

        for (int i = 0; i < 4; i++) {
            int new_x = current->x + dx[i], new_y = current->y + dy[i];

            // Check bounds and if the cell is walkable
            if (new_x >= 0 && new_x < GRID_SIZE && new_y >= 0 && new_y < GRID_SIZE &&
                grid[new_x][new_y] != BLOCKED) {

                Node* neighbor = create_node(new_x, new_y, current);
                neighbor->g_cost = current->g_cost + 1;
                neighbor->h_cost = heuristic(neighbor, goal);
                neighbor->f_cost = neighbor->g_cost + neighbor->h_cost;

                // Add the neighbor to the open set
                open_set[open_set_size++] = neighbor;
            }
        }
    }

    return false; // Path not found
}

// Main function
int main() {
    printf("Welcome to the Happy Pathfinding Adventure!\n");
    printf("Here is your grid:\n");

    // Mark start and goal
    Node* start = create_node(0, 0, NULL);
    Node* goal = create_node(8, 7, NULL);
    grid[0][0] = START;
    grid[8][7] = GOAL;

    print_grid(); // Show the grid

    if (a_star(start, goal)) {
        printf("\nA path was found! Here is the path:\n");
        print_grid(); // Show the grid with path
    } else {
        printf("\nNo path found :(\n");
    }

    // Clean up dynamically allocated nodes (not shown for brevity)
    // Memory management would typically be needed for production code
    
    return 0;
}