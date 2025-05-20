//FormAI DATASET v1.0 Category: Game of Life ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 20 // size of the grid

void print_grid(int **grid) { // function to print the grid
    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            if (grid[i][j] == 1)
                printf("X");
            else
                printf("-");
        }
        printf("\n");
    }
}

void generate_initial(int **grid) { // function to generate the initial grid
    srand(time(NULL));

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int random = rand() % 2; // randomly choose between 0 and 1
            grid[i][j] = random;
        }
    }

    print_grid(grid); // print the initial grid
}

int count_neighbors(int **grid, int i, int j) { // function to count the number of live neighbors
    int count = 0;

    for (int x = -1; x <= 1; x++) {
        for (int y = -1; y <= 1; y++) {
            if (x == 0 && y == 0) // exclude the current cell
                continue;

            int row = (i + x + SIZE) % SIZE; // wrap around the edges
            int col = (j + y + SIZE) % SIZE;

            count += grid[row][col];
        }
    }

    return count;
}

void update_grid(int **grid) { // function to update the grid
    int new_grid[SIZE][SIZE];

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            int count = count_neighbors(grid, i, j);

            if (grid[i][j] == 1) { // alive cell
                if (count < 2 || count > 3) // underpopulation or overpopulation
                    new_grid[i][j] = 0;
                else
                    new_grid[i][j] = 1;
            } else { // dead cell
                if (count == 3) // reproduction
                    new_grid[i][j] = 1;
                else
                    new_grid[i][j] = 0;
            }
        }
    }

    for (int i = 0; i < SIZE; i++) {
        for (int j = 0; j < SIZE; j++) {
            grid[i][j] = new_grid[i][j]; // update the grid
        }
    }

    print_grid(grid); // print the updated grid
}

int main() {
    int **grid = malloc(SIZE * sizeof(int*)); // allocate memory for the grid

    for (int i = 0; i < SIZE; i++) {
        grid[i] = malloc(SIZE * sizeof(int));
    }

    generate_initial(grid); // generate the initial grid

    while (1) {
        update_grid(grid); // update the grid
    }

    return 0;
}