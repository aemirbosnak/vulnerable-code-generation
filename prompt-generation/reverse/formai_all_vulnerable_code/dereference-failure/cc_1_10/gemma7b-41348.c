//Gemma-7B DATASET v1.0 Category: Building a CSV Reader ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINES 100
#define MAX_COLS 20

typedef struct CSV_DATA {
    char **data;
    int num_rows;
    int num_cols;
} CSV_DATA;

CSV_DATA *read_csv(char *filename) {
    CSV_DATA *csv_data = malloc(sizeof(CSV_DATA));
    csv_data->data = NULL;
    csv_data->num_rows = 0;
    csv_data->num_cols = 0;

    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        return NULL;
    }

    char line[MAX_LINES];
    while (fgets(line, MAX_LINES, fp) != NULL) {
        char **columns = NULL;
        int num_cols = 0;

        // Parse the line into columns
        char *column = strtok(line, ",");
        while (column) {
            columns = realloc(columns, (num_cols + 1) * sizeof(char *));
            columns[num_cols++] = strdup(column);
            column = strtok(NULL, ",");
        }

        // Update the CSV data
        csv_data->data = realloc(csv_data->data, (csv_data->num_rows + 1) * sizeof(char **));
        csv_data->data[csv_data->num_rows++] = columns;
        csv_data->num_cols = num_cols;
    }

    fclose(fp);
    return csv_data;
}

int main() {
    char *filename = "data.csv";
    CSV_DATA *csv_data = read_csv(filename);

    // Print the CSV data
    for (int i = 0; i < csv_data->num_rows; i++) {
        for (int j = 0; j < csv_data->num_cols; j++) {
            printf("%s ", csv_data->data[i][j]);
        }
        printf("\n");
    }

    free(csv_data);
    return 0;
}