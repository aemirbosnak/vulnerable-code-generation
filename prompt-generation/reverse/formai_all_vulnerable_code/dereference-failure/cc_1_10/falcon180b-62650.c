//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1000
#define MAX_COL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_create() {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;
    return csv;
}

void csv_destroy(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

void csv_read_file(CSV *csv, const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: Could not open file '%s'.\n", filename);
        exit(1);
    }

    char buffer[MAX_ROW_SIZE];
    char *row = NULL;
    int row_size = 0;
    int num_cols = 0;
    while (fgets(buffer, MAX_ROW_SIZE, fp)!= NULL) {
        row = realloc(row, row_size + strlen(buffer) + 1);
        strcat(row, buffer);
        row_size += strlen(buffer);
        if (buffer[strlen(buffer) - 1] == '\n') {
            csv->data = realloc(csv->data, sizeof(char *) * (csv->num_rows + 1));
            csv->data[csv->num_rows] = row;
            csv->num_rows++;
            csv->num_cols = num_cols;
            row = NULL;
            row_size = 0;
            num_cols = 0;
        } else {
            num_cols++;
        }
    }

    csv->data = realloc(csv->data, sizeof(char *) * (csv->num_rows + 1));
    csv->data[csv->num_rows] = row;
    csv->num_rows++;
    csv->num_cols = num_cols;

    fclose(fp);
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        printf("%s\n", csv->data[i]);
    }
}

int main() {
    CSV *csv = csv_create();
    csv_read_file(csv, "example.csv");
    csv_print(csv);
    csv_destroy(csv);
    return 0;
}