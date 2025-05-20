//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CSV_LINE_LEN 10000

typedef struct {
    int rows;
    int cols;
    char **data;
} csv_t;

csv_t *csv_read(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    csv_t *csv = malloc(sizeof(csv_t));
    csv->rows = 0;
    csv->cols = 0;
    csv->data = NULL;

    char line[MAX_CSV_LINE_LEN];
    while (fgets(line, MAX_CSV_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        int cols = 0;
        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }
        if (cols > csv->cols) {
            csv->cols = cols;
        }
        csv->rows++;
    }

    csv->data = malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = malloc(csv->cols * sizeof(char));
    }

    rewind(fp);
    int row = 0;
    while (fgets(line, MAX_CSV_LINE_LEN, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col = 0;
        while (token!= NULL) {
            strncpy(csv->data[row][col], token, strlen(token));
            col++;
            token = strtok(NULL, ",");
        }
        row++;
    }

    fclose(fp);
    return csv;
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    csv_t *csv = csv_read("example.csv");
    csv_print(csv);
    csv_free(csv);

    return 0;
}