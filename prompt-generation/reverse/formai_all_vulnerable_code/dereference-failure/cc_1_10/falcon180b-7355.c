//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: standalone
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_LINE_LENGTH 10000

typedef struct {
    int num_rows;
    int num_cols;
    char delimiter;
    char **data;
} CSV;

CSV *csv_read(FILE *fp) {
    CSV *csv = (CSV *)malloc(sizeof(CSV));
    csv->num_rows = 0;
    csv->num_cols = 0;
    csv->delimiter = ',';
    csv->data = (char **)malloc(MAX_ROWS * sizeof(char *));

    char line[MAX_LINE_LENGTH];
    while (fgets(line, MAX_LINE_LENGTH, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            csv->num_cols = (csv->num_cols > col_count)? csv->num_cols : col_count;
            csv->data[csv->num_rows] = (char *)malloc(MAX_LINE_LENGTH);
            strcpy(csv->data[csv->num_rows], token);
            csv->num_rows++;
            col_count++;
            token = strtok(NULL, ",");
        }
    }

    csv->data = (char **)realloc(csv->data, csv->num_rows * sizeof(char *));

    return csv;
}

void csv_print(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        for (int j = 0; j < csv->num_cols; j++) {
            printf("%s\t", csv->data[i]);
        }
        printf("\n");
    }
}

void csv_free(CSV *csv) {
    for (int i = 0; i < csv->num_rows; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

int main(int argc, char **argv) {
    if (argc!= 3) {
        printf("Usage: %s <input_file> <output_file>\n", argv[0]);
        return 1;
    }

    FILE *input_fp = fopen(argv[1], "r");
    if (input_fp == NULL) {
        printf("Error: could not open input file.\n");
        return 1;
    }

    CSV *csv = csv_read(input_fp);
    fclose(input_fp);

    FILE *output_fp = fopen(argv[2], "w");
    if (output_fp == NULL) {
        printf("Error: could not open output file.\n");
        csv_free(csv);
        return 1;
    }

    csv_print(csv);
    fprintf(output_fp, "Total number of rows: %d\n", csv->num_rows);
    fprintf(output_fp, "Total number of columns: %d\n", csv->num_cols);

    fclose(output_fp);
    csv_free(csv);

    return 0;
}