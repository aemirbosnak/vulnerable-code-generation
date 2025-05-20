//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 50
#define MAX_ROWS 1000
#define MAX_FIELD_SIZE 100

typedef struct {
    char** data;
} row;

typedef struct {
    row* rows;
    int num_rows;
    int num_columns;
} csv_data;

void free_csv_data(csv_data* csv) {
    int i, j;
    for (i = 0; i < csv->num_rows; i++) {
        for (j = 0; j < csv->num_columns; j++) {
            free(csv->rows[i].data[j]);
        }
        free(csv->rows[i].data);
    }
    free(csv->rows);
}

csv_data* read_csv(char* file_name) {
    FILE* file = fopen(file_name, "r");
    if (!file) {
        printf("Could not open file %s\n", file_name);
        return NULL;
    }

    char line[MAX_ROWS * MAX_FIELD_SIZE];
    int i = 0, j = 0;
    char* field;
    csv_data* csv = malloc(sizeof(csv_data));
    csv->rows = malloc(sizeof(row) * MAX_ROWS);
    csv->num_rows = 0;
    csv->num_columns = 0;

    while (fgets(line, sizeof(line), file)) {
        csv->rows[i].data = malloc(sizeof(char*) * MAX_COLUMNS);
        j = 0;

        field = strtok(line, ",");
        while (field) {
            csv->rows[i].data[j] = malloc(MAX_FIELD_SIZE);

            // Remove trailing newline from field
            field[strcspn(field, "\n")] = 0;

            strcpy(csv->rows[i].data[j], field);

            j++;
            field = strtok(NULL, ",");
        }

        if (j > csv->num_columns) {
            csv->num_columns = j;
        }

        i++;
        if (i >= MAX_ROWS) {
            printf("Too many rows in %s\n", file_name);
            free_csv_data(csv);
            return NULL;
        }
    }

    csv->num_rows = i;

    return csv;
}

int main() {
    csv_data* csv = read_csv("example.csv");

    if (csv) {
        for (int i = 0; i < csv->num_rows; i++) {
            for (int j = 0; j < csv->num_columns; j++) {
                printf("%s,", csv->rows[i].data[j]);
            }
            printf("\n");
        }

        free_csv_data(csv);
    }

    return 0;
}