//Falcon-180B DATASET v1.0 Category: Procedurally Generated Maze ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int width, height, start_x, start_y, end_x, end_y;
int **maze;

void generate_maze(int x, int y) {
    int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
    int count = 0;
    int nx, ny;

    if (x < 0 || x >= width || y < 0 || y >= height)
        return;

    if (maze[y][x] & 1)
        return;

    maze[y][x] |= 1;
    count++;

    for (int i = 0; i < 4; i++) {
        nx = x + dir[i][0];
        ny = y + dir[i][1];

        if (nx >= 0 && nx < width && ny >= 0 && ny < height &&
           !maze[ny][nx]) {
            generate_maze(nx, ny);
        }
    }

    if (count == 1) {
        start_x = x;
        start_y = y;
    } else if (count == width * height - 1) {
        end_x = x;
        end_y = y;
    }
}

void print_maze(int x, int y) {
    if (x < 0 || x >= width || y < 0 || y >= height)
        return;

    if (maze[y][x] & 1) {
        printf("#");
    } else {
        printf(" ");
    }
}

int main() {
    srand(time(NULL));
    int i, j;

    printf("Enter the width of the maze: ");
    scanf("%d", &width);
    printf("Enter the height of the maze: ");
    scanf("%d", &height);

    maze = (int **)malloc(height * sizeof(int *));
    for (i = 0; i < height; i++) {
        maze[i] = (int *)malloc(width * sizeof(int));
        for (j = 0; j < width; j++) {
            maze[i][j] = 0;
        }
    }

    generate_maze(0, 0);

    printf("\n");
    for (i = 0; i < height; i++) {
        for (j = 0; j < width; j++) {
            print_maze(j, i);
        }
        printf("\n");
    }

    return 0;
}