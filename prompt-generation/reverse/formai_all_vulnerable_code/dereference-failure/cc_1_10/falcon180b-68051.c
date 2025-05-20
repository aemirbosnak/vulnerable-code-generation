//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROW_SIZE 1024
#define MAX_COL_SIZE 1024

typedef struct {
    char **rows;
    int num_rows;
    int num_cols;
} CsvData;

CsvData *csv_read(FILE *fp) {
    CsvData *data = malloc(sizeof(CsvData));
    data->num_rows = 0;
    data->num_cols = 0;
    data->rows = NULL;

    char line[MAX_ROW_SIZE];
    while (fgets(line, MAX_ROW_SIZE, fp)!= NULL) {
        char *token = strtok(line, ",");
        int col_count = 0;
        while (token!= NULL) {
            col_count++;
            if (data->num_cols == 0) {
                data->num_cols = col_count;
            } else if (col_count!= data->num_cols) {
                printf("Error: Number of columns in row %d does not match header\n", data->num_rows + 1);
                exit(1);
            }
            data->rows = realloc(data->rows, sizeof(char *) * (data->num_rows + 1));
            data->rows[data->num_rows] = malloc(strlen(token) + 1);
            strcpy(data->rows[data->num_rows], token);
            data->num_rows++;
            token = strtok(NULL, ",");
        }
    }

    return data;
}

void csv_print(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->num_cols; j++) {
            printf("%s\t", data->rows[i]);
        }
        printf("\n");
    }
}

void csv_free(CsvData *data) {
    for (int i = 0; i < data->num_rows; i++) {
        free(data->rows[i]);
    }
    free(data->rows);
    free(data);
}

int main() {
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        printf("Error: Could not open file\n");
        exit(1);
    }

    CsvData *data = csv_read(fp);
    csv_print(data);
    csv_free(data);

    fclose(fp);
    return 0;
}