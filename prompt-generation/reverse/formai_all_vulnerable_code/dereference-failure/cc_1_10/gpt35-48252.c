//FormAI DATASET v1.0 Category: Data structures visualization ; Style: medieval
#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int x, y;
} Point;

typedef struct {
    int width, height;
    char** map;
} Grid;

Grid createGrid(int width, int height) {
    Grid grid;
    grid.width = width;
    grid.height = height;

    grid.map = (char**)malloc(sizeof(char*) * height);
    for (int i = 0; i < height; i++) {
        grid.map[i] = (char*)malloc(sizeof(char) * width);
        for (int j = 0; j < width; j++) {
            grid.map[i][j] = '_';
        }
    }

    return grid;
}

void printGrid(Grid grid) {
    for (int i = 0; i < grid.height; i++) {
        for (int j = 0; j < grid.width; j++) {
            printf("%c ", grid.map[i][j]);
        }
        printf("\n");
    }
}

void drawLine(Grid* grid, Point start, Point end, char symbol) {
    if (start.x > end.x) {  // Ensure start is always the leftmost point
        Point temp = start;
        start = end;
        end = temp;
    }

    if (start.x < 0 || start.x >= grid->width || end.x < 0 || end.x >= grid->width
        || start.y < 0 || start.y >= grid->height || end.y < 0 || end.y >= grid->height) {
        printf("Error: Invalid coordinates\n");
        return;
    }

    // Bresenham's line algorithm (source: wikipedia)
    int dx = end.x - start.x;
    int dy = end.y - start.y;
    int error = 0;
    int derror = abs(dy) * 2;
    int y = start.y;

    for (int x = start.x; x <= end.x; x++) {
        grid->map[y][x] = symbol;

        error += derror;
        if (error > dx) {
            y += (end.y > start.y ? 1 : -1);
            error -= dx * 2;
        }
    }
}

int main() {
    Grid grid = createGrid(30, 20);

    // Draw the castle walls
    drawLine(&grid, (Point){2, 2}, (Point){2, 17}, '|');  // Left wall
    drawLine(&grid, (Point){2, 2}, (Point){27, 2}, '-');  // Top wall
    drawLine(&grid, (Point){27, 2}, (Point){27, 17}, '|');  // Right wall
    drawLine(&grid, (Point){2, 17}, (Point){27, 17}, '-');  // Bottom wall

    // Draw the towers
    drawLine(&grid, (Point){6, 2}, (Point){6, 6}, '#');  // Left tower
    drawLine(&grid, (Point){23, 2}, (Point){23, 6}, '#');  // Right tower

    // Draw the gate
    Point gate1 = {14, 2};
    Point gate2 = {14, 4};
    drawLine(&grid, gate1, gate2, '-');
    drawLine(&grid, (Point){13, 3}, (Point){15, 3}, '_');
    drawLine(&grid, (Point){13, 4}, (Point){13, 6}, '|');
    drawLine(&grid, (Point){15, 4}, (Point){15, 6}, '|');
    drawLine(&grid, (Point){14, 6}, (Point){15, 6}, '_');

    printGrid(grid);

    return 0;
}