//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a line from a CSV file
char *read_line(FILE *file) {
    char *line = malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file)) {
        return line;
    }
    free(line);
    return NULL;
}

// Function to split a line into fields based on the comma delimiter
char **split_line(char *line, int *field_count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    char *token;
    int count = 0;

    token = strtok(line, ",");
    while (token != NULL && count < MAX_FIELDS) {
        fields[count] = malloc(strlen(token) + 1);
        strcpy(fields[count], token);
        count++;
        token = strtok(NULL, ",");
    }

    *field_count = count;
    return fields;
}

// Function to free the allocated memory for fields
void free_fields(char **fields, int field_count) {
    for (int i = 0; i < field_count; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Main function to read and display CSV data
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename.csv>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    char *line;
    int line_number = 0;
    while ((line = read_line(file)) != NULL) {
        line_number++;
        int field_count;
        char **fields = split_line(line, &field_count);

        printf("Line %d:\n", line_number);
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }
        printf("\n");

        free(line);
        free_fields(fields, field_count);
    }

    fclose(file);
    return EXIT_SUCCESS;
}