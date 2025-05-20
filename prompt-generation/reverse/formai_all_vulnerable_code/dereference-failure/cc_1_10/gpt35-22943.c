//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROW 6
#define COL 6

int heuristic[ROW][COL] = {
        {1, 2, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 2},
        {1, 1, 1, 1, 1, 1}
};

struct Node {
    int x, y;
    int g, h, f;
    struct Node *parent;
};

struct List {
    struct Node *node;
    struct List *next;
};

struct List * open_list[ROW][COL];
struct List * closed_list[ROW][COL];

bool is_valid_position(int row, int col) {
    return (row >= 0 && row < ROW && col >= 0 && col < COL);
}

bool is_obstacle(int matrix[ROW][COL], int row, int col) {
    return matrix[row][col] == 0;
}

bool is_in_closed_list(int row, int col) {
    struct List* ptr = closed_list[row][col];
    while (ptr != NULL) {
        if (ptr->node->x == row && ptr->node->y == col) {
            return true;
        }
        ptr = ptr->next;
    }
    return false;
}

struct Node* create_node(int x, int y, int g, int h, struct Node* parent) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->x = x;
    new_node->y = y;
    new_node->g = g;
    new_node->h = h;
    new_node->f = g + h;
    new_node->parent = parent;
    return new_node;
}

int get_g_value(struct Node* node) {
    return node->g + 1;
}

void insert_node_to_open_list(struct Node* node, int row, int col) {
    struct List* new_list_node = (struct List*)malloc(sizeof(struct List));
    new_list_node->node = node;
    new_list_node->next = open_list[row][col];
    open_list[row][col] = new_list_node;
}

void print_path(struct Node* node) {
    struct Node* ptr = node;
    while (ptr != NULL) {
        printf("(%d,%d) -> ", ptr->x, ptr->y);
        ptr = ptr->parent;
    }
}

void a_star(int matrix[ROW][COL], int start_row, int start_col, int end_row, int end_col) {
    int dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1};
    int dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};

    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COL; j++) {
            open_list[i][j] = NULL;
            closed_list[i][j] = NULL;
        }
    }

    struct Node* start_node = create_node(start_row, start_col, 0, heuristic[start_row][start_col], NULL);
    insert_node_to_open_list(start_node, start_row, start_col);

    while (open_list[end_row][end_col] != NULL) {
        int min_f = 9999, curr_row = -1, curr_col = -1;
        for (int i = 0; i < ROW; i++) {
            for (int j = 0; j < COL; j++) {
                if (open_list[i][j] != NULL && open_list[i][j]->node->f < min_f) {
                    min_f = open_list[i][j]->node->f;
                    curr_row = i;
                    curr_col = j;
                }
            }
        }

        struct Node* curr_node = open_list[curr_row][curr_col]->node;

        if (curr_node->x == end_row && curr_node->y == end_col) {
            print_path(curr_node);
            return;
        }

        open_list[curr_row][curr_col] = open_list[curr_row][curr_col]->next;

        struct List* new_list_node = (struct List*)malloc(sizeof(struct List));
        new_list_node->node = curr_node;
        new_list_node->next = closed_list[curr_row][curr_col];
        closed_list[curr_row][curr_col] = new_list_node;

        for (int i = 0; i < 8; i++) {
            int new_x = curr_row + dx[i];
            int new_y = curr_col + dy[i];

            if (is_valid_position(new_x, new_y) && !is_obstacle(matrix, new_x, new_y) && !is_in_closed_list(new_x, new_y)) {
                int g_val = get_g_value(curr_node);
                struct Node* new_node = create_node(new_x, new_y, g_val, heuristic[new_x][new_y], curr_node);
                insert_node_to_open_list(new_node, new_x, new_y);
            }
        }
    }

    printf("Path not found\n");
}

int main() {
    int matrix[ROW][COL] = {
            {1, 1, 0, 1, 1, 1},
            {1, 0, 1, 1, 1, 1},
            {1, 1, 1, 1, 0, 1},
            {1, 1, 1, 0, 1, 1},
            {1, 1, 1, 1, 1, 0},
            {1, 1, 1, 1, 1, 1}
    };
    a_star(matrix, 0, 0, 5, 5);
    return 0;
}