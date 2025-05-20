//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV* csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;

        while (token!= NULL) {
            csv->data[csv->rows] = realloc(csv->data[csv->rows], (csv->cols + 1) * sizeof(char*));
            csv->data[csv->rows][cols] = strdup(token);
            cols++;
            token = strtok(NULL, ",");
        }

        csv->rows++;
        csv->cols = cols;
    }

    fclose(fp);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read_file(csv, "data.csv");
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}