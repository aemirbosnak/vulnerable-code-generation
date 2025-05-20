//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = (char **) malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            if (csv->cols <= col_count) {
                csv->cols++;
                csv->data = (char **) realloc(csv->data, csv->rows * csv->cols * sizeof(char *));
            }
            csv->data[csv->rows][col_count] = strdup(token);
            token = strtok(NULL, ",");
            col_count++;
        }
        csv->rows++;
        if (csv->rows >= MAX_ROWS) {
            printf("Error: too many rows in file %s\n", filename);
            exit(1);
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
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

int main(int argc, char *argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    CSV *csv = csv_open(argv[1]);
    csv_print(csv);
    csv_close(csv);

    return 0;
}