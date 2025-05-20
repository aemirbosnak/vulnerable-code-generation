//GEMINI-pro DATASET v1.0 Category: Maze Route Finder ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point start;
    point end;
} maze;

typedef struct {
    point *arr;
    int size;
} stack;

stack *create_stack() {
    stack *s = malloc(sizeof(stack));
    s->arr = malloc(sizeof(point) * MAX_SIZE);
    s->size = 0;
    return s;
}

void push(stack *s, point p) {
    s->arr[s->size++] = p;
}

point pop(stack *s) {
    return s->arr[--s->size];
}

bool is_empty(stack *s) {
    return s->size == 0;
}

void free_stack(stack *s) {
    free(s->arr);
    free(s);
}

maze *create_maze(int size) {
    maze *m = malloc(sizeof(maze));
    m->start.x = 0;
    m->start.y = 0;
    m->end.x = size - 1;
    m->end.y = size - 1;
    return m;
}

void free_maze(maze *m) {
    free(m);
}

bool is_valid(maze *m, point p) {
    return p.x >= 0 && p.x < m->end.x && p.y >= 0 && p.y < m->end.y;
}

bool is_goal(maze *m, point p) {
    return p.x == m->end.x && p.y == m->end.y;
}

void print_maze(maze *m) {
    for (int i = 0; i < m->end.x; i++) {
        for (int j = 0; j < m->end.y; j++) {
            printf("%c", (i == m->start.x && j == m->start.y) ? 'S' : (i == m->end.x && j == m->end.y) ? 'E' : '.');
        }
        printf("\n");
    }
}

bool find_path(maze *m, stack *s) {
    push(s, m->start);

    while (!is_empty(s)) {
        point p = pop(s);

        if (is_goal(m, p)) {
            return true;
        }

        point next_p;
        next_p.x = p.x + 1;
        next_p.y = p.y;
        if (is_valid(m, next_p)) {
            push(s, next_p);
        }

        next_p.x = p.x - 1;
        next_p.y = p.y;
        if (is_valid(m, next_p)) {
            push(s, next_p);
        }

        next_p.x = p.x;
        next_p.y = p.y + 1;
        if (is_valid(m, next_p)) {
            push(s, next_p);
        }

        next_p.x = p.x;
        next_p.y = p.y - 1;
        if (is_valid(m, next_p)) {
            push(s, next_p);
        }
    }

    return false;
}

int main() {
    int size;
    printf("Enter the size of the maze: ");
    scanf("%d", &size);

    maze *m = create_maze(size);
    print_maze(m);

    stack *s = create_stack();
    bool found = find_path(m, s);

    if (found) {
        printf("Path found!\n");
    } else {
        printf("Path not found!\n");
    }

    free_stack(s);
    free_maze(m);

    return 0;
}