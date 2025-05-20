//GEMINI-pro DATASET v1.0 Category: Procedurally Generated Maze ; Style: interoperable
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define WIDTH 100
#define HEIGHT 100

typedef struct {
    int x;
    int y;
} point;

typedef struct {
    point* points;
    int size;
} stack;

void push(stack* stack, point* point) {
    stack->points = realloc(stack->points, sizeof(point) * (stack->size + 1));
    stack->points[stack->size] = *point;
    stack->size++;
}

point* pop(stack* stack) {
    stack->size--;
    return &stack->points[stack->size];
}

int is_valid_point(int x, int y) {
    return (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT);
}

int is_visited(int x, int y, int** maze) {
    return maze[x][y] == 1;
}

void mark_visited(int x, int y, int** maze) {
    maze[x][y] = 1;
}

point* get_random_unvisited_neighbor(int x, int y, int** maze) {
    int directions[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
    int num_directions = 4;

    while (num_directions > 0) {
        int random_direction = rand() % num_directions;
        int new_x = x + directions[random_direction][0];
        int new_y = y + directions[random_direction][1];

        if (is_valid_point(new_x, new_y) && !is_visited(new_x, new_y, maze)) {
            return malloc(sizeof(point));
        }

        num_directions--;
    }

    return NULL;
}

void generate_maze(int** maze) {
    stack stack;
    stack.points = malloc(sizeof(point));
    stack.size = 0;

    point* start_point = malloc(sizeof(point));
    start_point->x = 0;
    start_point->y = 0;
    push(&stack, start_point);

    while (stack.size > 0) {
        point* current_point = pop(&stack);

        mark_visited(current_point->x, current_point->y, maze);

        point* neighbor = get_random_unvisited_neighbor(current_point->x, current_point->y, maze);
        if (neighbor != NULL) {
            push(&stack, neighbor);
            maze[current_point->x + (neighbor->x - current_point->x) / 2][current_point->y + (neighbor->y - current_point->y) / 2] = 1;
        }
    }
}

void print_maze(int** maze) {
    for (int i = 0; i < WIDTH; i++) {
        for (int j = 0; j < HEIGHT; j++) {
            printf("%d ", maze[i][j]);
        }
        printf("\n");
    }
}

int main() {
    srand(time(NULL));

    int** maze = malloc(sizeof(int*) * WIDTH);
    for (int i = 0; i < WIDTH; i++) {
        maze[i] = malloc(sizeof(int) * HEIGHT);
    }

    generate_maze(maze);
    print_maze(maze);

    return 0;
}