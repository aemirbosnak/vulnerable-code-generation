//MISTRAL-7B DATASET v1.0 Category: Percolation Simulator ; Style: interoperable
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    int rows;
    int cols;
    bool** grid;
} Percolation;

void initPercolation(Percolation* percolation, int rows, int cols) {
    percolation->rows = rows;
    percolation->cols = cols;
    percolation->grid = calloc(rows, sizeof(bool*));
    for (int i = 0; i < rows; ++i) {
        percolation->grid[i] = calloc(cols, sizeof(bool));
    }
}

void displayGrid(Percolation percolation) {
    for (int i = 0; i < percolation.rows; ++i) {
        for (int j = 0; j < percolation.cols; ++j) {
            printf("%-4d", percolation.grid[i][j]);
        }
        printf("\n");
    }
}

bool isValid(int row, int col, int rows, int cols) {
    return row >= 0 && row < rows && col >= 0 && col < cols;
}

void openSite(Percolation* percolation, int row, int col) {
    if (!percolation->grid[row][col]) {
        percolation->grid[row][col] = true;

        int neighbors = 0;
        if (isValid(row - 1, col, percolation->rows, percolation->cols) && percolation->grid[row - 1][col]) {
            ++neighbors;
        }
        if (isValid(row + 1, col, percolation->rows, percolation->cols) && percolation->grid[row + 1][col]) {
            ++neighbors;
        }
        if (isValid(row, col - 1, percolation->rows, percolation->cols) && percolation->grid[row][col - 1]) {
            ++neighbors;
        }
        if (isValid(row, col + 1, percolation->rows, percolation->cols) && percolation->grid[row][col + 1]) {
            ++neighbors;
        }

        if (neighbors > 0 && percolation->grid[0][0]) {
            percolation->grid[0][0] = false;
        }

        for (int i = 0; i < 4; ++i) {
            int dirRow = row + (i % 2) * 2 - 1;
            int dirCol = col + (i / 2) * 2 - 1;
            openSite(percolation, dirRow, dirCol);
        }
    }
}

bool isPercolated(Percolation percolation) {
    for (int i = 0; i < percolation.rows; ++i) {
        if (percolation.grid[i][0]) {
            return true;
        }
    }

    return false;
}

#ifdef __cplusplus
}
#endif

int main() {
    int rows, cols;
    printf("Enter rows and columns: ");
    scanf("%d%d", &rows, &cols);

    Percolation percolation;
    initPercolation(&percolation, rows, cols);

    printf("Initial grid:\n");
    displayGrid(percolation);

    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            openSite(&percolation, i, j);
        }
    }

    printf("\nGrid after simulation:\n");
    displayGrid(percolation);

    if (isPercolated(percolation)) {
        printf("\nThe grid is percolated.\n");
    } else {
        printf("\nThe grid is not percolated.\n");
    }

    return 0;
}