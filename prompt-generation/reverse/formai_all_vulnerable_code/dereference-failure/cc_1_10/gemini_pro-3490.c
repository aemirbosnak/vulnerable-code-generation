//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>

#define MAZE_SIZE 10
#define START_X 0
#define START_Y 0
#define END_X (MAZE_SIZE - 1)
#define END_Y (MAZE_SIZE - 1)

int maze[MAZE_SIZE][MAZE_SIZE] = {
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 1, 0, 1},
    {1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 1, 1, 1, 1, 1, 0, 1, 1, 1},
    {1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
    {1, 0, 1, 1, 1, 1, 1, 1, 0, 1},
    {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

int visited[MAZE_SIZE][MAZE_SIZE];

struct position {
    int x;
    int y;
};

struct stack {
    struct position *positions;
    int top;
};

void init_stack(struct stack *s) {
    s->positions = malloc(sizeof(struct position) * MAZE_SIZE * MAZE_SIZE);
    s->top = -1;
}

void push(struct stack *s, struct position p) {
    s->top++;
    s->positions[s->top] = p;
}

struct position pop(struct stack *s) {
    return s->positions[s->top--];
}

int is_empty(struct stack *s) {
    return s->top == -1;
}

int is_valid(int x, int y) {
    return x >= 0 && x < MAZE_SIZE && y >= 0 && y < MAZE_SIZE && !visited[x][y] && maze[x][y] == 0;
}

void print_path(struct stack *s) {
    while (!is_empty(s)) {
        struct position p = pop(s);
        printf("(%d, %d)\n", p.x, p.y);
    }
}

int find_path() {
    struct stack s;
    init_stack(&s);

    struct position start = {START_X, START_Y};
    push(&s, start);
    visited[start.x][start.y] = 1;

    while (!is_empty(&s)) {
        struct position p = pop(&s);

        if (p.x == END_X && p.y == END_Y) {
            print_path(&s);
            return 1;
        }

        if (is_valid(p.x + 1, p.y)) {
            struct position next = {p.x + 1, p.y};
            push(&s, next);
            visited[next.x][next.y] = 1;
        }

        if (is_valid(p.x - 1, p.y)) {
            struct position next = {p.x - 1, p.y};
            push(&s, next);
            visited[next.x][next.y] = 1;
        }

        if (is_valid(p.x, p.y + 1)) {
            struct position next = {p.x, p.y + 1};
            push(&s, next);
            visited[next.x][next.y] = 1;
        }

        if (is_valid(p.x, p.y - 1)) {
            struct position next = {p.x, p.y - 1};
            push(&s, next);
            visited[next.x][next.y] = 1;
        }
    }

    return 0;
}

int main() {
    if (find_path()) {
        printf("Path found!\n");
    } else {
        printf("No path found!\n");
    }

    return 0;
}