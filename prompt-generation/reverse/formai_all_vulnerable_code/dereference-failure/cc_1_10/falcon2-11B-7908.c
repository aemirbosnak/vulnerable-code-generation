//Falcon2-11B DATASET v1.0 Category: Procedurally Generated Maze ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_X 100
#define MAX_Y 100

struct Maze {
    int x, y;
    struct Maze* next;
};

struct Maze* create_maze(int x, int y) {
    struct Maze* new_maze = malloc(sizeof(struct Maze));
    new_maze->x = x;
    new_maze->y = y;
    new_maze->next = NULL;
    return new_maze;
}

void print_maze(struct Maze* maze) {
    printf("Maze size: %dx%d\n", maze->x, maze->y);
    printf("Maze:\n");
    struct Maze* curr_maze = maze;
    while (curr_maze!= NULL) {
        for (int i = 0; i < curr_maze->x; i++) {
            for (int j = 0; j < curr_maze->y; j++) {
                if (i < curr_maze->x / 2 && j < curr_maze->y / 2) {
                    printf("*");
                } else {
                    printf("#");
                }
            }
            printf("\n");
        }
        curr_maze = curr_maze->next;
    }
    printf("\n");
}

void generate_maze(struct Maze* maze) {
    struct Maze* start = create_maze(1, 1);
    struct Maze* end = create_maze(MAX_X - 2, MAX_Y - 2);
    struct Maze* current = start;
    struct Maze* prev = NULL;
    int x_steps = 0;
    int y_steps = 0;
    while (current!= end) {
        if (rand() % 2 == 0) {
            if (current->x < MAX_X - 1) {
                struct Maze* new_maze = create_maze(current->x + 1, current->y);
                new_maze->next = current;
                current = new_maze;
                x_steps++;
            }
        } else {
            if (current->y < MAX_Y - 1) {
                struct Maze* new_maze = create_maze(current->x, current->y + 1);
                new_maze->next = current;
                current = new_maze;
                y_steps++;
            }
        }
        prev = current;
        current = current->next;
    }
    start->next = end;
}

int main() {
    srand(time(NULL));
    struct Maze* maze = create_maze(MAX_X, MAX_Y);
    generate_maze(maze);
    print_maze(maze);
    return 0;
}