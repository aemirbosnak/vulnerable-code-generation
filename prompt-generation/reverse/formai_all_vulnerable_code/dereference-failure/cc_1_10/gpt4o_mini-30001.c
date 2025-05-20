//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE 1024
#define DELIMITER ","

// Struct to hold CSV Data
typedef struct {
    char **fields;
    int field_count;
} CSVRow;

// Function to free allocated memory for a CSVRow
void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

// Function to read a CSV file and return a dynamic array of CSVRow
CSVRow *read_csv(const char *filename, int *row_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }

    char line[MAX_LINE];
    int capacity = 10;
    *row_count = 0;
    CSVRow *rows = malloc(capacity * sizeof(CSVRow));

    while (fgets(line, sizeof(line), file)) {
        if (*row_count >= capacity) {
            capacity *= 2;
            rows = realloc(rows, capacity * sizeof(CSVRow));
        }

        CSVRow *current_row = &rows[*row_count];
        current_row->field_count = 0;
        current_row->fields = malloc(sizeof(char*) * MAX_LINE);

        char *token = strtok(line, DELIMITER);
        while (token) {
            current_row->fields[current_row->field_count] = malloc(strlen(token) + 1);
            strcpy(current_row->fields[current_row->field_count], token);
            current_row->field_count++;
            token = strtok(NULL, DELIMITER);
        }

        (*row_count)++;
    }

    fclose(file);
    return rows;
}

// Function to print the CSV data
void print_csv(CSVRow *rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        CSVRow *row = &rows[i];
        for (int j = 0; j < row->field_count; j++) {
            printf("%s", row->fields[j]);
            if (j < row->field_count - 1) {
                printf("%s", DELIMITER);
            }
        }
        printf("\n");
    }
}

// Main Function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int row_count = 0;
    CSVRow *csv_data = read_csv(argv[1], &row_count);
    if (!csv_data) {
        return EXIT_FAILURE;
    }

    print_csv(csv_data, row_count);

    for (int i = 0; i < row_count; i++) {
        free_csv_row(&csv_data[i]);
    }
    free(csv_data);

    return EXIT_SUCCESS;
}