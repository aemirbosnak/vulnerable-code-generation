//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include <limits.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row, col;
    int f_cost, g_cost, h_cost;
    struct Node* parent;
} Node;

Node* new_node(int row, int col, Node* parent, int g_cost, int h_cost);
int calculate_g_cost(Node* node, Node* parent);
int calculate_h_cost(Node* node, Node* destination_node);
void add_to_open_list(Node* node);
Node* get_lowest_f_cost_node();
bool is_destination_node(Node* node, Node* destination_node);
void add_adjacent_nodes_to_open_list(Node* node, Node* destination_node);
bool is_valid_node(int row, int col);
void print_path(Node* destination_node);
void free_memory();

Node* grid[ROWS][COLS];
Node* open_list[ROWS*COLS];
int open_list_length = 0;

int main() {
    // create grid with random node costs
    srand(time(NULL));
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            grid[i][j] = new_node(i, j, NULL, rand() % 5 + 1, 0);
        }
    }

    // select random start and destination nodes
    Node* start_node = grid[rand() % ROWS][rand() % COLS];
    Node* dest_node = grid[rand() % ROWS][rand() % COLS];

    // set start node's g_cost to 0 and add it to open list
    start_node->g_cost = 0;
    add_to_open_list(start_node);

    // perform A* algorithm
    while(open_list_length > 0) {
        Node* current_node = get_lowest_f_cost_node();

        if(is_destination_node(current_node, dest_node)) {
            print_path(dest_node);
            free_memory();
            return 0;
        }

        add_adjacent_nodes_to_open_list(current_node, dest_node);
    }

    // if destination node not found, print error message and free memory
    printf("Path not found.\n");
    free_memory();
    return 0;
}

Node* new_node(int row, int col, Node* parent, int g_cost, int h_cost) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f_cost = INT_MAX;
    node->g_cost = g_cost;
    node->h_cost = h_cost;
    node->parent = parent;
    return node;
}

int calculate_g_cost(Node* node, Node* parent) {
    if(node->row == parent->row || node->col == parent->col) {
        return parent->g_cost + node->g_cost;
    } else {
        return parent->g_cost + (int)(node->g_cost * sqrt(2));
    }
}

int calculate_h_cost(Node* node, Node* destination_node) {
    int dx = abs(destination_node->col - node->col);
    int dy = abs(destination_node->row - node->row);
    return (int)(sqrt(pow(dx, 2) + pow(dy, 2)) * destination_node->g_cost);
}

void add_to_open_list(Node* node) {
    open_list[open_list_length++] = node;
    node->f_cost = node->g_cost + node->h_cost;
}

Node* get_lowest_f_cost_node() {
    Node* lowest_f_node = open_list[0];
    int lowest_f_index = 0;

    for(int i = 1; i < open_list_length; i++) {
        if(open_list[i]->f_cost < lowest_f_node->f_cost) {
            lowest_f_node = open_list[i];
            lowest_f_index = i;
        }
    }

    open_list[lowest_f_index] = open_list[--open_list_length];

    return lowest_f_node;
}

bool is_destination_node(Node* node, Node* destination_node) {
    return node == destination_node;
}

void add_adjacent_nodes_to_open_list(Node* node, Node* destination_node) {
    for(int i = node->row - 1; i <= node->row + 1; i++) {
        for(int j = node->col - 1; j <= node->col + 1; j++) {
            if(is_valid_node(i, j) && (i != node->row || j != node->col)) {
                Node* adj_node = grid[i][j];

                if(adj_node->parent == NULL) {
                    adj_node->parent = node;
                    adj_node->g_cost = calculate_g_cost(adj_node, node);
                    adj_node->h_cost = calculate_h_cost(adj_node, destination_node);
                    add_to_open_list(adj_node);
                } else {
                    int new_g_cost = calculate_g_cost(adj_node, node);

                    if(new_g_cost < adj_node->g_cost) {
                        adj_node->parent = node;
                        adj_node->g_cost = new_g_cost;
                        adj_node->f_cost = adj_node->g_cost + adj_node->h_cost;
                    }
                }
            }
        }
    }
}

bool is_valid_node(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

void print_path(Node* destination_node) {
    Node* current_node = destination_node;
    printf("Path: (%d,%d)", current_node->row, current_node->col);

    while(current_node->parent != NULL) {
        printf(" <- (%d,%d)", current_node->parent->row, current_node->parent->col);
        current_node = current_node->parent;
    }

    printf("\n");
}

void free_memory() {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            free(grid[i][j]);
        }
    }
}