//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a line from a file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) != NULL) {
        return line;
    }
    free(line);
    return NULL;
}

// Function to split a line into fields based on comma delimiter
int split_line(char *line, char **fields) {
    int field_count = 0;
    char *token = strtok(line, ",");
    
    while (token != NULL) {
        fields[field_count++] = strdup(token);  // duplicate the token to avoid memory access issues
        token = strtok(NULL, ",");
    }
    return field_count;
}

// Function to free the allocated memory for fields
void free_fields(char **fields, int field_count) {
    for (int i = 0; i < field_count; i++) {
        free(fields[i]);
    }
}

// Main function: CSV Reader
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Unable to open file");
        return EXIT_FAILURE;
    }

    char *line;
    char *fields[MAX_FIELDS];

    // Reading the CSV line by line
    while ((line = read_line(file)) != NULL) {
        int field_count = split_line(line, fields);
        
        // Displaying the fields
        printf("Row:\n");
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        printf("\n");

        // Free allocated fields
        free_fields(fields, field_count);
        free(line);
    }

    fclose(file);
    return EXIT_SUCCESS;
}