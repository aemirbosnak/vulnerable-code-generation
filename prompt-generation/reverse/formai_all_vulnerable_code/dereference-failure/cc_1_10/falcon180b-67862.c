//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1024

typedef struct {
    char delimiter;
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char first_line[MAX_CELL_SIZE];
    fgets(first_line, MAX_CELL_SIZE, fp);

    char delimiter = first_line[0];
    int num_cols = 0;
    for (int i = 0; i < strlen(first_line); i++) {
        if (first_line[i] == ',') {
            num_cols++;
        }
    }

    rewind(fp);

    CSV *csv = malloc(sizeof(CSV));
    csv->delimiter = delimiter;
    csv->num_rows = 0;
    csv->num_cols = num_cols;
    csv->data = malloc(sizeof(char *) * num_cols);

    for (int i = 0; i < num_cols; i++) {
        csv->data[i] = malloc(MAX_CELL_SIZE * sizeof(char));
    }

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_cols; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_num_rows(CSV *csv) {
    return csv->num_rows;
}

int csv_get_num_cols(CSV *csv) {
    return csv->num_cols;
}

char csv_get_delimiter(CSV *csv) {
    return csv->delimiter;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[col][row];
}

int main() {
    CSV *csv = csv_open("example.csv");

    int num_rows = csv_get_num_rows(csv);
    int num_cols = csv_get_num_cols(csv);

    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}