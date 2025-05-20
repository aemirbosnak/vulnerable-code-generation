//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 1000
#define MAX_ROWS 1000
#define MAX_CELL_DATA 1000

typedef struct {
    char **data;
    int rows;
    int columns;
} CSV;

CSV *csv_create(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->columns = 0;

    int c;
    while ((c = fgetc(file))!= EOF) {
        if (c == '\n') {
            csv->rows++;
        } else if (c == ',') {
            csv->columns++;
        }
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->columns * MAX_CELL_DATA);
    }

    rewind(file);
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->columns; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_create(file);
    csv_print(csv);
    csv_destroy(csv);
    fclose(file);

    return 0;
}