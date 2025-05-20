//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAZE_SIZE 10
#define START_X 0
#define START_Y 0
#define END_X 9
#define END_Y 9

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point *points;
    int size;
} stack;

void init_stack(stack *s) {
    s->points = malloc(sizeof(point) * MAZE_SIZE * MAZE_SIZE);
    s->size = 0;
}

void push(stack *s, point p) {
    s->points[s->size++] = p;
}

point pop(stack *s) {
    return s->points[--s->size];
}

int is_empty(stack *s) {
    return s->size == 0;
}

char maze[MAZE_SIZE][MAZE_SIZE] = {
    {'#', '#', '#', '#', '#', '#', '#', '#', '#', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '#', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'},
    {'#', '.', '#', '#', '#', '#', '#', '#', '.', '#'},
    {'#', '.', '.', '.', '.', '.', '.', '.', '.', '#'}
};

int is_valid_move(int x, int y) {
    return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && maze[y][x] != '#';
}

int find_path(int x, int y) {
    stack s;
    init_stack(&s);
    point p = {x, y};
    push(&s, p);

    while (!is_empty(&s)) {
        p = pop(&s);

        if (p.x == END_X && p.y == END_Y) {
            return 1;
        }

        if (is_valid_move(p.x + 1, p.y)) {
            p.x++;
            push(&s, p);
        }

        if (is_valid_move(p.x - 1, p.y)) {
            p.x--;
            push(&s, p);
        }

        if (is_valid_move(p.x, p.y + 1)) {
            p.y++;
            push(&s, p);
        }

        if (is_valid_move(p.x, p.y - 1)) {
            p.y--;
            push(&s, p);
        }
    }

    return 0;
}

int main() {
    if (find_path(START_X, START_Y)) {
        printf("Path found!\n");
    } else {
        printf("No path found.\n");
    }

    return 0;
}