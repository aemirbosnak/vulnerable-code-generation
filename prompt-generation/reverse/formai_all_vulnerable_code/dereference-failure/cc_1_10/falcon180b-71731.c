//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_open(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        char *token = strtok(line, ",");
        int columns = 0;

        while (token!= NULL) {
            columns++;
            token = strtok(NULL, ",");
        }

        if (columns > csv->columns) {
            csv->columns = columns;
        }

        csv->rows++;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->columns * MAX_CELL_SIZE);
    }

    rewind(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char *csv_get(CSV *csv, int row, int column) {
    return csv->data[row][column];
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_open(file);

    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s ", csv_get(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);
    fclose(file);

    return 0;
}