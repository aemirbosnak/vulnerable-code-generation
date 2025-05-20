//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Structure to hold data from CSV
typedef struct {
    char **fields;
    int field_count;
} CSVRow;

// Function to free memory allocated for CSVRow
void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

// Function to read a CSV file and store the data in an array of CSVRow
CSVRow *read_csv(const char *filename, int *row_count) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return NULL;
    }
    
    char line[MAX_LINE_LENGTH];
    CSVRow *rows = NULL;
    *row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        if (line[0] == '\n') continue; // Skip empty lines
        
        // Allocate memory for a new row
        rows = realloc(rows, (*row_count + 1) * sizeof(CSVRow));
        if (!rows) {
            perror("Memory allocation error");
            fclose(file);
            return NULL;
        }

        CSVRow *current_row = &rows[*row_count];
        current_row->field_count = 0;
        current_row->fields = malloc(MAX_FIELDS * sizeof(char*));
        
        char *token = strtok(line, ",");
        while (token) {
            current_row->fields[current_row->field_count] = malloc(strlen(token) + 1);
            strcpy(current_row->fields[current_row->field_count], token);
            current_row->field_count++;
            token = strtok(NULL, ",");
        }

        (*row_count)++;
    }

    fclose(file);
    return rows;
}

// Function to print the contents of CSVRow
void print_csv_rows(CSVRow *rows, int row_count) {
    for (int i = 0; i < row_count; i++) {
        for (int j = 0; j < rows[i].field_count; j++) {
            printf("%s", rows[i].fields[j]);
            if (j < rows[i].field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");
    }
}

// Main function to demonstrate CSV reading
int main() {
    const char *filename = "data.csv"; // Replace with your CSV file name
    int row_count = 0;

    CSVRow *rows = read_csv(filename, &row_count);
    if (!rows) {
        return EXIT_FAILURE;
    }

    printf("CSV Data:\n");
    print_csv_rows(rows, row_count);

    // Free allocated memory
    for (int i = 0; i < row_count; i++) {
        free_csv_row(&rows[i]);
    }
    free(rows);

    return EXIT_SUCCESS;
}