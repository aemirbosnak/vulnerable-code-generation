//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp;
    char line[MAX_CELL_SIZE];
    char *token;
    CSV *csv;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(EXIT_FAILURE);
    }

    csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols++;
            token = strtok(NULL, ",");
        }
        csv->rows++;
    }

    csv->data = realloc(csv->data, csv->rows * sizeof(char *));
    rewind(fp);

    return csv;
}

void csv_close(CSV *csv) {
    int i;

    for (i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_cols(CSV *csv) {
    return csv->cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    CSV *csv;
    int rows, cols;
    int i, j;

    csv = csv_open("example.csv");

    rows = csv_get_rows(csv);
    cols = csv_get_cols(csv);

    printf("CSV file has %d rows and %d columns:\n", rows, cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}