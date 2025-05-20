//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        csv->rows++;
    }

    csv->data = malloc(sizeof(char *) * csv->rows);
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(sizeof(char) * csv->cols);
    }

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_row_count(CSV *csv) {
    return csv->rows;
}

int csv_get_col_count(CSV *csv) {
    return csv->cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    if (row >= csv->rows || col >= csv->cols) {
        return NULL;
    }
    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");

    int rows = csv_get_row_count(csv);
    int cols = csv_get_col_count(csv);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *cell = csv_get_cell(csv, i, j);
            printf("%s ", cell);
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}