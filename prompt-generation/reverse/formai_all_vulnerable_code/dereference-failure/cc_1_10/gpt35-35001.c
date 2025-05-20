//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLS 10

typedef struct node {
    int row, col;
    struct node* parent;
    struct node* next;
} Node;

void print_grid(int grid[ROWS][COLS], Node* start, Node* goal) {
    for (int r = 0; r < ROWS; r++) {
        for (int c = 0; c < COLS; c++) {
            if (r == start->row && c == start->col) {
                printf("S ");
            } else if (r == goal->row && c == goal->col) {
                printf("E ");
            } else if (grid[r][c] == 0) {
                printf("- ");
            } else {
                printf("X ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int manhattan_dist(int row1, int col1, int row2, int col2) {
    return abs(row1 - row2) + abs(col1 - col2);
}

int min_node(Node** open_list, int* f_vals) {
    int min_index = 0;
    int min_f_val = f_vals[0];
    for (int i = 1; i < ROWS * COLS; i++) {
        if (open_list[i] != NULL && f_vals[i] < min_f_val) {
            min_index = i;
            min_f_val = f_vals[i];
        }
    }
    return min_index;
}

void insert_node(Node** list, Node* node, int* f_vals, int g_val) {
    int index = node->row * COLS + node->col;
    if (list[index] == NULL || g_val < f_vals[index]) {
        node->next = list[index];
        list[index] = node;
        f_vals[index] = g_val + manhattan_dist(node->row, node->col, 0, 0);
    }
}

void remove_node(Node** list, int row, int col) {
    int index = row * COLS + col;
    Node* curr = list[index];
    if (curr->row == row && curr->col == col) {
        list[index] = curr->next;
    } else {
        while (curr->next->row != row || curr->next->col != col) {
            curr = curr->next;
        }
        curr->next = curr->next->next;
    }
}

Node* create_node(int row, int col, Node* parent) {
    Node* node = (Node*) malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->parent = parent;
    node->next = NULL;
    return node;
}

Node* min_path(Node* start, Node* goal, int grid[ROWS][COLS]) {
    Node* open_list[ROWS * COLS] = {NULL};
    Node* closed_list[ROWS * COLS] = {NULL};
    int f_vals[ROWS * COLS] = {0};
    
    insert_node(open_list, start, f_vals, 0);
    
    while (open_list[0] != NULL) {
        int curr_index = min_node(open_list, f_vals);
        Node* curr = open_list[curr_index];
        
        if (curr->row == goal->row && curr->col == goal->col) {
            return curr;
        }
        
        remove_node(open_list, curr->row, curr->col);
        insert_node(closed_list, curr, f_vals, 0);
        
        for (int r = curr->row - 1; r <= curr->row + 1; r++) {
            for (int c = curr->col - 1; c <= curr->col + 1; c++) {
                if (r >= 0 && r < ROWS && c >= 0 && c < COLS && (r == curr->row || c == curr->col)) {
                    if (grid[r][c] == 0) {
                        Node* new_node = create_node(r, c, curr);
                        insert_node(open_list, new_node, f_vals, f_vals[curr_index] + 1);
                    }
                }
            }
        }
    }
    
    return NULL;
}

int main() {
    int grid[ROWS][COLS] = {{0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
                            {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                            {0, 1, 1, 0, 1, 1, 1, 0, 1, 0},
                            {0, 1, 1, 1, 1, 0, 0, 1, 1, 0},
                            {0, 1, 0, 0, 0, 1, 1, 1, 1, 0},
                            {0, 1, 1, 1, 0, 1, 1, 1, 1, 0},
                            {0, 1, 0, 1, 1, 1, 0, 1, 1, 0},
                            {0, 1, 0, 0, 0, 1, 0, 0, 1, 0},
                            {0, 0, 1, 1, 1, 1, 1, 1, 1, 0},
                            {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}};
    
    Node* start = create_node(1, 1, NULL);
    Node* goal = create_node(8, 8, NULL);
    
    Node* path = min_path(start, goal, grid);
    
    if (path == NULL) {
        printf("No path found.\n");
    } else {
        printf("Path found.\n");
        print_grid(grid, start, goal);
        while (path != NULL) {
            printf("(%d, %d)\n", path->row, path->col);
            path = path->parent;
        }
    }
    
    return 0;
}