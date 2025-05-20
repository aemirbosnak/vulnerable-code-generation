//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV file.
#define MAX_COLUMNS 100

// Define the maximum number of rows in a CSV file.
#define MAX_ROWS 1000

// Define the maximum length of a line in a CSV file.
#define MAX_LINE_LENGTH 10000

// Define the delimiter used in the CSV file.
#define DELIMITER ','

// Define the null character.
#define NULL_CHAR '\0'

// Define the true value.
#define TRUE 1

// Define the false value.
#define FALSE 0

// Define the type of a CSV reader.
typedef struct csv_reader {
    FILE *file;
    char line[MAX_LINE_LENGTH];
    int row;
    int column;
} csv_reader;

// Create a new CSV reader.
csv_reader *csv_reader_new(FILE *file) {
    csv_reader *reader = malloc(sizeof(csv_reader));
    reader->file = file;
    reader->row = 0;
    reader->column = 0;
    return reader;
}

// Read the next line from the CSV file.
int csv_reader_next_line(csv_reader *reader) {
    if (fgets(reader->line, MAX_LINE_LENGTH, reader->file) == NULL) {
        return FALSE;
    }
    reader->row++;
    reader->column = 0;
    return TRUE;
}

// Read the next column from the CSV file.
int csv_reader_next_column(csv_reader *reader) {
    if (reader->column >= MAX_COLUMNS) {
        return FALSE;
    }
    char *start = reader->line;
    while (*start != DELIMITER && *start != NULL_CHAR) {
        start++;
    }
    if (*start == NULL_CHAR) {
        return FALSE;
    }
    *start = NULL_CHAR;
    reader->column++;
    return TRUE;
}

// Get the value of the current column.
char *csv_reader_get_value(csv_reader *reader) {
    return reader->line;
}

// Free the CSV reader.
void csv_reader_free(csv_reader *reader) {
    fclose(reader->file);
    free(reader);
}

// Parse a CSV file.
int csv_parse(FILE *file, char *results[MAX_ROWS][MAX_COLUMNS]) {
    csv_reader *reader = csv_reader_new(file);
    while (csv_reader_next_line(reader)) {
        while (csv_reader_next_column(reader)) {
            results[reader->row][reader->column] = csv_reader_get_value(reader);
        }
    }
    csv_reader_free(reader);
    return TRUE;
}

// Print the results of parsing a CSV file.
void csv_print_results(char *results[MAX_ROWS][MAX_COLUMNS]) {
    for (int row = 0; row < MAX_ROWS; row++) {
        for (int column = 0; column < MAX_COLUMNS; column++) {
            printf("%s", results[row][column]);
            if (column < MAX_COLUMNS - 1) {
                printf(",");
            }
        }
        printf("\n");
    }
}

int main(int argc, char *argv[]) {
    // Open the CSV file.
    FILE *file = fopen("data.csv", "r");
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    // Parse the CSV file.
    char *results[MAX_ROWS][MAX_COLUMNS];
    if (!csv_parse(file, results)) {
        return EXIT_FAILURE;
    }

    // Print the results of parsing the CSV file.
    csv_print_results(results);

    // Close the CSV file.
    fclose(file);

    return EXIT_SUCCESS;
}