//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int row;
    int col;
    int f, g, h;
    bool is_obstacle;
    struct Node* parent;
} Node;

Node* create_node(int row, int col) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->is_obstacle = false;
    node->parent = NULL;
    return node;
}

Node* get_smallest_f_cost_node(Node** open_list) {
    Node* smallest_node = open_list[0];
    int smallest_f_cost = smallest_node->f;
    for (int i = 1; i < ROWS * COLS; i++) {
        if (open_list[i] == NULL) {
            continue;
        }
        if (open_list[i]->f < smallest_f_cost) {
            smallest_node = open_list[i];
            smallest_f_cost = smallest_node->f;
        }
    }
    return smallest_node;
}

bool is_valid_cell(int row, int col) {
   if (row >= 0 && row < ROWS && col >= 0 && col < COLS)
       return true;
   return false;
}

int manhattan_distance(int row1, int col1, int row2, int col2) {
    int dist = abs(row1 - row2) + abs(col1 - col2);
    return dist;
}

bool is_obstacle_present(int row, int col, int obstacles[][COLS]) {
    if (obstacles[row][col] == 1) {
        return true;
    }
    return false;
}

int main() {
    // define start and goal positions
    int start_row = 2, start_col = 2;
    int goal_row = 8, goal_col = 8;

    // define obstacle positions
    int obstacles[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    };

    Node* start = create_node(start_row, start_col);
    Node* goal = create_node(goal_row, goal_col);

    // initialize the open and closed lists
    Node* open_list[ROWS * COLS];
    for (int i = 0; i < ROWS * COLS; i++) {
        open_list[i] = NULL;
    }
    Node* closed_list[ROWS * COLS];
    for (int i = 0; i < ROWS * COLS; i++) {
        closed_list[i] = NULL;
    }

    // add the start node to the open list
    int start_index = start_row * COLS + start_col;
    open_list[start_index] = start;

    // loop until we find the goal node or run out of nodes to search
    while (open_list[0] != NULL) {
        Node* current_node = get_smallest_f_cost_node(open_list);

        // if we have found the goal node, reconstruct the path and exit the loop
        if (current_node->row == goal->row && current_node->col == goal->col) {
            printf("Found path to goal!\n");
            Node* path_node = current_node;
            while (path_node->parent != NULL) {
                printf("(%d,%d) -> ", path_node->row, path_node->col);
                path_node = path_node->parent;
            }
            printf("(%d,%d)\n", start_row, start_col);
            exit(0);
        }

        // remove the current node from the open list and add it to the closed list
        int current_index = current_node->row * COLS + current_node->col;
        open_list[current_index] = NULL;
        closed_list[current_index] = current_node;

        // loop through all the neighboring nodes
        int delta_rows[] = {-1, 0, 1, 0};
        int delta_cols[] = {0, 1, 0, -1};
        for (int i = 0; i < 4; i++) {
            int neighbor_row = current_node->row + delta_rows[i];
            int neighbor_col = current_node->col + delta_cols[i];

            // if the neighbor is not a valid cell, skip it
            if (!is_valid_cell(neighbor_row, neighbor_col)) {
                continue;
            }

            // if the neighbor is an obstacle, skip it
            if (is_obstacle_present(neighbor_row, neighbor_col, obstacles)) {
                continue;
            }

            // if the neighbor is in the closed list, skip it
            int neighbor_index = neighbor_row * COLS + neighbor_col;
            if (closed_list[neighbor_index] != NULL) {
                continue;
            }

            Node* neighbor_node = create_node(neighbor_row, neighbor_col);
            neighbor_node->parent = current_node;

            // calculate the f, g, h costs for the neighbor node
            int g_cost = current_node->g + 1;
            int h_cost = manhattan_distance(neighbor_row, neighbor_col, goal_row, goal_col);
            int f_cost = g_cost + h_cost;

            neighbor_node->g = g_cost;
            neighbor_node->h = h_cost;
            neighbor_node->f = f_cost;

            // if the neighbor is not in the open list, add it
            if (open_list[neighbor_index] == NULL) {
                open_list[neighbor_index] = neighbor_node;
            }
            // otherwise, update the neighbor in the open list if the new f cost is less
            else if (f_cost < open_list[neighbor_index]->f) {
                open_list[neighbor_index] = neighbor_node;
            }
        }
    }

    printf("Failed to find path to goal.\n");

    return 0;
}