//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

void parse_csv_line(char *line, char ***fields, int *field_count) {
    char *token;
    int count = 0;
    
    // Allocate initial space for fields
    char **temp_fields = malloc(MAX_FIELD_LENGTH * sizeof(char *));
    if (temp_fields == NULL) {
        fprintf(stderr, "Memory allocation error\n");
        exit(EXIT_FAILURE);
    }

    // Tokenize the line using comma as a delimiter
    token = strtok(line, ",");
    while (token != NULL) {
        temp_fields[count] = malloc(strlen(token) + 1);
        if (temp_fields[count] == NULL) {
            fprintf(stderr, "Memory allocation error\n");
            exit(EXIT_FAILURE);
        }
        strcpy(temp_fields[count], token);
        count++;
        token = strtok(NULL, ",");
    }

    *fields = temp_fields;
    *field_count = count;
}

void free_fields(char **fields, int count) {
    for (int i = 0; i < count; i++) {
        free(fields[i]);
    }
    free(fields);
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file) != NULL) {
        char **fields;
        int field_count;
        
        // Removing newline character that fgets may capture
        line[strcspn(line, "\n")] = 0;

        // Parse the CSV line into fields
        parse_csv_line(line, &fields, &field_count);
        
        // Print the fields
        for (int i = 0; i < field_count; i++) {
            printf("Field %d: %s\n", i + 1, fields[i]);
        }

        // Free allocated fields
        free_fields(fields, field_count);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv_file(argv[1]);

    return EXIT_SUCCESS;
}