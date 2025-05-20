//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} CSV;

int read_csv(FILE *fp, CSV *csv) {
    char line[MAX_CELL_SIZE];
    char delimiter = ',';
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        row++;
        col = 0;
        token = strtok(line, &delimiter);

        while (token!= NULL) {
            if (col >= csv->cols) {
                csv->cols += 10;
                csv->data = realloc(csv->data, csv->rows * csv->cols * sizeof(char*));
            }

            if (row >= csv->rows) {
                csv->rows += 10;
                csv->data = realloc(csv->data, csv->rows * csv->cols * sizeof(char*));
            }

            csv->data[row*csv->cols + col] = strdup(token);

            col++;
            token = strtok(NULL, &delimiter);
        }
    }

    return 0;
}

void print_csv(CSV *csv) {
    int row, col;

    for (row = 0; row < csv->rows; row++) {
        for (col = 0; col < csv->cols; col++) {
            printf("%s\t", csv->data[row*csv->cols + col]);
        }
        printf("\n");
    }
}

void free_csv(CSV *csv) {
    int row, col;

    for (row = 0; row < csv->rows; row++) {
        for (col = 0; col < csv->cols; col++) {
            free(csv->data[row*csv->cols + col]);
        }
    }

    free(csv->data);
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
}

int main() {
    FILE *fp;
    CSV csv;

    fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    csv.data = malloc(MAX_ROWS * MAX_COLS * sizeof(char*));
    csv.rows = 0;
    csv.cols = 0;

    read_csv(fp, &csv);

    print_csv(&csv);

    free_csv(&csv);

    fclose(fp);

    return 0;
}