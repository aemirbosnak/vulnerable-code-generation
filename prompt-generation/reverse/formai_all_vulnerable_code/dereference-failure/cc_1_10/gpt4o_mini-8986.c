//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char *fields[MAX_FIELDS];
    int field_count;
} CSVRow;

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
}

CSVRow *parse_csv_line(char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (!row) {
        perror("Unable to allocate memory for CSVRow");
        exit(EXIT_FAILURE);
    }
    
    row->field_count = 0;
    
    char *token = strtok(line, ",");
    while (token) {
        row->fields[row->field_count] = malloc(strlen(token) + 1);
        if (!row->fields[row->field_count]) {
            perror("Unable to allocate memory for field");
            free_csv_row(row);
            exit(EXIT_FAILURE);
        }
        strcpy(row->fields[row->field_count], token);
        row->field_count++;
        
        token = strtok(NULL, ",");
    }
    
    return row;
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        CSVRow *row = parse_csv_line(line);
        
        // Print the parsed fields in a Cyberpunk way
        printf("++ Data Node ++\n");
        for (int i = 0; i < row->field_count; i++) {
            printf("Field %d: %s\n", i + 1, row->fields[i]);
        }
        printf("++ END DATA NODE ++\n\n");

        // Free allocated memory
        free_csv_row(row);
        free(row);
    }

    fclose(file);
}

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Usage: ./cyber_csv_reader <filename>\n");
        exit(EXIT_FAILURE);
    }

    printf("Initializing Cyber CSV Reader...\n");
    read_csv_file(argv[1]);
    
    printf("Reading complete. Powering down...\n");
    return 0;
}