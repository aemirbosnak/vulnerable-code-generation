//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: recursive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_reader(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->data[csv->rows] = (char *)malloc(MAX_CELL_SIZE * sizeof(char));
            strcpy(csv->data[csv->rows], token);
            csv->cols++;
            csv->rows++;
            token = strtok(NULL, ",");
        }
    }

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_reader(fp);
    csv_print(csv);
    csv_free(csv);

    return 0;
}