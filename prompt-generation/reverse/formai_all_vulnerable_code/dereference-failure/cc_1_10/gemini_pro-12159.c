//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Custom types and structs
typedef struct {
    char *data;
    size_t len;
} CsvField;

typedef struct {
    CsvField *fields;
    size_t num_fields;
} CsvRow;

// Function prototypes
CsvRow *parse_csv_line(char *line);
void print_csv_row(CsvRow *row);
void free_csv_row(CsvRow *row);

// Main function
int main() {
    // Read the input CSV file
    FILE *fp = fopen("input.csv", "r");
    if (fp == NULL) {
        perror("fopen");
        exit(EXIT_FAILURE);
    }

    // Read each line of the CSV file and parse it
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    while ((read = getline(&line, &len, fp)) != -1) {
        CsvRow *row = parse_csv_line(line);
        print_csv_row(row);
        free_csv_row(row);
    }

    // Free the input line buffer
    free(line);

    // Close the input CSV file
    fclose(fp);

    return EXIT_SUCCESS;
}

// Function to parse a single line of CSV data
CsvRow *parse_csv_line(char *line) {
    // Allocate memory for the CSV row
    CsvRow *row = malloc(sizeof(CsvRow));
    if (row == NULL) {
        perror("malloc");
        exit(EXIT_FAILURE);
    }

    // Initialize the CSV row
    row->fields = NULL;
    row->num_fields = 0;

    // Parse the line into fields
    char *start = line;
    char *end = NULL;
    while ((end = strchr(start, ',')) != NULL) {
        // Allocate memory for the field
        CsvField *field = malloc(sizeof(CsvField));
        if (field == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // Copy the field data
        field->len = end - start;
        field->data = malloc(field->len + 1);
        if (field->data == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strncpy(field->data, start, field->len);
        field->data[field->len] = '\0';

        // Add the field to the row
        row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(CsvField));
        if (row->fields == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        row->fields[row->num_fields++] = *field;

        // Advance the start pointer
        start = end + 1;
    }

    // Handle the last field
    if (*start != '\0') {
        // Allocate memory for the field
        CsvField *field = malloc(sizeof(CsvField));
        if (field == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }

        // Copy the field data
        field->len = strlen(start);
        field->data = malloc(field->len + 1);
        if (field->data == NULL) {
            perror("malloc");
            exit(EXIT_FAILURE);
        }
        strcpy(field->data, start);
        field->data[field->len] = '\0';

        // Add the field to the row
        row->fields = realloc(row->fields, (row->num_fields + 1) * sizeof(CsvField));
        if (row->fields == NULL) {
            perror("realloc");
            exit(EXIT_FAILURE);
        }
        row->fields[row->num_fields++] = *field;
    }

    // Return the CSV row
    return row;
}

// Function to print a CSV row
void print_csv_row(CsvRow *row) {
    for (size_t i = 0; i < row->num_fields; i++) {
        printf("%s", row->fields[i].data);
        if (i < row->num_fields - 1) {
            printf(",");
        }
    }
    printf("\n");
}

// Function to free the memory allocated for a CSV row
void free_csv_row(CsvRow *row) {
    for (size_t i = 0; i < row->num_fields; i++) {
        free(row->fields[i].data);
    }
    free(row->fields);
    free(row);
}