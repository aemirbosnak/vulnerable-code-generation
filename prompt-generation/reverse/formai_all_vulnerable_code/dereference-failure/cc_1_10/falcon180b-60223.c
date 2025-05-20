//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_COLUMNS 100
#define MAX_ROWS 1000
#define MAX_LINE_SIZE 8192

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CsvData;

CsvData *csv_read_file(FILE *fp) {
    CsvData *data = malloc(sizeof(CsvData));
    data->num_rows = 0;
    data->num_columns = 0;
    data->data = malloc(MAX_COLUMNS * sizeof(char*));

    char line[MAX_LINE_SIZE];
    while (fgets(line, MAX_LINE_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            if (col_count >= MAX_COLUMNS) {
                printf("Error: Too many columns in row.\n");
                exit(1);
            }
            data->data[col_count] = strdup(token);
            col_count++;
            token = strtok(NULL, ",");
        }
        data->num_columns = col_count;
        data->num_rows++;
    }

    if (data->num_columns == 0) {
        printf("Error: No columns found in CSV file.\n");
        exit(1);
    }

    return data;
}

void csv_print_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_columns; j++) {
            printf("%s\t", data->data[j]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData *data) {
    for (int i = 0; i < data->num_columns; i++) {
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    FILE *fp;
    fp = fopen("example.csv", "r");
    if (fp == NULL) {
        printf("Error: Unable to open CSV file.\n");
        exit(1);
    }

    CsvData *data = csv_read_file(fp);
    csv_print_data(data);
    csv_free_data(data);

    fclose(fp);
    return 0;
}