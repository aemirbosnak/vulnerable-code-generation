//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_COLUMNS 100

// Struct to hold a single CSV row
typedef struct {
    char** columns;
    int column_count;
} CSVRow;

// Function to create a new CSVRow
CSVRow* create_csv_row(int max_columns) {
    CSVRow* row = (CSVRow*)malloc(sizeof(CSVRow));
    row->columns = (char**)malloc(sizeof(char*) * max_columns);
    for (int i = 0; i < max_columns; i++) {
        row->columns[i] = NULL;
    }
    row->column_count = 0;
    return row;
}

// Function to free allocated memory for CSVRow
void free_csv_row(CSVRow* row) {
    for (int i = 0; i < row->column_count; i++) {
        free(row->columns[i]);
    }
    free(row->columns);
    free(row);
}

// Function to split a line into columns based on a delimiter
void split_line(const char* line, CSVRow* row, const char delimiter) {
    char* token;
    char* line_copy = strdup(line); // Make a copy to tokenize
    token = strtok(line_copy, &delimiter);
    while (token != NULL) {
        row->columns[row->column_count] = strdup(token);
        row->column_count++;
        token = strtok(NULL, &delimiter);
    }
    free(line_copy);
}

// Function to read CSV from a file
CSVRow** read_csv(const char* filename, int* row_count, const char delimiter) {
    FILE* file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return NULL;
    }

    char line[MAX_LINE_LENGTH];
    CSVRow** rows = NULL;
    *row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        rows = (CSVRow**)realloc(rows, sizeof(CSVRow*) * (*row_count + 1));
        rows[*row_count] = create_csv_row(MAX_COLUMNS);
        split_line(line, rows[*row_count], delimiter);
        (*row_count)++;
    }
    fclose(file);
    return rows;
}

// Function to print the CSV data
void print_csv_data(CSVRow** rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < rows[i]->column_count; j++) {
            printf("%s", rows[i]->columns[j]);
            if (j < rows[i]->column_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Function to free all allocated memory for CSV data
void free_csv_data(CSVRow** rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        free_csv_row(rows[i]);
    }
    free(rows);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename> [delimiter]\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char delimiter = (argc >= 3) ? argv[2][0] : ',';

    int row_count = 0;
    CSVRow** csv_data = read_csv(argv[1], &row_count, delimiter);

    if (csv_data) {
        print_csv_data(csv_data, row_count);
        free_csv_data(csv_data, row_count);
    }

    return EXIT_SUCCESS;
}