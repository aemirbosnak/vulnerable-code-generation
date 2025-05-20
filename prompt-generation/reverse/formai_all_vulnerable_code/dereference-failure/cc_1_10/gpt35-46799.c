//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLS 1024
#define MAX_ROWS 1024
#define MAX_FIELD_LEN 256

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(1);
    }
    
    char filename[MAX_FIELD_LEN];
    strncpy(filename, argv[1], MAX_FIELD_LEN);
    
    FILE *fp;
    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: cannot open %s\n", filename);
        exit(1);
    }
    
    char line[MAX_ROWS][MAX_COLS][MAX_FIELD_LEN];
    int n_rows = 0, n_cols = 0;
    
    // read in the CSV file
    while (fgets(line[n_rows][0], MAX_FIELD_LEN, fp)) {
        char *field;
        field = strtok(line[n_rows][0], ",");
        n_cols = 0;
        while (field) {
            strncpy(line[n_rows][n_cols], field, MAX_FIELD_LEN);
            n_cols++;
            field = strtok(NULL, ",");
        }
        n_rows++;
    }
    
    fclose(fp);
    
    // perform some statistical analysis on the data
    double sum = 0.0, mean = 0.0, variance = 0.0;
    int i, j;
    for (i = 0; i < n_cols; i++) {
        double column_sum = 0.0, column_mean = 0.0;
        for (j = 0; j < n_rows; j++) {
            char *str = line[j][i];
            double num = atof(str);
            column_sum += num;
        }
        column_mean = column_sum / n_rows;
        sum += column_sum;
        mean += column_mean;
    }
    mean /= n_cols;
    for (i = 0; i < n_cols; i++) {
        double column_variance = 0.0;
        for (j = 0; j < n_rows; j++) {
            char *str = line[j][i];
            double num = atof(str);
            column_variance += (num - mean) * (num - mean);
        }
        variance += column_variance;
    }
    variance /= (n_rows * n_cols);
    
    printf("Number of rows: %d\n", n_rows);
    printf("Number of columns: %d\n", n_cols);
    printf("Sum: %f\n", sum);
    printf("Mean: %f\n", mean);
    printf("Variance: %f\n", variance);
    
    return 0;
}