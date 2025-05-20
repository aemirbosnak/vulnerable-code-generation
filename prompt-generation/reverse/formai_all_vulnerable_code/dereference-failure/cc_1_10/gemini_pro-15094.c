//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the CSV file
#define MAX_COLUMNS 10

// Define the maximum length of a line in the CSV file
#define MAX_LINE_LENGTH 1024

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the structure of a CSV record
typedef struct {
    char *columns[MAX_COLUMNS];
    int num_columns;
} CSVRecord;

// Define the structure of a CSV reader
typedef struct {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    int line_number;
    int num_columns;
    char *columns[MAX_COLUMNS];
} CSVReader;

// Create a new CSV reader
CSVReader *csv_reader_new(FILE *fp) {
    CSVReader *reader = malloc(sizeof(CSVReader));
    reader->fp = fp;
    reader->line_number = 0;
    reader->num_columns = 0;
    for (int i = 0; i < MAX_COLUMNS; i++) {
        reader->columns[i] = NULL;
    }
    return reader;
}

// Free a CSV reader
void csv_reader_free(CSVReader *reader) {
    for (int i = 0; i < reader->num_columns; i++) {
        free(reader->columns[i]);
    }
    free(reader);
}

// Read the next line from the CSV file
int csv_reader_next_line(CSVReader *reader) {
    if (fgets(reader->line, MAX_LINE_LENGTH, reader->fp) == NULL) {
        return 0;
    }

    reader->line_number++;

    // Split the line into columns
    char *token = strtok(reader->line, DELIMITER);
    reader->num_columns = 0;
    while (token != NULL && reader->num_columns < MAX_COLUMNS) {
        reader->columns[reader->num_columns++] = strdup(token);
        token = strtok(NULL, DELIMITER);
    }

    return 1;
}

// Get the value of the specified column in the current record
char *csv_reader_get_column(CSVReader *reader, int column_index) {
    if (column_index < 0 || column_index >= reader->num_columns) {
        return NULL;
    }

    return reader->columns[column_index];
}

// Print the current record to the console
void csv_reader_print_record(CSVReader *reader) {
    for (int i = 0; i < reader->num_columns; i++) {
        printf("%s", reader->columns[i]);
        if (i < reader->num_columns - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Read and print all records from the CSV file
int main() {
    // Open the CSV file for reading
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a CSV reader
    CSVReader *reader = csv_reader_new(fp);

    // Read and print each record from the CSV file
    while (csv_reader_next_line(reader)) {
        csv_reader_print_record(reader);
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(fp);

    return EXIT_SUCCESS;
}