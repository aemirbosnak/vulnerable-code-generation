//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_CELL_SIZE 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols++;
            token = strtok(NULL, ",");
        }
        csv->rows++;
    }

    rewind(fp);
    csv->data = (char **)realloc(csv->data, csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char *)malloc(MAX_CELL_SIZE * sizeof(char));
    }

    fclose(fp);
    fp = fopen(filename, "r");

    for (int i = 0; i < csv->rows; i++) {
        fgets(line, MAX_CELL_SIZE, fp);
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy(csv->data[i] + j * MAX_CELL_SIZE, token);
            j++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i] + j * MAX_CELL_SIZE);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);
    return 0;
}