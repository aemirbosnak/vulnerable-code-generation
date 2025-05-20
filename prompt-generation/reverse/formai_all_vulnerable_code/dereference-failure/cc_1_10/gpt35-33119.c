//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int row;
    int col;
    int g_score;
    int f_score;
    int h_score;
    struct node* parent;
} Node;

Node* start_node;
Node* target_node;
Node* open_list[ROWS * COLS];
Node* closed_list[ROWS * COLS];

bool is_obstacle(int row, int col) {
    // Check if the specified cell is an obstacle
    // For example, (3, 5) is an obstacle
    return (row == 3 && col == 5);
}

bool is_valid_node(int row, int col) {
    // Check if the specified cell is valid (within the bounds of the grid)
    return (row >= 0 && row < ROWS && col >= 0 && col < COLS);
}

bool is_closed_node(Node* node) {
    // Check if the specified node is in the closed list
    for (int i = 0; i < ROWS * COLS; i++) {
        if (closed_list[i] == node) {
            return true;
        }
    }
    return false;
}

bool is_open_node(Node* node) {
    // Check if the specified node is in the open list
    for (int i = 0; i < ROWS * COLS; i++) {
        if (open_list[i] == node) {
            return true;
        }
    }
    return false;
}

int manhattan_distance(Node* node1, Node* node2) {
    // Calculate the Manhattan distance between two nodes
    int dx = abs(node1->col - node2->col);
    int dy = abs(node1->row - node2->row);
    return dx + dy;
}

void add_to_open_list(Node* node) {
    // Add the node to the open list
    for (int i = 0; i < ROWS * COLS; i++) {
        if (open_list[i] == NULL) {
            open_list[i] = node;
            return;
        }
    }
}

void remove_from_open_list(Node* node) {
    // Remove the node from the open list
    for (int i = 0; i < ROWS * COLS; i++) {
        if (open_list[i] == node) {
            open_list[i] = NULL;
            return;
        }
    }
}

void add_to_closed_list(Node* node) {
    // Add the node to the closed list
    for (int i = 0; i < ROWS * COLS; i++) {
        if (closed_list[i] == NULL) {
            closed_list[i] = node;
            return;
        }
    }
}

void print_path(Node* node) {
    // Print the path from the start node to the end node
    if (node->parent) {
        print_path(node->parent);
    }
    printf("(%d, %d)\n", node->row, node->col);
}

void find_path() {
    start_node->g_score = 0;
    start_node->h_score = manhattan_distance(start_node, target_node);
    start_node->f_score = start_node->g_score + start_node->h_score;
    add_to_open_list(start_node);
    Node* current_node;
    while (open_list[0] != NULL) {
        current_node = open_list[0];
        if (current_node == target_node) {
            print_path(current_node);
            return;
        }
        remove_from_open_list(current_node);
        add_to_closed_list(current_node);
        for (int dx = -1; dx <= 1; dx++) {
            for (int dy = -1; dy <= 1; dy++) {
                if (dx == 0 && dy == 0) {
                    continue;
                }
                int row = current_node->row + dy;
                int col = current_node->col + dx;
                if (is_valid_node(row, col) && !is_obstacle(row, col)) {
                    Node* neighbor = (Node*)malloc(sizeof(Node));
                    neighbor->row = row;
                    neighbor->col = col;
                    neighbor->g_score = current_node->g_score + 1;
                    neighbor->h_score = manhattan_distance(neighbor, target_node);
                    neighbor->f_score = neighbor->g_score + neighbor->h_score;
                    neighbor->parent = current_node;
                    if (is_closed_node(neighbor)) {
                        free(neighbor);
                        continue;
                    }
                    if (!is_open_node(neighbor)) {
                        add_to_open_list(neighbor);
                    } else {
                        for (int i = 0; i < ROWS * COLS; i++) {
                            if (open_list[i] == neighbor) {
                                if (neighbor->g_score < open_list[i]->g_score) {
                                    open_list[i]->g_score = neighbor->g_score;
                                    open_list[i]->parent = neighbor->parent;
                                    open_list[i]->f_score = open_list[i]->g_score + open_list[i]->h_score;
                                }
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
    printf("No path found\n");
}

int main() {
    // Define the start node and target node
    start_node = (Node*)malloc(sizeof(Node));
    start_node->row = 0;
    start_node->col = 0;
    start_node->parent = NULL;
    target_node = (Node*)malloc(sizeof(Node));
    target_node->row = 9;
    target_node->col = 9;

    // Initialize the open list and closed list to NULL
    for (int i = 0; i < ROWS * COLS; i++) {
        open_list[i] = NULL;
        closed_list[i] = NULL;
    }

    // Find the path
    find_path();

    // Free the memory allocated for the nodes
    free(start_node);
    free(target_node);

    return 0;
}