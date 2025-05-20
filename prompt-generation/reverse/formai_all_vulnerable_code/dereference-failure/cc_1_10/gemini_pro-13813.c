//GEMINI-pro DATASET v1.0 Category: Pathfinding algorithms ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define ROWS 5
#define COLS 5

typedef struct {
    int x;
    int y;
    int cost;
    struct point *parent;
} point;

point* init_point(int x, int y, int cost, point *parent) {
    point *p = malloc(sizeof(point));
    p->x = x;
    p->y = y;
    p->cost = cost;
    p->parent = parent;
    return p;
}

int** init_grid() {
    int **grid = malloc(sizeof(int*) * ROWS);
    for (int i = 0; i < ROWS; i++) {
        grid[i] = malloc(sizeof(int) * COLS);
        for (int j = 0; j < COLS; j++) {
            grid[i][j] = 0;
        }
    }
    return grid;
}

void print_grid(int **grid) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            printf("%d ", grid[i][j]);
        }
        printf("\n");
    }
}

int get_cost(int **grid, int x, int y) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return -1;
    }
    return grid[x][y];
}

void set_cost(int **grid, int x, int y, int cost) {
    if (x < 0 || x >= ROWS || y < 0 || y >= COLS) {
        return;
    }
    grid[x][y] = cost;
}

point** init_queue() {
    point **queue = malloc(sizeof(point*) * ROWS * COLS);
    for (int i = 0; i < ROWS * COLS; i++) {
        queue[i] = NULL;
    }
    return queue;
}

void enqueue(point **queue, point *p) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (queue[i] == NULL) {
            queue[i] = p;
            return;
        }
    }
}

point* dequeue(point **queue) {
    point *p = queue[0];
    for (int i = 1; i < ROWS * COLS; i++) {
        queue[i - 1] = queue[i];
    }
    queue[ROWS * COLS - 1] = NULL;
    return p;
}

bool is_in_queue(point **queue, point *p) {
    for (int i = 0; i < ROWS * COLS; i++) {
        if (queue[i] == p) {
            return true;
        }
    }
    return false;
}

bool astar(int **grid, point *start, point *end) {
    point **queue = init_queue();
    enqueue(queue, start);
    while (!is_in_queue(queue, end)) {
        point *current = dequeue(queue);
        if (current == NULL) {
            return false;
        }
        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                if (i == 0 && j == 0) {
                    continue;
                }
                int x = current->x + i;
                int y = current->y + j;
                int cost = get_cost(grid, x, y);
                if (cost == -1) {
                    continue;
                }
                point *neighbor = init_point(x, y, current->cost + cost, current);
                if (!is_in_queue(queue, neighbor)) {
                    enqueue(queue, neighbor);
                }
            }
        }
    }
    return true;
}

int main() {
    int **grid = init_grid();
    point *start = init_point(0, 0, 0, NULL);
    point *end = init_point(4, 4, 0, NULL);
    if (astar(grid, start, end)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }
    return 0;
}