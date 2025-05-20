//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of columns in a CSV file
#define MAX_COLUMNS 10

// Define the maximum length of a line in a CSV file
#define MAX_LINE_LENGTH 1024

// Define the field separator character
#define FIELD_SEPARATOR ','

// Define the end-of-line character
#define END_OF_LINE '\n'

// Define the protected struct for the CSV reader
struct csv_reader {
    FILE *fp;
    char line[MAX_LINE_LENGTH];
    char *fields[MAX_COLUMNS];
    int num_fields;
};

// Create a new CSV reader
struct csv_reader *csv_reader_new(FILE *fp) {
    struct csv_reader *reader = malloc(sizeof(struct csv_reader));
    if (reader == NULL) {
        return NULL;
    }

    reader->fp = fp;
    reader->line[0] = '\0';
    reader->num_fields = 0;

    return reader;
}

// Free the CSV reader
void csv_reader_free(struct csv_reader *reader) {
    free(reader);
}

// Read the next line from the CSV file
int csv_reader_next_line(struct csv_reader *reader) {
    // Read the next line from the file
    if (fgets(reader->line, MAX_LINE_LENGTH, reader->fp) == NULL) {
        return -1;
    }

    // Remove the newline character from the end of the line
    reader->line[strlen(reader->line) - 1] = '\0';

    // Split the line into fields
    reader->num_fields = 0;
    char *field = strtok(reader->line, FIELD_SEPARATOR);
    while (field != NULL) {
        reader->fields[reader->num_fields++] = field;
        field = strtok(NULL, FIELD_SEPARATOR);
    }

    return 0;
}

// Get the value of the specified field
char *csv_reader_get_field(struct csv_reader *reader, int index) {
    if (index < 0 || index >= reader->num_fields) {
        return NULL;
    }

    return reader->fields[index];
}

// Print the CSV file
void csv_reader_print(struct csv_reader *reader) {
    int i;

    for (i = 0; i < reader->num_fields; i++) {
        printf("%s", reader->fields[i]);
        if (i < reader->num_fields - 1) {
            printf(",");
        }
    }

    printf("\n");
}

// Main function
int main() {
    // Open the CSV file
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a new CSV reader
    struct csv_reader *reader = csv_reader_new(fp);
    if (reader == NULL) {
        perror("Error creating CSV reader");
        fclose(fp);
        return EXIT_FAILURE;
    }

    // Read the CSV file
    while (csv_reader_next_line(reader) == 0) {
        // Print the CSV line
        csv_reader_print(reader);
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the CSV file
    fclose(fp);

    return EXIT_SUCCESS;
}