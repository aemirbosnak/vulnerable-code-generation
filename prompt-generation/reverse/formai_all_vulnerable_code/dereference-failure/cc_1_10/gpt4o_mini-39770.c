//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Structure to hold a single row of CSV data
typedef struct {
    char **fields;
    int field_count;
} CsvRow;

// Function to free CsvRow memory
void free_csv_row(CsvRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

// Function to split a CSV line into fields
CsvRow *parse_csv_line(const char *line) {
    CsvRow *row = malloc(sizeof(CsvRow));
    row->fields = malloc(MAX_FIELDS * sizeof(char *));
    row->field_count = 0;
    
    char *token;
    char *line_copy = strdup(line);  // Duplicate the line to avoid modifying the original.

    token = strtok(line_copy, ",");
    while (token != NULL && row->field_count < MAX_FIELDS) {
        row->fields[row->field_count++] = strdup(token);
        token = strtok(NULL, ",");
    }

    free(line_copy);
    return row;
}

// Function to read a CSV file and print its contents
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    
    if (file == NULL) {
        perror("File opening failed");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    while (fgets(line, sizeof(line), file)) {
        line_number++;
        // Remove the trailing newline character from the line
        line[strcspn(line, "\n")] = 0;

        CsvRow *row = parse_csv_line(line);
        
        printf("Row %d: ", line_number);
        for (int i = 0; i < row->field_count; i++) {
            printf("[%s] ", row->fields[i]);
        }
        printf("\n");

        free_csv_row(row);  // Clean up memory
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}