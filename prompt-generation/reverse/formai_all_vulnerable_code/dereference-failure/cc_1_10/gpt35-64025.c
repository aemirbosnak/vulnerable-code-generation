//FormAI DATASET v1.0 Category: Fractal Generation ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

// function to simulate a single step in the fractal generation process
void simulate(int *grid, int width, int height, float prob) {
    int i, j, count;

    // create a copy of the grid to ensure we change each cell at the same time
    int *copy = calloc(width * height, sizeof(int));
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            copy[i + j * width] = grid[i + j * width];
        }
    }

    // iterate over each cell in the grid and update based on surrounding cells
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            count = 0;
            if (i > 0 && copy[i-1 + j * width]) count++;
            if (i < width - 1 && copy[i+1 + j * width]) count++;
            if (j > 0 && copy[i + (j-1) * width]) count++;
            if (j < height - 1 && copy[i + (j+1) * width]) count++;

            if (!grid[i + j * width] && (float)rand()/RAND_MAX < prob) {
                grid[i + j * width] = 1;
            } else if (grid[i + j * width] && count < 2) {
                grid[i + j * width] = 0;
            } else if (grid[i + j * width] && count > 3) {
                grid[i + j * width] = 0;
            }
        }
    }

    free(copy);
}

// function to generate and print the fractal
void generate_fractal(int *grid, int width, int height, float prob, int steps) {
    int i, j, s;
    srand(time(NULL));

    // fill the grid with random cells
    for (i = 0; i < width; i++) {
        for (j = 0; j < height; j++) {
            grid[i + j * width] = (float)rand()/RAND_MAX < prob;
        }
    }

    // simulate the fractal generation process for the specified number of steps
    for (s = 0; s < steps; s++) {
        simulate(grid, width, height, prob);
        system("clear"); // clear the console for each step
        for (i = 0; i < width; i++) {
            for (j = 0; j < height; j++) {
                printf("%c ", grid[i + j * width] ? '*' : ' ');
            }
            printf("\n");
        }
        usleep(100000); // pause execution for 100 milliseconds
    }
}

int main() {
    int width = 64, height = 32; // dimensions of the grid
    float prob = 0.5; // probability of a cell starting as alive
    int steps = 100; // number of steps in the fractal generation process

    int *grid = calloc(width * height, sizeof(int));

    generate_fractal(grid, width, height, prob, steps);

    free(grid);

    return 0;
}