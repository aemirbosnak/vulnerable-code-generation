//MISTRAL-7B DATASET v1.0 Category: Pattern printing ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define WIDTH 21
#define HEIGHT 11

typedef struct {
    int x;
    int y;
} point;

void init_grid(char grid[HEIGHT][WIDTH]);
void print_solid_rectangle(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2);
void print_diagonal_pattern(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2);
void print_spiral_pattern(char grid[HEIGHT][WIDTH]);

int main() {
    char grid[HEIGHT][WIDTH];

    init_grid(grid);

    print_solid_rectangle(grid, 0, 0, WIDTH - 1, HEIGHT - 1);
    print_diagonal_pattern(grid, 0, 0, WIDTH - 1, HEIGHT - 1);
    print_spiral_pattern(grid);

    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%c", grid[i][j]);
        }
        printf("\n");
    }

    return 0;
}

void init_grid(char grid[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            grid[i][j] = ' ';
        }
    }
}

void print_solid_rectangle(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    for (int i = y1; i <= y2; i++) {
        for (int j = x1; j <= x2; j++) {
            grid[i][j] = '#';
        }
    }
}

void print_diagonal_pattern(char grid[HEIGHT][WIDTH], int x1, int y1, int x2, int y2) {
    int dx = x2 - x1;
    int dy = y1 - y2;

    for (int i = 0; i < abs(dx) > abs(dy) ? abs(dx) : abs(dy); i++) {
        int x = x1 + (i > 0 ? i * (dx > 0 ? 1 : -1) : x1);
        int y = y1 + (i > 0 ? i * (dy > 0 ? 1 : -1) : y1);

        grid[y][x] = 'O';
    }
}

void print_spiral_pattern(char grid[HEIGHT][WIDTH]) {
    point start = {0, 0};
    point end = {WIDTH - 1, HEIGHT - 1};
    point current = start;
    int direction = 0;

    while (current.x != end.x || current.y != end.y) {
        switch (direction % 4) {
            case 0:
                current.x++;
                break;
            case 1:
                current.y++;
                break;
            case 2:
                current.x--;
                break;
            case 3:
                current.y--;
                break;
        }

        grid[current.y][current.x] = '*';
        direction++;
    }
}