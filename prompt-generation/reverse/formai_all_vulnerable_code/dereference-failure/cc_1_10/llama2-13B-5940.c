//LLAMA2-13B DATASET v1.0 Category: Pattern printing ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

#define WIDTH 80
#define HEIGHT 25

// Structure to represent a point on the grid
typedef struct {
    int x;
    int y;
} Point;

// Function to generate a random point on the grid
Point random_point(void) {
    return (Point) {
        (rand() % WIDTH) * 2 - WIDTH / 2,
        (rand() % HEIGHT) * 2 - HEIGHT / 2
    };
}

// Function to print the grid
void print_grid(Point *grid, int size) {
    int i, j;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size; j++) {
            printf("%d ", grid[i * size + j].x);
        }
        printf("\n");
    }
}

// Function to draw a line connecting two points
void draw_line(Point start, Point end) {
    int dx = abs(start.x - end.x);
    int dy = abs(start.y - end.y);
    int x = start.x < end.x ? start.x : end.x;
    int y = start.y < end.y ? start.y : end.y;

    if (dx > dy) {
        int temp = dx;
        dx = dy;
        dy = temp;
    }

    for (int i = 0; i < dx; i++) {
        printf(" ");
    }

    for (int i = 0; i < dy; i++) {
        printf("-");
    }

    printf("\n");
}

int main(void) {
    // Initialize the grid with random points
    Point *grid = malloc(WIDTH * HEIGHT * sizeof(Point));
    for (int i = 0; i < WIDTH * HEIGHT; i++) {
        grid[i] = random_point();
    }

    // Draw the grid
    print_grid(grid, WIDTH * HEIGHT);

    // Get two points from the user
    Point start, end;
    printf("Enter the starting point (x, y): ");
    scanf("%d%d", &start.x, &start.y);
    printf("Enter the ending point (x, y): ");
    scanf("%d%d", &end.x, &end.y);

    // Draw the line connecting the two points
    draw_line(start, end);

    // Free the memory allocated for the grid
    free(grid);

    return 0;
}