//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[1024];
    while (fgets(line, sizeof(line), fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        char *token = strtok(line, ",");
        int cols = 1;
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
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_rows(csv_t *csv) {
    return csv->rows;
}

int csv_get_cols(csv_t *csv) {
    return csv->cols;
}

char *csv_get_cell(csv_t *csv, int row, int col) {
    return csv->data[row][col];
}

int main() {
    csv_t *csv = csv_open("example.csv");

    int rows = csv_get_rows(csv);
    int cols = csv_get_cols(csv);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);

    return 0;
}