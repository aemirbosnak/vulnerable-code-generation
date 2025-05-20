//FormAI DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 10
#define COLS 10

typedef struct {
    int x, y;                     
    int f, g, h;                  
    bool is_closed;
    struct Node* parent;          
} Node;

int get_heuristic(Node* node1, Node* node2) {
    return abs(node1->x - node2->x) + abs(node1->y - node2->y);
}

bool is_valid(int x, int y) {
    return (x >= 0 && x < ROWS && y >= 0 && y < COLS);
}

bool is_blocked(int** grid, int x, int y) {
    return (grid[x][y] == 1);       
}

Node* create_node(int x, int y) {
    Node* node = (Node*)malloc(sizeof(Node));
    node->x = x;
    node->y = y;
    node->f = 0;
    node->g = 0;
    node->h = 0;
    node->parent = NULL;
    return node;
}

void print_path(Node* node) {
    if (node == NULL) { return; }
    print_path(node->parent);
    printf("(%d,%d) ", node->x, node->y);
}

void free_nodes(Node** nodes) {
    for (int i = 0; i < ROWS; i++) {
        free(nodes[i]);
    }
    free(nodes);
}

Node* a_star(int** grid, Node* start_node, Node* end_node) {

    Node** nodes = (Node**)malloc(sizeof(Node*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        nodes[i] = (Node*) malloc(sizeof(Node) * COLS);
    }
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            nodes[i][j].x = i;
            nodes[i][j].y = j;
            nodes[i][j].f = 0;
            nodes[i][j].g = 0;
            nodes[i][j].h = 0;
            nodes[i][j].is_closed = false;
            nodes[i][j].parent = NULL;
        }
    }

    start_node = &nodes[start_node->x][start_node->y];
    end_node = &nodes[end_node->x][end_node->y];

    start_node->g = 0;
    start_node->h = get_heuristic(start_node, end_node);
    start_node->f = start_node->g + start_node->h;

    Node* open_list[ROWS * COLS] = { NULL };
    int open_count = 0;
    open_list[0] = start_node;
    open_count++;
    Node* current_node = NULL;

    while (open_count > 0) {
        int current_index = 0;
        int current_f = open_list[0]->f;

        for (int i = 1; i < open_count; i++) {
            if (open_list[i]->f < current_f) {
                current_index = i;
                current_f = open_list[i]->f;
            }
        }

        current_node = open_list[current_index];

        if (current_node == end_node) {
            free_nodes(nodes);
            return current_node;
        }

        open_list[current_index] = NULL;
        open_count--;

        current_node->is_closed = true;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                int neighbour_x = current_node->x + i;
                int neighbour_y = current_node->y + j;

                if (is_valid(neighbour_x, neighbour_y)) {
                    Node* neighbour = &nodes[neighbour_x][neighbour_y];

                    if (!neighbour->is_closed && !is_blocked(grid, neighbour_x, neighbour_y)) {

                        int neighbour_g = current_node->g + ((i == 0 || j == 0) ? 10 : 14);

                        if (neighbour_g < neighbour->g || neighbour->parent == NULL) {
                            neighbour->g = neighbour_g;
                            neighbour->h = get_heuristic(neighbour, end_node);
                            neighbour->f = neighbour->g + neighbour->h;
                            neighbour->parent = current_node;

                            if (neighbour->is_closed) {
                                neighbour->is_closed = false;
                                open_list[open_count] = neighbour;
                                open_count++;
                            }
                        }
                    }
                }
            }
        }
    }

    free_nodes(nodes);
    return NULL;
}

int main() {

    int grid[ROWS][COLS] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 1, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 1, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 1, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 1, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 1, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 1, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    Node* start_node = create_node(0, 0);
    Node* end_node = create_node(9, 9);

    Node* path = a_star((int**)grid, start_node, end_node);

    if (path == NULL) { printf("Path not possible!\n"); }
    else { print_path(path); }

    return 0;
}