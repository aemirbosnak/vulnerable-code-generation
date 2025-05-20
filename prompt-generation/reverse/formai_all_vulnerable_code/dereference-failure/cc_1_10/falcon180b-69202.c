//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 100
#define MAX_CELL_SIZE 1000

typedef struct {
    char *data;
    int rows;
    int cols;
} CSV;

CSV *csv_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    CSV *csv = (CSV *) malloc(sizeof(CSV));
    csv->data = NULL;
    csv->rows = 0;
    csv->cols = 0;

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
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

    rewind(fp);

    csv->data = (char **) malloc(csv->rows * sizeof(char *));
    for (int i = 0; i < csv->rows; i++) {
        csv->data[i] = (char *) malloc(csv->cols * MAX_CELL_SIZE);
    }

    fseek(fp, 0, SEEK_SET);
    for (int i = 0; i < csv->rows; i++) {
        fgets(line, MAX_CELL_SIZE, fp);
        char *token = strtok(line, ",");
        int j = 0;
        while (token!= NULL) {
            strcpy(csv->data[i] + j * MAX_CELL_SIZE, token);
            j++;
            token = strtok(NULL, ",");
        }
    }

    fclose(fp);

    return csv;
}

void csv_print_data(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        for (int j = 0; j < csv->cols; j++) {
            printf("%s ", csv->data[i] + j * MAX_CELL_SIZE);
        }
        printf("\n");
    }
}

void csv_free_data(CSV *csv) {
    for (int i = 0; i < csv->rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_read_file("data.csv");
    csv_print_data(csv);
    csv_free_data(csv);

    return 0;
}