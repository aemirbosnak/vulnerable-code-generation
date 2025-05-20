//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define the struct for a node
typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    int closed;
    struct node* parent;
} node;

// Define the grid as a 2D array of nodes
node** grid;
int width = 10;
int height = 10;

// Initialize the grid
void init_grid() {
    grid = malloc(height * sizeof(node*));
    for (int i = 0; i < height; i++) {
        grid[i] = malloc(width * sizeof(node));
        for (int j = 0; j < width; j++) {
            grid[i][j].x = j;
            grid[i][j].y = i;
            grid[i][j].f = 0;
            grid[i][j].g = 0;
            grid[i][j].h = 0;
            grid[i][j].closed = 0;
            grid[i][j].parent = NULL;
        }
    }
}

// Calculate the heuristic value for a node
int heuristic(node* n, node* goal) {
    return abs(n->x - goal->x) + abs(n->y - goal->y);
}

// Find the node with the lowest f value in the open list
node* find_lowest_f(node** open_list, int num_nodes) {
    node* lowest_node = open_list[0];
    for (int i = 0; i < num_nodes; i++) {
        if (open_list[i]->f < lowest_node->f) {
            lowest_node = open_list[i];
        }
    }
    return lowest_node;
}

// Check if a node is in the open list
int in_open_list(node** open_list, int num_nodes, node* n) {
    for (int i = 0; i < num_nodes; i++) {
        if (open_list[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Check if a node is in the closed list
int in_closed_list(node** closed_list, int num_nodes, node* n) {
    for (int i = 0; i < num_nodes; i++) {
        if (closed_list[i] == n) {
            return 1;
        }
    }
    return 0;
}

// Get the path from the start node to the end node
void get_path(node* start, node* end) {
    node* current = end;
    while (current != start) {
        printf("(%d, %d)\n", current->x, current->y);
        current = current->parent;
    }
    printf("(%d, %d)\n", start->x, start->y);
}

// A* pathfinding algorithm
void a_star(node* start, node* end) {
    // Initialize the start node
    start->g = 0;
    start->h = heuristic(start, end);
    start->f = start->g + start->h;

    // Initialize the open list with the start node
    node* open_list[width * height];
    int num_open_nodes = 0;
    open_list[num_open_nodes] = start;
    num_open_nodes++;

    // Initialize the closed list
    node* closed_list[width * height];
    int num_closed_nodes = 0;

    while (num_open_nodes > 0) {
        // Find the node with the lowest f value in the open list
        node* current = find_lowest_f(open_list, num_open_nodes);

        // If the current node is the end node, we're done
        if (current == end) {
            get_path(start, end);
            return;
        }

        // Move the current node from the open list to the closed list
        int current_index;
        for (int i = 0; i < num_open_nodes; i++) {
            if (open_list[i] == current) {
                current_index = i;
                break;
            }
        }
        for (int i = current_index; i < num_open_nodes - 1; i++) {
            open_list[i] = open_list[i + 1];
        }
        num_open_nodes--;
        current->closed = 1;
        closed_list[num_closed_nodes] = current;
        num_closed_nodes++;

        // Check each neighbor of the current node
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + j;
                int y = current->y + i;
                if (x < 0 || x >= width || y < 0 || y >= height) {
                    continue;
                }
                node* neighbor = &grid[y][x];
                if (neighbor->closed) {
                    continue;
                }
                int tentative_g = current->g + abs(i) + abs(j);
                if (!in_open_list(open_list, num_open_nodes, neighbor) ||
                        tentative_g < neighbor->g) {
                    neighbor->parent = current;
                    neighbor->g = tentative_g;
                    neighbor->h = heuristic(neighbor, end);
                    neighbor->f = neighbor->g + neighbor->h;
                    if (!in_open_list(open_list, num_open_nodes, neighbor)) {
                        open_list[num_open_nodes] = neighbor;
                        num_open_nodes++;
                    }
                }
            }
        }
    }
}

// main function
int main() {
    init_grid();
    node* start = &grid[0][0];
    node* end = &grid[9][9];
    a_star(start, end);
    return 0;
}