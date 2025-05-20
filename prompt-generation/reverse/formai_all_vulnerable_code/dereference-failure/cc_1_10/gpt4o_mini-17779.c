//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELD_LENGTH 256

typedef struct {
    char **fields;
    size_t field_count;
} CSVRow;

void free_csv_row(CSVRow *row) {
    if (row) {
        for (size_t i = 0; i < row->field_count; i++) {
            free(row->fields[i]);
        }
        free(row->fields);
        free(row);
    }
}

CSVRow* create_csv_row(size_t field_count) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (!row) {
        fprintf(stderr, "Memory allocation failed for CSVRow\n");
        exit(EXIT_FAILURE);
    }

    row->fields = malloc(field_count * sizeof(char *));
    if (!row->fields) {
        fprintf(stderr, "Memory allocation failed for fields\n");
        free(row);
        exit(EXIT_FAILURE);
    }

    row->field_count = field_count;
    for (size_t i = 0; i < field_count; i++) {
        row->fields[i] = malloc(MAX_FIELD_LENGTH);
        if (!row->fields[i]) {
            fprintf(stderr, "Memory allocation failed for field %zu\n", i);
            free_csv_row(row);
            exit(EXIT_FAILURE);
        }
    }
    
    return row;
}

size_t count_fields(const char *line) {
    size_t count = 0;
    const char *ptr = line;

    while (*ptr) {
        if (*ptr == ',') {
            count++;
        }
        ptr++;
    }

    return count + 1; // Increment for the last field
}

void parse_csv_line(const char *line, CSVRow *row) {
    char *token;
    char temp_line[MAX_LINE_LENGTH];
    strncpy(temp_line, line, MAX_LINE_LENGTH);
    temp_line[MAX_LINE_LENGTH - 1] = '\0'; // Null terminate

    size_t index = 0;
    token = strtok(temp_line, ",");
    while (token && index < row->field_count) {
        strncpy(row->fields[index], token, MAX_FIELD_LENGTH);
        row->fields[index][MAX_FIELD_LENGTH - 1] = '\0'; // Null terminate
        index++;
        token = strtok(NULL, ",");
    }
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        fprintf(stderr, "Failed to open file %s\n", filename);
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        size_t field_count = count_fields(line);
        CSVRow *row = create_csv_row(field_count);
        parse_csv_line(line, row);

        // For debugging: print parsed fields
        for (size_t i = 0; i < row->field_count; i++) {
            printf("Field %zu: %s\n", i, row->fields[i]);
        }

        free_csv_row(row);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <csv_file>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *filename = argv[1];
    read_csv_file(filename);

    return EXIT_SUCCESS;
}