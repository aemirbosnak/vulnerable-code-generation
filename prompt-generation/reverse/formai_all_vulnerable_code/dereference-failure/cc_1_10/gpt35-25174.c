//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define ROW 10
#define COL 10

// Node structure representing a single point on the map
struct Node {
    int row;
    int col;
    int f;
    int g;
    int h;
    struct Node* parent;
};

// Map of the environment
char map[ROW][COL] = {
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' },
    { '.', '.', '.', '.', '.', '.', '.', '.', '.', '.' }
};

// Heuristic function to calculate estimated cost from current node to goal node
int heuristic(struct Node* current, struct Node* goal) {
    int h = abs(current->row - goal->row) + abs(current->col - goal->col);
    return h;
}

// Check if the node is valid (i.e. not a boundary and not an obstacle)
int is_valid_node(struct Node* node) {
    if (node->row < 0 || node->row >= ROW || node->col < 0 || node->col >= COL) {
        return 0;
    }
    if (map[node->row][node->col] == '#') {
        return 0;
    }
    return 1;
}

// Check if the node is the goal node
int is_goal_node(struct Node* node, struct Node* goal) {
    if (node->row == goal->row && node->col == goal->col) {
        return 1;
    }
    return 0;
}

// Construct the final path by backtracking using parent node pointers
void construct_path(struct Node* current) {
    while (current->parent != NULL) {
        printf("(%d,%d) -> ", current->row, current->col);
        current = current->parent;
    }
    printf("(%d,%d)\n", current->row, current->col);
}

// Implementation of the A* pathfinding algorithm
void a_star(struct Node* start, struct Node* goal) {
    struct Node* open_set[ROW * COL] = {NULL};
    struct Node* closed_set[ROW * COL] = {NULL};
    int open_set_len = 0;

    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    open_set[0] = start;
    open_set_len++;

    while (open_set_len > 0) {
        // Find the node with the lowest f value in the open set
        int lowest_f_index = 0;
        for (int i = 0; i < open_set_len; i++) {
            if (open_set[i]->f < open_set[lowest_f_index]->f) {
                lowest_f_index = i;
            }
        }

        struct Node* current = open_set[lowest_f_index];
        open_set[lowest_f_index] = open_set[open_set_len-1];
        open_set_len--;

        closed_set[current->row * COL + current->col] = current;

        if (is_goal_node(current, goal)) {
            construct_path(current);
            return;
        }

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }

                struct Node* neighbor = (struct Node*) malloc(sizeof(struct Node));
                neighbor->row = current->row + i;
                neighbor->col = current->col + j;
                neighbor->g = current->g + 1; // g value is always 1 for horizontal or vertical movement
                neighbor->h = heuristic(neighbor, goal);
                neighbor->f = neighbor->g + neighbor->h;
                neighbor->parent = current;

                if (!is_valid_node(neighbor)) {
                    continue;
                }

                if (closed_set[neighbor->row * COL + neighbor->col] != NULL) {
                    continue;
                }

                int is_new_node = 1;
                for (int k = 0; k < open_set_len; k++) {
                    if (open_set[k]->row == neighbor->row && open_set[k]->col == neighbor->col) {
                        is_new_node = 0;
                        if (neighbor->g < open_set[k]->g) {
                            open_set[k]->g = neighbor->g;
                            open_set[k]->f = neighbor->f;
                            open_set[k]->parent = neighbor->parent;
                        }
                    }
                }
                if (is_new_node) {
                    open_set[open_set_len] = neighbor;
                    open_set_len++;
                }
            }
        }
    }
}

// Driver program to test the A* algorithm
int main() {
    struct Node* start = (struct Node*) malloc(sizeof(struct Node));
    start->row = 0;
    start->col = 0;
    start->f = INT_MAX;
    start->g = INT_MAX;
    start->h = INT_MAX;
    start->parent = NULL;

    struct Node* goal = (struct Node*) malloc(sizeof(struct Node));
    goal->row = 9;
    goal->col = 9;
    goal->f = INT_MAX;
    goal->g = INT_MAX;
    goal->h = INT_MAX;
    goal->parent = NULL;

    printf("Path: ");
    a_star(start, goal);

    return 0;
}