//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

// Function Prototypes
void read_csv_file(const char *filename);
void parse_line(char *line);
void trim_whitespace(char *str);
char** split_line(char *line, int *field_count);

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csvfile>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    return EXIT_SUCCESS;
}

// Function to read the CSV file
void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        parse_line(line);
    }

    fclose(file);
}

// Function to parse a line from the CSV file
void parse_line(char *line) {
    int field_count = 0;
    char **fields = split_line(line, &field_count);

    // Print the fields
    for (int i = 0; i < field_count; i++) {
        printf("Field %d: %s\n", i + 1, fields[i]);
        free(fields[i]); // Free each field after use
    }
    free(fields); // Free the fields array

    printf("\n");
}

// Function to split a line into fields by comma
char** split_line(char *line, int *field_count) {
    char **fields = malloc(MAX_FIELDS * sizeof(char*));
    if (!fields) {
        perror("Could not allocate memory");
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, ",");
    *field_count = 0;

    while (token != NULL) {
        trim_whitespace(token);
        if (*field_count < MAX_FIELDS) {
            fields[*field_count] = malloc(strlen(token) + 1);
            if (fields[*field_count] == NULL) {
                perror("Could not allocate memory for field");
                exit(EXIT_FAILURE);
            }
            strcpy(fields[*field_count], token);
            (*field_count)++;
        }
        token = strtok(NULL, ",");
    }

    return fields;
}

// Function to trim leading and trailing whitespace
void trim_whitespace(char *str) {
    char *end;

    // Trim leading space
    while (isspace((unsigned char)*str)) str++;

    // Trim trailing space
    end = str + strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) end--;

    *(end + 1) = '\0';
}