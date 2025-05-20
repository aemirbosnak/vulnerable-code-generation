//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 50

// Function to trim newline characters from a string
void trim_newline(char *str) {
    str[strcspn(str, "\n")] = 0; // Remove the newline character
}

// Function to read a line from a CSV file
char **read_csv_line(FILE *file) {
    char line[MAX_LINE_LENGTH];
    if (fgets(line, sizeof(line), file) == NULL) {
        return NULL; // EOF or error
    }

    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *token = strtok(line, ",");
    int field_count = 0;

    while (token != NULL) {
        fields[field_count] = malloc((strlen(token) + 1) * sizeof(char));
        strcpy(fields[field_count], token);
        trim_newline(fields[field_count]);
        token = strtok(NULL, ",");
        field_count++;
    }
    fields[field_count] = NULL; // NULL-terminate the array of fields

    return fields;
}

// Function to free the allocated memory
void free_fields(char **fields) {
    for (int i = 0; fields[i] != NULL; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Function to display the CSV data
void display_csv_data(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Error: Could not open file %s\n", filename);
        return;
    }

    printf("Here's the content of %s:\n", filename);
    
    char **fields;
    while ((fields = read_csv_line(file)) != NULL) {
        for (int i = 0; fields[i] != NULL; i++) {
            printf("Field %d: '%s'\n", i + 1, fields[i]);
        }
        printf("---\n");
        free_fields(fields); // Free the allocated fields after displaying
    }

    fclose(file);
    printf("End of the CSV data. Thank you for joining!\n");
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    display_csv_data(filename);

    return EXIT_SUCCESS;
}