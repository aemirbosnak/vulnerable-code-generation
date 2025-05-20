//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

// Node structure for A* algorithm
typedef struct Node {
    int x;
    int y;
    int g_score;    // cost from start node
    int f_score;    // estimated total cost to target node
    struct Node *parent;
} Node;

// Define start and target nodes
Node *start, *target;

// Create a grid for the pathfinding algorithm
int grid[ROWS][COLS] = 
{
    {0,0,1,0,0,0,0,0,0,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,0,0,0,1,0,1,1,1,0},
    {0,0,0,0,1,0,0,0,0,0},
    {0,1,1,1,1,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0,0,0}
};

// Initialize a new node
Node *init_node(int x, int y, int g_score, int f_score, Node *parent) {
    Node *node = malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->g_score = g_score;
    node->f_score = f_score;
    node->parent = parent;
    return node;
}

// Calculate distance between two nodes
int dist_between(Node *node1, Node *node2) {
    int x_diff = abs(node1->x - node2->x);
    int y_diff = abs(node1->y - node2->y);
    return x_diff + y_diff;
}

// Check if node is in the grid and is not an obstacle
int is_valid(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS || grid[x][y] == 1) {
        return 0;
    }
    return 1;
}

// Get list of neighboring nodes
Node **get_neighbors(Node *node) {
    Node **neighbors = malloc(sizeof(Node*) * 8);
    int x = node->x;
    int y = node->y;
    int index = 0;

    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) {
                continue;
            }
            int neighbor_x = x + i;
            int neighbor_y = y + j;
            if (is_valid(neighbor_x, neighbor_y)) {
                neighbors[index] = init_node(neighbor_x, neighbor_y, 0, 0, node);
                index++;
            }
        }
    }
    return neighbors;
}

// Check if node is in list
int in_list(Node **list, Node *node, int len) {
    for (int i = 0; i < len; i++) {
        if (list[i] == node) {
            return 1;
        }
    }
    return 0;
}

// Find best node in the open list
Node *get_best_node(Node **list, int len) {
    Node *best_node = list[0];
    for (int i = 1; i < len; i++) {
        if (list[i]->f_score < best_node->f_score) {
            best_node = list[i];
        }
    }
    return best_node;
}

// Reconstruct path from end node to start node
int reconstruct_path(Node **path, Node *start_node, Node *end_node) {
    int path_len = 0;
    Node *node = end_node;
    while (node != start_node) {
        path[path_len] = node;
        path_len++;
        node = node->parent;
    }
    path[path_len] = start_node;
    return path_len;
}

// A* pathfinding algorithm
int a_star(Node *start_node, Node *end_node, Node **path) {
    Node *open_list[ROWS * COLS] = {0};
    Node *closed_list[ROWS * COLS] = {0};

    int open_len = 1;
    int closed_len = 0;

    start_node->g_score = 0;
    start_node->f_score = dist_between(start_node, end_node);
    open_list[0] = start_node;

    while (open_len > 0) {
        Node *current_node = get_best_node(open_list, open_len);
        if (current_node == end_node) {
            return reconstruct_path(path, start_node, end_node);
        }

        // Remove current node from open list
        for (int i = 0; i < open_len; i++) {
            if (open_list[i] == current_node) {
                open_list[i] = open_list[open_len - 1];
                open_len--;
                break;
            }
        }

        // Add current node to closed list
        closed_list[closed_len] = current_node;
        closed_len++;

        // Get list of neighboring nodes
        Node **neighbors = get_neighbors(current_node);

        for (int i = 0; i < 8; i++) {
            Node *neighbor = neighbors[i];
            if (neighbor == NULL) {
                continue;
            }

            int tentative_g_score = current_node->g_score + dist_between(current_node, neighbor);

            if (in_list(closed_list, neighbor, closed_len) && tentative_g_score >= neighbor->g_score) {
                continue;
            }

            if (!in_list(open_list, neighbor, open_len) || tentative_g_score < neighbor->g_score) {
                neighbor->parent = current_node;
                neighbor->g_score = tentative_g_score;
                neighbor->f_score = tentative_g_score + dist_between(neighbor, end_node);

                if (!in_list(open_list, neighbor, open_len)) {
                    open_list[open_len] = neighbor;
                    open_len++;
                }
            }
        }
        free(neighbors);
    }
    return 0;
}

int main() {
    // Initialize start and target nodes
    start = init_node(0, 0, 0, 0, NULL);
    target = init_node(9, 9, 0, 0, NULL);
    Node *path[ROWS * COLS];

    // Find path using A* algorithm
    int path_len = a_star(start, target, path);
    if (path_len > 0) {
        printf("Path found: ");
        for (int i = path_len; i >= 0; i--) {
            printf("(%d,%d) ", path[i]->x, path[i]->y);
        }
        printf("\n");
    } else {
        printf("No path found.\n");
    }
    return 0;
}