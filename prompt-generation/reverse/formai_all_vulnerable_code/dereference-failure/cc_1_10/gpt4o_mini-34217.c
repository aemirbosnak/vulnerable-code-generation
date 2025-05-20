//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to trim newline characters from strings
void trim_newline(char *str) {
    char *pos;
    if ((pos = strchr(str, '\n')) != NULL) {
        *pos = '\0';
    }
}

// Function to split a line into fields using a delimiter
void split_line(const char *line, char fields[MAX_FIELDS][MAX_LINE_LENGTH], char delimiter, int *field_count) {
    char *token;
    char *line_copy = strdup(line); // Create a mutable copy of the line
    *field_count = 0;

    token = strtok(line_copy, &delimiter);
    while (token != NULL) {
        strcpy(fields[*field_count], token);
        (*field_count)++;
        token = strtok(NULL, &delimiter);
    }
    free(line_copy); // Release memory
}

// Function to read CSV file and print its contents
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    char fields[MAX_FIELDS][MAX_LINE_LENGTH];
    int field_count;

    // Reading each line of the CSV file
    while (fgets(line, sizeof(line), file) != NULL) {
        trim_newline(line); // Trim newline character
        split_line(line, fields, ',', &field_count); // Split the line into fields

        // Print the fields
        for (int i = 0; i < field_count; i++) {
            if (i > 0) printf(", ");
            printf("%s", fields[i]);
        }
        printf("\n");
    }

    fclose(file);
}

// Main function to handle command line argument and call the CSV reader
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]); // Call the CSV reader with the provided filename
    return EXIT_SUCCESS;
}