//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_SIZE 4096
#define MAX_COLUMNS 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        if (cols > csv->num_cols) {
            csv->num_cols = cols;
        }

        csv->num_rows++;
    }

    rewind(fp);
    csv->data = malloc(csv->num_rows * sizeof(char *));
    for (int i = 0; i < csv->num_rows; i++) {
        csv->data[i] = malloc(csv->num_cols * sizeof(char));
    }

    fseek(fp, 0, SEEK_SET);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
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

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    CSV *csv = csv_open("example.csv");

    if (csv == NULL) {
        printf("Error opening CSV file.\n");
        return 1;
    }

    for (int i = 0; i < csv_get_num_rows(csv); i++) {
        for (int j = 0; j < csv_get_num_cols(csv); j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}