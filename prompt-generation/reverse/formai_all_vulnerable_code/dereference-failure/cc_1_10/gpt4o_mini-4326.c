//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to split a line into fields based on a delimiter
char **split_line(char *line, const char *delimiter, int *count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char *));
    if (!fields) {
        perror("Unable to allocate memory for fields");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, delimiter);
    int idx = 0;

    while (token != NULL && idx < MAX_FIELDS) {
        fields[idx] = malloc(strlen(token) + 1);
        if (!fields[idx]) {
            perror("Unable to allocate memory for field");
            exit(EXIT_FAILURE);
        }
        strcpy(fields[idx], token);
        idx++;
        token = strtok(NULL, delimiter);
    }
    *count = idx;
    return fields;
}

// Function to free allocated memory for fields
void free_fields(char **fields, int count) {
    for (int i = 0; i < count; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Function to read and parse a CSV file
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    printf("Reading CSV file: %s\n", filename);
    printf("---------------------------------\n");

    while (fgets(line, sizeof(line), file)) {
        line_count++;
        int field_count = 0;
        char **fields = split_line(line, ",", &field_count);

        printf("Line %d: ", line_count);
        for (int i = 0; i < field_count; i++) {
            printf("[%s] ", fields[i]);
        }
        printf("\n");

        free_fields(fields, field_count);
    }

    fclose(file);
    printf("---------------------------------\n");
    printf("Total Lines Read: %d\n", line_count);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv-file>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    read_csv(argv[1]);
    return 0;
}