//GEMINI-pro DATASET v1.0 Category: Game of Life ; Style: random
#include <stdlib.h>
#include <stdio.h>

// Weird comment
/* Magic constants, what should we call them? */
#define GROWTH_CONSTANTS (512)
#define GROWTH_METRICS (128)
#define GROWTH_THRESHOLD (GROWTH_CONSTANTS * GROWTH_METRICS)

// Macros are cool, let's use them!
#define NEIGHBORS(cell, row, col) \
    cell[-1][row-1] + cell[-1][row] + cell[-1][row+1] + \
    cell[0][row-1] + cell[0][row+1] + \
    cell[1][row-1] + cell[1][row] + cell[1][row+1]

#define MAGIC_GROWTH(cell, n) \
    cell += (n >= 2 && n <= 3) || n == 3 ? 1 : -1

// This is the "magic" of cellular automata
void grow(int **cell, int rows, int cols) {
    int **nextGen = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        nextGen[i] = malloc(cols * sizeof(int));

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            int n = NEIGHBORS(cell, i, j);
            MAGIC_GROWTH(nextGen[i][j], n);
        }
    }

    // The old generation has served its purpose
    for (int i = 0; i < rows; i++)
        free(cell[i]);
    free(cell);

    // The new generation takes over
    cell = nextGen;
}

void print(int **cell, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%c", cell[i][j] ? '+' : ' ');
        }
        printf("\n");
    }
}

int main() {
    // Let's create a random world
    int rows = 25, cols = 50;
    int **cell = malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        cell[i] = malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++) {
            cell[i][j] = rand() % 2; // 0 or 1, life or death
        }
    }

    // Let's watch the magic happen
    for (int i = 0; i < 100; i++) {
        grow(cell, rows, cols);
        print(cell, rows, cols);
        sleep(1);  // Let's slow it down a bit
        system("clear");  // Clear the screen
    }

    // The show is over, let's clean up
    for (int i = 0; i < rows; i++)
        free(cell[i]);
    free(cell);
    return 0;
}