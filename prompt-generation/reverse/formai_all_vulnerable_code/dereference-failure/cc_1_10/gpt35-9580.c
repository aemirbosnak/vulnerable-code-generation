//FormAI DATASET v1.0 Category: File handling ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {

    // Declare variables for file handling
    FILE *fileIn;
    FILE *fileOut;
    char inputFile[20], outputFile[20];
    int rows, cols, value, i, j;

    // Prompt the user for input file name
    printf("Enter name of input file: ");
    scanf("%s", inputFile);

    // Open input file for reading
    fileIn = fopen(inputFile, "r");

    // Check if fileIn is null
    if(fileIn == NULL) {
        printf("File does not exist.\n");
        return 0;
    }

    // Read in rows and columns from input file
    fscanf(fileIn, "%d %d", &rows, &cols);

    // Allocate memory for array
    int **array = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++) {
        array[i] = (int *)malloc(cols * sizeof(int));
    }

    // Read values into array
    for(i = 0; i < rows; i++) {
        for(j = 0; j < cols; j++) {
            fscanf(fileIn, "%d", &value);
            array[i][j] = value;
        }
    }

    // Close the input file
    fclose(fileIn);

    // Compute the determinant of the matrix
    int det = computeDeterminant(array, rows, cols);

    // Prompt user for output file name
    printf("Enter name of output file: ");
    scanf("%s", outputFile);

    // Open output file for writing
    fileOut = fopen(outputFile, "w");

    // Write the determinant to the file
    fprintf(fileOut, "Determinant: %d\n", det);

    // Close the output file
    fclose(fileOut);

    // Free memory used by array
    for(i = 0; i < rows; i++) {
        free(array[i]);
    }
    free(array);

    return 0;
}

int computeDeterminant(int **array, int rows, int cols) {

    // Check for invalid matrix dimensions
    if(rows != cols) {
        printf("Invalid Matrix. Rows and columns must be equal.\n");
        exit(0);
    }

    int i, j, k, sign = 1;
    int deter = 0;
    int **temp = (int **)malloc(rows * sizeof(int *));
    for(i = 0; i < rows; i++) {
        temp[i] = (int *)malloc(cols * sizeof(int));
    }

    // Base Case: 1x1 matrix
    if(rows == 1) {
        return array[0][0];
    }

    // Recursive Case: NxN matrix
    for(i = 0; i < rows; i++) {
        int p = 0, q = 0;
        for(j = 0; j < rows; j++) {
            for(k = 0; k < rows; k++) {
                if(j != 0 && k != i) {
                    temp[p][q++] = array[j][k];
                    if(q == rows - 1) {
                        p++;
                        q = 0;
                    }
                }
            }
        }
        deter += sign * array[0][i] * computeDeterminant(temp, rows - 1, cols - 1);
        sign = -sign;
    }
    return deter;
}