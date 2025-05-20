//GPT-4o-mini DATASET v1.0 Category: Building a CSV Reader ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LINE_LENGTH 1024
#define MAX_FIELDS 100

typedef struct {
    char **fields;
    int field_count;
} CSVRow;

CSVRow* create_csv_row(int number_of_fields) {
    CSVRow *row = (CSVRow *) malloc(sizeof(CSVRow));
    row->fields = (char **) malloc(number_of_fields * sizeof(char *));
    row->field_count = number_of_fields;

    for (int i = 0; i < number_of_fields; i++) {
        row->fields[i] = (char *) malloc(MAX_LINE_LENGTH * sizeof(char));
    }
    return row;
}

void free_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        free(row->fields[i]);
    }
    free(row->fields);
    free(row);
}

void parse_line(char *line, CSVRow *row) {
    char *token;
    int index = 0;

    token = strtok(line, ",");
    while (token != NULL && index < row->field_count) {
        strcpy(row->fields[index], token);
        token = strtok(NULL, ",");
        index++;
    }
}

void print_csv_row(CSVRow *row) {
    for (int i = 0; i < row->field_count; i++) {
        printf("Field %d: %s\n", i + 1, row->fields[i]);
    }
}

void read_csv(const char *filename) {
    FILE *file = fopen(filename, "r");
    if (!file) {
        perror("Error opening file");
        return;
    }

    char line[MAX_LINE_LENGTH];
    int line_count = 0;

    while (fgets(line, sizeof(line), file)) {
        line_count++;
        
        // Remove newline character if present
        line[strcspn(line, "\n")] = 0;

        int field_count = 0;
        char *temp = line;
        while (*temp) {
            if (*temp == ',') {
                field_count++;
            }
            temp++;
        }
        field_count++; // For the last field

        CSVRow *row = create_csv_row(field_count);
        parse_line(line, row);
        printf("Line %d:\n", line_count);
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

    read_csv(argv[1]);
    return EXIT_SUCCESS;
}