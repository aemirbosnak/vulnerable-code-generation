//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CSV_LINE 10000

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: could not open file '%s'\n", filename);
        exit(1);
    }

    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = malloc(MAX_ROWS * sizeof(char *));
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CSV_LINE];
    while (fgets(line, MAX_CSV_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        while (token!= NULL) {
            csv->cols++;
            token = strtok(NULL, ",");
        }
        csv->rows++;
    }

    csv->data = realloc(csv->data, csv->rows * sizeof(char *));
    rewind(fp);

    int i = 0;
    while (fgets(line, MAX_CSV_LINE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            csv->data[i] = malloc(strlen(token) + 1);
            strcpy(csv->data[i], token);
            token = strtok(NULL, ",");
            j++;
        }
        i++;
    }

    fclose(fp);

    return csv;
}

void csv_close(csv_t *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            free(csv->data[i * csv->cols + j]);
        }
    }
    free(csv->data);
    free(csv);
}

void csv_print(const csv_t *csv) {
    int i, j;
    for (i = 0; i < csv->rows; i++) {
        for (j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i * csv->cols + j]);
        }
        printf("\n");
    }
}

int main() {
    csv_t *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}