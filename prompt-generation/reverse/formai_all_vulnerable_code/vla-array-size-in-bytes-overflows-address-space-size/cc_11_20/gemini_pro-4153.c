//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>

typedef struct cell {
    int state;
    int neighbours;
} cell;

int main() {
    int width, height;
    printf("Enter the width and height of the grid: ");
    scanf("%d %d", &width, &height);

    cell grid[width][height];

    for (int i = 0; i < width; i++) {
        for (int j = 0; j < height; j++) {
            grid[i][j].state = rand() % 2;
            grid[i][j].neighbours = 0;
        }
    }

    while (1) {
        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                grid[i][j].neighbours = 0;

                if (i > 0) {
                    grid[i][j].neighbours += grid[i - 1][j].state;
                }
                if (i < width - 1) {
                    grid[i][j].neighbours += grid[i + 1][j].state;
                }
                if (j > 0) {
                    grid[i][j].neighbours += grid[i][j - 1].state;
                }
                if (j < height - 1) {
                    grid[i][j].neighbours += grid[i][j + 1].state;
                }

                if (grid[i][j].state == 1 && (grid[i][j].neighbours < 2 || grid[i][j].neighbours > 3)) {
                    grid[i][j].state = 0;
                } else if (grid[i][j].state == 0 && grid[i][j].neighbours == 3) {
                    grid[i][j].state = 1;
                }
            }
        }

        for (int i = 0; i < width; i++) {
            for (int j = 0; j < height; j++) {
                printf("%d", grid[i][j].state);
            }
            printf("\n");
        }

        printf("\n");
    }

    return 0;
}