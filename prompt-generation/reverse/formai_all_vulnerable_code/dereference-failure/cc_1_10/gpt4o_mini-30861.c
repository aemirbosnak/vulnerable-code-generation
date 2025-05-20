//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
}

CSVRow *parse_csv_line(char *line) {
    CSVRow *row = malloc(sizeof(CSVRow));
    if (!row) {
        perror("Unable to allocate memory for CSVRow");
        exit(EXIT_FAILURE);
    }
    
    row->fields = malloc(sizeof(char *) * MAX_FIELDS);
    if (!row->fields) {
        perror("Unable to allocate memory for fields");
        free(row);
        exit(EXIT_FAILURE);
    }

    char *token = strtok(line, ",");
    row->field_count = 0;

    while (token != NULL && row->field_count < MAX_FIELDS) {
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

void print_csv_row(const CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("%s", row->fields[i]);
        if (i < row->field_count - 1) {
            printf(" | ");
        }
    }
    printf("\n");
}

void read_csv_file(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Could not open file");
        exit(EXIT_FAILURE);
    }

    char line[MAX_LINE_LENGTH];
    while (fgets(line, sizeof(line), file)) {
        line[strcspn(line, "\n")] = 0; // Remove newline character
        CSVRow *row = parse_csv_line(line);
        print_csv_row(row);
        free_csv_row(row);
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