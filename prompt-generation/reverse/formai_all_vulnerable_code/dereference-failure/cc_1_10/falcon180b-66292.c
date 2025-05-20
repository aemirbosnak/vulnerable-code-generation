//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_LENGTH 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, FILE *fp) {
    char line[MAX_CELL_LENGTH];
    char delimiter = ',';
    char **row = NULL;
    int row_count = 0;
    int col_count = 0;

    while (fgets(line, MAX_CELL_LENGTH, fp)!= NULL) {
        if (row_count >= MAX_ROWS || col_count >= MAX_COLS) {
            printf("Error: CSV file exceeds maximum size.\n");
            csv_destroy(csv);
            exit(1);
        }

        row = realloc(row, sizeof(char *) * (col_count + 1));
        row[col_count] = strdup(line);
        col_count++;

        if (col_count == 1) {
            csv->cols = col_count;
        }

        row_count++;
    }

    csv->data = row;
    csv->rows = row_count;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    FILE *fp = fopen("example.csv", "r");

    if (fp == NULL) {
        printf("Error: Unable to open CSV file.\n");
        csv_destroy(csv);
        exit(1);
    }

    csv_read_file(csv, fp);
    fclose(fp);

    csv_print(csv);

    csv_destroy(csv);

    return 0;
}