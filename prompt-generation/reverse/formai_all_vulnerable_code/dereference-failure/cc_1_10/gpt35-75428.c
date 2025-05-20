//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct node {
    int x, y, f, g, h;
    struct node* parent;
} node;

node* create_node(int x, int y) {
    node* new_node = (node*) malloc(sizeof(node));
    new_node->x = x;
    new_node->y = y;
    new_node->f = 0;
    new_node->g = 0;
    new_node->h = 0;
    new_node->parent = NULL;
    return new_node;
}

node** create_map(int row, int col) {
    node** map = (node**) malloc(row*sizeof(node*));
    for (int i = 0; i < row; i++) {
        map[i] = (node*) malloc(col*sizeof(node));
        for (int j = 0; j < col; j++) {
            map[i][j] = *create_node(i, j);
        }
    }
    return map;
}

int heuristic(node* current, node* goal) {
    int dx = abs(current->x - goal->x);
    int dy = abs(current->y - goal->y);
    return dx + dy;
}

bool is_valid(node* current, int row, int col) {
    if (current->x < 0 || current->x >= row || current->y < 0 || current->y >= col) {
        return false;
    }
    return true;
}

bool is_obstacle(node* current) {
    if (current->x == 1 && (current->y >= 2 && current->y <= 6)) {
        return true;
    }
    if (current->x == 3 && (current->y >= 4 && current->y <= 8)) {
        return true;
    }
    return false;
}

void print_path(node* current) {
    if (current == NULL) {
        return;
    }
    print_path(current->parent);
    printf("(%d, %d) ", current->x, current->y);
}

void a_star(node** map, int row, int col, node* start, node* goal) {
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, 1, 0, -1};
    bool closed_list[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            closed_list[i][j] = false;
        }
    }
    start->g = 0;
    start->h = heuristic(start, goal);
    start->f = start->g + start->h;
    node* open_list[row*col];
    int open_size = 1;
    open_list[0] = start;
    while (open_size > 0) {
        node* current = open_list[0];
        if (current->x == goal->x && current->y == goal->y) {
            print_path(current);
            return;
        }
        open_size--;
        open_list[0] = open_list[open_size];
        for (int i = 0; i < 4; i++) {
            node* neighbor = &map[current->x + dx[i]][current->y + dy[i]];
            if (is_valid(neighbor, row, col) && !is_obstacle(neighbor) && !closed_list[neighbor->x][neighbor->y]) {
                int g_score = current->g + 1;
                bool is_in_open = false;
                for (int j = 0; j < open_size; j++) {
                    if (open_list[j] == neighbor) {
                        is_in_open = true;
                        break;
                    }
                }
                if (!is_in_open || g_score < neighbor->g) {
                    neighbor->g = g_score;
                    neighbor->h = heuristic(neighbor, goal);
                    neighbor->f = neighbor->g + neighbor->h;
                    neighbor->parent = current;
                    if (!is_in_open) {
                        open_list[open_size] = neighbor;
                        open_size++;
                    }
                }
            }
        }
        closed_list[current->x][current->y] = true;
        for (int i = open_size/2-1; i >= 0; i--) {
            int max_child = 2*i+1;
            if (max_child < open_size-1 && open_list[max_child]->f < open_list[max_child+1]->f) {
                max_child++;
            }
            if (open_list[i]->f < open_list[max_child]->f) {
                node* temp = open_list[i];
                open_list[i] = open_list[max_child];
                open_list[max_child] = temp;
            }
        }
    }
    printf("No path found!\n");
}

int main() {
    node** map = create_map(6, 10);
    node start = map[0][0];
    node goal = map[5][9];
    a_star(map, 6, 10, &start, &goal);
    return 0;
}