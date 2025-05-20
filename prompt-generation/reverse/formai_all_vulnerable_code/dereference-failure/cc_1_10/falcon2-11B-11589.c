//Falcon2-11B DATASET v1.0 Category: Building a CSV Reader ; Style: Alan Turing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to read CSV file
void read_csv(const char* filename, int **matrix, int *nrows, int *ncols) {
    // Open the file
    FILE* file = fopen(filename, "r");
    if (file == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }
    
    // Read the header line
    *nrows = 0;
    fscanf(file, "%s", (*matrix) + (*nrows) * (*ncols));
    
    // Read the data rows
    int row = 0;
    while (fscanf(file, "%s", (*matrix) + row * (*ncols)) == 1) {
        (*nrows)++;
        row++;
    }
    
    // Close the file
    fclose(file);
}

int main() {
    char* filename = "data.csv";
    int **matrix;
    int nrows = 0;
    int ncols = 0;
    
    // Allocate memory for the matrix
    matrix = (int**)malloc(sizeof(int*) * nrows);
    if (matrix == NULL) {
        printf("Error: Could not allocate memory for the matrix.\n");
        exit(1);
    }
    
    // Read the CSV file
    read_csv(filename, matrix, &nrows, &ncols);
    
    // Print the matrix
    for (int i = 0; i < nrows; i++) {
        for (int j = 0; j < ncols; j++) {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
    
    // Free the memory
    for (int i = 0; i < nrows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}