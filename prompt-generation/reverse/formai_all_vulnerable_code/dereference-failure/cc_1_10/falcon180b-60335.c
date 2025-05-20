//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_CELL_SIZE];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        if (row >= MAX_ROWS) {
            fprintf(stderr, "Error: too many rows.\n");
            exit(1);
        }
        csv->data[row] = malloc(MAX_CELL_SIZE);
        strcpy(csv->data[row], line);
        token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            if (col >= MAX_COLS) {
                fprintf(stderr, "Error: too many columns.\n");
                exit(1);
            }
            csv->data[row][col] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[row][col], token);
            token = strtok(NULL, ",");
        }
        row++;
        col = 0;
    }

    csv->num_rows = row;
    csv->num_cols = col;

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s ", csv->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            free(csv->data[i][j]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    FILE *fp = fopen("example.csv", "r");
    CSV *csv = csv_read(fp);
    csv_print(csv);
    csv_free(csv);
    fclose(fp);
    return 0;
}