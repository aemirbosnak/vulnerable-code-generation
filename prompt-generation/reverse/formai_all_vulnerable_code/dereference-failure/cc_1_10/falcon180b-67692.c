//Falcon-180B DATASET v1.0 Category: Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define HEIGHT 10
#define WIDTH 10

void generate_maze(char maze[HEIGHT][WIDTH]);
void print_maze(const char maze[HEIGHT][WIDTH]);
int valid_move(int x, int y, int dx, int dy);

int main() {
    srand(time(NULL));

    char maze[HEIGHT][WIDTH];
    generate_maze(maze);
    print_maze(maze);

    return 0;
}

void generate_maze(char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            maze[i][j] = rand() % 2? '.' : '#';
        }
    }

    int start_x = rand() % HEIGHT;
    int start_y = rand() % WIDTH;

    while (!valid_move(start_x, start_y, 0, -1)) {
        start_x = rand() % HEIGHT;
        start_y = rand() % WIDTH;
    }

    maze[start_x][start_y] = 'S';
    maze[start_x][start_y + 1] = '.';
}

void print_maze(const char maze[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; ++i) {
        for (int j = 0; j < WIDTH; ++j) {
            printf("%c", maze[i][j]);
        }
        printf("\n");
    }
}

int valid_move(int x, int y, int dx, int dy) {
    return x + dx >= 0 && x + dx < HEIGHT && y + dy >= 0 && y + dy < WIDTH;
}