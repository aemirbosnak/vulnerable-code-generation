//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char *data;
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
    char *token = strtok(line, ",");
    int count = 0;

    while (token!= NULL) {
        count++;
        token = strtok(NULL, ",");
    }

    csv->cols = count;
    csv->rows = 0;

    rewind(fp);
    return csv;
}

int csv_read(CSV *csv, int row, int col, char **data) {
    if (row >= csv->rows || col >= csv->cols) {
        return -1;
    }

    fseek(csv->data, (row * csv->cols + col) * sizeof(char), SEEK_SET);
    fread(data, sizeof(char), MAX_CELL_SIZE, csv->data);

    return 0;
}

void csv_close(CSV *csv) {
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");

    if (csv == NULL) {
        printf("Error opening file\n");
        return -1;
    }

    int rows = csv->rows;
    int cols = csv->cols;

    printf("Rows: %d\n", rows);
    printf("Cols: %d\n", cols);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            char *data = malloc(MAX_CELL_SIZE);
            csv_read(csv, i, j, &data);
            printf("%s ", data);
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}