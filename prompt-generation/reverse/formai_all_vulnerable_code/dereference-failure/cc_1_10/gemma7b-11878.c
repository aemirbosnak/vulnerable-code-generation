//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 1024
#define MAX_COLS 256

typedef struct CSV_ROW {
    char **cells;
    int num_cols;
} CSV_ROW;

typedef struct CSV_DATA {
    CSV_ROW **rows;
    int num_rows;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
    CSV_DATA *data = malloc(sizeof(CSV_DATA));
    data->rows = malloc(MAX_LINES * sizeof(CSV_ROW));
    data->num_rows = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening file");
        free(data);
        return NULL;
    }

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        CSV_ROW *row = malloc(sizeof(CSV_ROW));
        row->cells = malloc(MAX_COLS * sizeof(char *));
        row->num_cols = 0;

        char *cell = strtok(line, ",");
        while (cell) {
            row->cells[row->num_cols++] = strdup(cell);
            cell = strtok(NULL, ",");
        }

        data->rows[data->num_rows++] = row;
    }

    fclose(fp);
    return data;
}

int main() {
    CSV_DATA *data = read_csv("data.csv");

    for (int i = 0; i < data->num_rows; i++) {
        for (int j = 0; j < data->rows[i]->num_cols; j++) {
            printf("%s ", data->rows[i]->cells[j]);
        }
        printf("\n");
    }

    free(data);
    return 0;
}