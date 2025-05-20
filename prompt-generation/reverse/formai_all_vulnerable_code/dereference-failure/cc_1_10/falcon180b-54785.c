//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 100
#define MAX_CELL_DATA 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_open(char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[MAX_CELL_DATA];
    int rows = 0, cols = 0;

    CSV *csv = malloc(sizeof(CSV));
    csv->data = malloc(sizeof(char *) * MAX_ROWS);
    csv->rows = 0;
    csv->cols = 0;

    while (fgets(line, MAX_CELL_DATA, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        rows++;
    }

    csv->rows = rows;
    csv->cols = cols;

    rewind(fp);
    csv->data = realloc(csv->data, sizeof(char *) * rows);

    int i = 0;
    while (fgets(line, MAX_CELL_DATA, fp)!= NULL) {
        char *token = strtok(line, ",");
        csv->data[i] = malloc(sizeof(char) * strlen(token) + 1);
        strcpy(csv->data[i], token);
        i++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i * csv->cols]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("data.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}