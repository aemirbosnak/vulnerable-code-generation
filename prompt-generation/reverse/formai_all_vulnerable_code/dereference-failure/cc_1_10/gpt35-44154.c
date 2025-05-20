//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROW 7
#define COL 10

struct Node {
    int row;
    int col;
    double f;
    struct Node* parent;
};

int map[ROW][COL] = {
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 1, 1, 0, 1, 1},
    {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
};

double heuristic(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2-x1, 2) + pow(y2-y1, 2));
}

int is_valid(int row, int col) {
    if (row < 0 || col < 0 || row >= ROW || col >= COL) {
        return 0;
    }
    return map[row][col] != 0;
}

int is_destination(int row, int col, struct Node* destination) {
    return row == destination->row && col == destination->col;
}

void print_path(struct Node* node) {
    if (node == NULL) {
        return;
    }
    print_path(node->parent);
    printf("(%d, %d)\n", node->row, node->col);
}

void a_star_search(int start_row, int start_col, int end_row, int end_col) {
    struct Node* start = (struct Node*)malloc(sizeof(struct Node));
    start->row = start_row;
    start->col = start_col;
    start->f = 0.0;
    start->parent = NULL;

    struct Node* destination = (struct Node*)malloc(sizeof(struct Node));
    destination->row = end_row;
    destination->col = end_col;
    destination->f = 0.0;
    destination->parent = NULL;

    if (!is_valid(start_row, start_col)) {
        printf("Start position is not valid.\n");
        return;
    }

    if (!is_valid(end_row, end_col)) {
        printf("Destination is not valid.\n");
        return;
    }

    if (is_destination(start_row, start_col, destination)) {
        printf("You are already at your destination.\n");
        return;
    }

    int open_list_size = 0;
    struct Node** open_list = (struct Node**)malloc(ROW*COL*sizeof(struct Node*));
    for (int i = 0; i < ROW*COL; i++) {
        open_list[i] = NULL;
    }

    int closed_list_size = 0;
    struct Node** closed_list = (struct Node**)malloc(ROW*COL*sizeof(struct Node*));
    for (int i = 0; i < ROW*COL; i++) {
        closed_list[i] = NULL;
    }

    open_list[open_list_size++] = start;

    while (open_list_size > 0) {
        struct Node* current = open_list[0];
        int current_index = 0;
        for (int i = 0; i < open_list_size; i++) {
            if (open_list[i]->f < current->f) {
                current = open_list[i];
                current_index = i;
            }
        }

        open_list[current_index] = open_list[open_list_size-1];
        open_list_size--;

        closed_list[closed_list_size++] = current;

        if (is_destination(current->row, current->col, destination)) {
            printf("Path found!\n");
            print_path(current);
            return;
        }

        struct Node* neighbors[8];
        int neighbor_count = 0;
        int row = current->row;
        int col = current->col;

        if (is_valid(row-1, col)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row-1;
            neighbors[neighbor_count-1]->col = col;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row-1, col, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row+1, col)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row+1;
            neighbors[neighbor_count-1]->col = col;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row+1, col, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row, col-1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row;
            neighbors[neighbor_count-1]->col = col-1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row, col-1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row, col+1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row;
            neighbors[neighbor_count-1]->col = col+1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row, col+1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row-1, col-1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row-1;
            neighbors[neighbor_count-1]->col = col-1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row-1, col-1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row-1, col+1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row-1;
            neighbors[neighbor_count-1]->col = col+1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row-1, col+1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row+1, col-1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row+1;
            neighbors[neighbor_count-1]->col = col-1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row+1, col-1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        if (is_valid(row+1, col+1)) {
            neighbors[neighbor_count++] = (struct Node*)malloc(sizeof(struct Node));
            neighbors[neighbor_count-1]->row = row+1;
            neighbors[neighbor_count-1]->col = col+1;
            neighbors[neighbor_count-1]->f = current->f + heuristic(row+1, col+1, end_row, end_col);
            neighbors[neighbor_count-1]->parent = current;
        }

        for (int i = 0; i < neighbor_count; i++) {
            int is_closed = 0;
            for (int j = 0; j < closed_list_size; j++) {
                if (neighbors[i]->row == closed_list[j]->row && neighbors[i]->col == closed_list[j]->col) {
                    is_closed = 1;
                    break;
                }
            }
            if (is_closed) {
                continue;
            }

            int in_open_list_index = -1;
            for (int j = 0; j < open_list_size; j++) {
                if (neighbors[i]->row == open_list[j]->row && neighbors[i]->col == open_list[j]->col) {
                    in_open_list_index = j;
                    break;
                }
            }

            if (in_open_list_index != -1) {
                if (open_list[in_open_list_index]->f > neighbors[i]->f) {
                    open_list[in_open_list_index]->f = neighbors[i]->f;
                    open_list[in_open_list_index]->parent = current;
                }
                else {
                    free(neighbors[i]);
                    continue;
                }
            }
            else {
                open_list[open_list_size++] = neighbors[i];
            }
        }
    }

    printf("Path not found.\n");
}

int main() {
    int start_row = 1;
    int start_col = 1;
    int end_row = 5;
    int end_col = 8;

    a_star_search(start_row, start_col, end_row, end_col);

    return 0;
}