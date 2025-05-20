//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_ROW_LENGTH 10000

typedef struct {
    int num_rows;
    int num_cols;
    char **data;
} CsvData;

CsvData *read_csv(FILE *fp) {
    CsvData *csv = malloc(sizeof(CsvData));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_ROW_LENGTH];
    char *token;
    int row = 0;
    int col = 0;

    while (fgets(line, MAX_ROW_LENGTH, fp)!= NULL) {
        row++;
        csv->num_rows = row;
        token = strtok(line, ",");
        while (token!= NULL) {
            col++;
            csv->num_cols = (col > csv->num_cols)? col : csv->num_cols;
            csv->data[row - 1] = realloc(csv->data[row - 1], sizeof(char *) * (col + 1));
            csv->data[row - 1][col - 1] = strdup(token);
            token = strtok(NULL, ",");
        }
    }

    return csv;
}

void print_csv(CsvData *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i][j]);
        }
        printf("\n");
    }
}

void free_csv(CsvData *csv) {
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
    if (fp == NULL) {
        printf("Error opening file\n");
        return 1;
    }

    CsvData *csv = read_csv(fp);
    if (csv == NULL) {
        printf("Error reading file\n");
        return 1;
    }

    print_csv(csv);

    free_csv(csv);
    fclose(fp);

    return 0;
}