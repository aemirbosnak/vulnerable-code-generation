//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV row
#define MAX_COLUMNS 10

// Define the maximum length of a line in a CSV file
#define MAX_LINE_LENGTH 1024

// Define the delimiter used to separate columns in a CSV file
#define DELIMITER ','

// Create a struct to represent a CSV row
typedef struct csv_row {
    char *columns[MAX_COLUMNS];
    int num_columns;
} csv_row;

// Create a struct to represent a CSV file
typedef struct csv_file {
    FILE *file;
    csv_row *rows;
    int num_rows;
} csv_file;

// Open a CSV file for reading
csv_file *csv_open(const char *filename) {
    // Allocate memory for the CSV file struct
    csv_file *file = malloc(sizeof(csv_file));
    if (file == NULL) {
        return NULL;
    }

    // Open the CSV file
    file->file = fopen(filename, "r");
    if (file->file == NULL) {
        free(file);
        return NULL;
    }

    // Initialize the number of rows to 0
    file->num_rows = 0;

    // Return the CSV file struct
    return file;
}

// Close a CSV file
void csv_close(csv_file *file) {
    // Close the CSV file
    fclose(file->file);

    // Free the memory allocated for the rows
    for (int i = 0; i < file->num_rows; i++) {
        for (int j = 0; j < file->rows[i].num_columns; j++) {
            free(file->rows[i].columns[j]);
        }
        free(file->rows[i].columns);
    }
    free(file->rows);

    // Free the memory allocated for the CSV file struct
    free(file);
}

// Read a line from a CSV file
char *csv_readline(csv_file *file) {
    // Allocate memory for the line
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        return NULL;
    }

    // Read a line from the CSV file
    if (fgets(line, MAX_LINE_LENGTH, file->file) == NULL) {
        free(line);
        return NULL;
    }

    // Return the line
    return line;
}

// Parse a CSV line into a row
csv_row *csv_parse_line(char *line) {
    // Allocate memory for the row
    csv_row *row = malloc(sizeof(csv_row));
    if (row == NULL) {
        return NULL;
    }

    // Initialize the number of columns to 0
    row->num_columns = 0;

    // Split the line into columns
    char *column = strtok(line, DELIMITER);
    while (column != NULL) {
        // Allocate memory for the column
        char *column_copy = malloc(strlen(column) + 1);
        if (column_copy == NULL) {
            free(row);
            return NULL;
        }

        // Copy the column into the row
        strcpy(column_copy, column);
        row->columns[row->num_columns++] = column_copy;

        // Get the next column
        column = strtok(NULL, DELIMITER);
    }

    // Return the row
    return row;
}

// Read a CSV file into a list of rows
csv_row **csv_read(csv_file *file) {
    // Allocate memory for the list of rows
    csv_row **rows = malloc(sizeof(csv_row *) * file->num_rows);
    if (rows == NULL) {
        return NULL;
    }

    // Read the lines from the CSV file
    char *line;
    while ((line = csv_readline(file)) != NULL) {
        // Parse the line into a row
        csv_row *row = csv_parse_line(line);
        if (row == NULL) {
            free(rows);
            return NULL;
        }

        // Add the row to the list of rows
        rows[file->num_rows++] = row;

        // Free the line
        free(line);
    }

    // Return the list of rows
    return rows;
}

// Print a CSV row
void csv_print_row(csv_row *row) {
    // Print the columns
    for (int i = 0; i < row->num_columns; i++) {
        printf("%s", row->columns[i]);
        if (i < row->num_columns - 1) {
            printf(", ");
        }
    }

    // Print a newline
    printf("\n");
}

// Print a CSV file
void csv_print(csv_file *file) {
    // Read the rows from the CSV file
    csv_row **rows = csv_read(file);
    if (rows == NULL) {
        return;
    }

    // Print the rows
    for (int i = 0; i < file->num_rows; i++) {
        csv_print_row(rows[i]);
    }

    // Free the memory allocated for the rows
    for (int i = 0; i < file->num_rows; i++) {
        free(rows[i]);
    }
    free(rows);
}

// Main function
int main() {
    // Open a CSV file
    csv_file *file = csv_open("data.csv");
    if (file == NULL) {
        return EXIT_FAILURE;
    }

    // Print the CSV file
    csv_print(file);

    // Close the CSV file
    csv_close(file);

    return EXIT_SUCCESS;
}