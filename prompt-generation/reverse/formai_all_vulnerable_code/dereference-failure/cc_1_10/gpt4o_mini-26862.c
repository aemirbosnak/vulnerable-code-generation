//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_TOKENS 100

// Structure to hold CSV data
typedef struct {
    char **data;
    int column_count;
} CSVRow;

// Function to split a string based on a delimiter
int split(char *line, char **tokens, const char *delimiter) {
    int count = 0;
    char *token = strtok(line, delimiter);

    while (token != NULL && count < MAX_TOKENS) {
        tokens[count++] = token;
        token = strtok(NULL, delimiter);
    }
    return count;
}

// Function to free allocated memory for CSVRow
void free_csv_row(CSVRow *row) {
    if (row) {
        free(row->data);
        free(row);
    }
}

// Function to read a CSV file and store it into a dynamic array of CSVRow
CSVRow **read_csv(const char *filename, int *row_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Could not open file: %s\n", filename);
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    CSVRow **rows = NULL;
    *row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        rows = realloc(rows, (*row_count + 1) * sizeof(CSVRow *));
        if (!rows) {
            fprintf(stderr, "Memory allocation failed.\n");
            fclose(file);
            return NULL;
        }

        CSVRow *row = malloc(sizeof(CSVRow));
        row->data = malloc(MAX_TOKENS * sizeof(char *));
        row->column_count = split(line, row->data, ",\n");

        rows[*row_count] = row;
        (*row_count)++;
    }

    fclose(file);
    return rows;
}

// Function to print the CSV data
void print_csv(CSVRow **rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        CSVRow *row = rows[i];
        for (int j = 0; j < row->column_count; j++) {
            printf("%s", row->data[j]);
            if (j < row->column_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to release all allocated resources
void free_csv(CSVRow **rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        free_csv_row(rows[i]);
    }
    free(rows);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int row_count = 0;
    CSVRow **csv_data = read_csv(argv[1], &row_count);
    if (!csv_data) {
        return EXIT_FAILURE;
    }

    print_csv(csv_data, row_count);
    free_csv(csv_data, row_count);

    return EXIT_SUCCESS;
}