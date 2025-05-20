//FormAI DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

#define ROWS 10
#define COLUMNS 10

typedef struct node {
    int x;
    int y;
    int f;
    int g;
    int h;
    struct node* parent;
} node;

node* create_node(int x, int y, node* parent, int g, int h) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->parent = parent;
    new_node->g = g;
    new_node->h = h;
    new_node->f = g + h;
    return new_node;
}

int heuristic(int x, int y, int target_x, int target_y) {
    return abs(x - target_x) + abs(y - target_y);
}

void insert_in_open_list(node* new_node, node** open_list, int* open_list_size) {
    int i;
    for (i = 0; i < *open_list_size; i++) {
        if (new_node->f < open_list[i]->f) {
            break;
        }
    }
    *open_list_size = *open_list_size + 1;
    int j;
    for (j = *open_list_size - 1; j > i; j--) {
        open_list[j] = open_list[j - 1];
    }
    open_list[i] = new_node;
}

node* retrieve_smallest_f(node** open_list, int* open_list_size) {
    node* smallest_f = open_list[0];
    int i;
    for (i = 0; i < *open_list_size - 1; i++) {
        open_list[i] = open_list[i + 1];
    }
    *open_list_size = *open_list_size - 1;
    return smallest_f;
}

int is_valid(int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLUMNS) {
        return 0;
    }
    return 1;
}

int is_on_closed_list(node* n, node** closed_list, int closed_list_size) {
    int i;
    for (i = 0; i < closed_list_size; i++) {
        if (n->x == closed_list[i]->x && n->y == closed_list[i]->y) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int map[ROWS][COLUMNS] = {{0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 1, 0, 1, 0, 1, 0, 1, 0, 0},
                              {0, 1, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 1, 1, 1, 1, 1, 1, 1, 0, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
                              {0, 0, 1, 1, 1, 1, 1, 0, 1, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 1, 0, 1, 1, 1, 0, 1, 0},
                              {0, 0, 1, 0, 0, 0, 0, 0, 1, 0},
                              {0, 0, 0, 0, 0, 1, 0, 0, 0, 0}};

    int starting_x = 0;
    int starting_y = 0;
    int target_x = 9;
    int target_y = 9;

    node* starting_node = create_node(starting_x, starting_y, NULL, 0, heuristic(starting_x, starting_y, target_x, target_y));
    node* open_list[ROWS*COLUMNS];
    int open_list_size = 1;
    open_list[0] = starting_node;
    node* closed_list[ROWS*COLUMNS];
    int closed_list_size = 0;

    while (open_list_size > 0) {
        node* current_node = retrieve_smallest_f(open_list, &open_list_size);
        if (current_node->x == target_x && current_node->y == target_y) {
            printf("Path found!");
            break;
        }
        closed_list[closed_list_size] = current_node;
        closed_list_size++;
        int i;
        for (i = -1; i <= 1; i++) {
            int j;
            for (j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                if (!is_valid(current_node->x + i, current_node->y + j)) {
                    continue;
                }
                if (map[current_node->x + i][current_node->y + j] == 1) {
                    continue;
                }
                node* neighbor_node = create_node(current_node->x + i, current_node->y + j, current_node, current_node->g + 1, heuristic(current_node->x + i, current_node->y + j, target_x, target_y));
                if (is_on_closed_list(neighbor_node, closed_list, closed_list_size)) {
                    continue;
                }
                insert_in_open_list(neighbor_node, open_list, &open_list_size);
            }
        }
    }

    return 0;
}