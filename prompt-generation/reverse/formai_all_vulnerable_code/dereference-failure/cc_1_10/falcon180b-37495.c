//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 100
#define MAX_COL_SIZE 100

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_init() {
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

void csv_read_file(CSV *csv, FILE *fp) {
    char line[MAX_ROW_SIZE];
    char delimiter = ',';
    int row = 0;
    int col = 0;

    while (fgets(line, sizeof(line), fp)!= NULL) {
        if (row >= csv->rows) {
            csv->rows += 10;
            csv->data = realloc(csv->data, sizeof(char *) * csv->rows);
        }

        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (col >= csv->cols) {
                csv->cols += 10;
                for (int i = csv->rows - 1; i > row; i--) {
                    csv->data[i] = realloc(csv->data[i], sizeof(char) * (csv->cols + 1));
                }
                csv->data[row] = realloc(csv->data[row], sizeof(char) * (csv->cols + 1));
            }

            strcpy(csv->data[row][col], token);
            col++;

            token = strtok(NULL, &delimiter);
        }

        row++;
    }
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
    FILE *fp = fopen("data.csv", "r");
    CSV *csv = csv_init();

    if (fp == NULL) {
        printf("Error: could not open file.\n");
        exit(1);
    }

    csv_read_file(csv, fp);

    csv_print(csv);

    fclose(fp);
    csv_destroy(csv);

    return 0;
}