//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 5
#define COL 5

// Define the structure for a Node
typedef struct node {
    int row;
    int col;
    int f_value;
    int g_value;
    struct node* parent;
} Node;

// Define the goal node coordinates
int goal_row = 4;
int goal_col = 4;

// Declare the open and closed lists
Node* open_list[ROW*COL] = {NULL};
Node* closed_list[ROW*COL] = {NULL};

// Calculate the distance between two nodes
int distance(int current_row, int current_col) {
    int dx = abs(current_col - goal_col);
    int dy = abs(current_row - goal_row);
    return (dx + dy);
}

// Check if a given node is the goal node
int is_goal_node(Node* current_node) {
    if ((current_node->row == goal_row) && (current_node->col == goal_col)) {
        return 1;
    }
    return 0;
}

// Check if a given node is valid and not on the closed list
int is_valid_node(int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL) {
        return 0;
    }
    if (closed_list[row*COL + col] != NULL) {
        return 0;
    }
    return 1;
}

// Expand the current node and add it to the open list
void expand_node(Node* current_node) {
    int row = current_node->row;
    int col = current_node->col;
    int g_value = current_node->g_value + 1;
    
    // Check the eight neighbors
    if (is_valid_node(row, col+1)) {
        Node* right = malloc(sizeof(Node));
        right->row = row;
        right->col = col+1;
        right->f_value = g_value + distance(row, col+1);
        right->g_value = g_value;
        right->parent = current_node;
        open_list[row*COL + col+1] = right;
    }
    if (is_valid_node(row, col-1)) {
        Node* left = malloc(sizeof(Node));
        left->row = row;
        left->col = col-1;
        left->f_value = g_value + distance(row, col-1);
        left->g_value = g_value;
        left->parent = current_node;
        open_list[row*COL + col-1] = left;
    }
    if (is_valid_node(row+1, col)) {
        Node* down = malloc(sizeof(Node));
        down->row = row+1;
        down->col = col;
        down->f_value = g_value + distance(row+1, col);
        down->g_value = g_value;
        down->parent = current_node;
        open_list[(row+1)*COL + col] = down;
    }
    if (is_valid_node(row-1, col)) {
        Node* up = malloc(sizeof(Node));
        up->row = row-1;
        up->col = col;
        up->f_value = g_value + distance(row-1, col);
        up->g_value = g_value;
        up->parent = current_node;
        open_list[(row-1)*COL + col] = up;
    }
    if (is_valid_node(row+1, col+1)) {
        Node* down_right = malloc(sizeof(Node));
        down_right->row = row+1;
        down_right->col = col+1;
        down_right->f_value = g_value + distance(row+1, col+1);
        down_right->g_value = g_value;
        down_right->parent = current_node;
        open_list[(row+1)*COL + col+1] = down_right;
    }
    if (is_valid_node(row+1, col-1)) {
        Node* down_left = malloc(sizeof(Node));
        down_left->row = row+1;
        down_left->col = col-1;
        down_left->f_value = g_value + distance(row+1, col-1);
        down_left->g_value = g_value;
        down_left->parent = current_node;
        open_list[(row+1)*COL + col-1] = down_left;
    }
    if (is_valid_node(row-1, col+1)) {
        Node* up_right = malloc(sizeof(Node));
        up_right->row = row-1;
        up_right->col = col+1;
        up_right->f_value = g_value + distance(row-1, col+1);
        up_right->g_value = g_value;
        up_right->parent = current_node;
        open_list[(row-1)*COL + col+1] = up_right;
    }
    if (is_valid_node(row-1, col-1)) {
        Node* up_left = malloc(sizeof(Node));
        up_left->row = row-1;
        up_left->col = col-1;
        up_left->f_value = g_value + distance(row-1, col-1);
        up_left->g_value = g_value;
        up_left->parent = current_node;
        open_list[(row-1)*COL + col-1] = up_left;
    }
}

// Select the node with the lowest f value from the open list
Node* select_node_to_expand() {
    Node* current_node;
    int i;
    int min_f = 100000;
    int min_index = -1;
    
    for (i = 0; i < ROW*COL; i++) {
        if (open_list[i] != NULL) {
            if (open_list[i]->f_value < min_f) {
                current_node = open_list[i];
                min_f = current_node->f_value;
                min_index = i;
            }
        }
    }
    
    open_list[min_index] = NULL;
    return current_node;
}

// Print the path from the start node to the goal node
void print_path(Node* current_node) {
    if (current_node == NULL) {
        return;
    }
    print_path(current_node->parent);
    printf("(%d,%d) ", current_node->row, current_node->col);
}

int main() {
    Node* start = malloc(sizeof(Node));
    start->row = 0;
    start->col = 0;
    start->f_value = distance(0, 0);
    start->g_value = 0;
    start->parent = NULL;
    
    open_list[0] = start;
    
    while (1) {
        Node* current_node = select_node_to_expand();
        if (is_goal_node(current_node)) {
            printf("Path: ");
            print_path(current_node);
            printf("\n");
            break;
        }
        closed_list[current_node->row*COL + current_node->col] = current_node;
        expand_node(current_node);
    }
    
    return 0;
}