//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1000
#define MAX_COLUMNS 100

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CSV;

CSV *csv_open(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_cols = 0;

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, file)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            col_count++;
            token = strtok(NULL, ",");
        }
        if (col_count > csv->num_cols) {
            csv->num_cols = col_count;
        }
        csv->num_rows++;
    }

    csv->data = malloc(csv->num_rows * sizeof(char *));
    for (int i = 0; i < csv->num_rows; i++) {
        csv->data[i] = malloc(csv->num_cols * MAX_LINE_LENGTH);
    }

    rewind(file);
    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int csv_get_num_rows(CSV *csv) {
    return csv->num_rows;
}

int csv_get_num_cols(CSV *csv) {
    return csv->num_cols;
}

char *csv_get_cell(CSV *csv, int row, int col) {
    return csv->data[row][col];
}

int main(int argc, char **argv) {
    if (argc < 2) {
        printf("Usage: %s <csv_file>\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Error opening file '%s'.\n", argv[1]);
        return 1;
    }

    CSV *csv = csv_open(file);

    printf("Number of rows: %d\n", csv_get_num_rows(csv));
    printf("Number of columns: %d\n", csv_get_num_cols(csv));

    for (int i = 0; i < csv_get_num_rows(csv); i++) {
        for (int j = 0; j < csv_get_num_cols(csv); j++) {
            printf("%s ", csv_get_cell(csv, i, j));
        }
        printf("\n");
    }

    csv_close(csv);
    fclose(file);

    return 0;
}