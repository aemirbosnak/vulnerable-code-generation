//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROWS 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int rows;
    int cols;
} CSV_DATA;

CSV_DATA *csv_read(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = malloc(MAX_ROWS * MAX_COLS * sizeof(char *));
    csv_data->rows = 0;
    csv_data->cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_ROWS];
    while (fgets(line, MAX_ROWS, fp) != NULL) {
        char **columns = malloc(MAX_COLS * sizeof(char *));
        int i = 0;
        columns[i] = strtok(line, ",");
        while (columns[i] != NULL) {
            i++;
            columns[i] = strtok(NULL, ",");
        }

        csv_data->data[csv_data->rows] = columns;
        csv_data->rows++;
    }

    fclose(fp);

    return csv_data;
}

int main() {
    char *filename = "data.csv";
    CSV_DATA *csv_data = csv_read(filename);

    if (csv_data) {
        for (int i = 0; i < csv_data->rows; i++) {
            for (int j = 0; j < csv_data->cols; j++) {
                printf("%s,", csv_data->data[i][j]);
            }
            printf("\n");
        }

        free(csv_data->data);
        free(csv_data);
    }

    return 0;
}