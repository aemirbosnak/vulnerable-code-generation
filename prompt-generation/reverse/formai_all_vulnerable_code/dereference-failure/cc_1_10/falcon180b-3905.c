//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: immersive
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
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
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

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * MAX_CELL_SIZE);
    }

    rewind(fp);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
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
    CSV *csv = csv_open("example.csv");

    int rows = csv_get_rows(csv);
    int cols = csv_get_cols(csv);

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