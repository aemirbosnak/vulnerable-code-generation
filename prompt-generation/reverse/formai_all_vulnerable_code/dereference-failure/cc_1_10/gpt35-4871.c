//FormAI DATASET v1.0 Category: Building a CSV Reader ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_COLUMNS 10
#define MAX_CELL_LENGTH 50

typedef struct {
    char column_names[MAX_COLUMNS][MAX_CELL_LENGTH];
    int column_count;
    char **data;
    int row_count;
} CSV;

void free_csv(CSV *csv) {
    for (int i = 0; i < csv->row_count; i++) {
        free(csv->data[i]);
    }
    free(csv->data);
}

CSV read_csv(const char *file_path) {
    FILE *file = fopen(file_path, "r");
    if (file == NULL) {
        printf("Error: Could not open %s\n", file_path);
        exit(1);
    }

    CSV csv;
    csv.column_count = 0;
    csv.row_count = 0;

    char buffer[MAX_CELL_LENGTH];
    char *token;

    // Read column names from first row
    fgets(buffer, MAX_CELL_LENGTH, file);
    token = strtok(buffer, ",");
    while (token != NULL) {
        strcpy(csv.column_names[csv.column_count], token);
        csv.column_count++;
        token = strtok(NULL, ",");
    }

    // Allocate memory for data
    csv.data = (char **)malloc(sizeof(char *) * 100);
    for (int i = 0; i < 100; i++) {
        csv.data[i] = (char *)malloc(sizeof(char) * csv.column_count * MAX_CELL_LENGTH);
    }

    // Read data from subsequent rows
    while (fgets(buffer, MAX_CELL_LENGTH, file)) {
        csv.row_count++;
        token = strtok(buffer, ",");
        int column_index = 0;

        while (token != NULL) {
            strcpy(csv.data[csv.row_count - 1] + column_index * MAX_CELL_LENGTH, token);
            column_index++;
            token = strtok(NULL, ",");
        }

        if (column_index != csv.column_count) {
            printf("Error: Number of columns in row %d does not match number of columns in header\n", csv.row_count);
            exit(1);
        }
    }

    fclose(file);
    return csv;
}

int main() {
    CSV csv = read_csv("example.csv");

    printf("Column names:\n");
    for (int i = 0; i < csv.column_count; i++) {
        printf("%s ", csv.column_names[i]);
    }
    printf("\n\n");

    printf("Data:\n");
    for (int i = 0; i < csv.row_count; i++) {
        for (int j = 0; j < csv.column_count; j++) {
            printf("%s ", csv.data[i] + j * MAX_CELL_LENGTH);
        }
        printf("\n");
    }

    free_csv(&csv);
    return 0;
}