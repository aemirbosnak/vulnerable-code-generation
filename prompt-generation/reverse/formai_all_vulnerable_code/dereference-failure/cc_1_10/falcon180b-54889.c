//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    int rows;
    int cols;
    char **data;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error opening file: %s\n", filename);
        return NULL;
    }

    csv_t *csv = malloc(sizeof(csv_t));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = malloc(sizeof(char *));

    char line[MAX_CELL_SIZE];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            csv->cols = cols > csv->cols? cols : csv->cols;
            csv->data = realloc(csv->data, sizeof(char *) * csv->rows * csv->cols);
            csv->data[csv->rows * csv->cols - 1] = strdup(token);
            token = strtok(NULL, ",");
            cols++;
        }
        csv->rows++;
    }

    csv->data = realloc(csv->data, sizeof(char *) * csv->rows * csv->cols);

    fclose(fp);
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

void csv_print(const csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    csv_t *csv = csv_open("example.csv");
    if (csv == NULL) {
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}