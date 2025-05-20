//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LEN 1024
#define MAX_FIELDS 100

// Function to read a line from the CSV file
int read_line(FILE *file, char *buffer, int size) {
    if (fgets(buffer, size, file) != NULL) {
        return strlen(buffer);
    }
    return -1; // Indicating end of file or error
}

// Function to parse a line into fields based on the delimiter
int parse_line(char *line, char fields[][MAX_LINE_LEN], char delimiter, int max_fields) {
    int field_count = 0;
    char *token;

    token = strtok(line, &delimiter);
    while (token != NULL && field_count < max_fields) {
        strncpy(fields[field_count++], token, MAX_LINE_LEN);
        token = strtok(NULL, &delimiter);
    }

    return field_count; // Return number of fields found
}

// Function to print the fields for a given line
void print_fields(char fields[][MAX_LINE_LEN], int field_count) {
    for (int i = 0; i < field_count; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    FILE *file;
    char line[MAX_LINE_LEN];
    char fields[MAX_FIELDS][MAX_LINE_LEN];
    char delimiter = ',';
    int field_count;

    file = fopen(argv[1], "r");
    if (file == NULL) {
        fprintf(stderr, "Error: Unable to open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    // Read the CSV file line by line
    while (read_line(file, line, sizeof(line)) > 0) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        field_count = parse_line(line, fields, delimiter, MAX_FIELDS);
        print_fields(fields, field_count);
        printf("\n"); // Add spacing between records
    }

    fclose(file);
    return EXIT_SUCCESS;
}