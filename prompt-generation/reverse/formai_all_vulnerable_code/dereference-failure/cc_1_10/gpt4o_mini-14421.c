//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Structure to hold CSV data
typedef struct {
    char **fields;
    int field_count;
} CSVRow;

// Function to split a line into fields based on the delimiter
CSVRow *parse_csv_line(const char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (!row) {
        perror("Unable to allocate memory for CSV row");
        exit(EXIT_FAILURE);
    }

    row->fields = malloc(MAX_FIELDS * sizeof(char *));
    if (!row->fields) {
        perror("Unable to allocate memory for fields");
        free(row);
        exit(EXIT_FAILURE);
    }

    char *token;
    char *line_copy = strdup(line);
    int count = 0;

    token = strtok(line_copy, ",");  // Assuming a comma is the delimiter
    while (token != NULL && count < MAX_FIELDS) {
        row->fields[count] = strdup(token);
        if (!row->fields[count]) {
            perror("Unable to allocate memory for field");
            free(line_copy);
            free(row->fields);
            free(row);
            exit(EXIT_FAILURE);
        }
        count++;
        token = strtok(NULL, ",");
    }

    row->field_count = count;
    free(line_copy);
    return row;
}

// Function to free the memory allocated for a CSV row
void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

// Function to read CSV file and print its content
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Failed to open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int row_count = 0;

    while (fgets(line, sizeof(line), file)) {
        CSVRow *row = parse_csv_line(line);
        printf("Row %d:", row_count++);
        for (int i = 0; i < row->field_count; i++) {
            printf(" [%s]", row->fields[i]);
        }
        printf("\n");
        free_csv_row(row);
    }

    fclose(file);
}

// Main function to take filename from command line and read CSV
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}