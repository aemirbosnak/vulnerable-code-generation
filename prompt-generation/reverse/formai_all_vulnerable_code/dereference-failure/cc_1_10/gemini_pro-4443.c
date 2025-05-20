//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV row
#define MAX_COLUMNS 100

// Define the maximum length of a CSV field
#define MAX_FIELD_LENGTH 1000

// Define the delimiter used to separate fields in a CSV row
#define DELIMITER ','

// Define the character used to quote fields in a CSV row
#define QUOTE '"'

// Create a structure to represent a CSV row
typedef struct {
    char *fields[MAX_COLUMNS];
    int num_fields;
} csv_row;

// Create a function to read a CSV file and return an array of CSV rows
csv_row *read_csv_file(char *filename, int *num_rows) {
    // Open the CSV file
    FILE *fp = fopen(filename, "r");
    if (fp == NULL) {
        perror("Error opening CSV file");
        return NULL;
    }

    // Allocate memory for the array of CSV rows
    csv_row *rows = malloc(sizeof(csv_row));
    if (rows == NULL) {
        perror("Error allocating memory for CSV rows");
        return NULL;
    }

    // Read the first line of the CSV file to get the number of columns
    char line[MAX_FIELD_LENGTH];
    if (fgets(line, MAX_FIELD_LENGTH, fp) == NULL) {
        perror("Error reading first line of CSV file");
        return NULL;
    }

    // Parse the first line of the CSV file to get the number of columns
    int num_columns = 0;
    char *field = strtok(line, DELIMITER);
    while (field != NULL) {
        num_columns++;
        field = strtok(NULL, DELIMITER);
    }

    // Allocate memory for the array of CSV fields
    for (int i = 0; i < num_columns; i++) {
        rows->fields[i] = malloc(MAX_FIELD_LENGTH);
        if (rows->fields[i] == NULL) {
            perror("Error allocating memory for CSV fields");
            return NULL;
        }
    }

    // Read the remaining lines of the CSV file
    int row_index = 0;
    while (fgets(line, MAX_FIELD_LENGTH, fp) != NULL) {
        // Parse the line to get the fields
        int field_index = 0;
        char *field = strtok(line, DELIMITER);
        while (field != NULL) {
            // Unquote the field if it is quoted
            if (*field == QUOTE) {
                field++;
                field[strlen(field) - 1] = '\0';
            }

            // Copy the field to the array of CSV fields
            strcpy(rows->fields[field_index], field);
            field_index++;

            // Get the next field
            field = strtok(NULL, DELIMITER);
        }

        // Increment the row index
        row_index++;

        // Reallocate memory for the array of CSV rows if necessary
        if (row_index >= *num_rows) {
            *num_rows *= 2;
            rows = realloc(rows, sizeof(csv_row) * *num_rows);
            if (rows == NULL) {
                perror("Error reallocating memory for CSV rows");
                return NULL;
            }
        }

        // Allocate memory for the array of CSV fields for the new row
        for (int i = 0; i < num_columns; i++) {
            rows[row_index].fields[i] = malloc(MAX_FIELD_LENGTH);
            if (rows[row_index].fields[i] == NULL) {
                perror("Error allocating memory for CSV fields");
                return NULL;
            }
        }
    }

    // Close the CSV file
    fclose(fp);

    // Return the array of CSV rows
    return rows;
}

// Create a function to free the memory allocated for an array of CSV rows
void free_csv_rows(csv_row *rows, int num_rows) {
    // Free the memory allocated for the array of CSV fields for each row
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            free(rows[i].fields[j]);
        }
    }

    // Free the memory allocated for the array of CSV rows
    free(rows);
}

// Create a function to print an array of CSV rows
void print_csv_rows(csv_row *rows, int num_rows) {
    // Print the CSV rows
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < MAX_COLUMNS; j++) {
            printf("%s,", rows[i].fields[j]);
        }
        printf("\n");
    }
}

// Create a function to main to test the CSV reader
int main() {
    // Read the CSV file
    int num_rows = 0;
    csv_row *rows = read_csv_file("data.csv", &num_rows);
    if (rows == NULL) {
        return 1;
    }

    // Print the CSV rows
    print_csv_rows(rows, num_rows);

    // Free the memory allocated for the CSV rows
    free_csv_rows(rows, num_rows);

    return 0;
}