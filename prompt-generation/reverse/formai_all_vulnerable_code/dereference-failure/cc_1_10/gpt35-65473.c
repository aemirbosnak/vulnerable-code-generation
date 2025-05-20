//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000

/* Function to parse a CSV file and return a two-dimensional array of double values */
double** read_csv(char* filename, int* rows, int* columns) {
    FILE* fp = fopen(filename, "r");

    if (fp == NULL) {
        printf("Error: Unable to open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    int row = 0;
    int col = 0;
    double** data = (double**)calloc(MAX_ROWS, sizeof(double*));

    while (fgets(line, 1024, fp) && row < MAX_ROWS) {
        char* tok = strtok(line, ",");
        col = 0;
        data[row] = (double*)calloc(MAX_COLUMNS, sizeof(double));

        while (tok != NULL && col < MAX_COLUMNS) {
            data[row][col] = atof(tok);
            tok = strtok(NULL, ",");
            col++;
        }

        row++;
    }

    *rows = row;
    *columns = col;
    fclose(fp);
    return data;
}

/* Function to calculate the mean and standard deviation of a column of data */
void calculate_stats(double* data, int length, double* mean, double* stdev) {
    double sum = 0.0;
    double sum_squares = 0.0;

    for (int i = 0; i < length; i++) {
        sum += data[i];
        sum_squares += data[i] * data[i];
    }

    *mean = sum / length;
    *stdev = sqrt(sum_squares / length - (*mean)*(*mean));
}

int main(int argc, char** argv) {
    if (argc != 2) {
        printf("Error: Invalid arguments. Usage: %s filename.csv\n", argv[0]);
        exit(1);
    }

    int rows, cols;
    double** data = read_csv(argv[1], &rows, &cols);

    /* Print the data to the console */
    printf("Data:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%f ", data[i][j]);
        }
        printf("\n");
    }

    /* Calculate the mean and standard deviation of the first column */
    double* first_col = (double*)calloc(rows, sizeof(double));
    for (int i = 0; i < rows; i++) {
        first_col[i] = data[i][0];
    }
    double mean, stdev;
    calculate_stats(first_col, rows, &mean, &stdev);

    printf("Mean of first column: %f\n", mean);
    printf("Standard deviation of first column: %f\n", stdev);

    /* Free the memory allocated for the data */
    for (int i = 0; i < rows; i++) {
        free(data[i]);
    }
    free(data);
    free(first_col);

    return 0;
}