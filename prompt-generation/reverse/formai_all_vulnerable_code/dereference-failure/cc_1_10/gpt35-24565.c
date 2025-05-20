//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define the width and height of the grid
#define WIDTH 10
#define HEIGHT 10

// Define the start and end nodes
#define START_X 2
#define START_Y 2
#define END_X 7
#define END_Y 7

// Struct to represent each node in the grid
typedef struct node {
    int x;
    int y;
    int g_score; // the cost to get to this node from the start
    int h_score; // the heuristic cost to get to the end from this node
    int f_score; // the total estimated cost f(x) = g(x) + h(x)
    struct node *parent; // the parent node in the path
} node;

// Create the grid and initialize all nodes to null
node *grid[WIDTH][HEIGHT] = {NULL};

// Function to calculate Manhattan distance between two nodes
int manhattan_distance(node *a, node *b) {
    return abs(a->x - b->x) + abs(a->y - b->y);
}

// Function to get the node with the lowest f_score from a list of nodes
node *get_lowest_f_score_node(node **nodes, int count) {
    node *lowest_node = nodes[0];
    for (int i = 1; i < count; i++) {
        if (nodes[i]->f_score < lowest_node->f_score) {
            lowest_node = nodes[i];
        }
    }
    return lowest_node;
}

// Function to check if a node is in a list of nodes
bool is_in_list(node **list, int count, node *node) {
    for (int i = 0; i < count; i++) {
        if (list[i] == node) {
            return true;
        }
    }
    return false;
}

// Function to get the neighbors of a node
int get_neighbors(node *parent, node **neighbors) {
    int count = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) { // skip the parent node
                continue;
            }
            int x = parent->x + i;
            int y = parent->y + j;
            if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && grid[x][y] != NULL) {
                neighbors[count] = grid[x][y];
                count++;
            }
        }
    }
    return count;
}

// Function to reconstruct the path from start to end
void reconstruct_path(node *node) {
    if (node->parent != NULL) {
        reconstruct_path(node->parent);
    }
    printf("(%d, %d) -> ", node->x, node->y);
}

// Main function to run the A* algorithm
void a_star() {
    // Initialize the start and end nodes
    node *start = grid[START_X][START_Y];
    node *end = grid[END_X][END_Y];

    // Initialize the open and closed lists
    node *open_list[WIDTH*HEIGHT] = {NULL};
    int open_count = 0;
    node *closed_list[WIDTH*HEIGHT] = {NULL};
    int closed_count = 0;

    // Add the start node to the open list
    start->g_score = 0;
    start->h_score = manhattan_distance(start, end);
    start->f_score = start->g_score + start->h_score;
    open_list[open_count] = start;
    open_count++;

    // Loop until the end node is found or there are no more nodes to check
    while (open_count > 0) {
        // Get the node with the lowest f_score from the open list
        node *current = get_lowest_f_score_node(open_list, open_count);

        // If the current node is the end node, we're done
        if (current == end) {
            printf("Path found: ");
            reconstruct_path(end);
            return;
        }

        // Remove the current node from the open list and add it to the closed list
        for (int i = 0; i < open_count; i++) {
            if (open_list[i] == current) {
                open_list[i] = open_list[open_count-1];
                open_count--;
                break;
            }
        }
        closed_list[closed_count] = current;
        closed_count++;

        // Get the neighbors of the current node
        node *neighbors[8] = {NULL};
        int neighbor_count = get_neighbors(current, neighbors);

        // Loop through each neighbor node and update its score if necessary
        for (int i = 0; i < neighbor_count; i++) {
            node *neighbor = neighbors[i];
            int tentative_g_score = current->g_score + 1;

            // If the neighbor is already in the closed list, skip it
            if (is_in_list(closed_list, closed_count, neighbor)) {
                continue;
            }

            // If the neighbor is not in the open list, add it
            if (!is_in_list(open_list, open_count, neighbor)) {
                neighbor->parent = current;
                neighbor->g_score = tentative_g_score;
                neighbor->h_score = manhattan_distance(neighbor, end);
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
                open_list[open_count] = neighbor;
                open_count++;
            }
            // If the tentative g_score is less than the neighbor's g_score, update it
            else if (tentative_g_score < neighbor->g_score) {
                neighbor->parent = current;
                neighbor->g_score = tentative_g_score;
                neighbor->f_score = neighbor->g_score + neighbor->h_score;
            }
        }
    }

    // If we get here, there is no path
    printf("No path found");
}

int main() {
    // Initialize the grid with nodes
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            node *n = malloc(sizeof(node));
            n->x = i;
            n->y = j;
            n->parent = NULL;
            grid[i][j] = n;
        }
    }

    // Run the A* algorithm
    a_star();

    // Free all nodes in the grid
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            free(grid[i][j]);
        }
    }
    
    return 0;
}