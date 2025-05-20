//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: single-threaded
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10
#define MAX_NODES 100

typedef struct node {
    int x, y;  // coordinates of current node
    int f, g, h;  // f, g, h values for A* algorithm
    struct node *parent;  // parent node pointer
} node_t;

// create array of nodes for the grid
node_t nodes[MAX_NODES];
int num_nodes = 0;

// create 2D array for the grid
int grid[ROWS][COLS] = {
    {0,0,0,0,0,0,0,0,0,0},
    {0,1,1,1,1,0,0,0,0,0},
    {0,0,0,1,1,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,1,1,1,1,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,1,1,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// find the distance between two nodes using the Manhattan distance heuristic
int distance(node_t *a, node_t *b) {
    int dx = abs(a->x - b->x);
    int dy = abs(a->y - b->y);
    return dx + dy;
}

// find the neighbor nodes of a given node
int find_neighbors(node_t *node, node_t **neighbors) {
    int count = 0;
    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) {
                continue;
            }
            int nx = node->x + x;
            int ny = node->y + y;
            if (nx < 0 || nx >= ROWS || ny < 0 || ny >= COLS) {
                continue;
            }
            if (grid[nx][ny] != 0) {
                continue;
            }
            neighbors[count] = &nodes[num_nodes++];
            neighbors[count]->x = nx;
            neighbors[count]->y = ny;
            count++;
        }
    }
    return count;
}

// retrace the path from the end node to the start node
void retrace_path(node_t *start_node, node_t *end_node) {
    node_t *current_node = end_node;
    while (current_node != start_node) {
        printf("(%d,%d)\n", current_node->x, current_node->y);
        current_node = current_node->parent;
    }
    printf("(%d,%d)\n", start_node->x, start_node->y);
}

// find the node with the lowest f value in the open set
node_t *find_lowest_f(node_t **open_set, int open_length) {
    node_t *lowest_node = open_set[0];
    for (int i = 1; i < open_length; i++) {
        if (open_set[i]->f < lowest_node->f) {
            lowest_node = open_set[i];
        }
    }
    return lowest_node;
}

// A* pathfinding algorithm
void pathfinding(node_t *start_node, node_t *end_node) {
    node_t **open_set = (node_t **) malloc(sizeof(node_t*) * MAX_NODES);
    int open_length = 0;
    node_t **closed_set = (node_t **) malloc(sizeof(node_t*) * MAX_NODES);
    int closed_length = 0;
    
    start_node->g = 0;
    start_node->h = distance(start_node, end_node);
    start_node->f = start_node->g + start_node->h;
    open_set[open_length++] = start_node;
    
    while (open_length > 0) {
        node_t *current_node = find_lowest_f(open_set, open_length);
        if (current_node == end_node) {
            retrace_path(start_node, end_node);
            return;
        }
        // remove current node from open set
        for (int i = 0; i < open_length; i++) {
            if (open_set[i] == current_node) {
                for (int j = i; j < open_length-1; j++) {
                    open_set[j] = open_set[j+1];
                }
                open_length--;
                break;
            }
        }
        // add current node to closed set
        closed_set[closed_length++] = current_node;
        // find neighbor nodes
        node_t **neighbors = (node_t **) malloc(sizeof(node_t*) * 8);
        int num_neighbors = find_neighbors(current_node, neighbors);
        for (int i = 0; i < num_neighbors; i++) {
            node_t *neighbor = neighbors[i];
            // if neighbor is in closed set, skip it
            bool in_closed_set = false;
            for (int j = 0; j < closed_length; j++) {
                if (closed_set[j] == neighbor) {
                    in_closed_set = true;
                    break;
                }
            }
            if (in_closed_set) {
                continue;
            }
            int tentative_g = current_node->g + distance(current_node, neighbor);
            bool is_better_path = false;
            // if neighbor is in open set, check if this is a better path
            for (int j = 0; j < open_length; j++) {
                if (open_set[j] == neighbor) {
                    if (tentative_g < neighbor->g) {
                        neighbor->g = tentative_g;
                        neighbor->f = neighbor->g + neighbor->h;
                        neighbor->parent = current_node;
                    }
                    is_better_path = true;
                    break;
                }
            }
            // if neighbor is not in open set, add it
            if (!is_better_path) {
                neighbor->g = tentative_g;
                neighbor->h = distance(neighbor, end_node);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current_node;
                open_set[open_length++] = neighbor;
            }
        }
        free(neighbors); // free memory allocated for neighbors
    }
    printf("No valid path found.\n");
}

int main() {
    node_t *start_node = &nodes[num_nodes++];
    node_t *end_node = &nodes[num_nodes++];
    start_node->x = 0;
    start_node->y = 0;
    end_node->x = 9;
    end_node->y = 9;
    pathfinding(start_node, end_node);
    return 0;
}