//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to split a line into fields based on the specified delimiter
char **split_line(char *line, const char *delimiter, int *field_count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    if (!fields) {
        perror("Unable to allocate memory for fields.");
        exit(EXIT_FAILURE);
    }

    char *token;
    int count = 0;

    token = strtok(line, delimiter);
    while (token != NULL && count < MAX_FIELDS) {
        fields[count] = malloc(strlen(token) + 1);
        if (!fields[count]) {
            perror("Unable to allocate memory for a field.");
            exit(EXIT_FAILURE);
        }
        strcpy(fields[count], token);
        count++;
        token = strtok(NULL, delimiter);
    }
    *field_count = count;

    return fields;
}

// Function to free the memory allocated for fields
void free_fields(char **fields, int field_count) {
    for (int i = 0; i < field_count; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Main CSV Reader function
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_number = 0;

    // Read each line from the file
    while (fgets(line, sizeof(line), file)) {
        line_number++;
        int field_count = 0;

        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        // Split the line into fields
        char **fields = split_line(line, ",", &field_count);
        
        printf("Line %d: ", line_number);
        for (int i = 0; i < field_count; i++) {
            printf("[%s]", fields[i]);
            if (i < field_count - 1) {
                printf(", ");
            }
        }
        printf("\n");

        // Free the allocated memory for fields
        free_fields(fields, field_count);
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Read and process the CSV file
    read_csv(argv[1]);

    return 0;
}