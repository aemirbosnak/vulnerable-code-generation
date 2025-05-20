//Falcon-180B DATASET v1.0 Category: Building a CSV Reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROWS 1000
#define MAX_COLUMNS 1000
#define MAX_CELL_SIZE 1000

typedef struct {
    char **data;
    int num_rows;
    int num_columns;
} CSV;

CSV *csv_open(FILE *file) {
    CSV *csv = malloc(sizeof(CSV));
    csv->data = NULL;
    csv->num_rows = 0;
    csv->num_columns = 0;

    char line[MAX_CELL_SIZE];
    int in_data = 0;
    int num_columns = 0;

    while (fgets(line, MAX_CELL_SIZE, file)!= NULL) {
        if (in_data) {
            char *token = strtok(line, ",");

            while (token!= NULL) {
                int column_index = num_columns++;
                csv->data = realloc(csv->data, sizeof(char *) * num_columns);
                csv->data[column_index] = strdup(token);
                token = strtok(NULL, ",");
            }

            csv->num_rows++;
        } else if (strlen(line) > 0) {
            in_data = 1;
            csv->num_columns = num_columns;
            csv->data = malloc(sizeof(char *) * num_columns);
        }
    }

    csv->data = realloc(csv->data, sizeof(char *) * csv->num_columns);

    return csv;
}

void csv_close(CSV *csv) {
    for (int i = 0; i < csv->num_columns; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
    free(csv);
}

char **csv_get_row(CSV *csv, int row) {
    if (row >= csv->num_rows || row < 0) {
        return NULL;
    }

    return csv->data;
}

int main() {
    FILE *file = fopen("example.csv", "r");
    CSV *csv = csv_open(file);

    for (int i = 0; i < csv->num_rows; i++) {
        char **row = csv_get_row(csv, i);

        for (int j = 0; j < csv->num_columns; j++) {
            printf("%s\t", row[j]);
        }
        printf("\n");
    }

    csv_close(csv);
    fclose(file);

    return 0;
}