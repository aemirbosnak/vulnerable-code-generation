//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: lively
#include <stdio.h>
#include <stdlib.h>

#define ROW 5
#define COLUMN 5

typedef struct Node Node;
struct Node {
    int f;
    int g;
    int h;
    int row;
    int col;
    Node* parent;
};

typedef struct List List;
struct List {
    Node* node;
    List* next;
};

void print_matrix(int matrix[ROW][COLUMN]) {
    for (int i = 0; i < ROW; i++) {
        for (int j = 0; j < COLUMN; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int is_valid(int row, int col) {
    return row >= 0 && row < ROW && col >= 0 && col < COLUMN;
}

int is_obstacle(int matrix[ROW][COLUMN], int row, int col) {
    return !is_valid(row, col) || matrix[row][col] == 1;
}

int heuristic(int start_row, int start_col, int end_row, int end_col) {
    return abs(start_row - end_row) + abs(start_col - end_col);
}

List* add_sorted(List* list, Node* node) {
    Node* tmp_node = NULL;
    Node* prev_node = NULL;
    List* prev_list = NULL;
    List* curr_list = list;
    while (curr_list != NULL && curr_list->node->f < node->f) {
        prev_list = curr_list;
        curr_list = curr_list->next;
    }
    if (prev_list == NULL) {
        list = malloc(sizeof(List));
        list->node = node;
        list->next = curr_list;
    } else {
        prev_list->next = malloc(sizeof(List));
        prev_list->next->node = node;
        prev_list->next->next = curr_list;
    }
    return list;
}

Node* create_node(int row, int col, int f, int g, int h, Node* parent) {
    Node* node = malloc(sizeof(Node));
    node->row = row;
    node->col = col;
    node->f = f;
    node->g = g;
    node->h = h;
    node->parent = parent;
    return node;
}

Node* a_star(int matrix[ROW][COLUMN], int start_row, int start_col, int end_row, int end_col) {
    List* open_list = NULL;
    List* closed_list = NULL;
    Node* start_node = create_node(start_row, start_col, 0, 0, 0, NULL);
    Node* end_node = create_node(end_row, end_col, 0, 0, 0, NULL);
    open_list = add_sorted(open_list, start_node);
    while (open_list != NULL) {
        Node* curr_node = open_list->node;
        if (curr_node->row == end_row && curr_node->col == end_col) {
            return curr_node;
        }
        closed_list = add_sorted(closed_list, curr_node);
        open_list = open_list->next;
        int row = curr_node->row;
        int col = curr_node->col;
        int g = curr_node->g + 1;
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int new_row = row + i;
                int new_col = col + j;
                if (is_obstacle(matrix, new_row, new_col)) {
                    continue;
                }
                int h = heuristic(new_row, new_col, end_row, end_col);
                int f = g + h;
                Node* new_node = create_node(new_row, new_col, f, g, h, curr_node);
                List* tmp_list = NULL;
                for (List* list = open_list; list != NULL; list = list->next) {
                    if (list->node->row == new_node->row && list->node->col == new_node->col) {
                        tmp_list = list;
                        break;
                    }
                }
                for (List* list = closed_list; list != NULL; list = list->next) {
                    if (list->node->row == new_node->row && list->node->col == new_node->col) {
                        if (list->node->f < new_node->f) {
                            free(new_node);
                            new_node = NULL;
                        } else {
                            tmp_list = list;
                        }
                        break;
                    }
                }
                if (new_node != NULL && tmp_list != NULL) {
                    tmp_list->node->parent = curr_node;
                    tmp_list->node->f = new_node->f;
                    tmp_list->node->g = new_node->g;
                    tmp_list->node->h = new_node->h;
                    free(new_node);
                } else if (new_node != NULL && tmp_list == NULL) {
                    open_list = add_sorted(open_list, new_node);
                }
            }
        }
    }
    return NULL;
}

int main() {
    int matrix[ROW][COLUMN] = {
        {0, 0, 0, 0, 0},
        {0, 1, 1, 0, 0},
        {0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1},
        {0, 0, 0, 0, 0}
    };
    int start_row = 0;
    int start_col = 0;
    int end_row = 4;
    int end_col = 4;
    Node* end_node = a_star(matrix, start_row, start_col, end_row, end_col);
    if (end_node != NULL) {
        printf("Path found:\n");
        while (end_node->parent != NULL) {
            matrix[end_node->row][end_node->col] = 2;
            end_node = end_node->parent;
        }
        matrix[start_row][start_col] = 2;
        print_matrix(matrix);
    } else {
        printf("No path found!\n");
    }
    return 0;
}