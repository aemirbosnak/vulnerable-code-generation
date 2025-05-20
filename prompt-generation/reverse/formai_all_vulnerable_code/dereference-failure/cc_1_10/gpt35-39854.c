//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: Dennis Ritchie
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ROW 6
#define COL 8

struct Node {
    int row, col;
    int f_cost, g_cost, h_cost;
    struct Node* parent;
};

bool is_valid(int row, int col);
bool is_destination(int row, int col, struct Node* dest);
void trace_path(struct Node* dest);
void a_star_search(int grid[][COL], struct Node* src, struct Node* dest);

int row_direction[] = {-1, 0, 1, 0};
int col_direction[] = {0, 1, 0, -1};

int main() {
    int grid[ROW][COL] = {
            {1, 1, 1, 1, 0, 1, 0, 1},
            {0, 0, 1, 0, 1, 1, 1, 0},
            {0, 0, 0, 0, 1, 0, 1, 1},
            {1, 1, 1, 0, 1, 1, 1, 1},
            {0, 0, 1, 1, 1, 0, 0, 0},
            {1, 1, 0, 1, 0, 1, 1, 1}
    };

    struct Node source = {0, 0, 0, 0, 0, NULL};
    struct Node destination = {ROW-1, COL-1, 0, 0, 0, NULL};

    a_star_search(grid, &source, &destination);

    return 0;
}

bool is_valid(int row, int col) {
    return row >=0 && row < ROW && col >= 0 && col < COL;
}

bool is_destination(int row, int col, struct Node* dest) {
    return row == dest->row && col == dest->col;
}

void trace_path(struct Node* dest) {
    struct Node* current = dest;
    while(current) {
        printf("(%d,%d) -> ", current->row, current->col);
        current = current->parent;
    }
}

void a_star_search(int grid[][COL], struct Node* src, struct Node* dest) {

    if(!is_valid(src->row, src->col)) {
        printf("Invalid source\n");
        return;
    }

    if(!is_valid(dest->row, dest->col)) {
        printf("Invalid destination\n");
        return;
    }

    if(grid[src->row][src->col] == 0 || grid[dest->row][dest->col] == 0) {
        printf("Blocked source or destination\n");
        return;
    }

    bool** visited = malloc(sizeof(bool*) * ROW);
    for(int i=0; i<ROW; i++) {
        visited[i] = calloc(sizeof(bool), COL);
    }

    struct Node** node_map = malloc(sizeof(struct Node*) * ROW);
    for(int i=0; i<ROW; i++) {
        node_map[i] = malloc(sizeof(struct Node) * COL);
        for(int j=0; j<COL; j++) {
            node_map[i][j].row = i;
            node_map[i][j].col = j;
            node_map[i][j].f_cost = node_map[i][j].g_cost = node_map[i][j].h_cost = 0;
            node_map[i][j].parent = NULL;
        }
    }

    int src_row = src->row;
    int src_col = src->col;
    node_map[src_row][src_col].f_cost = node_map[src_row][src_col].g_cost = node_map[src_row][src_col].h_cost = 0;
    node_map[src_row][src_col].parent = NULL;

    struct Node* open_list[ROW*COL];
    int open_list_size = 0;
    open_list[open_list_size++] = &node_map[src_row][src_col];

    while(open_list_size > 0) {
        struct Node* current_node = open_list[0];
        int current_index = 0;
        for(int i=1; i<open_list_size; i++) {
            if(open_list[i]->f_cost < current_node->f_cost) {
                current_node = open_list[i];
                current_index = i;
            }
        }

        open_list_size--;

        open_list[current_index] = open_list[open_list_size];

        if(is_destination(current_node->row, current_node->col, dest)) {
            printf("\nPath Found!\n\n");
            trace_path(current_node);
            printf("\n");
            return;
        }

        int row = current_node->row;
        int col = current_node->col;

        visited[row][col] = true;

        for(int i=0; i<4; i++) {
            int new_row = row + row_direction[i];
            int new_col = col + col_direction[i];

            if(is_valid(new_row, new_col) && grid[new_row][new_col] == 1) {
                if(visited[new_row][new_col]) {
                    continue;
                }

                int f_cost = current_node->g_cost + 1 + abs(new_row - dest->row) + abs(new_col - dest->col);
                int g_cost = current_node->g_cost + 1;
                int h_cost = abs(new_row - dest->row) + abs(new_col - dest->col);

                if(!node_map[new_row][new_col].f_cost || f_cost < node_map[new_row][new_col].f_cost) {
                    node_map[new_row][new_col].f_cost = f_cost;
                    node_map[new_row][new_col].g_cost = g_cost;
                    node_map[new_row][new_col].h_cost = h_cost;
                    node_map[new_row][new_col].parent = current_node;

                    if(!visited[new_row][new_col]) {
                        open_list[open_list_size++] = &node_map[new_row][new_col];
                    }
                }
            }
        }
    }

    printf("No Path Found!\n");
}