//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row;
    int col;
    int f_score;
    int g_score;
    int h_score;
    bool is_visited;
    struct Node* parent;
} Node;

Node* create_node(int row, int col) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f_score = 0;
    node->g_score = 0;
    node->h_score = 0;
    node->is_visited = false;
    node->parent = NULL;
    return node;
}

int manhattan_distance(Node* current_node, Node* goal_node) {
    int dx = abs(current_node->row - goal_node->row);
    int dy = abs(current_node->col - goal_node->col);
    int distance = dx + dy;
    return distance;
}

Node* get_lowest_f_score_node(Node** open_list, int open_list_size) {
    int min_f_score = 99999;
    Node* lowest_f_score_node = NULL;
    for(int i = 0; i < open_list_size; i++) {
        if(open_list[i]->f_score < min_f_score) {
            min_f_score = open_list[i]->f_score;
            lowest_f_score_node = open_list[i];
        }
    }
    return lowest_f_score_node;
}

bool is_valid_state(int row, int col) {
    return row >= 0 && row < ROWS && col >= 0 && col < COLS;
}

bool is_unblocked(int grid[][COLS], int row, int col) {
    return grid[row][col] == 0;
}

bool is_destination(int row, int col, Node* goal_node) {
    return row == goal_node->row && col == goal_node->col;
}

void print_path(Node* current_node) {
    if(current_node->parent == NULL) {
        printf("(%d, %d)", current_node->row, current_node->col);
        return;
    }
    print_path(current_node->parent);
    printf(" -> (%d, %d)", current_node->row, current_node->col);
}

void run_a_star(int grid[][COLS], Node* start_node, Node* goal_node) {
    Node* open_list[ROWS * COLS];
    int open_list_size = 0;
    start_node->h_score = manhattan_distance(start_node, goal_node);
    start_node->f_score = start_node->g_score + start_node->h_score;
    open_list[open_list_size++] = start_node;

    while(open_list_size > 0) {
        Node* current_node = get_lowest_f_score_node(open_list, open_list_size);
        current_node->is_visited = true;

        if(is_destination(current_node->row, current_node->col, goal_node)) {
            printf("Found the destination: ");
            print_path(current_node);
            printf("\n");
            return;
        }

        int row = current_node->row;
        int col = current_node->col;

        // north
        if(is_valid_state(row-1, col) && is_unblocked(grid, row-1, col)) {
            Node* neighbor_node = create_node(row-1, col);
            if(!neighbor_node->is_visited) {
                neighbor_node->g_score = current_node->g_score + 1;
                neighbor_node->h_score = manhattan_distance(neighbor_node, goal_node);
                neighbor_node->f_score = neighbor_node->g_score + neighbor_node->h_score;
                neighbor_node->parent = current_node;
                open_list[open_list_size++] = neighbor_node;
            }
        }

        // east
        if(is_valid_state(row, col+1) && is_unblocked(grid, row, col+1)) {
            Node* neighbor_node = create_node(row, col+1);
            if(!neighbor_node->is_visited) {
                neighbor_node->g_score = current_node->g_score + 1;
                neighbor_node->h_score = manhattan_distance(neighbor_node, goal_node);
                neighbor_node->f_score = neighbor_node->g_score + neighbor_node->h_score;
                neighbor_node->parent = current_node;
                open_list[open_list_size++] = neighbor_node;
            }
        }

        // south
        if(is_valid_state(row+1, col) && is_unblocked(grid, row+1, col)) {
            Node* neighbor_node = create_node(row+1, col);
            if(!neighbor_node->is_visited) {
                neighbor_node->g_score = current_node->g_score + 1;
                neighbor_node->h_score = manhattan_distance(neighbor_node, goal_node);
                neighbor_node->f_score = neighbor_node->g_score + neighbor_node->h_score;
                neighbor_node->parent = current_node;
                open_list[open_list_size++] = neighbor_node;
            }
        }

        // west
        if(is_valid_state(row, col-1) && is_unblocked(grid, row, col-1)) {
            Node* neighbor_node = create_node(row, col-1);
            if(!neighbor_node->is_visited) {
                neighbor_node->g_score = current_node->g_score + 1;
                neighbor_node->h_score = manhattan_distance(neighbor_node, goal_node);
                neighbor_node->f_score = neighbor_node->g_score + neighbor_node->h_score;
                neighbor_node->parent = current_node;
                open_list[open_list_size++] = neighbor_node;
            }
        }
    }

    printf("Unable to find the destination.\n");
}

int main() {
    // initialize the grid with blocked and unblocked cells
    int grid[ROWS][COLS] = {
        {0, 1, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 1, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {1, 0, 1, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 1, 0, 1, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Node* start_node = create_node(0, 0);
    Node* goal_node = create_node(9, 9);

    run_a_star(grid, start_node, goal_node);

    return 0;
}