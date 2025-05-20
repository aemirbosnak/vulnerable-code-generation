//GEMINI-pro DATASET v1.0 Category: Building a CSV Reader ; Style: artistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of fields in a CSV line
#define MAX_FIELDS 100

// Define the maximum length of a field in a CSV line
#define MAX_FIELD_LENGTH 100

// Define the delimiter used to separate fields in a CSV line
#define DELIMITER ','

// Define the newline character used to separate lines in a CSV file
#define NEWLINE '\n'

// Create a structure to represent a CSV reader
typedef struct csv_reader {
    FILE *fp;  
    char line[MAX_FIELD_LENGTH * MAX_FIELDS]; 
    char *fields[MAX_FIELDS]; 
    int num_fields; 
} csv_reader_t;

// Create a new CSV reader
csv_reader_t *csv_reader_new(FILE *fp) {
    csv_reader_t *reader = malloc(sizeof(csv_reader_t));
    reader->fp = fp;
    reader->line[0] = '\0';
    reader->num_fields = 0;
    return reader;
}

// Free a CSV reader
void csv_reader_free(csv_reader_t *reader) {
    free(reader);
}

// Read the next line from a CSV file
int csv_reader_next_line(csv_reader_t *reader) {
    // Read a line from the file
    if (fgets(reader->line, sizeof(reader->line), reader->fp) == NULL) {
        return -1;
    }

    // Split the line into fields
    reader->num_fields = 0;
    char *field = strtok(reader->line, DELIMITER);
    while (field != NULL) {
        reader->fields[reader->num_fields++] = field;
        field = strtok(NULL, DELIMITER);
    }

    // Return the number of fields in the line
    return reader->num_fields;
}

// Get the value of a field in the current line
char *csv_reader_get_field(csv_reader_t *reader, int index) {
    if (index < 0 || index >= reader->num_fields) {
        return NULL;
    }
    return reader->fields[index];
}

// Print the current line of a CSV file
void csv_reader_print_line(csv_reader_t *reader) {
    for (int i = 0; i < reader->num_fields; i++) {
        printf("%s", reader->fields[i]);
        if (i < reader->num_fields - 1) {
            printf(", ");
        }
    }
    printf("\n");
}

// Read a CSV file and print its contents
int main() {
 
    FILE *fp = fopen("data.csv", "r");
    if (fp == NULL) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    // Create a CSV reader
    csv_reader_t *reader = csv_reader_new(fp);

    // Read the lines of the CSV file
    while (csv_reader_next_line(reader) != -1) {
        // Print the line
        csv_reader_print_line(reader);
    }

    // Free the CSV reader
    csv_reader_free(reader);

    // Close the file
    fclose(fp);

    return EXIT_SUCCESS;
}