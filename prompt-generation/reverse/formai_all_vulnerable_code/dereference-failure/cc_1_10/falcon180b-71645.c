//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 256

typedef struct {
    char **data;
    int rows;
    int cols;
} csv_t;

csv_t *csv_open(const char *filename) {
    csv_t *csv = malloc(sizeof(csv_t));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_CELL_SIZE];
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        int len = strlen(line);
        if (line[len - 1] == '\n') {
            line[len - 1] = '\0';
            len--;
        }

        char *token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            if (col > csv->cols) {
                csv->cols = col;
            }

            if (row >= csv->rows) {
                csv->data = realloc(csv->data, sizeof(char *) * (csv->rows + 1));
            }

            csv->data[row] = realloc(csv->data[row], sizeof(char) * (csv->cols + 1));
            strcpy(csv->data[row], token);

            token = strtok(NULL, ",");
            row++;
        }

        row++;
        if (row >= csv->rows) {
            csv->rows++;
            csv->data = realloc(csv->data, sizeof(char *) * (csv->rows + 1));
        }
    }

    fclose(fp);
    return csv;
}

void csv_close(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_print(csv_t *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i]);
        }
        printf("\n");
    }
}

int main() {
    csv_t *csv = csv_open("example.csv");
    if (csv == NULL) {
        printf("Error: Failed to open CSV file.\n");
        return 1;
    }

    csv_print(csv);

    csv_close(csv);

    return 0;
}