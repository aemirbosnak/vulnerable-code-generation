//GEMINI-pro DATASET v1.0 Category: A* Pathfinding Algorithm ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ROWS 10
#define COLS 10

typedef struct Node {
    int x, y;
    float g, h, f;
    struct Node *parent;
} Node;

Node *start, *end;
Node *grid[ROWS][COLS];

void init_grid() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = malloc(sizeof(Node));
            grid[i][j]->x = j;
            grid[i][j]->y = i;
            grid[i][j]->g = INFINITY;
            grid[i][j]->h = 0;
            grid[i][j]->f = INFINITY;
            grid[i][j]->parent = NULL;
        }
    }
}

void set_start_end(int sx, int sy, int ex, int ey) {
    start = grid[sy][sx];
    end = grid[ey][ex];
}

float heuristic(Node *a, Node *b) {
    return sqrt((a->x - b->x) * (a->x - b->x) + (a->y - b->y) * (a->y - b->y));
}

Node *get_lowest_f() {
    Node *lowest = NULL;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (grid[i][j]->f < lowest->f) {
                lowest = grid[i][j];
            }
        }
    }
    return lowest;
}

int is_valid(Node *node) {
    return node->x >= 0 && node->x < COLS && node->y >= 0 && node->y < ROWS && node->g != INFINITY;
}

void reconstruct_path(Node *node) {
    while (node != NULL) {
        printf("(%d, %d)\n", node->x, node->y);
        node = node->parent;
    }
}

void astar() {
    start->g = 0;
    start->f = heuristic(start, end);

    while (!is_valid(end)) {
        Node *current = get_lowest_f();
        current->g = INFINITY;

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) continue;

                Node *neighbor = grid[current->y + i][current->x + j];
                if (!is_valid(neighbor)) continue;

                float tentative_g = current->g + 1;
                if (tentative_g < neighbor->g) {
                    neighbor->parent = current;
                    neighbor->g = tentative_g;
                    neighbor->f = neighbor->g + heuristic(neighbor, end);
                }
            }
        }
    }

    reconstruct_path(end);
}

int main() {
    init_grid();
    set_start_end(0, 0, 9, 9);
    astar();
    return 0;
}