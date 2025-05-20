//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

// Function to allocate memory for a CSVRow
CSVRow *create_csv_row(int field_count) {
    CSVRow *row = (CSVRow *)malloc(sizeof(CSVRow));
    row->fields = (char **)malloc(field_count * sizeof(char *));
    row->field_count = field_count;
    for (int i = 0; i < field_count; i++) {
        row->fields[i] = NULL;
    }
    return row;
}

// Function to free a CSVRow
void free_csv_row(CSVRow *row) {
    if (row) {
        for (int i = 0; i < row->field_count; i++) {
            free(row->fields[i]);
        }
        free(row->fields);
        free(row);
    }
}

// Function to split a CSV line into fields
CSVRow *parse_csv_line(const char *line) {
    CSVRow *row = create_csv_row(MAX_FIELDS);
    char *buffer = strdup(line);
    char *token = strtok(buffer, ",");

    int count = 0;
    while (token != NULL && count < MAX_FIELDS) {
        row->fields[count] = strdup(token);
        token = strtok(NULL, ",");
        count++;
    }
    row->field_count = count;

    free(buffer);
    return row;
}

// Function to read a CSV file and print its content
void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (file == NULL) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character from the line
        line[strcspn(line, "\n")] = 0;

        CSVRow *row = parse_csv_line(line);

        // Print the fields of the row
        for (int i = 0; i < row->field_count; i++) {
            printf("Field %d: %s\n", i + 1, row->fields[i]);
        }
        printf("\n");

        free_csv_row(row);
    }

    fclose(file);
}

// Main function
int main(int argc, char *argv[]) {
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return EXIT_FAILURE;
    }

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}