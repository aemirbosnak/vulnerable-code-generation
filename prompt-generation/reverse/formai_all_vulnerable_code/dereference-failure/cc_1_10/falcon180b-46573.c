//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
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

CSV *csv_open(char *filename) {
    FILE *fp;
    CSV *csv;
    char ch;
    int rows = 0;
    int cols = 0;

    fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: unable to open file %s\n", filename);
        exit(1);
    }

    csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    while ((ch = fgetc(fp))!= EOF) {
        if (ch == '\n') {
            rows++;
        } else if (ch == ',') {
            cols++;
        }
    }

    rewind(fp);

    csv->data = (char **)realloc(csv->data, rows * sizeof(char *));
    csv->rows = rows;
    csv->cols = cols;

    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char *)malloc(MAX_CELL_SIZE * sizeof(char));
    }

    fseek(fp, 0, SEEK_SET);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            fscanf(fp, "%s", csv->data[i] + j * MAX_CELL_SIZE);
        }
    }

    fclose(fp);

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

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col * MAX_CELL_SIZE];
}

int csv_get_rows(CSV *csv) {
    return csv->rows;
}

int csv_get_cols(CSV *csv) {
    return csv->cols;
}

int main() {
    CSV *csv;
    int rows, cols;
    int i, j;

    csv = csv_open("example.csv");

    rows = csv_get_rows(csv);
    cols = csv_get_cols(csv);

    printf("CSV file has %d rows and %d columns\n", rows, cols);

    for (i = 0; i < rows; i++) {
        for (j = 0; j < cols; j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}