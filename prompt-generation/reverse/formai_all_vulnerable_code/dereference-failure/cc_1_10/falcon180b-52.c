//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1024
#define MAX_COL_SIZE 1024

typedef struct {
    char **data;
    int rows;
    int cols;
} CSV;

CSV *csv_create() {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            free(csv->data[i]);
        }
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_load_file(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        fprintf(stderr, "Error: Failed to open file '%s'\n", filename);
        return 1;
    }

    int rows = 0;
    int cols = 0;
    char line[MAX_ROW_SIZE];

    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        if (token == NULL) {
            fprintf(stderr, "Error: Invalid CSV format in file '%s'\n", filename);
            csv_destroy(csv);
            fclose(fp);
            return 1;
        }

        while (token!= NULL) {
            cols++;
            token = strtok(NULL, ",");
        }

        rows++;
    }

    rewind(fp);

    csv->data = (char **)malloc(rows * sizeof(char *));
    for (int i = 0; i < rows; i++) {
        csv->data[i] = (char *)malloc(cols * MAX_COL_SIZE);
        fgets(line, MAX_ROW_SIZE, fp);
        char *token = strtok(line, ",");
        for (int j = 0; j < cols; j++) {
            strcpy(csv->data[i] + j * MAX_COL_SIZE, token);
            token = strtok(NULL, ",");
        }
    }

    csv->rows = rows;
    csv->cols = cols;

    fclose(fp);

    return 0;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i] + j * MAX_COL_SIZE);
        }
        printf("\n");
    }
}

int main() {
    CSV *csv = csv_create();
    csv_load_file(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);

    return 0;
}