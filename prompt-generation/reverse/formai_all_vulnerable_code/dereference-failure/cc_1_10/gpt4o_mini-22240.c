//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to trim whitespace from both ends of a string
char* trim_whitespace(char* str) {
    char* end;

    // Trim leading space
    while (*str == ' ') str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && (*end == ' ' || *end == '\n')) end--;

    // Null terminate
    *(end + 1) = '\0';

    return str;
}

// Function to read a line from the CSV file
int read_line(FILE *file, char *buffer, size_t buffer_size) {
    if (fgets(buffer, buffer_size, file) != NULL) {
        return 1; // Line successfully read
    }
    return 0; // EOF or read error
}

// Function to split a line into fields based on the CSV rules
int parse_csv_line(char *line, char fields[MAX_FIELDS][MAX_LINE_LENGTH]) {
    int field_index = 0;
    int inside_quotes = 0;
    char *token = line;
    char *start = line;

    while (*token) {
        if (*token == '"') {
            inside_quotes = !inside_quotes; // Toggle the quote flag
        }
        if (*token == ',' && !inside_quotes) {
            // End of field
            *token = '\0'; // Replace comma with null terminator
            strcpy(fields[field_index++], trim_whitespace(start)); // Store trimmed field
            start = token + 1; // Move to the start of the next field
        }
        token++;
    }

    // Handle the last field
    if (start != token) {
        strcpy(fields[field_index++], trim_whitespace(start));
    }

    return field_index; // Return the number of fields
}

// Main function to read a CSV file and display its content
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_LINE_LENGTH];
    int line_number = 0;

    // Read and parse each line of the CSV file
    while (read_line(file, line, sizeof(line))) {
        line_number++;
        int num_fields = parse_csv_line(line, fields);

        // Display the parsed fields
        printf("Line %d:\n", line_number);
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        printf("\n");
    }

    fclose(file);
    return EXIT_SUCCESS;
}