//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 1000
#define MAX_COLS 1000
#define MAX_CELL_DATA_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_cols;
} CsvData;

CsvData *csv_read_file(const char *filename) {
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        printf("Error: could not open file %s\n", filename);
        exit(1);
    }

    CsvData *data = malloc(sizeof(CsvData));
    data->data = NULL;
    data->num_rows = 0;
    data->num_cols = 0;

    char line[MAX_CELL_DATA_SIZE];
    char delimiter = ',';
    while (fgets(line, MAX_CELL_DATA_SIZE, fp)!= NULL) {
        int cell_count = 0;
        char *token = strtok(line, &delimiter);
        while (token!= NULL) {
            if (cell_count >= MAX_COLS) {
                printf("Error: too many columns in row\n");
                exit(1);
            }
            data->data[data->num_rows] = realloc(data->data[data->num_rows], sizeof(char *) * (data->num_cols + 1));
            data->data[data->num_rows][data->num_cols] = strdup(token);
            cell_count++;
        }
        if (cell_count == 0) {
            printf("Error: empty row\n");
            exit(1);
        }
        data->num_cols = cell_count;
        data->num_rows++;
    }

    fclose(fp);
    return data;
}

void csv_print_data(const CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s ", data->data[i][j]);
        }
        printf("\n");
    }
}

void csv_free_data(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            free(data->data[i][j]);
        }
        free(data->data[i]);
    }
    free(data->data);
    free(data);
}

int main() {
    CsvData *data = csv_read_file("example.csv");
    csv_print_data(data);
    csv_free_data(data);
    return 0;
}