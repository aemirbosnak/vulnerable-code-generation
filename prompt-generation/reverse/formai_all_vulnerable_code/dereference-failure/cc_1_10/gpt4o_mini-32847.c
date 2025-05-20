//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function to read a line from the CSV file
char* read_line(FILE *file) {
    char *line = (char*) malloc(MAX_LINE_LENGTH);
    if (fgets(line, MAX_LINE_LENGTH, file) == NULL) {
        free(line);
        return NULL;
    }
    return line;
}

// Function to split a line into fields based on comma delimiter
char** parse_line(char *line, int *field_count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char*));
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

// Function to free memory allocated for fields
void free_fields(char **fields, int field_count) {
    for (int i = 0; i < field_count; i++) {
        free(fields[i]);
    }
    free(fields);
}

// Function to print the fields
void print_fields(char **fields, int field_count) {
    for (int i = 0; i < field_count; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
    }
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    FILE *file = fopen(argv[1], "r");
    if (!file) {
        perror("Could not open file");
        return EXIT_FAILURE;
    }

    char *line;
    int field_count;

    while ((line = read_line(file)) != NULL) {
        // Remove the newline character at the end if present
        line[strcspn(line, "\n")] = 0;

        char **fields = parse_line(line, &field_count);
        print_fields(fields, field_count);
        free_fields(fields, field_count);
        free(line);
    }

    fclose(file);
    return EXIT_SUCCESS;
}