//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char delimiter;
    int num_rows;
    int num_cols;
    char **data;
} CSV;

CSV *csv_open(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    CSV *csv = malloc(sizeof(CSV));
    csv->delimiter = ','; // default delimiter
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->data = malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_CELL_SIZE];
    while (fgets(line, MAX_CELL_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        if (csv->num_cols == 0) {
            csv->num_cols = 1;
            csv->data[0] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[0], token);
        } else {
            csv->num_cols++;
            csv->data = realloc(csv->data, csv->num_cols * sizeof(char *));
            csv->data[csv->num_cols - 1] = malloc(MAX_CELL_SIZE);
            strcpy(csv->data[csv->num_cols - 1], token);
        }
        csv->num_rows++;
    }

    fclose(fp);
    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[j]);
        }
        printf("\n");
    }
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main() {
    CSV *csv = csv_open("example.csv");
    csv_print(csv);
    csv_close(csv);

    return 0;
}