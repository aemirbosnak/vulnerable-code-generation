//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: invasive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create(void) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_add_row(CSV *csv, char *row) {
    csv->data[csv->num_rows++] = row;
}

int csv_get_num_cols(CSV *csv) {
    if (csv->num_cols == 0) {
        csv->num_cols = strlen(csv->data[0]);
    }
    return csv->num_cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    if (row < 0 || row >= csv->num_rows || col < 0 || col >= csv->num_cols) {
        return NULL;
    }
    return csv->data[row];
}

int main() {
    FILE *fp;
    char line[MAX_CELL_SIZE];
    CSV *csv = csv_create();

    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file.\n");
        return 1;
    }

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        csv_add_row(csv, line);
    }

    fclose(fp);

    int num_cols = csv_get_num_cols(csv);
    printf("Number of columns: %d\n", num_cols);

    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            char *cell = csv_get_cell(csv, i, j);
            if (cell!= NULL) {
                printf("%s ", cell);
            } else {
                printf("NULL ");
            }
        }
        printf("\n");
    }

    csv_destroy(csv);

    return 0;
}