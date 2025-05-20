//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in the CSV file
#define MAX_COLUMNS 10

// Define the maximum length of a line in the CSV file
#define MAX_LINE_LENGTH 1024

// Define the delimiter used in the CSV file
#define DELIMITER ','

// Define the structure of a CSV row
typedef struct {
    char *columns[MAX_COLUMNS];
    int num_columns;
} CSVRow;

// Read a line from the CSV file
char *readLine(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (line == NULL) {
        return NULL;
    }

    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL;
    }

    return line;
}

// Split a line into columns
CSVRow *splitLine(char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (row == NULL) {
        return NULL;
    }

    row->num_columns = 0;

    char *column = strtok(line, DELIMITER);
    while (column != NULL) {
        row->columns[row->num_columns] = strdup(column);
        row->num_columns++;

        column = strtok(NULL, DELIMITER);
    }

    return row;
}

// Free the memory allocated for a CSV row
void freeRow(CSVRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        free(row->columns[i]);
    }

    free(row);
}

// Read a CSV file
CSVRow **readCSV(char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        return NULL;
    }

    // Read the header line
    char *header = readLine(file);
    if (header == NULL) {
        fclose(file);
        return NULL;
    }

    // Split the header line into columns
    CSVRow *headerRow = splitLine(header);
    if (headerRow == NULL) {
        free(header);
        fclose(file);
        return NULL;
    }

    // Allocate memory for the array of rows
    CSVRow **rows = malloc(sizeof(CSVRow *) * 100);
    if (rows == NULL) {
        freeRow(headerRow);
        free(header);
        fclose(file);
        return NULL;
    }

    // Read the data lines
    int num_rows = 0;
    while (1) {
        char *line = readLine(file);
        if (line == NULL) {
            break;
        }

        // Split the line into columns
        CSVRow *row = splitLine(line);
        if (row == NULL) {
            free(line);
            break;
        }

        // Add the row to the array of rows
        rows[num_rows] = row;
        num_rows++;

        free(line);
    }

    // Free the memory allocated for the header row
    freeRow(headerRow);
    free(header);

    // Close the file
    fclose(file);

    return rows;
}

// Print a CSV row
void printRow(CSVRow *row) {
    for (int i = 0; i < row->num_columns; i++) {
        printf("%s", row->columns[i]);

        if (i < row->num_columns - 1) {
            printf(",");
        }
    }

    printf("\n");
}

// Print a CSV file
void printCSV(CSVRow **rows, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        printRow(rows[i]);
    }
}

// Free the memory allocated for a CSV file
void freeCSV(CSVRow **rows, int num_rows) {
    for (int i = 0; i < num_rows; i++) {
        freeRow(rows[i]);
    }

    free(rows);
}

// Main function
int main() {
    // Read the CSV file
    CSVRow **rows = readCSV("data.csv");

    // Print the CSV file
    printCSV(rows, 10);

    // Free the memory allocated for the CSV file
    freeCSV(rows, 10);

    return 0;
}