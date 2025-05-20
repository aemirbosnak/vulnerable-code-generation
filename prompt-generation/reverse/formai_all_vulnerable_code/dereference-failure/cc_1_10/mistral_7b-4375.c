//MISTRAL-7B DATASET v1.0 Category: Procedurally Generated Maze ; Style: immersive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define WIDTH 41
#define HEIGHT 21
#define CELL_SIZE 2

typedef struct {
    int x, y;
} point;

void print_maze(bool** maze) {
    int i, j;

    for (i = 0; i < HEIGHT; i++) {
        for (j = 0; j < WIDTH; j++) {
            if (maze[i][j])
                printf("#");
            else
                printf(" ");
        }
        printf("\n");
    }
}

bool is_valid_move(bool** maze, int x, int y) {
    return x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && !maze[y][x];
}

void generate_maze(bool** maze) {
    point stack[WIDTH * HEIGHT / 2];
    int top = 0;
    point current = {.x = 0, .y = 0};
    int dx[4] = {-1, 1, 1, -1};
    int dy[4] = {-1, -1, 1, 1};

    maze[current.y][current.x] = true;
    stack[top++] = current;

    while (top) {
        current = stack[--top];

        int next_x, next_y;
        for (int dir = 0; dir < 4; dir++) {
            next_x = current.x + dx[dir];
            next_y = current.y + dy[dir];

            if (is_valid_move(maze, next_x, next_y)) {
                maze[next_y][next_x] = true;
                stack[top++] = (point){next_x, next_y};
            }
        }
    }
}

int main() {
    srand(time(NULL));

    bool** maze = malloc(HEIGHT * sizeof(bool*));
    for (int i = 0; i < HEIGHT; i++) {
        maze[i] = calloc(WIDTH, sizeof(bool));
    }

    generate_maze(maze);

    printf("Welcome adventurer to the mystical maze of Enchanted Forest!\n");
    printf("Use WASD keys to navigate through the maze. Good luck!\n");

    while (true) {
        int x = getchar() - 'A' + 1;
        int y = getchar() - '0';

        if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT && maze[y][x]) {
            printf("You reached a new room in the maze.\n");
        } else {
            printf("You hit a wall. Try another direction.\n");
            getchar();
        }

        print_maze(maze);
    }

    for (int i = 0; i < HEIGHT; i++) {
        free(maze[i]);
    }
    free(maze);

    return 0;
}