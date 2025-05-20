//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to split a line into fields based on the delimiter
char **split_line(char *line, int *num_fields) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    if (!fields) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, ",");
    *num_fields = 0;

    while (token != NULL && *num_fields < MAX_FIELDS) {
        fields[*num_fields] = malloc(strlen(token) + 1);
        if (!fields[*num_fields]) {
            fprintf(stderr, "Memory allocation failed\n");
            exit(EXIT_FAILURE);
        }
        strcpy(fields[*num_fields], token);
        (*num_fields)++;
        token = strtok(NULL, ",");
    }

    return fields;
}

// Function to free memory allocated for fields
void free_fields(char **fields, int num_fields) {
    for (int i = 0; i < num_fields; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Main function to read the CSV file
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Error opening file");
        return EXIT_FAILURE;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;
    
    printf("Reading CSV file: %s\n", argv[1]);
    
    while (fgets(line, sizeof(line), file) != NULL) {
        line_count++;
        int num_fields;
        
        // Remove trailing newline character
        line[strcspn(line, "\n")] = 0;

        char **fields = split_line(line, &num_fields);

        printf("Row %d:\n", line_count);
        for (int i = 0; i < num_fields; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }

        free_fields(fields, num_fields);
    }

    fclose(file);
    printf("Total rows read: %d\n", line_count);
    
    return EXIT_SUCCESS;
}